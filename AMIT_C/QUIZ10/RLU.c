#include"RLU.h"
/*-----------------------------------------------------------------------------------------------*/
/*Functions and Modular MSG*/

void PRINTMSG1()
{

    printf("samir ahmed\n");

}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that prints the cube of any number.*/

void cube_number (int x)
{

printf("the cube of %d is = %d",x,x*x);

}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that takes one character and checks if it alphabet or not.*/

void ck_alph (char x)
{

int alph[]={65,66,67,68,69,70,71,72,73,74,75,76,78,79,80,81,82,83,84,85,86,87,88,89,90,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};//ascii Code alphabet
    int i;
    int ck=0;
    for(i =0;i<=size_of_array;i++)
    {
        if (alph[i]==x)
        {
            ck=1;
        }
        else
        {

        }
        
    }

    if (ck==1)
        {
            printf("you enter char of alphabet\n");
        }
        else
        {
            printf("your enter is not char of alphabet\n");
        }

    
}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that check if the number if positive or negative.*/

void ck_pos_neg (int x)
{

    if (x>=0)
    {
        printf("The number is positive \n");
    }
    else
    {
        printf("The number is negative \n");
    }

}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that return the addition or subtraction 
  or multiplication or division for two numbers. The function 
  should take the required operation and two numbers as arguments. 
  It also should check that the input operation is one of those 
  operation that mentioned before and if not it should return error. 
  The function should be implemented using switch case.*/

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

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that checks if an integer is even or odd.*/
void even_odd_ck (int x)
{
    if(x<0)
    {
        x*=-1;
    }
    else
    {
        //nothing
    }
    int ck=0 ;
    if(x==0)
    {
        ck=1;
    }
    else
    {
        int i;
        for(i=0;i<=x;i++)
        {
            if((2*i)==x)
            {
                ck=1;
                break;
            }
            else
            {
                //nothing
            }
        }
        
    }
    
    
    if(ck==1)
    {
        printf("the number is even \n");
    }
    else
    {
        printf("the number is odd \n");
    }

}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that reads two integers and checks if the first is multiple of the second.*/

void multiple_ck (int x,int y)
{
    if(x<0||y<0)
    {
        if(x<0&&y<0)
        {
            x*=-1;
            y*=-1;
        }
        else if (y<0)
        {
            y*=-1;
        }
        else
        {
            x*=-1;
        }
    }
    else
    {
        //nothing
    }

    int ck=0 ;

    if(x%y==0)//second in one 
    {
        ck=1;
    }
    else
    {

    }
    if(ck==1)
    {
        printf("the first is multiple of the second. \n");
    }
    else
    {
        printf("the first is not multiple of the second. \n");
    }

}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that display Prime Numbers between Intervals (two numbers) by Making Function.*/

void prime_ck(int x ,int y)
{
    if (x<0||y<0)
    {
        printf("negative number not allow \n");
    }
    else
    {
        int i =x+1 ;
        
        for (i ; i < y; i++)
        {
            int ck=0;
            if (i==1)
            {
                continue;
            }
            else
            {
                int j ;
                for ( j = 2; j <= i ; j++)
                {
                    if(i%j==0)
                    {
                        ck+=1;
                        
                    }
                }
                if(ck==1)
                {
                    printf("%d ",i);
                }
                else
                {
                    //nothing
                }

            }
        }
    }
}

/*-----------------------------------------------------------------------------------------------*/
/*Write a C Function that swaps the value of two integer numbers.*/

void swaps(int * x , int *y )
{
    int temp = (*x);
    *x=*y;
    *y=temp;
}

/*-----------------------------------------------------------------------------------------------*/
/*Write a program to display the following stars pattern. 
      * 1
     *** 3
    ***** 5
   ******* 7 
  ********* 9
*/

void stars_pattern(int x)
{
    if (x<=0)
    {
        printf("negative number or zero not allow \n");
    }
    else
    {
        int i;
        for(i=1;i<=x;i++)
        {
            int j,w=0,n=0;
            int space=x-i;//5-1=4
            for ( j = 1; j<=((2*x)-1); j++) 
            {
                if(j<=space)
                {
                    printf(" ");
                }
                else if(w<((2*x)-1-(space*2)))//(2*x)-1-(space*2) is number of *
                {
                    w++;
                    printf("*");
                    n++;
                }
                else
                {
                    //nothing
                }
                
            }

            printf(" %d\n",n);   
        }
    }
}
/*-----------------------------------------------------------------------------------------------*/
/*Write C Function that converts the any letter from lowercase to uppercase.*/
void Lc_to_UC_converter (char * ptr,int len)
{
    char LC[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char UC[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
    for(i=0;i<len;i++)
    {
        int j;
        for (j = 0; j < 26; j++)
        {
            if (ptr[i]==LC[j])
            {
                ptr[i]=UC[j];
            }
        }
        
        
    }

}