/*
 * SDBAPP.c
 *
 *  Created on: May 24, 2023
 *      Author: Mohamed Samir
 */

#include "C:\Users\moham\workspace\C_Programming\Amit_C_Project\Application\SDBAPP.h"

uint8 exit1 =1;

/*
 * ******************************** Function Description **************************
 *Description: it well takes the user choice and call the responding function for this
 *choice.You make the right response to give a valid Output for the user
 */

void SDB_action (uint8 choice)
{
	uint32 id;
	switch(choice)
	{
		case 0: exit1=0;
				break;
		case 1: SDB_AddEntry();
				break;
		case 2: printf("the size is %d\n",SDB_GetUsedSize());
				break;
		case 3: printf("enter id : \n");
				fflush(stdout);
				scanf("%d",&id);
				if(SDB_ReadEntry (id)==FALSE)
				{
					printf("this id is not exist\n");
				}
				break;
		case 4: SDB_GetList();
				break;
		case 5: printf("enter id : \n");
				fflush(stdout);
				scanf("%d",&id);
				if(SDB_IsIdExist(id)==TRUE)
				{
					printf("this id is exist\n");
				}
				else
				{
					printf("this id is not exist\n");
				}
				break;
		case 6: printf("enter id : \n");
				fflush(stdout);
				scanf("%d",&id);
				SDB_DeletEntry (id);
				break;
		case 7: if(SDB_IsFull()==TRUE)
				{
					printf("the database is FULL\n");
				}
				else
				{
					printf("the database is not FULL\n");
				}
				break;
		default :printf("this choice is not valid\n");
				 break;
	}

}



/*
 * ******************************** Function Description **************************
 *Description: it has a super loop it will make your project until the user chose to exit you
 *will ask the user to choose between these options :
 *1. To add entry, enter 1
 *2. To get used size in database, enter 2
 *3. To read student data, enter 3
 *4. To get the list of all student IDs, enter 4
 *5. To check is ID is existed, enter 5
 *6. To delete student data, enter 6
 *7. To check is database is full, enter 7
 *8. To exit enter 0
 *The it will call the SDB_action
 */

void SDB_APP (void)
{
	uint8 choose =0;
	printf("choose between these options\n");
	printf("To add entry, enter 1\n");
	printf("To get used size in database, enter 2\n");
	printf("To read student data, enter 3\n");
	printf("To get the list of all student IDs, enter 4\n");
	printf("To check is ID is existed, enter 5\n");
	printf("To delete student data, enter 6\n");
	printf("To check is database is full, enter 7\n");
	printf("To exit enter 0\n");
	fflush(stdout);
	scanf("%d",&choose);
	SDB_action (choose);//pass choose to SDB_action function

}


