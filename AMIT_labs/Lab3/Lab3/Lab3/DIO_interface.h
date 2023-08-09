#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


#define DIO_PORTA	((unit8)0u)//u to define 0 as unsiend 
#define DIO_PORTB	((unit8)1u)
#define DIO_PORTC	((unit8)2u)
#define DIO_PORTD	((unit8)3u)


#define DIO_OUTPUT	((unit8)1u)
#define DIO_INPUT	((unit8)0u)


#define DIO_HIGH	((unit8)1u)
#define DIO_LOW		((unit8)0u)


#define DIO_PIN0	((unit8)0u)
#define DIO_PIN1	((unit8)1u)
#define DIO_PIN2	((unit8)2u)
#define DIO_PIN3	((unit8)3u)
#define DIO_PIN4	((unit8)4u)
#define DIO_PIN5	((unit8)5u)
#define DIO_PIN6	((unit8)6u)
#define DIO_PIN7	((unit8)7u)

Std_ReturnType DIO_udtSetPinDirection
(
	unit8 u8Port,
	unit8 u8Pin,
	unit8 u8Direction
);//udt user define type of return 



Std_ReturnType DIO_udtSetPinValue
(
	unit8 u8Port,
	unit8 u8Pin,
	unit8 u8Value
);


Std_ReturnType DIO_udtGetPinValue
(
	unit8 u8Port,
	unit8 u8Pin,
	unit8* pu8Value
);

Std_ReturnType DIO_udtTogglePinValue
(
	unit8 u8Port,
	unit8 u8Pin
);


Std_ReturnType DIO_udtSetPortDirection
(
	unit8 u8Port,
	unit8 u8Value
);



Std_ReturnType DIO_udtSetPortValue
(
	unit8 u8Port,
	unit8 u8Value
);


Std_ReturnType DIO_udtGetPortValue
(
	unit8 u8Port,
	unit8* pu8Value
);


Std_ReturnType DIO_udtReadPortValue
(
	unit8 u8Port,
	unit8* pu8Value
);

#endif