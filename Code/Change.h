#ifndef COURSEWORK_CHANGE_H
#define COURSEWORK_CHANGE_H

#include "Work_with_nodes.h"
#include"Struct.h"
#include "CheckValues.h"
#ifdef __unix__
#define CLS system("clear");
#elif WIN32
#define  CLS system("cls");
#endif
void Change(LH*);// Общая функция
void ADD(LH*);// Добавление элементов
void CHANGE(LH*);// Изменение элементов
void DELETE(LH*);// Удаление элементов

/*Функции для изменения значений полей элемента*/
float NameChange(LN* Node,char* value);
float SpecChange(LN* Node,char* value);
float YearBegChange(LN* Node,char* value);
float GroupChange(LN* Node,char* value);
float AvgChange(LN* Node,char* value);
float AttendanceChange(LN* Node,char* value);
float DataChange(LN* Node,char* value);
void DoChange(LN* Node,char* value,float(*funcName)(LN*,char*));
void Working_Change(LH* Head,float(*funcName)(LH*));


#endif //COURSEWORK_CHANGE_H
