//
// Created by Artem_Taksheev on 03.05.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "CheckValues.h"

int CheckFile(FILE* df)/*Проверка файла*/
{
    fseek(df,0,SEEK_END);
    int i= ftell(df);
    return ftell(df);//Возвращает текущую позициюв файле (если 0, то файл пустой)
}
int CheckList(LH* Head)/*Проверка списка на заполненость*/
{
    if(Head->first==NULL)return 0;
    else return 1;
}
int IntCheck()/*Проверка целых чисел*/
{
    int check;
    int id;
    check=0;
    while(check!=1)
    {
        printf("Your value: ");
        check=scanf("%d",&id);
        getchar();
        if(check!=1)
        {
            puts("Incorrect value. (You can't write any symbols). Try again ");
            while(getchar()!='\n');
        }
    }
    return id;

}
char* NameCheck(char* value)/*Проверка имени*/
{
    int size;
    int check;
    char* s;

    check=0;
    while(check!=1)
    {
        printf("Your value of Name: ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        check=1;
        while((*s!='\0'))
        {
            if(isdigit(*s)==1)check=0;
            s++;
        }
        if(check==0)puts("Incorrect input (You can't write any number in Name). Try again");
    }
    return value;
}
char* SpecCheck(char* value)/*Проверка специальности*/
{
    int size;
    int check;
    char*s;
    check=0;
    while(check!=1)
    {
        printf("Your value of Special: ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        check=1;
        while((*s!='\0'))
        {
            if(isdigit(*s)==1)check=0;
            s++;
        }
        if(check==0)puts("Incorrect input (You can't write any number in Special). Try again");
    }
    return value;
}
char* YearBegCheck(char* value)/*Проверка год потупления*/
{
    int size;
    int check;
    check=0;
    char* s;

    while(check!=1)
    {
        printf("Your value of Year of Begin: ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        check=1;
        while((*s!='\0'))
        {
            if(isdigit(*s)==0)check=0;
            s++;
        }
        if(check==0)puts("Incorrect input (You can't write any symbol in Year of begin). Try again");
    }
    return value;
}
char* GroupCheck(char* value)/*Проверка номера группы*/
{
    int size;
    int check;
    char*s;
    check=0;
    while(check!=1)
    {
        printf("Your value of Group: ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        check=1;
        while((*s!='\0'))
        {
            if(isdigit(*s)==0)check=0;
            s++;
        }
        if(check==0)puts("Incorrect input (You can't write any symbol in Group). Try again");
    }
    return value;
}
char* AvgCheck(char* value)/*Проверка среднего балла*/
{
    int size;
    int check;
    int countsep;
    char*s;
    check=0;
    while(check!=1)
    {
        printf("Your value of Average score: ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        check=1;
        countsep=0;
        while((*s!='\0'))
        {
            if((isdigit(*s)==0)&&(*s!='.'))check=0;
            if(*s=='.')countsep++;
            s++;
        }
        if(countsep!=1)check=0;
        if(check==0)puts("Incorrect input (You can't write any symbol (except '.') in Average score). Try again");
    }
    return value;
}
char* AttendanceCheck(char* value)/*Проверка посещаемости*/
{
    int size;
    int check;
    int countsep;
    int countnum;
    int firstnum;
    char*s;
    char num;
    check=0;
    while(check!=1)
    {
        printf("Your value of Attendance: ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        check=1;
        countsep=0;
        countnum=0;
        firstnum=0;
        while((*s!='\0'))
        {
            if((isdigit(*s)==0)&&(*s!='.'))check=0;
            if(*s=='.')
            {
                countsep++;
                countnum=0;
            }
            else
            {
                countnum++;
                num=*s;
                if((countsep==0)&&((countnum>1)||(num>49)))check=0;
                else if(countsep==0) firstnum=(int)num-48;
                if(firstnum &&(num>48))check=0;
            }
            s++;
        }
        if (countsep!=1)check=0;
        if(check==0)puts("Incorrect input (You can't write any symbol (except '.') in Attendance). Try again");
    }
    return value;
}

char* DateCheck(char* value)/*Проверка даты*/
{

    int size;
    int check;
    int countsep;
    int countnum;
    char*s;
    check=0;
    while(check!=1)
    {
        printf("Your value of Date(yyyy/mm/dd): ");
        fgets(value,MAXLINE,stdin);
        size=strlen(value);
        value[size-1]='\0';
        s=value;
        countsep=0;
        countnum=0;
        check=1;
        while((*s!='\0'))
        {
            if((isdigit(*s)==0)&&(*s!='/'))check=0;

            if(*s=='/')
            {
                countsep++;
                if(countsep==1)
                {
                    if(countnum!=4)check=0;

                }
                else if(countnum!=2)check=0;
                countnum=0;
            }
            else countnum++;

            s++;
        }
        if(countsep!=2)check=0;
        if(check==0)puts("Incorrect input (You can't write any symbol (except '/') in Data). Try again");
    }
    return value;
}

char* DoCheck(char* value,char*(*funcName)(char*))
{
   value = funcName(value);
   return value;
}