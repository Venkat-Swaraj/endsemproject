#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addnl.h"


int main()
{
    int d,i,len,life=4,count;
    char ch;
    char *string="haricharan";
    len = d = strlen(string);
    char print[len];


    for(i=0;i<len;i++)
    {
        print[i] = '_';
    }

    printword(print);

    while (d)
    {
        printf("You have %d lifes left\n",life);
        scanf("%c",&ch);

        for(i=0;i<len;i++)
        {
            if(string[i]==ch)
            {
                print[i] = ch;
                d--;
            }
            
        }
        systemclear();
        printword(print);
    }


}

void printword(char *print)
{
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