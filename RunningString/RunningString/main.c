//������� ������������ f=1MHz
#define F_CPU 1000000UL

//����������� ���������
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "indicator_alphabet.h"



//����� SPI
#define DDR_SHIFT_REGISTER		DDRB
#define PORT_SHIFT_REGISTER		PORTB
#define DATA					PB3			//MOSI
#define LATCH					PB2			//SS
#define CLOCK					PB5			//SCK


//���������� �������� ��������������� ������
//����� ������� int const ACCEPTED_STRING_LENGTH 8 ������ ��� ����� ��������
#define ACCEPTED_STRING_LENGTH	8



//SPI �������
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
	//������� � ���������
	PORT_SHIFT_REGISTER |= (1<<LATCH);
	PORT_SHIFT_REGISTER |= (0<<LATCH);
}

//---------------------------------------------------------------------------


//UART �������
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void uartIni()
{
	// ��������� �������� 9600 baud (bps) ��� 
	// UBRR=(f/(8*baud))-1 ��� f=1000000�� baud=9600,
	// ����������� ��������������� ����� ������, double speed(U2X=1)
	// ��������� �������� 12 ���������� � ����� �����, ����� � ������� ���� ������� ����
		UBRR0H=0;    
		UBRR0L=12;   // ���� ������� ��� f = 8MHz
	
	
	//����:
	//�������� ���� �� UART
	//����������� ������� �������� �������� ������
	//���� ������ 8 ���
	//��� �������� ���� �� �������� ������
	
	
	//���������������� UCSR0A
	{
		
		UCSR0A=  (0<<RXC0)			//7 ���; ���������� �����
		        |(0<<TXC0)			//6 ���; ���������� ��������
		        |(0<<UDRE0)			//5 ���; ���������� ������ ��� ��������
		        |(0<<FE0)			//4 ���; ������ �����
		        |(0<<DOR0)			//3 ���; ������ ������������ ������
		        |(0<<UPE0)			//2 ���; ������ ��������
		        |(1<<U2X0)			//1 ���; ������� ��������
		        |(0<<MPCM0);		//0 ���; ����������������� �����
			
		
	}
	
	//���������������� UCSR0B
	{
		
		UCSR0B=  (0<<RXCIE0)		//7 ���; ���������� ��� ����� ������
				|(0<<TXCIE0)		//6 ���; ���������� ��� ���������� ��������
				|(0<<UDRIE0)		//5 ���; ���������� ���������� ������ ��� ��������
				|(1<<RXEN0)			//4 ���; ���������� �����
				|(0<<TXEN0)			//3 ���; ���������� ��������
				|(0<<UCSZ02)		//2 ���; ����������� ������� ����� ������
				|(0<<RXB80)			//1 ���; 9 ��� �������� ������
				|(0<<TXB80);		//0 ���; 9 ��� ���������� ������
	  
	}
	
	//���������������� UCSR0C
	{
		UCSR0C=  (0<<UMSEL01)		//7 ���; ����� ������ ����������/�����������
				|(0<<UMSEL00)		//6 ���; ����� ������ ����������/�����������
				|(1<<UPM01)			//5 ���; ����������� ���� ��������
				|(1<<UPM00)			//4 ���; ����������� ���� ��������
				|(0<<USBS0)			//3 ���; c��� ����: ��� 0-1 ���� ���, ��� 1-2 ���� ����
				|(1<<UCSZ01)		//2 ���; ����������� ������� ����� ������
				|(1<<UCSZ00)		//1 ���; ����������� ������� ����� ������
				|(0<<UCPOL0);		//0 ���; � ���������� ������ - ������������
		
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




//������� ��� ������ � ������� ������
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void printCharacter(uint16_t characterToPrintCode)
{

	uint8_t higherBits, lowerBits;

	//�������� �������������� ���� ������ ����� �������� ������� ����
	lowerBits = (uint8_t)(characterToPrintCode);
	higherBits = (uint8_t)(characterToPrintCode >> 8);

	//������ ����� � SPI DataRegister � �������� ����� �������� �����
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
	//�������� ������ ��� ������
		
	while(1)
	{
		
	
		//1 ��������
		for (int counter =0; ACCEPTED_STRING_LENGTH>counter; ++counter)
		StringToPrint[counter]='a'+counter;


		invertString(StringToPrint);

		//������� ���� �� ������ ������� ������ � ��������� �������� �������������� �� ������������ �.�. ������������ ������ ������� ��������� ��-�� ������� ��������� ���������
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
					
					//������� ���� �� ������ ������� ������ � ��������� �������� �������������� �� ������������ �.�. ������������ ������ ������� ��������� ��-�� ������� ��������� ���������
					for (int counter = 0; ACCEPTED_STRING_LENGTH>counter; ++counter)
					{
						uint16_t characterToPrint=getCodeFromChar(StringToPrint[counter]);
						printCharacter(characterToPrint);
					}
					
		
	

		latch();
		_delay_ms(30000);
		
	}
}




//��������� ��������� �������







		/*
	
	TEST = uartReceive();
	uint16_t TEST_SYM= getCodeFromChar(TEST);
	printCharacter(TEST_SYM);

		
		*/