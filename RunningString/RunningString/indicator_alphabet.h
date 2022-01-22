#ifndef INDICATOR_ALPHABET_H_
#define INDICATOR_ALPHABET_H_

//коды сегментов индикатора
enum eSeg
{
	//внешний круг	сегментов
	SEG_A=0b1000000000000000,
	SEG_B=0b0000000000000001,
	SEG_C=0b0000000000000100,
	SEG_D=0b0000000000100000,
	SEG_E=0b0000000001000000,
	SEG_F=0b0000000010000000,
	SEG_G=0b0000000100000000,
	SEG_H=0b0001000000000000,
	
	//внутренний круг сегментов
	SEG_K=0b0010000000000000,
	SEG_M=0b0100000000000000,
	SEG_N=0b0000000000000010,
	SEG_P=0b0000000000001000,
	SEG_R=0b0000000000010000,
	SEG_S=0b0000010000000000,
	SEG_T=0b0000001000000000,
	SEG_U=0b0000100000000000

};


//коды символов индикатора
enum eSym
{
	SYM_EN_A=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_U|SEG_P),
	SYM_EN_B=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_S|SEG_M|SEG_P),
	SYM_EN_C=(SEG_A|SEG_B|SEG_E|SEG_F|SEG_G|SEG_H),
	SYM_EN_D=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_S|SEG_M),
	SYM_EN_E=(SEG_A|SEG_B|SEG_H|SEG_G|SEG_E|SEG_F|SEG_U|SEG_P),
	SYM_EN_F=(SEG_A|SEG_B|SEG_H|SEG_G|SEG_U|SEG_P),
	SYM_EN_G=(SEG_A|SEG_B|SEG_H|SEG_G|SEG_E|SEG_F|SEG_D|SEG_P),
	SYM_EN_H=(SEG_D|SEG_C|SEG_H|SEG_G|SEG_U|SEG_P),
	SYM_EN_I=(SEG_A|SEG_B|SEG_M|SEG_S|SEG_E|SEG_F),
	SYM_EN_J=(SEG_G|SEG_E|SEG_F|SEG_D|SEG_C),
	SYM_EN_K=(SEG_H|SEG_G|SEG_U|SEG_N|SEG_R),
	SYM_EN_L=(SEG_H|SEG_G|SEG_E|SEG_F),
	SYM_EN_M=(SEG_K|SEG_N|SEG_H|SEG_G|SEG_C|SEG_D),
	SYM_EN_N=(SEG_K|SEG_R|SEG_H|SEG_G|SEG_C|SEG_D),
	SYM_EN_O=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_F|SEG_E),
	SYM_EN_P=(SEG_A|SEG_B|SEG_C|SEG_G|SEG_H|SEG_U|SEG_P),
	SYM_EN_Q=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_F|SEG_E|SEG_R),
	SYM_EN_R=(SEG_A|SEG_B|SEG_C|SEG_R|SEG_G|SEG_H|SEG_U|SEG_P),
	SYM_EN_S=(SEG_A|SEG_B|SEG_D|SEG_H|SEG_F|SEG_E|SEG_U|SEG_P),
	SYM_EN_T=(SEG_A|SEG_B|SEG_M|SEG_S),
	SYM_EN_U=(SEG_C|SEG_D|SEG_G|SEG_H|SEG_F|SEG_E),
	SYM_EN_V=(SEG_H|SEG_G|SEG_T|SEG_N),
	SYM_EN_W=(SEG_T|SEG_R|SEG_H|SEG_G|SEG_C|SEG_D),
	SYM_EN_X=(SEG_K|SEG_R|SEG_T|SEG_N),
	SYM_EN_Y=(SEG_K|SEG_S|SEG_N),
	SYM_EN_Z=(SEG_A|SEG_B|SEG_F|SEG_E|SEG_T|SEG_N),
	
	
	
	SYM_RU_A=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_U|SEG_P),
	SYM_RU_B=(SEG_A|SEG_B|SEG_H|SEG_G|SEG_E|SEG_F|SEG_D|SEG_P|SEG_U),	//Б
	SYM_RU_V=(SEG_B|SEG_M|SEG_N|SEG_S|SEG_E|SEG_P|SEG_D),	//В
	SYM_RU_G=(SEG_A|SEG_B|SEG_G|SEG_H),
	SYM_RU_D=(SEG_A|SEG_B|SEG_C|SEG_G|SEG_E|SEG_F|SEG_D|SEG_P|SEG_U),
	SYM_RU_E=(SEG_A|SEG_B|SEG_H|SEG_G|SEG_E|SEG_F|SEG_U|SEG_P),
	SYM_RU_J=(SEG_K|SEG_R|SEG_T|SEG_N|SEG_M|SEG_S), //Ж
	SYM_RU_Z=(SEG_B|SEG_N|SEG_P|SEG_D|SEG_E),
	SYM_RU_I=(SEG_T|SEG_N|SEG_H|SEG_G|SEG_C|SEG_D),
	SYM_RU_K=(SEG_H|SEG_G|SEG_U|SEG_N|SEG_R),
	SYM_RU_L=(SEG_T|SEG_N|SEG_C|SEG_D),
	SYM_RU_M=(SEG_K|SEG_N|SEG_H|SEG_G|SEG_C|SEG_D),
	SYM_RU_N=(SEG_D|SEG_C|SEG_H|SEG_G|SEG_U|SEG_P),
	SYM_RU_O=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_F|SEG_E),	
	SYM_RU_P=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H),
	SYM_RU_R=(SEG_A|SEG_B|SEG_C|SEG_G|SEG_H|SEG_U|SEG_P),
	SYM_RU_S=(SEG_A|SEG_B|SEG_E|SEG_F|SEG_G|SEG_H),
	SYM_RU_T=(SEG_A|SEG_B|SEG_M|SEG_S),
	SYM_RU_U=(SEG_H|SEG_U|SEG_P|SEG_D|SEG_C|SEG_E),
	SYM_RU_F=(SEG_A|SEG_B|SEG_C|SEG_M|SEG_H|SEG_U|SEG_P),
	SYM_RU_H=(SEG_K|SEG_R|SEG_T|SEG_N),	
	SYM_RU_CC=(SEG_H|SEG_G|SEG_F|SEG_M|SEG_S|SEG_E), //Ц
	SYM_RU_CH=(SEG_H|SEG_U|SEG_P|SEG_D|SEG_C),	//Ч
	SYM_RU_SH=(SEG_F|SEG_E|SEG_H|SEG_G|SEG_C|SEG_D|SEG_S),//Ш
	SYM_RU_TZ=(SEG_A|SEG_M|SEG_S|SEG_E|SEG_P|SEG_D),//Ъ
	SYM_RU_II=(SEG_H|SEG_G|SEG_F|SEG_S|SEG_U|SEG_D|SEG_C),	//Ы
	SYM_RU_MZ=(SEG_H|SEG_G|SEG_F|SEG_S|SEG_U),	//Ь
	SYM_RU_EE=(SEG_A|SEG_B|SEG_E|SEG_F|SEG_D|SEG_C|SEG_P|SEG_U), //Э
	SYM_RU_YOU=(SEG_H|SEG_G|SEG_U|SEG_M|SEG_S|SEG_E|SEG_D|SEG_C|SEG_B), //Ю
	SYM_RU_YA=(SEG_A|SEG_H|SEG_M|SEG_U|SEG_S|SEG_T),
	
	
	SYM_1=(SEG_N|SEG_C|SEG_D),
	SYM_2=(SEG_A|SEG_B|SEG_C|SEG_G|SEG_F|SEG_E|SEG_U|SEG_P),
	SYM_3=(SEG_A|SEG_B|SEG_E|SEG_F|SEG_D|SEG_C|SEG_P),
	SYM_4=(SEG_H|SEG_U|SEG_P|SEG_D|SEG_C),
	SYM_5=(SEG_A|SEG_B|SEG_D|SEG_H|SEG_F|SEG_E|SEG_U|SEG_P),
	SYM_6=(SEG_A|SEG_B|SEG_H|SEG_G|SEG_E|SEG_F|SEG_D|SEG_P|SEG_U),
	SYM_7=(SEG_A|SEG_B|SEG_C|SEG_D),
	SYM_8=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_U|SEG_P|SEG_F|SEG_E),
	SYM_9=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_H|SEG_U|SEG_P|SEG_F|SEG_E),
	SYM_0=(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G|SEG_H|SEG_F|SEG_E),

	SYM_TEST=((SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G|SEG_H)|(SEG_K|SEG_M|SEG_N|SEG_P|SEG_R|SEG_S|SEG_T|SEG_U)), //ВСЕ СЕГМЕНТЫ ГОРЯТ
	SYM_ERASE=~((SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G|SEG_H)|(SEG_K|SEG_M|SEG_N|SEG_P|SEG_R|SEG_S|SEG_T|SEG_U)),//ВСЕ СЕГМЕНТЫ ПОГАСЛИ

};


