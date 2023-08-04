
#ifndef _LEDS_H_
#define _LEDS_H_

typedef enum
{
	
	LED_OFF,
	LED_ON,
	LED_TOGGLE
	
}LED_STATES;

#define LED0 	((unit8)2u)
#define LED1 	((unit8)7u)
#define LED2 	((unit8)3u)


Std_ReturnType LEDS_utdInit
(
	unit8 u8ledNo
);
Std_ReturnType LEDS_utdLED_ON
(
	unit8 u8ledNo
);
Std_ReturnType LEDS_utdLED_OFF
(
	unit8 u8ledNo
);

Std_ReturnType LEDS_utdLED_TOGGLE
(
	unit8 u8ledNo
);

Std_ReturnType LEDS_utdLED_Control
(
	unit8 u8ledNo, 
	LED_STATES udtState
);


#endif