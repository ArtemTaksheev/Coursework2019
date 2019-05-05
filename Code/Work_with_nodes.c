#include "Work_with_nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Выыод всего массива структур*/
void Show(LH* Head)
{
    LN* q=NULL;
    q=Head->first;
    print_head();
    while(q!=NULL)
    {
        printf("%3d|",q->id);
        print_struct(q->data);
        q=q->next;
    }
    puts("Press Enter to continue");
    getchar();
}
LH *MakeHead() /* Создание головы */
{
    LH *ph=NULL;
    ph=(LH*)malloc(sizeof(LH));
    if(ph!=NULL)
    {
        ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}
LN *CreateNode(char **NewData) /* Создание узла*/
{
    LN *NewNode=NULL; /* указатель на новый узел */
    NewNode = (LN*)malloc(sizeof(LN));
    if(NewNode)
    {
        NewNode->id = 0;
        NewNode->data=struct_fill(NewData);
        NewNode->next = NULL;
    }
    return NewNode;
}
void AddFirst(LH *MyHead, LN *NewNode)/* Добавление первого элемента */
{
    if(MyHead&&NewNode)
    {
        /*Связываем голову с элементом */
        MyHead->first = NewNode;
        MyHead->last = NewNode;
        NewNode->id=1;
        MyHead->cnt++;//Увеличиваем счетчик количества элементов в списке
    }
}

void InsertAfter(LH *MyHead, LN *NewNode, LN *CurrentNode) /* Вставка после */
{
    int n;
    if(MyHead&&NewNode&&CurrentNode)
    {
        n=MyHead->cnt+1;
        if(CurrentNode->next==NULL)// Если вставляем после последного элемента
        {
            CurrentNode->next=NewNode;
            MyHead->last=NewNode;
        }
        else
        {
            NewNode->next = CurrentNode->next;
            CurrentNode->next=NewNode;
        }
        NewNode->id=n;
        MyHead->cnt=n;
    }
}

void ClearNodes(LH* Head) /* Очистка списка */
{
    LN *q=NULL;
    q=Head->first;
    while(q!=NULL)
    {
        ClearStruct(q->data);//Очищаем данные
        free(q);
        q=q->next;
    }
}

void DeleteNode(LH *MyHead,LN * CurrentNode) /* Удаление элемента списка */
{
    LN *q=NULL,*q1=NULL;
    q=MyHead->first;
    q1=MyHead->last;
    if(CurrentNode==q)//если удаляемый элемент первый в списке
    {
        MyHead->first=CurrentNode->next;
        CurrentNode->next=NULL;
        ClearStruct(CurrentNode->data);
        free(CurrentNode);
        CurrentNode=NULL;
    }
    else
    {
        while(CurrentNode!=NULL)//Пока не удалим что-то
        {
            if(q->next==CurrentNode)//когда дошли до удаляемого элемета
            {
                if(q->next==q1)//если он последний
                {
                    MyHead->last=q;
                    q->next=NULL;
                    ClearStruct(CurrentNode->data);
                    free(CurrentNode);
                    CurrentNode=NULL;
                }
                else
                {
                    q->next=CurrentNode->next;
                    CurrentNode->next=NULL;
                    ClearStruct(CurrentNode->data);
                    free(CurrentNode);
                    CurrentNode=NULL;
                }
            }
            else q=q->next;
        }
    }
}

int CountOfElem(LH*Head)/*Подсчет количества элементов в списке*/
{
    int count=0;
    LN*q=NULL;
    q=Head->first;
    if(q!=NULL)
    {
        while(q!=NULL)
        {
            count++;
            q=q->next;
        }
    }
    return count;
}
void SwapNodes(LN* Node1,LN*Node2)/*Перестановка значений элементов*/
{

    int id;
    ST*tmp;

    id=Node1->id;
    Node1->id=Node2->id;
    Node2->id=id;

    tmp=Node1->data;
    Node1->data=Node2->data;
    Node2->data=tmp;
}