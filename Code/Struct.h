#ifndef COURSEWORK_STRUCT_H
#define COURSEWORK_STRUCT_H
typedef struct
{
    char* Name;//Имя
    char* Spec;//Специальность
    int DATE[3];//Дата рождения(yyyy/mm/dd)
    int year_begin;//Год начала учебы
    int group;//Номер группы
    float average;//Средний бал
    float attendance;//Посещаемость (в процентах от 0.0 до 1.0)

}ST;
enum sizes{MAXLINE=80};

//Для работы с динамикой
void ClearStruct (ST* MASS);//Очистка структуры
void ClearArray (char** s, int size);//Очисткамассива строк
//Для работы со структурой
char** split(char* s,int size,char sep);//Разделение прочитанной строки на слова
ST* struct_fill(char** str);//Заполнение структуры
void print_head();//Вывод шапки таблицы
void print_struct(ST* MASS);//Вывод структуры на экран

#endif //COURSEWORK_STRUCT_H
