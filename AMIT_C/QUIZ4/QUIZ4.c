/*
 ============================================================================
 Name        : QUIZ4.C
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : ASG_2-2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
void ck_Armstrong(unsigned int x);
int main(void) {

printf("enter your number = ");

unsigned int x;

scanf("%d",&x);

ck_Armstrong(x);

	return EXIT_SUCCESS;
}

void ck_Armstrong(unsigned int x)
{
unsigned int i=x;
unsigned int result=0;
while (i!=0)
{
    result+=(i%10)*(i%10)*(i%10);
    i/=10;
}
if(result==x)
{
    printf("Armstrong Number\n");
}
else
{
    printf("is not Armstrong Number\n");
}

}