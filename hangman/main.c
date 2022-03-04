#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addnl.h"


int main()
{
    

    startscreen();
    
}

void printword(char *print)
{
    printf("\t\t\t\t\t\t\tHANGMAN\n");
    printf("\t\t\t\t\t\t\t");
    for(int i=0;i<strlen(print);i++)
    {
        printf("%c ",print[i]);
    }
    printf("\n");
}

void systemclear()
{
    system("cls");
}

void startgame()
{
    int d,i,len,life=4,count;
    char ch;
    char names[3][20]={"swaraj","kailash","kirtika"};
    char *string;
    count = len = d = strlen(string);
    char print[len];

    for(i=0;i<len;i++)
    {
        print[i] = '_';
    }

    printword(print);
    printf("\t\t\t\t\t\t   You have %d lifes left\n",life);
    
    while (d)
    {
        
        scanf(" %c",&ch);
        count=len;

        for(i=0;i<len;i++)
        {
            if(string[i]==ch)
            {
                print[i] = ch;
                d--;
                count--;
            }
            
        }
        if(count==len)
        {
            life--;
        }
        if(life==0)
        {
            d=0;
        }
        systemclear();
        printword(print);
        printf("\t\t\t\t\t\t   You have %d lifes left\n",life);
        if(life==0)
        {
            printf("\t\t\t\t\tYour lifes are completed and you are hanged\n");
        }
        else if(d==0)
        {
            printf("\t\t\t\t\t\t   You won and you are saved from hanging\n");
        }
    }
}

void startscreen()
{
    int num;
    char ch = 0;
    printf("\n\n\n\t\t\t\t\t\t\tHangman\n\n\n");

    printf("\t\t\t\t\t\tPress any key to start\n\n\n");
    
    scanf(" %c",&ch);
    if(ch)
    {
        systemclear();
        printf("\n\n\n\t\t\t\t\t\t\tHangman\n\n\n");
        printf("\t\t\t\t\t\t   1 - play game.\n\n\t\t\t\t\t\t   2 - add names\n\n\t\t\t\t\t\t   3 - authors.\n\n\t\t\t\t\t\t   4 - exit.\n\n\n\n\t\t\t\t Enter the corresponding number to continue: ");
        scanf(" %d",&num);
        if(num==1)
        {
            systemclear();
            startgame();
        }
        // else if(num==2)
        // {
        //     addname();
        // }
        else if(num==3)
        {
            systemclear();
            printauthor();
        }
        // else if(num==4)
        // {
        //     exit();
        // }
    }
}

void printauthor()
{
    printf("\t\t\t\t\t\t\tGame developed by: \n\n");
    printf("\t\t\t\t\t\t\t******************\n");
    printf("\t\t\t\t\t\t\tSwaraj and Kailash\n");
    printf("\t\t\t\t\t\t\t******************\n");
}

// int exit()
// {
//     return 0;
// }