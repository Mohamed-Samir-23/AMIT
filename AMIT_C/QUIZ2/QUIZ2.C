/*
 ============================================================================
 Name        : QUIZ2.C
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : ASG_1-2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("Enter your number: ");
	int number;
	scanf("%d",&number); //read number
    printf("Enter nth bit to toggle (0-31): ");
	int bit;
	scanf("%d",&bit); //read bit 0-31

    int val=number^(1<<bit); //toggle bit



	printf("Number before toggling %d bit: %d\n",bit,number);
    printf("Number after toggling %d bit: %d\n",bit,val);

	return EXIT_SUCCESS;
}