#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
    #define CLS system("clear");
#elif WIN32
    #define  CLS system("cls");
#endif

#include "Work_with_nodes.h"
#include"Struct.h"
#include "Change.h"
#include "Sort.h"
#include "Find.h"
#include "Files.h"
#include "CheckValues.h"
void Working(LH* Head,float(*funcName)(LH*));
int main()
{


    int key;
    LH* head=NULL;

    /*Создание массива указателей на функции*/
    float (*kindwork[5])(LH*);
    kindwork[0]=Info;
    kindwork[1]=Show;
    kindwork[2]=Change;
    kindwork[3]=Sort;
    kindwork[4]=Find;
    key=0;

    head=MakeHead();
    if(head)
    {
        /*Меню выбора работы с картотекой
            Информация,
            Вывод картотеки,
            Редактирование картотеки,
            Сортировка картотеки,
            Поиск необходимых карточек,
            Конец работы*/
        if(Read(head))// Чтение файла со списком (если это возможно)
        {
            do{
                do
                {
                    CLS;
                    puts("What to do:");
                    puts("0-Info");
                    puts("1-Show list");
                    puts("2-Correct list");
                    puts("3-Sort list");
                    puts("4-Find elements in list");
                    puts("5-End");
                    key=IntCheck();
                }while((key<0)||(key>5));

                if(key!=5)
                {
                    Working(head,kindwork[key]);//Работа с массивом согласно выбору пользователя
                }
            }while(key!=5);//Работаем пока пользователь не выберет пункт выхода
            Save(head);
            ClearNodes(head);
        }

        puts("Ending. Thank you for using this program!");

       free(head);

    }
    else
    {
        puts("Fatal error, Can't work\n");
    }
    puts("Press Enter to end");
    getchar();
    return 0;
}
/*Функция для работы со структурой*/
void Working(LH* Head,float(*funcName)(LH*))
{
    funcName(Head);//Вызов функции, которую выбрал пользователь
}

