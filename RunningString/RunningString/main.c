//частота тактирования f=1MHz
#define F_CPU 1000000UL

//подключение библиотек
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "indicator_alphabet.h"



//маски SPI
#define DDR_SHIFT_REGISTER		DDRB
#define PORT_SHIFT_REGISTER		PORTB
#define DATA					PB3			//MOSI
#define LATCH					PB2			//SS
#define CLOCK					PB5			//SCK


//количество символов программируемой строки
//можно сделать int const ACCEPTED_STRING_LENGTH 8 Только без лапки верблюда
#define ACCEPTED_STRING_LENGTH	8



//SPI функции
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void spiIni()
{
	DDR_SHIFT_REGISTER  |= (1<<DATA) | (1<<LATCH) | (1<<CLOCK);
	PORT_SHIFT_REGISTER |= (0<<DATA) | (0<<LATCH) | (0<<CLOCK);
	SPCR				|= (1<< SPE) | (1<< MSTR);
	PORT_SHIFT_REGISTER |= (0<<LATCH);
}


void latch()
{
	//защелка в регистрах
	PORT_SHIFT_REGISTER |= (1<<LATCH);
	PORT_SHIFT_REGISTER |= (0<<LATCH);
}

//---------------------------------------------------------------------------


//UART функции
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void uartIni()
{
	// Установка скорости 9600 baud (bps) для 
	// UBRR=(f/(8*baud))-1 при f=1000000Гц baud=9600,
	// асинхронный двунаправленный режим работы, double speed(U2X=1)
	// расчетное значение 12 помещается в одном байте, тогда в старший байт запишем нули
		UBRR0H=0;    
		UBRR0L=12;   // если считать что f = 8MHz
	
	
	//Ниже:
	//разрешен приём по UART
	//установлена двойная скорость передачи данных
	//кадр данных 8 бит
	//бит четности идет по нечетным кадрам
	
	
	//конфигурирование UCSR0A
	{
		
		UCSR0A=  (0<<RXC0)			//7 бит; завершение приёма
		        |(0<<TXC0)			//6 бит; завершение передачи
		        |(0<<UDRE0)			//5 бит; отсутствие данных для отправки
		        |(0<<FE0)			//4 бит; ошибка кадра
		        |(0<<DOR0)			//3 бит; ошибка переполнение буфера
		        |(0<<UPE0)			//2 бит; ошибка чётности
		        |(1<<U2X0)			//1 бит; двойная скорость
		        |(0<<MPCM0);		//0 бит; многопроцессорный режим
			
		
	}
	
	//конфигурирование UCSR0B
	{
		
		UCSR0B=  (0<<RXCIE0)		//7 бит; прерывание при приёме данных
				|(0<<TXCIE0)		//6 бит; прерывание при завершение передачи
				|(0<<UDRIE0)		//5 бит; прерывание отсутствие данных для отправки
				|(1<<RXEN0)			//4 бит; разрешение приёма
				|(0<<TXEN0)			//3 бит; разрешение передачи
				|(0<<UCSZ02)		//2 бит; определение размера кадра данных
				|(0<<RXB80)			//1 бит; 9 бит принятых данных
				|(0<<TXB80);		//0 бит; 9 бит переданных данных
	  
	}
	
	//конфигурирование UCSR0C
	{
		UCSR0C=  (0<<UMSEL01)		//7 бит; выбор режима синхронный/асинхронный
				|(0<<UMSEL00)		//6 бит; выбор режима синхронный/асинхронный
				|(1<<UPM01)			//5 бит; определение бита четности
				|(1<<UPM00)			//4 бит; определение бита четности
				|(0<<USBS0)			//3 бит; cтоп биты: лог 0-1 стоп бит, лог 1-2 стоп бита
				|(1<<UCSZ01)		//2 бит; определение размера кадра данных
				|(1<<UCSZ00)		//1 бит; определение размера кадра данных
				|(0<<UCPOL0);		//0 бит; в синхронном режиме - тактирование
		
	}
	
}

char uartReceive( void )
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	
	/* Get and return received data from buffer */
	return UDR0;
}


void fillStringWithUartReceivedData (char pStringToFillWithReceivedData[])
{

for (int counter = 0; ACCEPTED_STRING_LENGTH>counter; ++counter)
	*(pStringToFillWithReceivedData+counter)=uartReceive();

}

//---------------------------------------------------------------------------




//функции для работы с выводом строки
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void printCharacter(uint16_t characterToPrintCode)
{

	uint8_t higherBits, lowerBits;

	//Операция преобразования типа данных здесь отсекает старший байт
	lowerBits = (uint8_t)(characterToPrintCode);
	higherBits = (uint8_t)(characterToPrintCode >> 8);

	//Запись байта в SPI DataRegister и ожидание конца передачи байта
	SPDR = higherBits;
	while(!(SPSR & (1<< SPIF)));

	SPDR = lowerBits;
	while(!(SPSR & (1<< SPIF)));
	

}


void invertString (char pStringToInvert[]) 
{
	char tmpString [ACCEPTED_STRING_LENGTH];
	
	for (int counter = 0; ACCEPTED_STRING_LENGTH>counter; ++counter)
		tmpString[ACCEPTED_STRING_LENGTH-1-counter] = *(pStringToInvert+counter); 
	
	for (int counter = 0; ACCEPTED_STRING_LENGTH>counter; ++counter)
		*(pStringToInvert+counter)=tmpString[counter];	
}

//---------------------------------------------------------------------------

int main()
{
	uartIni();
	spiIni();
	
	char UartAcceptedString [ACCEPTED_STRING_LENGTH];
	char StringToPrint [ACCEPTED_STRING_LENGTH];
	//char TEST;
	//тестовая строка для вывода
		
	while(1)
	{
		
	
		//1 половина
		for (int counter =0; ACCEPTED_STRING_LENGTH>counter; ++counter)
		StringToPrint[counter]='a'+counter;


		invertString(StringToPrint);

		//выводим один за другим символы строки в сдвиговые регистры предварительно ее инвертировав т.к. индикаторная панель выводит зеркально из-за каскада сдвиговых регистров
		for (int counter = 0; ACCEPTED_STRING_LENGTH>counter; ++counter)
		{
			uint16_t characterToPrint=getCodeFromChar(StringToPrint[counter]);
			printCharacter(characterToPrint);
		}

		latch();


		
		
		
					fillStringWithUartReceivedData(UartAcceptedString);
					
					for (int counter =0; ACCEPTED_STRING_LENGTH>counter; ++counter)
					StringToPrint[counter]=UartAcceptedString[counter];
					

					
					invertString(StringToPrint);
					
					//выводим один за другим символы строки в сдвиговые регистры предварительно ее инвертировав т.к. индикаторная панель выводит зеркально из-за каскада сдвиговых регистров
					for (int counter = 0; ACCEPTED_STRING_LENGTH>counter; ++counter)
					{
						uint16_t characterToPrint=getCodeFromChar(StringToPrint[counter]);
						printCharacter(characterToPrint);
					}
					
		
	

		latch();
		_delay_ms(30000);
		
	}
}




//исправить обработку массива







		/*
	
	TEST = uartReceive();
	uint16_t TEST_SYM= getCodeFromChar(TEST);
	printCharacter(TEST_SYM);

		
		*/