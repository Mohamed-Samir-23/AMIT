#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_
#define F_CPU 16000000L
/*Mode Select*/
#define LCD_MODE 4	

#if LCD_MODE == 4

/*CONTROL PIN*/
#define LCD_CONTROL_Port 	DIO_PORTB
#define RS   				DIO_PIN1
#define RW   				DIO_PIN2
#define E    				DIO_PIN3
/*DATA PIN*/
#define LCD_Data_Port 		DIO_PORTA
#define LCD_Data_D4 		DIO_PIN4
#define LCD_Data_D5 		DIO_PIN5
#define LCD_Data_D6 		DIO_PIN6
#define LCD_Data_D7 		DIO_PIN7

#elif LCD_MODE == 8

/*CONTROL PIN*/
#define LCD_CONTROL_Port 	DIO_PORTB
#define RS   				DIO_PIN1
#define RW   				DIO_PIN2
#define E    				DIO_PIN3

/*DATA PIN*/
#define LCD_Data_Port 		DIO_PORTA
#define LCD_Data_D0 		DIO_PIN0
#define LCD_Data_D1 		DIO_PIN1
#define LCD_Data_D2 		DIO_PIN2
#define LCD_Data_D3 		DIO_PIN3
#define LCD_Data_D4 		DIO_PIN4
#define LCD_Data_D5 		DIO_PIN5
#define LCD_Data_D6 		DIO_PIN6
#define LCD_Data_D7 		DIO_PIN7

#else
/*NOTHING*/
#endif
#endif