uint16_t getCodeFromChar(char receivedSymbol)
{
	enum eSym charCode;
	
	switch (receivedSymbol)
	{
		case 'A':
		case 'a':
		case '\0':
		charCode=SYM_EN_A;
		break;
		
		case 'B':
		case 'b':
		charCode=SYM_EN_B;
		break;
		
		case 'C':
		case 'c':
		charCode=SYM_EN_C;
		break;
		
		case 'D':
		case 'd':
		charCode=SYM_EN_D;
		break;
		
		case 'E':
		case 'e':
		charCode=SYM_EN_E;
		break;
		
		case 'F':
		case 'f':
		charCode=SYM_EN_F;
		break;
		
		case 'G':
		case 'g':
		charCode=SYM_EN_G;
		break;
		
		case 'H':
		case 'h':
		charCode=SYM_EN_H;
		break;
		
		case 'I':
		case 'i':
		charCode=SYM_EN_I;
		break;
		
		case 'J':
		case 'j':
		charCode=SYM_EN_J;
		break;
		
		case 'K':
		case 'k':
		charCode=SYM_EN_K;
		break;
		
		case 'L':
		case 'l':
		charCode=SYM_EN_L;
		break;
		
		case 'M':
		case 'm':
		charCode=SYM_EN_M;
		break;
		
		case 'N':
		case 'n':
		charCode=SYM_EN_N;
		break;
		
		case 'O':
		case 'o':
		charCode=SYM_EN_O;
		break;
		
		case 'P':
		case 'p':
		charCode=SYM_EN_P;
		break;
		
		case 'Q':
		case 'q':
		charCode=SYM_EN_Q;
		break;
		
		case 'R':
		case 'r':
		charCode=SYM_EN_R;
		break;
		
		case 'S':
		case 's':
		charCode=SYM_EN_S;
		break;
		
		case 'T':
		case 't':
		charCode=SYM_EN_T;
		break;
		
		case 'U':
		case 'u':
		charCode=SYM_EN_U;
		break;
		
		case 'V':
		case 'v':
		charCode=SYM_EN_V;
		break;
		
		case 'W':
		case 'w':
		charCode=SYM_EN_W;
		break;
		
		case 'X':
		case 'x':
		charCode=SYM_EN_X;
		break;
		
		case 'Y':
		case 'y':
		charCode=SYM_EN_Y;
		break;
		
		case 'Z':
		case 'z':
		charCode=SYM_EN_Z;
		break;
		
	
		case 'А':
		case 'а':
		charCode=SYM_RU_A;
		break;
		
		case 'Б':
		case 'б':
		charCode=SYM_RU_B;
		break;
		
		case 'В':
		case 'в':
		charCode=SYM_RU_V;
		break;
		
		case 'Г':
		case 'г':
		charCode=SYM_RU_G;
		break;
		
		case 'Д':
		case 'д':
		charCode=SYM_RU_D;
		break;
		
		case 'Е':
		case 'е':
		charCode=SYM_RU_E;
		break;
		
		case 'Ж':
		case 'ж':
		charCode=SYM_RU_J;
		break;
		
		case 'З':
		case 'з':
		charCode=SYM_RU_Z;
		break;
		
		case 'И':
		case 'и':
		charCode=SYM_RU_I;
		break;
		
		case 'К':
		case 'к':
		charCode=SYM_RU_K;
		break;
		
		case 'Л':
		case 'л':
		charCode=SYM_RU_L;
		break;
		
		case 'М':
		case 'м':
		charCode=SYM_RU_V;
		break;

		case 'Н':
		case 'н':
		charCode=SYM_RU_N;
		break;
		
		case 'О':
		case 'о':
		charCode=SYM_RU_O;
		break;
		
		case 'П':
		case 'п':
		charCode=SYM_RU_P;
		break;
		
		case 'Р':
		case 'р':
		charCode=SYM_RU_R;
		break;
		
		case 'С':
		case 'с':
		charCode=SYM_RU_S;
		break;
		
		case 'Т':
		case 'т':
		charCode=SYM_RU_T;
		break;
		
		case 'У':
		case 'у':
		charCode=SYM_RU_U;
		break;
		
		case 'Ф':
		case 'ф':
		charCode=SYM_RU_F;
		break;
		
		case 'Х':
		case 'х':
		charCode=SYM_RU_H;
		break;
		
		case 'Ц':
		case 'ц':
		charCode=SYM_RU_CC;
		break;
		
		case 'Ч':
		case 'ч':
		charCode=SYM_RU_CH;
		break;
		
		case 'Ш':
		case 'ш':
		charCode=SYM_RU_SH;
		break;
		
		case 'Ъ':
		case 'ъ':
		charCode=SYM_RU_TZ;
		break;
		
		case 'Ы':
		case 'ы':
		charCode=SYM_RU_II;
		break;
		
		case 'Ь':
		case 'ь':
		charCode=SYM_RU_MZ;
		break;
		
		case 'Э':
		case 'э':
		charCode=SYM_RU_EE;
		break;
		
		case 'Ю':
		case 'ю':
		charCode=SYM_RU_YOU;
		break;
		
		case 'Я':
		case 'я':
		charCode=SYM_RU_YA;
		break;
		
		case '1':
		charCode=SYM_1;
		break;
		
		case '2':
		charCode=SYM_2;
		break;
		
		case '3':
		charCode=SYM_3;
		break;
		
		case '4':
		charCode=SYM_4;
		break;
		
		case '5':
		charCode=SYM_5;
		break;
		
		
		case '6':
		charCode=SYM_6;
		break;
		
		case '7':
		charCode=SYM_7;
		break;
		
		case '8':
		charCode=SYM_8;
		break;
		
		case '9':
		charCode=SYM_9;
		break;
		
		case '0':
		charCode=SYM_0;
		break;
		
		default:
		charCode=SYM_TEST;
		break;
	}
	
	return ((uint16_t)charCode);
	
}



#endif 