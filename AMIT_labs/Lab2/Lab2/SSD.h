#ifndef _SSD_H_
#define _SSD_H_
#define F_CPU 16000000UL

#define SSD_ONE ((unit8)1u)
#define SSD_TWO ((unit8)2u)

#define SSD_A 	((unit8)4u)
#define SSD_B 	((unit8)5u)
#define SSD_C 	((unit8)6u)
#define SSD_D 	((unit8)7u)
#define SSD_EN1 ((unit8)1u)
#define SSD_EN2 ((unit8)2u)



Std_ReturnType SSD_utdInit
(
	unit8 u8SSD_number
);


Std_ReturnType SSD_utdDisplay
(
	unit8 u8SSD_num,
	unit8 u8SSD_DisplayNum
);


Std_ReturnType SSD_utdDisplayTwoNum
(
	unit8 u8SSD_DisplayNum
);


#endif