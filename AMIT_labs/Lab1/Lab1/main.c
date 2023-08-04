/*
 * Lab1.c
 *
 * Created: 8/4/2023 1:52:25 AM
 * Author : Mohamed Samir
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "LEDS.h"


int main(void)
{
    LEDS_utdInit(LED0);
	LEDS_utdInit(LED1);
	LEDS_utdInit(LED2);
    while (1) 
    {
		LEDS_utdLED_Control(LED0,LED_TOGGLE);
		LEDS_utdLED_Control(LED1,LED_TOGGLE);
		LEDS_utdLED_Control(LED2,LED_TOGGLE);
		_delay_ms(1000);
    }
}

