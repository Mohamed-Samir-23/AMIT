/*
 * Lab5.c
 *
 * Created: 8/18/2023 4:28:29 PM
 * Author : moham
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
unit8 i=0;
int main(void)
{
	DIO_udtSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_OUTPUT);
    EXTI_voidInt0Init();
	GIE_voidEnable();
	
    while (1) 
    {
    }
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(i==0)
	{
		DIO_udtSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
		i=1;
	}
	else
	{
		DIO_udtSetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);
		i=0;
	}
	
}