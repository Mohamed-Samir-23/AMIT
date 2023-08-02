/*
 ============================================================================
 Name        : QUIZ3.C
 Author      : Mohamed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : ASG_2-1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void calc(int x ,int y ,char opr);
int main(void) {

printf("Enter Number_1 \n");
int x;
scanf("%d",&x);

printf("Enter operator \n");
char opr;
scanf(" %c",&opr);

printf("Enter Number_2 \n");
int y;
scanf("%d",&y);

calc(x ,y ,opr);


	return EXIT_SUCCESS;
}


void calc(int x ,int y ,char opr)
{


switch (opr)
{
case '+':
    printf("The result = %d\n",(x+y));
    break;


case '-':
    printf("The result = %d\n",(x-y));
    break;

case '*':
    printf("The result = %d\n",(x*y));
    break;

case '/':
    printf("The result = %d\n",(x/y));
    break;

default:
    printf("wrong operator\n");
    break;
}


}