/*
 * Lab4.c
 *
 * Created: 8/10/2023 10:18:09 PM
 * Author : Mohamed Samir
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"

#define KEYPAD_NOT_PRESSED	'N'

#define F_CPU 16000000L
#include <util/delay.h>
unit8 arrow [8]={0x00,0x00,0x04,0x06,0x1F,0x06,0x04,0x00};
	
unit8 PERSON_1_POS [8]={0x0C,0x0C,0x00,0x0E,0x1C,0x0C,0x1A,0x13};
unit8 PERSON_2_POS [8]={0x0C,0x0C,0x00,0x0C,0x0C,0x0C,0x0C,0x0E};
unit8 PERSON_3_POS [8]={0x06,0x06,0x00,0x06,0x06,0x06,0x06,0x0E};
unit8 ball_1_POS [8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10};
	
unit8 PERSON_4_POS [8]={0x06,0x06,0x00,0x07,0x06,0x06,0x16,0x06};
unit8 PERSON_5_POS [8]={0x06,0x06,0x00,0x17,0x06,0x1E,0x12,0x02};
unit8 PERSON_6_POS [8]={0x06,0x06,0x00,0x0F,0x06,0x06,0x0B,0x19};
unit8 ball_2_POS [8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01};

unit8 Home_A[8]={0x00,0x00,0x01,0x02,0x05,0x08,0x1F,0x08};
unit8 Home_B[8]={0x00,0x1F,0x08,0x04,0x12,0x01,0x1F,0x02};
unit8 Home_C[8]={0x00,0x10,0x08,0x04,0x02,0x01,0x1F,0x02};
	
unit8 Home_L[8]={0x08,0x08,0x08,0x09,0x09,0x09,0x09,0x0F};
unit8 Home_J[8]={0x02,0x02,0x02,0x12,0x12,0x12,0x12,0x1F};
unit8 Home_K[8]={0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x1E};
	
	
int main(void)
{
	unit8 arrow_pos=0,PB1_Value=1,PB2_Value=0;
    LCD_udtInitialized();//LCD initialization
	KEYPAD_udtInit();
	DIO_udtSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_INPUT);
	DIO_udtSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	_delay_ms(250);
	LCD_udtAddSpecialChar(arrow, 0);
	LCD_udtPrintSpecialChar(0,0,0);
	
    while (1) 
    {
		_delay_ms(50);
		DIO_udtGetPinValue(DIO_PORTB,DIO_PIN0,&PB1_Value);
		LCD_udtGoTo(0, 2);
		LCD_udtPrintString("Animation");
		LCD_udtGoTo(1, 2);
		LCD_udtPrintString("Calculator");
		
		if(1==arrow_pos&&1==PB1_Value)
		{
			LCD_udtGoTo(1, 0);
			LCD_udtSendData (' ');
			LCD_udtPrintSpecialChar(0,0,0);
			arrow_pos=0;
		}
		else if(0==arrow_pos&&1==PB1_Value)
		{
			LCD_udtGoTo(0, 0);
			LCD_udtSendData (' ');
			LCD_udtPrintSpecialChar(0,1,0);
			arrow_pos=1;
		}
		else
		{
			if(0==arrow_pos&&1==PB2_Value)
			{
				LCD_udtClear();
				LCD_udtPrintStringAtXY ("Hi Samir, HYD ? My Name is AMIT ",0,0);
				_delay_ms(5000);
				LCD_udtClear();
				LCD_udtAddSpecialChar(PERSON_1_POS, 0);
				LCD_udtAddSpecialChar(PERSON_1_POS, 0);
				LCD_udtAddSpecialChar(PERSON_2_POS, 1);
				LCD_udtAddSpecialChar(ball_1_POS, 2);
				LCD_udtClear();
				LCD_udtGoTo(0, 0);
				LCD_udtSendData (' ');
				while(1)
				{
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("I can run ");
					unit8 L_u8i=0;
					for(L_u8i=0;L_u8i<16;L_u8i++)
					{
						LCD_udtPrintSpecialChar(0,1,L_u8i);
						_delay_ms(200);
						LCD_udtPrintSpecialChar(1,1,L_u8i);
						_delay_ms(100);
						if(L_u8i==15)
						{
							
						}
						else
						{
							LCD_udtGoTo(1, L_u8i);
							LCD_udtSendData (' ');
						}
						
					}
					
					_delay_ms(1500);
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("Wait a Minute..");//10
					LCD_udtAddSpecialChar(PERSON_3_POS, 1);
					_delay_ms(1500);
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("               ");//10
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("give me ball");//10
					for(L_u8i=0;L_u8i<15;L_u8i++)
					{
						LCD_udtPrintSpecialChar(2,1,L_u8i);
						_delay_ms(400);
						LCD_udtGoTo(1, L_u8i);
						LCD_udtSendData (' ');
						if(L_u8i+1==15)
						{
							LCD_udtGoTo(1, 14);
							LCD_udtSendData (' ');
						}
					}

					LCD_udtAddSpecialChar(PERSON_4_POS, 0);
					LCD_udtAddSpecialChar(PERSON_5_POS, 2);
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("it\'s Fun    ");//10
					for(L_u8i=0;L_u8i<15;L_u8i++)
					{
						
						LCD_udtPrintSpecialChar(0,1,15);
						_delay_ms(400);
						LCD_udtPrintSpecialChar(2,1,15);
						_delay_ms(400);
					}
					LCD_udtPrintSpecialChar(1,1,15);
					LCD_udtAddSpecialChar(PERSON_6_POS, 2);
					LCD_udtAddSpecialChar(ball_2_POS, 3);
					for(L_u8i=0;L_u8i<15;L_u8i++)
					{
						LCD_udtPrintSpecialChar(2,1,(15-L_u8i));
						_delay_ms(200);
						LCD_udtPrintSpecialChar(1,1,(15-L_u8i));
						_delay_ms(50);
						LCD_udtPrintSpecialChar(3,1,(13-L_u8i));
						_delay_ms(200);
						
						LCD_udtGoTo(1, (15-L_u8i));
						LCD_udtSendData (' ');
						LCD_udtGoTo(1, (13-L_u8i));
						LCD_udtSendData (' ');
						
						
					}
					LCD_udtAddSpecialChar(PERSON_2_POS, 3);
					LCD_udtPrintSpecialChar(3,1,0);
					_delay_ms(1500);
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("i\'M Tired..");
					_delay_ms(1500);
					LCD_udtGoTo(0, 0);
					LCD_udtPrintString("i\'ll go home");
					_delay_ms(1000);
					LCD_udtAddSpecialChar(PERSON_1_POS, 2);
					LCD_udtAddSpecialChar(Home_A, 0);
					LCD_udtPrintSpecialChar(0,0,13);
					LCD_udtAddSpecialChar(Home_B, 1);
					LCD_udtPrintSpecialChar(1,0,14);
					LCD_udtAddSpecialChar(Home_C, 4);
					LCD_udtPrintSpecialChar(4,0,15);
					LCD_udtAddSpecialChar(Home_L, 5);
					LCD_udtPrintSpecialChar(5,1,13);
					LCD_udtAddSpecialChar(Home_J, 6);
					LCD_udtPrintSpecialChar(6,1,14);
					LCD_udtAddSpecialChar(Home_K, 7);
					LCD_udtPrintSpecialChar(7,1,15);
					
					for(L_u8i=0;L_u8i<13;L_u8i++)
					{
						LCD_udtPrintSpecialChar(2,1,L_u8i);
						_delay_ms(200);
						LCD_udtPrintSpecialChar(3,1,L_u8i);
						_delay_ms(100);
						if(L_u8i==15)
						{
								
						}
						else
						{
							LCD_udtGoTo(1, L_u8i);
							LCD_udtSendData (' ');
						}
							
					}
					LCD_udtClear();
					LCD_udtAddSpecialChar(arrow, 0);
					LCD_udtAddSpecialChar(arrow, 0);
					LCD_udtClear();
					LCD_udtPrintSpecialChar(0,0,0);
					break;
				}
			}
			else if (1==arrow_pos&&1==PB2_Value)
			{
				
				LCD_udtClear();
				LCD_udtPrintStringAtXY ("Hi Enter Number1",0,0);
				volatile char number1[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				unit8 L_u8number=KEYPAD_NOT_PRESSED,L_u8j=0,operant1=1,operant2=1,operation=0;
				unit32 u32Result_keypad=0;
				while((L_u8number!='\0'))
				{
					L_u8number=KEYPAD_NOT_PRESSED;
					while(L_u8number==KEYPAD_NOT_PRESSED)
					{
						
						KEYPAD_udtGetPressedKey(&L_u8number);
						
					}
					if(L_u8j==0&&L_u8number=='\0')
					{
						L_u8number==KEYPAD_NOT_PRESSED;
					}
					else
					{
						LCD_udtGoTo(1, L_u8j);
						LCD_udtSendData(L_u8number);
						_delay_ms(1000);
						number1[L_u8j]=L_u8number;
						L_u8j++;
						
					}
					
				}
				
				
				KEYPAD_udtConvertStrToNum(number1,&operant1);//convert string to number
				LCD_udtClear();
				LCD_udtPrintStringAtXY ("Enter operation",0,0);
				L_u8number=KEYPAD_NOT_PRESSED;
				while((L_u8number!='\0'))
				{
					while(L_u8number==KEYPAD_NOT_PRESSED)
					{
						
						KEYPAD_udtGetPressedKey(&L_u8number);
						
					}
					if(L_u8number=='\0')
					{
						L_u8number==KEYPAD_NOT_PRESSED;
					}
					else if((L_u8number!='*')&&(L_u8number!='+')&&(L_u8number!='-')&&(L_u8number!='/'))
					{
						L_u8number==KEYPAD_NOT_PRESSED;
					}
					else
					{
						LCD_udtGoTo(1, 0);
						LCD_udtSendData(L_u8number);
						_delay_ms(1000);
						operation=L_u8number;
						L_u8number='\0';
					}
					
				}
				
				LCD_udtClear();
				LCD_udtPrintStringAtXY ("Hi Enter Number2",0,0);
				volatile char number2[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				L_u8number=KEYPAD_NOT_PRESSED;
				L_u8j=0;
				while((L_u8number!='\0'))
				{
					L_u8number=KEYPAD_NOT_PRESSED;		
					while(L_u8number==KEYPAD_NOT_PRESSED)
					{
								
						KEYPAD_udtGetPressedKey(&L_u8number);
								
					}
					if(L_u8j==0&&L_u8number=='\0')
					{
						L_u8number==KEYPAD_NOT_PRESSED;
					}
					else
					{
						LCD_udtGoTo(1, L_u8j);
						LCD_udtSendData(L_u8number);
						_delay_ms(1000);
						number2[L_u8j]=L_u8number;
						L_u8j++;
					}
							
				}
						
				KEYPAD_udtConvertStrToNum(number2,&operant2);//convert string to number
				LCD_udtClear();
				LCD_udtPrintStringAtXY ("The result is ",0,0);
				switch(operation)
				{
					case '+':	u32Result_keypad=operant1+operant2;break;
					case '-':	u32Result_keypad=operant1-operant2;break;
					case '/':	u32Result_keypad=operant1/operant2;break;
					case '*':	u32Result_keypad=operant1*operant2;break;
					default:break;
				}
						
				LCD_DisplayNumber(u32Result_keypad,LCD_DecimalBase);
				_delay_ms(5000);
				LCD_udtClear();
				LCD_udtAddSpecialChar(arrow, 0);
				LCD_udtAddSpecialChar(arrow, 0);
				LCD_udtClear();
				LCD_udtPrintSpecialChar(0,0,0);
											
			}
			else
			{
				
			}
		}
		DIO_udtGetPinValue(DIO_PORTD,DIO_PIN2,&PB2_Value);
		_delay_ms(250);
    }
}

