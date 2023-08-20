#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_private.h"
#include "GIE_interface.h"



void GIE_voidEnable(void)
{
	SET_BIT(SREG, I_BIT);
}


void GIE_voidDisable(void)
{
	CLR_BIT(SREG, I_BIT);
}