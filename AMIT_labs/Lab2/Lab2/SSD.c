#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD.h"
#include <util/delay.h>

Std_ReturnType SSD_utdInit
(
	unit8 u8SSD_num
)
{
	
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8SSD_num)
	{
		case SSD_ONE:	DIO_udtSetPinDirection(DIO_PORTB,SSD_EN1,DIO_OUTPUT);udtReturnType=E_OK;break;				
		case SSD_TWO:	DIO_udtSetPinDirection(DIO_PORTB,SSD_EN2,DIO_OUTPUT);udtReturnType=E_OK;break;
		default :		udtReturnType=E_NOT_OK;break;
	}
	
	if(udtReturnType==E_OK)
	{
		DIO_udtSetPinDirection(DIO_PORTA,SSD_A,DIO_OUTPUT);
		DIO_udtSetPinDirection(DIO_PORTA,SSD_B,DIO_OUTPUT);
		DIO_udtSetPinDirection(DIO_PORTA,SSD_C,DIO_OUTPUT);
		DIO_udtSetPinDirection(DIO_PORTA,SSD_D,DIO_OUTPUT);
	}
	else
	{
		udtReturnType=E_NOT_OK;
	}
	
	return udtReturnType;
	
}


Std_ReturnType SSD_utdDisplay
(
	unit8 u8SSD_num,
	unit8 u8SSD_DisplayNum
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	unit8 u8halfport=0;
	if(u8SSD_DisplayNum<=9)
	{
		switch(u8SSD_num)
		{
			case SSD_ONE:	DIO_udtSetPinValue(DIO_PORTB,SSD_EN2,DIO_LOW);
							DIO_udtSetPinValue(DIO_PORTB,SSD_EN1,DIO_HIGH);
							DIO_udtReadPortValue(DIO_PORTA,&u8halfport);
							u8halfport=((u8SSD_DisplayNum<<4)|(u8halfport&0x0F));
							DIO_udtSetPortValue(DIO_PORTA, u8halfport);
							udtReturnType=E_OK;break;				
			case SSD_TWO:	DIO_udtSetPinValue(DIO_PORTB,SSD_EN1,DIO_LOW);
							DIO_udtSetPinValue(DIO_PORTB,SSD_EN2,DIO_HIGH);
							DIO_udtReadPortValue(DIO_PORTA,&u8halfport);
							u8halfport=((u8SSD_DisplayNum<<4)|(u8halfport&0x0F));
							DIO_udtSetPortValue(DIO_PORTA, u8halfport);
							udtReturnType=E_OK;break;
			default :		udtReturnType=E_NOT_OK;break;
		}
		
		
	}
	else
	{
		
		udtReturnType=E_NOT_OK;
		
	}
	
	return udtReturnType;
	
}


Std_ReturnType SSD_utdDisplayTwoNum
(
	unit8 u8SSD_DisplayNum
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	if(u8SSD_DisplayNum<=99)
	{
		
		SSD_utdDisplay(SSD_ONE,(unit8)(u8SSD_DisplayNum%10));
		_delay_ms(10);
		SSD_utdDisplay(SSD_TWO,(unit8)(u8SSD_DisplayNum/10));
		_delay_ms(10);
	}
	else
	{
		udtReturnType=E_NOT_OK;
	}
	
	return udtReturnType;
	
}
