/*
 ============================================================================
 Name        : Amit_C_Project.c
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\moham\workspace\C_Programming\Amit_C_Project\Application\SDBAPP.h"
extern uint8 exit1;

int main(void) {

	while(exit1)
	{
		SDB_APP ();
	}
	printf("the program is end \n");
	return EXIT_SUCCESS;
}
