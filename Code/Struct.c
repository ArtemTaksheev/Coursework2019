#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include"Struct.h"

/*Очистка структуры*/
void ClearStruct (ST *MASS)
{
    free(MASS->Name);
    free(MASS->Spec);
    MASS->Name=NULL;
    MASS->Spec=NULL;
    free(MASS);
    MASS=NULL;
}
/*Очистка массива слов*/
void ClearArray (char** s,int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        free(s[i]);
        s[i]=NULL;
    }
    free(s);
    s=NULL;
}
/*Разделение считанной строки*/
char** split(char* s,int size,char sep)
{
    char** s2=NULL;
    int i,m,j,count;
    /*Подсчет количества слов*/
    for(i=0,m=0;i<size;i++)
    {
        if((s[i]==sep)||(s[i]=='/')) m++;
    }

    /*Выделение памяти*/
    s2=(char**)malloc((m+1)*sizeof(char*));
    if(s2!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            s2[i]=(char*)malloc(size*sizeof(char));
            if(s2[i]==NULL) i=m+1;
        }
        if(count==i)
        {
            /*Разделение*/
            m=0;
            j=0;
            while(*s)
            {
                if((*s!=sep)&&(*s!='/'))
                {
                    s2[m][j]=*s;
                    j++;
                }
                else
                {
                    s2[m][j]='\0';
                    m++;
                    j=0;
                }
                s++;
            }
            s2[m][j]='\0';
        }
        else
        {
            ClearArray(s2,count);
        }
    }
    return s2;
}
/*Заполнение структуры*/
ST* struct_fill(char** str)
{
    ST* fill=NULL;
    fill=(ST*)malloc(sizeof(ST));
    if(fill!=NULL)
    {
        fill->Name=str[0];
        fill->Spec=str[1];
        fill->DATE[0]=atoi(str[2]);
        fill->DATE[1]=atoi(str[3]);
        fill->DATE[2]=atoi(str[4]);
        fill->year_begin=atoi(str[5]);
        fill->group=atoi(str[6]);
        fill->average=atof(str[7]);
        fill->attendance=atof(str[8]);
    }
    return fill;
}
/*Вывод шапки таблицы*/
void print_head()
{
    printf(" %2s|%20s|%10s|%12s|%10s|%11s|%10s|%10s|\n","id","FullName","Special","DateOfBirth","YearOfBegin","Group","Average Score","Attendance");
    printf("---+--------------------+----------+------------+-----------+-----------+-------------+----------+\n");
}
/*Вывод структуры*/
void print_struct(ST* MASS)
{
    printf("%20s|%10s|%6d.%2d.%2d|%11d|%11d|%13.2f|%10.2f|\n",
           MASS->Name,MASS->Spec,MASS->DATE[0],MASS->DATE[1],MASS->DATE[2],
           MASS->year_begin,MASS->group,MASS->average,MASS->attendance);

}