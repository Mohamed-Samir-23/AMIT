#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

typedef struct
{
	
	unit8 PIND;
	unit8 DDRD;
	unit8 PORTD;
	
	unit8 PINC;
	unit8 DDRC;
	unit8 PORTC;
	//RESERVED if you want 
	unit8 PINB;
	unit8 DDRB;
	unit8 PORTB;
	
	unit8 PINA;
	unit8 DDRA;
	unit8 PORTA;
	
	
}DIO_TYPE;

#define DIO ((DIO_TYPE*)0x30)
//DIO->PINA;



#endif