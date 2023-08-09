#ifndef _KEYPAD_CONFIG_H_
#define _KEYPAD_CONFIG_H_
#define KPD_BUTTONS {\
						{'1','2','3','+'},\
						{'4','5','6','-'},\
						{'7','8','9','*'},\
						{'.','0','=','/'},\
					}

#define KEYPAD_R0_PIN		DIO_PORTC,	DIO_PIN0
#define KEYPAD_R1_PIN		DIO_PORTC,	DIO_PIN1
#define KEYPAD_R2_PIN		DIO_PORTC,	DIO_PIN2
#define KEYPAD_R3_PIN		DIO_PORTC,	DIO_PIN3
#define KEYPAD_C0_PIN		DIO_PORTC,	DIO_PIN4
#define KEYPAD_C1_PIN		DIO_PORTC,	DIO_PIN5
#define KEYPAD_C2_PIN		DIO_PORTC,	DIO_PIN6
#define KEYPAD_C3_PIN		DIO_PORTD,	DIO_PIN5

#define KEYPAD_NOT_PRESSED	'N'



#endif