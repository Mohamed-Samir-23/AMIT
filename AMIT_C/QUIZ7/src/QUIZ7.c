/*
 ============================================================================
 Name        : QUIZ7.c
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {

	int x,y;
	printf("enter the first number : \n");
	fflush(stdout);
	scanf("%d",&x);
	printf("enter the second number : \n");
	fflush(stdout);
	scanf("%d",&y);
	printf("before swapping : \n");
	printf("x=%d y=%d \n",x,y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("after swapping : \n");
	printf("x=%d y=%d \n",x,y);

	return EXIT_SUCCESS;
}
