/*
 ============================================================================
 Name        : QUIZ8.c
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{

	if (n==0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n-1)+fibonacci(n-2);
	}


}

int main(void) {

	int num=0;
	printf("enter the first number : \n");
	fflush(stdout);
	scanf("%d",&num);
	int i;
	for(i = 0;i<num;i++)
	{
		printf("%d ",fibonacci(i));
	}
	return EXIT_SUCCESS;
}
