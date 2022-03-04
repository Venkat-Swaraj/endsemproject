#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "addnl.h"
#include <time.h>

int main()
{
    gamescreen();   
}

void printword(char *print)
{           
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t  HANGMAN");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<strlen(print);i++)
    {
        printf("%c ",print[i]);
    }
    printf("\n\n\n");
}

void systemclear()
{
    system("cls");
}

void startgame()
{
    system("color 10"); 
    int d,i=0,len,life=4,count;
    char ch;
    srand(time(NULL));
    FILE *strings = fopen("./names.txt","r");
    char names[62][20];
    while(fscanf(strings, "%s", names[i]) != EOF) {
        i++;
    }
    char *string = names[rand()%62 + 1];
    count = len = d = strlen(string);
    char print[len];

    for(i=0;i<len;i++)
    {
        print[i] = '_';
    }

    printword(print);
    printf("\t\t\t\t\t\t\t\t     You have %d lifes left\n",life);
    
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
        printf("\t\t\t\t\t\t\t\t     You have %d lifes left\n",life);
        if(life==0)
        {
            sleep(1);
            systemclear();
            stopscreen(0);
        }
        else if(d==0)
        {
            sleep(1);
            systemclear();
            stopscreen(1);
        }
    }
}

void gamescreen()
{
    char ch = 0;
    system("color 40");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tHangman\n\n\n");

    printf("\t\t\t\t\t\t\t\tPress any key to start\n\n\n");
    
    scanf(" %c",&ch);
    if(ch)
    {
        startscreen();
    }
}

void startscreen()
{
    int num;
    
    system("color 10");
    systemclear();
                          
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tHangman\n\n\n");
    printf("\t\t\t\t\t\t\t\t   1 - play game.\n\n\t\t\t\t\t\t\t\t   2 - authors.\n\n\t\t\t\t\t\t\t\t   3 - exit.\n\n\n\n\t\t\t\t\t\t Enter the corresponding number to continue: ");
    scanf(" %d",&num);
    if(num==1)
    {
        systemclear();
        startgame();
    }
    else if(num==2)
    {
        systemclear();
        printauthor();
    }
    else if(num==3)
    {
        systemclear();
        exit(0);
    }
}

void printauthor()
{
    system("color 30");
    int ch;                       
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGame developed by: \n\n");
    printf("\t\t\t\t\t\t\t\t\t******************\n");
    printf("\t\t\t\t\t\t\t\t\tSwaraj and Kailash\n");
    printf("\t\t\t\t\t\t\t\t\t******************\n");
    printf("\t\t\t\t\t\t\t\tStudents of Dr. Mandava Kranthi Kiran\n\n");
    printf("\t\t\t\t\t\t\t\tPress B to go back to main screen\n");
    scanf(" %c",&ch);
    while(ch!='b')
    {
        scanf(" %c",&ch);
    }
    startscreen();
}

void stopscreen(int a)
{
    if(a == 0)
    {
        system("color 40");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t   Your lifes are completed and you are hanged\n\n\n"); 
        restartgame();
    }
    else
    {
        system("color 20");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t   You won and you are saved from hanging\n\n\n");
        restartgame();
    }
}

void restartgame()
{
    char ch;
    printf("\t\t\t\t\t\t\t   Press R to restart the game\n");
    scanf(" %c",&ch);
    while(ch!='r')
    {
        scanf(" %c",&ch);
    }
    systemclear();
    startgame();
}