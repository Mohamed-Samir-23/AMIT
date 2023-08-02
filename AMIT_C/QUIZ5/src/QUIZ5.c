/*
 ============================================================================
 Name        : QUIZ5.c
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
	char * name;
	int age;
	int degree;
	int section;

}sc;



void print(sc*stud,int number_of_st)
{
	int i;
	for(i=0;i<number_of_st;i++)
	{
		printf("Name : %s\n",stud[i].name);

		printf("age : %d\n",stud[i].age);

		printf("degree : %d\n",stud[i].degree);

		printf("section : %d\n",stud[i].section);
		printf("--------------------------------\n");
	}

}

int main(void) {

	sc stu[4];
	stu[0].name="mohamed";
	stu[0].age=25;
	stu[0].degree=90;
	stu[0].section=1;
	//------------------------------
	stu[1].name="samir";
	stu[1].age=26;
	stu[1].degree=95;
	stu[1].section=2;
	//------------------------------
	stu[2].name="ahmed";
	stu[2].age=27;
	stu[2].degree=96;
	stu[2].section=3;
	//------------------------------
	stu[3].name="badwai";
	stu[3].age=28;
	stu[3].degree=97;
	stu[3].section=4;

	print(stu,4);

	return EXIT_SUCCESS;

}

