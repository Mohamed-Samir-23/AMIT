#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"


Std_ReturnType DIO_udtSetPinDirection
(
	unit8 u8Port,
	unit8 u8Pin,
	unit8 u8Direction
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	if(u8Direction==DIO_OUTPUT)
	{
		switch(u8Port)
		{
			case DIO_PORTA:SET_BIT(DIO->DDRA, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTB:SET_BIT(DIO->DDRB, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTC:SET_BIT(DIO->DDRC, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTD:SET_BIT(DIO->DDRD, u8Pin);udtReturnType=E_OK;break;
			default:/*!Comment: DO nothing*/break;
		}
		
	}
	else if(u8Direction==DIO_INPUT)
	{
		switch(u8Port)
		{
			case DIO_PORTA:CLR_BIT(DIO->DDRA, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTB:CLR_BIT(DIO->DDRB, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTC:CLR_BIT(DIO->DDRC, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTD:CLR_BIT(DIO->DDRD, u8Pin);udtReturnType=E_OK;break;
			default:/*!Comment: DO nothing*/break;
		}
		
	}
	else
	{
		/*!Comment: DO nothing*/
	}
	return udtReturnType;
} 


Std_ReturnType DIO_udtSetPinValue
(
	unit8 u8Port,
	unit8 u8Pin,
	unit8 u8Value
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	if(u8Value==DIO_HIGH)
	{
		switch(u8Port)
		{
			case DIO_PORTA:SET_BIT(DIO->PORTA, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTB:SET_BIT(DIO->PORTB, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTC:SET_BIT(DIO->PORTC, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTD:SET_BIT(DIO->PORTD, u8Pin);udtReturnType=E_OK;break;
			default:/*!Comment: DO nothing*/break;
		}
		
	}
	else if(u8Value==DIO_LOW)
	{
		switch(u8Port)
		{
			case DIO_PORTA:CLR_BIT(DIO->PORTA, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTB:CLR_BIT(DIO->PORTB, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTC:CLR_BIT(DIO->PORTC, u8Pin);udtReturnType=E_OK;break;
			case DIO_PORTD:CLR_BIT(DIO->PORTD, u8Pin);udtReturnType=E_OK;break;
			default:/*!Comment: DO nothing*/break;
		}
		
	}
	else
	{
		/*!Comment: DO nothing*/
	}
	
	return udtReturnType;
	
} 


Std_ReturnType DIO_udtGetPinValue
(
	unit8 u8Port,
	unit8 u8Pin,
	unit8* pu8Value
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8Port)
	{
		case DIO_PORTA:*pu8Value=GET_BIT(DIO->PINA, u8Pin);udtReturnType = E_OK;break;
		case DIO_PORTB:*pu8Value=GET_BIT(DIO->PINB, u8Pin);udtReturnType = E_OK;break;
		case DIO_PORTC:*pu8Value=GET_BIT(DIO->PINC, u8Pin);udtReturnType = E_OK;break;
		case DIO_PORTD:*pu8Value=GET_BIT(DIO->PIND, u8Pin);udtReturnType = E_OK;break;
		default:/*!Comment: DO nothing*/break;
	}
	
	return udtReturnType;
	
}


Std_ReturnType DIO_udtTogglePinValue
(
	unit8 u8Port,
	unit8 u8Pin
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8Port)
	{
		case DIO_PORTA:TOG_BIT(DIO->PORTA, u8Pin);udtReturnType=E_OK;break;
		case DIO_PORTB:TOG_BIT(DIO->PORTB, u8Pin);udtReturnType=E_OK;break;
		case DIO_PORTC:TOG_BIT(DIO->PORTC, u8Pin);udtReturnType=E_OK;break;
		case DIO_PORTD:TOG_BIT(DIO->PORTD, u8Pin);udtReturnType=E_OK;break;
		default:/*!Comment: DO nothing*/break;
	}
	return udtReturnType;
}


Std_ReturnType DIO_udtSetPortDirection
(
	unit8 u8Port,
	unit8 u8Value
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8Port)
	{
		case DIO_PORTA:DIO->DDRA = u8Value;udtReturnType = E_OK;break;
		case DIO_PORTB:DIO->DDRB = u8Value;udtReturnType = E_OK;break;
		case DIO_PORTC:DIO->DDRC = u8Value;udtReturnType = E_OK;break;
		case DIO_PORTD:DIO->DDRD = u8Value;udtReturnType = E_OK;break;
		default:/*!Comment: DO nothing*/break;
	}
	return udtReturnType;
}



Std_ReturnType DIO_udtSetPortValue
(
	unit8 u8Port,
	unit8 u8Value
)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8Port)
	{
		case DIO_PORTA:DIO->PORTA = u8Value;udtReturnType = E_OK;break;
		case DIO_PORTB:DIO->PORTB = u8Value;udtReturnType = E_OK;break;
		case DIO_PORTC:DIO->PORTC = u8Value;udtReturnType = E_OK;break;
		case DIO_PORTD:DIO->PORTD = u8Value;udtReturnType = E_OK;break;
		default:/*!Comment: DO nothing*/break;
	}
	return udtReturnType;
}


Std_ReturnType DIO_udtGetPortValue
(
	unit8 u8Port,
	unit8* pu8Value
)
{
	
	
	Std_ReturnType udtReturnType=E_NOT_OK;
	switch(u8Port)
	{
		case DIO_PORTA:*pu8Value = DIO->PINA;udtReturnType = E_OK;break;
		case DIO_PORTB:*pu8Value = DIO->PINB;udtReturnType = E_OK;break;
		case DIO_PORTC:*pu8Value = DIO->PINC;udtReturnType = E_OK;break;
		case DIO_PORTD:*pu8Value = DIO->PIND;udtReturnType = E_OK;break;
		default:/*!Comment: DO nothing*/break;
	}
	
	return udtReturnType;
	
	
	
}