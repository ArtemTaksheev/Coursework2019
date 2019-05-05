#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void Sort(LH* Head)
{
    int sign;

    float (*kind[6])(LN*,LN*);
    kind[0]=NameValue;
    kind[1]=SpecValue;
    kind[2]=YearBegValue;
    kind[3]=GroupValue;
    kind[4]=AvgValue;
    kind[5]=AttendanceValue;
    do
    {
        CLS;
        /*Выбор поля для сортировки*/
        printf("Kind of sort:\n"
               "1 - Name\n"
               "2 - Speciality\n"
               "3-Year of begin\n"
               "4-Group\n"
               "5-Max average\n"
               "6-Min average\n"
               "7-Date of birth\n"
               "8-Back\n");
        sign=IntCheck();
    }while((sign<1)||(sign>7));
    if(sign==7)
    {
        sortDate(Head);//Сортировка по дате
    }
    else
    {
        SortKind(Head,kind[sign-1]);//Другие сортировки
    }
    puts("Sorting list:");
    Show(Head);
}


int DataLook (LN *Node1, LN *Node2)/*Проверка дат на сортировку*/
{
    if(Node1->data->DATE[0]>=Node2->data->DATE[0])
    {
        if(Node1->data->DATE[0]==Node2->data->DATE[0])
        {
            if(Node1->data->DATE[1]>=Node2->data->DATE[1])
            {
                if(Node1->data->DATE[1]==Node2->data->DATE[1])
                {
                    if(Node1->data->DATE[2]>=Node2->data->DATE[2]) return 0;
                    else
                    {
                        return 1;
                    }
                }else return 0;
            }
            else
            {
                return 1;
            }
        }
        else return 0;

    }
    else
    {
        return 1;
    }

}
void SortKind(LH*Head,float(*funcName)(LN*,LN*))
{
    int i,j,n;
    LN*q=NULL,*q1=NULL;
    q=Head->first;
    n=CountOfElem(Head);
    for(i=0;i<n;i++,q=q->next)
    {
        q1=Head->first;
        for(j=0;j<n-i-1;j++,q1=q1->next)
        {
            if(funcName(q1,q1->next))//1 когда первый меньше второго(Сортировка по убыванию)
            {
                SwapNodes(q1,q1->next);//Перестановка значений элементов
            }
        }
    }
}
void sortDate (LH*Head)
{
    int i,j,n;
    LN*q=NULL,*q1=NULL;
    q=Head->first;
    n=CountOfElem(Head);
    for(i=0;i<n;i++,q=q->next)
    {
        q1=Head->first;
        for(j=0;j<n-i-1;j++,q1=q1->next)
        {
            if(DataLook(q1,q1->next))
            {
                SwapNodes(q1,q1->next);//Перестановка значений элементов
            }
        }
    }

}

float NameValue(LN* Node1,LN*Node2)
{
    int i;
    i=strcmp(Node1->data->Name,Node2->data->Name);
    if(i<=0)i=0;
    return i;
}
float SpecValue(LN* Node1,LN*Node2)
{
    int i;
    i=strcmp(Node1->data->Spec,Node2->data->Spec);
    if(i<=0)i=0;
    return i;
}
float YearBegValue(LN* Node1,LN*Node2)
{
    int i=0;
    if(Node1->data->year_begin<Node2->data->year_begin) i=1;
    return i;
}
float GroupValue(LN* Node1,LN*Node2)
{
    int i=0;
    if(Node1->data->group<Node2->data->group) i=1;
    return i;
}
float AvgValue(LN *Node1, LN *Node2)
{
    int i=0;
    if(Node1->data->average<Node2->data->average) i=1;
    return i;
}
float AttendanceValue(LN *Node1, LN *Node2)
{
    int i=0;
    if(Node1->data->attendance<Node2->data->attendance) i=1;
    return i;
}