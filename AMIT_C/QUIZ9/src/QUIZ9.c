/*
 ============================================================================
 Name        : QUIZ9.c
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void edit(int *ptr,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		ptr[i]+=1;
	}

}


int main(void) {

	int x[]={5,20,80};

	int i;
	printf("before calling edit x = ");
	for(i=0;i<3;i++)
	{
		printf("%d ",x[i]);
	}
	edit(x,3);
	printf("\nafter calling edit x = ");
	for(i=0;i<3;i++)
	{
		printf("%d ",x[i]);
	}

	return EXIT_SUCCESS;
}
