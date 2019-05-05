//
// Created by Artem_Taksheev on 03.05.2019.
//

#include "Files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Read(LH*Head)
{
    char* data_string=NULL;
    char** help_strings=NULL;
    LN* node=NULL;
    int i,size;
    int key;
    FILE* df;

    i=0;
    key=1;

    if((df=fopen("data.txt","r"))!=NULL)
    {
        if(CheckFile(df))
        {
            puts("Read data from 'data.txt' file");
            rewind(df);
            data_string=(char*)malloc(MAXLINE*sizeof(char));
            if(data_string!=NULL)
            {
                while((!feof(df))&&(key!=0))
                {
                    /*Считывание строки с файла*/
                    fgets(data_string,MAXLINE,df);
                    size=strlen(data_string);
                    data_string[size-1]='\0';
                    size=strlen(data_string);
                    /*Разделение полученной строки на слова и их запись в структуру*/
                    help_strings=split(data_string,size,';');
                    if(help_strings!=NULL)
                    {
                        node=CreateNode(help_strings);//Создание узла списка
                        if(node!=NULL)
                        {
                            if(i==0)AddFirst(Head,node);            //Если элемент первый, то добавляем в начало
                            else InsertAfter(Head,node,Head->last);//Если элемент первый, то добавляем в начало
                        }
                        else{
                            puts("Error of reading file");
                            ClearNodes(Head);
                            key=0;
                        }
                    }
                    i++;
                }

                if((fclose(df)!=EOF))
                {
                    puts("Close data file OK");
                }
                else
                {
                    /*Если файл не закрылся или зарылся с ошибкой*/
                    puts("Error of closing file");
                    free(data_string);
                    data_string=NULL;
                    ClearArray(help_strings,7);
                    ClearNodes(Head);
                    key=0;

                }
            }
            else
            {
                /*Если не выделилась память*/
                puts("Error of allocation memory");
                free(data_string);
                data_string=NULL;
                key= 0;
            }

        }
        else
        {

            do{
                CLS;
                puts("WARNING");
                puts("File 'data.txt' is empty");
                puts("Do you want to continue?");
                puts("1 - Yes");
                puts("2 - No");
                key=IntCheck();
            }while((key<1)||(key>2));

            if(key==2)key = 0;

        }
    }
    else
    {
        do{
            CLS;
            puts("The file 'data.txt' does not exist");
            puts("Do you want to continue (the new file will created)?");
            puts("1 - Yes");
            puts("2 - No");
            key=IntCheck();
        }while((key<1)||(key>2));

        if(key==2)key = 0;

    }
     return  key;

}

void Save(LH* Head)
{
    FILE *df;
    LN* q=NULL;
    q=Head->first;

    if((df=fopen("data_save.txt","w"))!=NULL)
    {
        while(q!=NULL)
        {
            /*Добавление строки в файл*/
            fputs(q->data->Name,df);
            fputc(';',df);
            fputs(q->data->Spec,df);
            fputc(';',df);
            fprintf(df,"%d",q->data->DATE[0]);
            fputc('/',df);
            fprintf(df,"%d",q->data->DATE[1]);
            fputc('/',df);
            fprintf(df,"%d",q->data->DATE[2]);
            fputc(';',df);
            fprintf(df,"%d",q->data->year_begin);
            fputc(';',df);
            fprintf(df,"%d",q->data->group);
            fputc(';',df);
            fprintf(df,"%2.2f",q->data->average);
            fputc(';',df);
            fprintf(df,"%2.2f",q->data->attendance);
            if(q->next!=NULL){fputc('\n',df);}//Если элемент не последний, то ставим переход на новую строчку
            q=q->next;
        }
        fgetc(df);
    }
    else
    {
        puts("Can't create save file!");
    }

    if((fclose(df)!=EOF))
    {
        puts("Your changes (or creation new card index) saved in 'data_save.txt' file");
    }

}

void Info()/*Вывод справки*/
{
    char* str;
    str=(char*)malloc(1000*sizeof(char));
    if(str!=NULL)
    {
        FILE* df;
        if((df=(fopen("INFO.txt","r")))!=NULL)
        {
            CLS;
            while((fgets(str,100,df))!=NULL)
            {
                printf("%s",str);
            }
        }
        else
        {
            puts("Error of reading file. Can't find file.");
        }
        free(str);
        str=NULL;
    }
    else
    {
        puts("Error of reading file. Can't find file.");
    }

    puts("Press Enter to continue");
    getchar();
}
