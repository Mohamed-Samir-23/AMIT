/*
 * Lab3.c
 *
 * Created: 8/9/2023 1:03:53 AM
 * Author : Mohamed Samir
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#define F_CPU 16000000L
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

/*
#define KEYPAD_PORT 		DIO_PORTC
#define KEYPAD_R0_PIN		DIO_PIN0
#define KEYPAD_R1_PIN		DIO_PIN1
#define KEYPAD_R2_PIN		DIO_PIN2
#define KEYPAD_R3_PIN		DIO_PIN3

#define KEYPAD_C0_PIN		DIO_PIN4
#define KEYPAD_C1_PIN		DIO_PIN5
#define KEYPAD_C2_PIN		DIO_PIN6
#define KEYPAD_C3_PIN		DIO_PIN7
*/
int main(void)
{
    LCD_udtInitialized();
	KEYPAD_voidInit();
	LCD_udtSendData('K');
	unit8 u8keypad='N';
    while (1) 
    {
		
		while(u8keypad=='N')
		{
			KEYPAD_u8GetPressedKey(&u8keypad);
		}
		LCD_udtSendData(u8keypad);
		_delay_ms(1000);
		u8keypad='N';
		/*
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_R0_PIN, DIO_OUTPUT);
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_R1_PIN, DIO_OUTPUT);
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_R2_PIN, DIO_OUTPUT);
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_R3_PIN, DIO_OUTPUT);
			
			
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_R0_PIN, DIO_HIGH);
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_R1_PIN, DIO_HIGH);
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_R2_PIN, DIO_HIGH);
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_R3_PIN, DIO_HIGH);
			
			
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_C0_PIN, DIO_INPUT);
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_C1_PIN, DIO_INPUT);
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_C2_PIN, DIO_INPUT);
			DIO_udtSetPinDirection(KEYPAD_PORT, KEYPAD_C3_PIN, DIO_INPUT);
			
			
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_C0_PIN, DIO_HIGH);
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_C1_PIN, DIO_HIGH);
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_C2_PIN, DIO_HIGH);
			DIO_udtSetPinValue(KEYPAD_PORT, KEYPAD_C3_PIN, DIO_HIGH);
			*/
    }
}

