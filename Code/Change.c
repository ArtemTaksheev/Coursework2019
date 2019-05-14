#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Change.h"


void Change(LH* Head)
{
    void (*kind[3])(LH*);
    kind[0]=ADD;
    kind[1]=CHANGE;
    kind[2]=DELETE;
    int key;
    /*Меню выбора работы
            Добавление нового элемента
            Редактирование
            Удаление
            Конец работы*/
    do
    {
        CLS;
        puts("What to do:");
        puts("0 - Add elements");
        puts("1 - Correct elements");
        puts("2 - Delete elements");
        puts("3 - Back to title");
        key=IntCheck();
        if(!CheckList(Head)&&(key!=0)&&(key!=3)) {                  //Если список пустой, а пользователь хочет удалять
            puts("You can't edit your list without any elements");// или изменять елементы списка
            key = -1;
        }
    }while((key<0)||(key>3));

    if(key!=3)
    {
            Working_Change(Head,kind[key]);
    }
}


void ADD(LH* Head) /* Добавление */
{
    int key;
    char* string;
    char*value;
    char** help_for_data;
    FILE* df;
    LN *node=NULL;
    ST* data;
    key=0;
    if((df=fopen("data.txt","a"))!=NULL)
    {
        CLS;
        string=(char*)malloc(MAXLINE*sizeof(char));
        value=(char*)malloc(MAXLINE*sizeof(char));
        /*Ввод структуры с клавиатуры*/
        if(string && value)
        {
            while(key!=2)//Пока пользователь не захочет завершить добавление элементов
            {
                /*Создание строки из введенных данных*/
                strcpy(string,NameCheck(value));
                strcat(string,";");
                strcat(string,SpecCheck(value));
                strcat(string,";");
                strcat(string,DateCheck(value));
                strcat(string,";");
                strcat(string,YearBegCheck(value));
                strcat(string,";");
                strcat(string,GroupCheck(value));
                strcat(string,";");
                strcat(string,AvgCheck(value));
                strcat(string,";");
                strcat(string,AttendanceCheck(value));
                help_for_data=split(string,strlen(string),';');
                node=CreateNode(help_for_data);//Создание элемента
                if(node!=NULL) {
                    if (Head->first != NULL)//Если в списке что-то есть
                    {
                        InsertAfter(Head, node, Head->last);//Вставляем его
                    } else {//Если элементов в списке не было
                        AddFirst(Head, node);//Вставляем новый элемент
                    }
                }
                do{
                    CLS;
                    puts("Do you want to add more?");
                    puts("1 - Yes");
                    puts("2 - No");
                    key=IntCheck();
                }while((key<1)||(key>2));
            }
            fclose(df);
        }
        else
        {
            puts("Error of work");
        }

    }
    else{puts("Error of reading file");}
}

void DELETE(LH* Head) /*Удаление выбранного количества элементов в списке */
{
    LN*q=NULL;
    int i,count,id,sign;

    i=0;
    count=0;
    do
    {
        printf("How many elements do you want to  delete: \n");
        i=IntCheck();//Ввод количества удаляемых элементов
        if(i>CountOfElem(Head))//Проверка на возможность удаления
        {
            puts("You can't delete more than exist");
            i=0;
        }
    }while(i==0);

    while(i!=0)//Пока не удалим i элементов
    {
        q=Head->first;
        printf("Write id of %d element: \n",count+1);
        id=IntCheck();
        sign=0;
        while((q!=NULL)&&(sign==0))//Находим элемент
        {
            if(q->id==id){sign=1;}
            else{q=q->next;}
        }
        if(sign==0)//Если в списке нет элемента с введенным id
        {
            printf("Can't delete this element\n");
        }
        else{
            DeleteNode(Head,q);
            count++;
            i=i-1;
        }

    }
    printf("Total delete: %d\n",count);
    puts("Press Enter to continue");
    getchar();
}

void CHANGE(LH*Head)/*Изменение элементов*/
{
    int id,sign;
    LN* q=NULL;
    char* value;
    float (*kind[7])(LN*,char*);
    kind[0]=NameChange;
    kind[1]=SpecChange;
    kind[2]=YearBegChange;
    kind[3]=GroupChange;
    kind[4]=AvgChange;
    kind[5]=AttendanceChange;
    kind[6]=DataChange;

    char* (*kind1[7])(char*);
    kind1[0]=NameCheck;
    kind1[1]=SpecCheck;
    kind1[2]=YearBegCheck;
    kind1[3]=GroupCheck;
    kind1[4]=AvgCheck;
    kind1[5]=AttendanceCheck;
    kind1[6]=DateCheck;



    sign=0;
    while(sign==0)//Пока пользователь хочет продолжатьработу*/
    {
        q=Head->first;
        printf("Write id of element \n");
        id=IntCheck();
        while((q!=NULL)&&(sign==0))//Находим элемент
        {
            if(q->id==id){sign=1;}
            else{q=q->next;}
        }
        if(sign==0)//Если в списке нет элемента с введенным id
        {
            printf("Can't find this element\n");
        }
        else{
                value=(char*)malloc(MAXLINE* sizeof(char));
                if(value)
                {


                    do
                    {
                        CLS;
                        print_head();//Вывод элемента для наглядности
                        printf("%3d|",q->id);
                        print_struct(q->data);
                        puts("What field do you want to change?");
                        printf("1 - Name\n"
                               "2 - Speciality\n"
                               "3 - Year of begin\n"
                               "4 - Group\n"
                               "5 - Average score\n"
                               "6 - Attendance\n"
                               "7 - Date of birth\n"
                               "8 - Back to title\n");
                        sign=IntCheck();
                    }while((sign<1)||(sign>8));

                    if(sign!=8)
                    {
                        /* Получение значения в зависимости от выбора и проверка */
                        value=DoCheck(value,kind1[sign-1]);
                        DoChange(q,value,kind[sign-1]);//Меняем значение

                        do{
                            CLS;
                            puts("Change OK");
                            puts("Do you want to change more?");
                            puts("1 - Yes");
                            puts("2 - No");
                            sign=IntCheck();
                        }while((sign<1)||(sign>2));
                        if(sign==1)sign=0;
                    }

                }
                else
                {
                    puts("Error of allocation memory");
                }
        }
    }

    puts("Press Enter to continue");
    getchar();
}
float NameChange(LN* Node,char* value)
{
    strcpy(Node->data->Name,value);
    return 1;
}
float SpecChange(LN* Node,char* value)
{
    strcpy(Node->data->Spec,value);
    return 1;
}
float YearBegChange(LN* Node,char* value)
{
    Node->data->year_begin=atoi(value);
    return 1;
}
float GroupChange(LN* Node,char* value)
{
    Node->data->group=atoi(value);
    return 1;
}
float AvgChange(LN* Node,char* value)
{
    Node->data->average=atof(value);
    return 1;
}
float AttendanceChange(LN* Node,char* value)
{
    Node->data->attendance=atof(value);
    return 1;
}

float DataChange(LN* Node,char* value)
{
    char** data;
    data=split(value,strlen(value),';');
    Node->data->DATE[0]=atoi(data[0]);
    Node->data->DATE[1]=atoi(data[1]);
    Node->data->DATE[2]=atoi(data[2]);
}

void DoChange(LN* Node,char* value,float(*funcName)(LN*,char*))
{
    funcName(Node,value);
}
void Working_Change(LH* Head,void(*funcName)(LH*))
{
    funcName(Head);//Вызов функции, которую выбрал пользователь
}