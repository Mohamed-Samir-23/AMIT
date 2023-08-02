/*
 ============================================================================
 Name        : QUIZ6.c
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float real;
	float img;
}complex;



void take_complex(complex * com1)
{
	printf("Enter real and imaginary part respectively:\n");
	scanf("%f%f",&com1->real,&com1->img);
}
complex add_complex (complex * com1,complex * com2)
{
	complex temp;
	temp.real=com1->real+com2->real;
	temp.img=com1->img+com2->img;
	return temp;

}

int main(void) {

	complex c1,c2,result;

	printf("For 1st complex number");

	take_complex(&c1);

	printf("For 2st complex number");

	take_complex(&c2);

	result=add_complex (&c1,&c2);

	printf("sum = %0.1f + %0.1f",result.real,result.img);

	return EXIT_SUCCESS;
}
