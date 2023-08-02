/*
 ============================================================================
 Name        : QUIZ1.C
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : ASG_1-1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("enter your number\n");
	int number;
	scanf("%d",&number);
	
	
	int i,check=0;
	if(number <0)
	{
		number*=-1;
	}
	for(i=0;i<=number;i++)
	{
		if((2*i)==number||number==0)//even 2n , odd 2n+1
		{
			check=1;
		}
		else
		{
		}
	}

	if(check==1)
	{
		printf("the number is odd = 0\n");
		printf("the number is even = 1\n");
	}
	else
	{
		printf("the number is odd = 1\n");
		printf("the number is even = 0\n");
	}

	return EXIT_SUCCESS;
}