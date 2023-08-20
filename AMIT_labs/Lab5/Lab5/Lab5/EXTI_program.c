#include "BIT_MATH.h"
#include "STD_TYPES.h"



#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"




void EXTI_voidInt0Init(void)
{
	
	#if EXTI_INT0_SENSE_MODE == FALLING_EDGE
	
	    CLR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		
	#elif EXTI_INT0_SENSE_MODE == RISING_EDGE	
	
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		
	#elif EXTI_INT0_SENSE_MODE == ON_CHANGE

		SET_BIT(MCUCR, ISC00);
	    CLR_BIT(MCUCR, ISC01);
		
	#elif EXTI_INT0_SENSE_MODE == LOW_LEVEL
	
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

	#else
		
	#error "Invalid sense mode configration"
	
	#endif
	
	/*ENABLE INTERRUPT ZERO*/
	SET_BIT(GICR, INT0);
}

