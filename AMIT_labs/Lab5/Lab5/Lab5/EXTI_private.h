#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define GICR 	*((volatile unit8 *)0x5B)//ENABLE 
#define INT2	5u
#define INT0	6u
#define INT1	7u

#define GIFR 	*((volatile unit8 *)0x5A)//FLAGS

#define MCUCR 	*((volatile unit8 *)0x55)//RISING FALLNG ON CHANGE LOW LEVEL INT 0 -INT 1
#define ISC00 0U
#define ISC01 1u
#define ISC10 2u
#define ISC11 3u


#define MCUCSR 	*((volatile unit8 *)0x54)//RISING FALLNG INT 2
#define ISC2 6u

#endif