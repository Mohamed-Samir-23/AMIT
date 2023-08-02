/*
 * SDB.h
 *
 *  Created on: May 24, 2023
 *      Author: Mohamed Samir
 */

#ifndef SDB_H_
#define SDB_H_

#include "C:\Users\moham\workspace\C_Programming\Amit_C_Project\Utility\STD.h"
#include <stdio.h>

#define max_student 10
#define min_student 3

typedef struct SimpleDb
{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
	struct SimpleDb * next;
}student;

bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(void);
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(void);
bool SDB_IsIdExist(uint32 id);


#endif /* SDB_H_ */
