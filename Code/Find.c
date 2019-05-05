#include "Find.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find(LH* Head)
{
    int sign,id;
    LN* q=NULL;
    char* value;
    float (*kind[7])(LN*,char*);
    kind[0]=NameFind;
    kind[1]=SpecFind;
    kind[2]=YearBegFind;
    kind[3]=GroupFind;
    kind[4]=AvgFind;
    kind[5]=AttendanceFind;
    kind[6]=DataFind;

    char* (*kind1[7])(char*);
    kind1[0]=NameCheck;
    kind1[1]=SpecCheck;
    kind1[2]=YearBegCheck;
    kind1[3]=GroupCheck;
    kind1[4]=AvgCheck;
    kind1[5]=AttendanceCheck;
    kind1[6]=DateCheck;
    q=Head->first;
    value=(char*)malloc(MAXLINE* sizeof(char));
    if(value)
    {
        do
        {
            CLS;
            /*Выбор поля для поиска*/
            puts("What field do you want to find?");
            printf("0 - Id\n"
                   "1 - Name\n"
                   "2 - Speciality\n"
                   "3 - Year of begin\n"
                   "4 - Group\n"
                   "5 - Average score\n"
                   "6 - Attendance\n"
                   "7 - Date of birth\n"
                   "8 - Back\n");
            sign=IntCheck();
        }while((sign<0)||(sign>7));

        if(sign!=8)
        {
            /* Получение значения в зависимости от выбора и проверка */
            if(sign==0)
            {
                id=IntCheck();
                print_head();
                while(q!=NULL)
                {
                    if(q->id==id)
                    {
                        printf("%3d|",q->id);
                        print_struct(q->data);
                    }
                    q=q->next;
                }
            }
            else
            {
                value=DoCheck(value,kind1[sign-1]);
                print_head();
                while(q!=NULL)
                {
                    if((Match(q,value,kind[sign-1])))//Проверка на совпадение
                    {
                        printf("%3d|",q->id);
                        print_struct(q->data);
                    }
                    q=q->next;
                }
            }
            }



    }
    else
    {
        puts("Error of allocation memory");
    }


    puts("Press Enter to continue");
    getchar();
}
float NameFind(LN* Node,char* value)
{
    if(strcmp(Node->data->Name,value)==0) return 1;
    else return 0;
}
float SpecFind(LN* Node,char* value)
{
    if(strcmp(Node->data->Spec,value)==0) return 1;
    else return 0;
}
float YearBegFind(LN* Node,char* value)
{
    if(Node->data->year_begin==atoi(value)) return 1;
    else return 0;
}
float GroupFind(LN* Node,char* value)
{
    if(Node->data->group==atoi(value)) return 1;
    else return 0;
}
float AvgFind(LN* Node,char* value)
{
    if(Node->data->year_begin==atof(value)) return 1;
    else return 0;
}
float AttendanceFind(LN* Node,char* value)
{
    if(Node->data->year_begin==atof(value)) return 1;
    else return 0;
}
float DataFind(LN* Node,char* value)
{
    char** data;
    data=split(value,strlen(value),';');
    if((Node->data->DATE[0]==atoi(data[0]))&&(Node->data->DATE[1]=atoi(data[1]))&&(Node->data->DATE[2]=atoi(data[2])))
        return 1;
    else return 0;
}

int Match(LN* Node,char* value,float(*funcName)(LN*,char*))
{
    return funcName(Node,value);
}