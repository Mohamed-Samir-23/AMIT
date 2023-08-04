#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LEDS.h"

Std_ReturnType LEDS_utdInit
(
	unit8 u8ledNo
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8ledNo)
	{
		case LED0:	DIO_udtSetPinDirection(DIO_PORTC,LED0,DIO_OUTPUT);udtReturnType=E_OK;break;
		case LED1:	DIO_udtSetPinDirection(DIO_PORTC,LED1,DIO_OUTPUT);udtReturnType=E_OK;break;
		case LED2:	DIO_udtSetPinDirection(DIO_PORTD,LED2,DIO_OUTPUT);udtReturnType=E_OK;break;
		default :	udtReturnType=E_NOT_OK;break;
	}
	return udtReturnType;
}


Std_ReturnType LEDS_utdLED_ON
(
	unit8 u8ledNo
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8ledNo)
	{
		case LED0:	DIO_udtSetPinValue(DIO_PORTC,LED0,DIO_HIGH);udtReturnType=E_OK;break;
		case LED1:	DIO_udtSetPinValue(DIO_PORTC,LED1,DIO_HIGH);udtReturnType=E_OK;break;
		case LED2:	DIO_udtSetPinValue(DIO_PORTD,LED2,DIO_HIGH);udtReturnType=E_OK;break;
		default :	udtReturnType=E_NOT_OK;break;
	}
	return udtReturnType;
}


Std_ReturnType LEDS_utdLED_OFF
(
	unit8 u8ledNo
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8ledNo)
	{
		case LED0:	DIO_udtSetPinValue(DIO_PORTC,LED0,DIO_LOW);udtReturnType=E_OK;break;
		case LED1:	DIO_udtSetPinValue(DIO_PORTC,LED1,DIO_LOW);udtReturnType=E_OK;break;
		case LED2:	DIO_udtSetPinValue(DIO_PORTD,LED2,DIO_LOW);udtReturnType=E_OK;break;
		default :	udtReturnType=E_NOT_OK;break;
	}
	return udtReturnType;
}


Std_ReturnType LEDS_utdLED_TOGGLE
(
	unit8 u8ledNo
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8ledNo)
	{
		case LED0:	DIO_udtTogglePinValue(DIO_PORTC,LED0);udtReturnType=E_OK;break;
		case LED1:	DIO_udtTogglePinValue(DIO_PORTC,LED1);udtReturnType=E_OK;break;
		case LED2:	DIO_udtTogglePinValue(DIO_PORTD,LED2);udtReturnType=E_OK;break;
		default :	udtReturnType=E_NOT_OK;break;
	}
	return udtReturnType;
}


Std_ReturnType LEDS_utdLED_Control
(
	unit8 u8ledNo, 
	LED_STATES udtState
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(udtState)
	{
		case LED_OFF:		udtReturnType = LEDS_utdLED_OFF(u8ledNo);break;
		case LED_ON:		udtReturnType = LEDS_utdLED_ON(u8ledNo);break;
		case LED_TOGGLE:	udtReturnType = LEDS_utdLED_TOGGLE(u8ledNo);break;
		default :		udtReturnType=E_NOT_OK;break;
	}
	return udtReturnType;
}