/*
 * SDB.c
 *
 *  Created on: May 24, 2023
 *      Author: Mohamed Samir
 */

#include "C:\Users\moham\workspace\C_Programming\Amit_C_Project\Application\SDB.h"


student*head=null;//make pointer that pointer to first node

uint8 static numstudent=0;//number of student of in list and make it privet for this file

/*
 * ******************************** Function Description **************************
 * Description: check if the database is full or not.
 * Return: if the database is full return true else return false
 */

bool SDB_IsFull (void)
{
	if(numstudent < max_student) //check if we have a space in list or not
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}

}
/*
 * ******************************** Function Description **************************
 * Description: get how many students in your database have added
 * Return: Return the number of students in the database
 */
uint8 SDB_GetUsedSize(void)
{
	return numstudent;
}

/*
 * ******************************** Function Description **************************
 * Description: When the user chooses to add entry this function asks him for the
 * required data in the database to add one
 * student which is his (id, year, Course1_ID,
 * Course1_grade, Course2_ID,
 * Course2_grade, Course3_ID, andCourse3_grade) and then add to your database.
 * Return: return 1 if the data is added successfully return 0 if the data not added
 * to your database which depend on the input of the user whether is the data
 * entered is correct or not and the data is full or not
 * implementation : by using linked list way
 * by creating node when we add element and check if list of full or not
 * then scan data and put it in object
 */

bool SDB_AddEntry(void)
{
	if(SDB_IsFull()==FALSE) //check if we have a space in list or not
	{
		student * newnode=(student *)malloc (sizeof(student));

		if(head==null)
		{
			head=newnode;
			head->next=null;
		}
		else
		{


			student * ptrtemp =head;

			while(ptrtemp->next!=null)
			{
				ptrtemp=ptrtemp->next; //Find the last node that have null in next pointer
			}
			ptrtemp->next=newnode; // make the next pointer of previous node pointer to new node
			newnode->next=null; //make the next pointer of last node pointer to null

		}

		//scan data

		printf("enter your student id \n");
		fflush(stdout);
		scanf("%d",&newnode->Student_ID);

		printf("enter your student year \n");
		fflush(stdout);
		scanf("%d",&newnode->Student_year);

		printf("enter your student Course1 ID \n");
		fflush(stdout);
		scanf("%d",&newnode->Course1_ID);

		printf("enter your Course1 grade \n");
		fflush(stdout);
		scanf("%d",&newnode->Course1_grade);

		printf("enter your student Course2 ID \n");
		fflush(stdout);
		scanf("%d",&newnode->Course2_ID);

		printf("enter your Course2 grade \n");
		fflush(stdout);
		scanf("%d",&newnode->Course2_grade);

		printf("enter your student Course3 ID \n");
		fflush(stdout);
		scanf("%d",&newnode->Course3_ID);

		printf("enter your Course3 grade \n");
		fflush(stdout);
		scanf("%d",&newnode->Course3_grade);

		numstudent++;
		return TRUE;
	}
	else
	{
		return FALSE;

	}

}

/*
 * ******************************** Function Description **************************
 * Description: Checks if the given id the isExist
 * Return: return 1 if the id is existed and return 0 if the id not found.
 * implementation : by make pointer temp looping the node to find id
 */


bool SDB_IsIdExist (uint32 id)
{
	student *ptr =head;
	while(ptr!=null)
		{
			if(ptr->Student_ID!=id)
			{
				return TRUE;
			}
			else
			{
				ptr=ptr->next;
			}
		}

	return FALSE;


}

/*
 * ******************************** Function Description **************************
 * Description: delete the student data with the given id.
 * implementation : by make next pointer of previous node pointer the next pointer in the node that we need
 * to delete then delete it by free
 *
 */


void SDB_DeletEntry (uint32 id)
{


	if(SDB_IsIdExist(id)==TRUE)
	{

	student *current =head;
	student * temp =null;
	student * previous =null;

	while(current->Student_ID!=id)
	{
		previous =current;
		current=current->next;
	}

	if(head->Student_ID==id)
	{
		temp=head;
		head=head->next;
		free(temp);
		numstudent--;

	}
	else
	{
		previous->next = current->next;
		free(current);
		numstudent--;
	}


	}
	else
	{
		printf("this id is not exist\n");
	}


}


/*
 * ******************************** Function Description **************************
 * Description: print the data of the user by searching on his data by the given id
 * Return: return 1 if the data is existed return 0 if this id not your database
 * implementation : by make pointer temp looping the node to find node that have id then print the node data
 *
 */


bool SDB_ReadEntry (uint32 id)
{

	if(SDB_IsIdExist(id)==TRUE)
	{
		student *current =head;

		while(current->Student_ID!=id)
		{
			current=current->next;
		}

		printf("Student id =%d :\n",current->Student_ID);
		printf("Student year =%d\n",current->Student_year);
		printf("Course1 ID =%d\n",current->Course1_ID);
		printf("Course1 ID =%d\n",current->Course1_grade);
		printf("Course2 ID =%d\n",current->Course2_ID);
		printf("Course2 ID =%d\n",current->Course2_grade);
		printf("Course3 ID =%d\n",current->Course3_ID);
		printf("Course3 ID =%d\n",current->Course3_grade);

		return TRUE;
	}
	else
	{
		return FALSE;
	}


}



/*
 * ******************************** Function Description **************************
 * Description: Description: it gets the number of ids in the count and the list of all ids in list array that’s
 * you get his base address.
 * implementation : by make pointer temp looping the node and print id of each node
 *
 */


void SDB_GetList (void)
{
	if(numstudent>0)
	{
		uint8 i;
		student * temp =head;
		for(i=1;i<=numstudent;i++)
		{
			printf("student %d id : %d\n",i,temp->Student_ID);
			temp=temp->next;
		}


	}
	else
	{

		printf("the list is empty");

	}


}

