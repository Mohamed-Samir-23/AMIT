/*
 * Lab2.c
 *
 * Created: 8/4/2023 4:05:52 AM
 * Author : Mohamed Samir
 */ 

#include "STD_TYPES.h"
#include "SSD.h"
#include <util/delay.h>
int main(void)
{
	SSD_utdInit(SSD_ONE);
	SSD_utdInit(SSD_TWO);
    while (1) 
    {
		unit8 i =0;
		for(i=0;i<99;i++)
		{
			unit16 t =50;
			while(t!=0)
			{
				SSD_utdDisplayTwoNum(i);
				t--;
			}
			

		}
    }
}

