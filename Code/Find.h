#ifndef COURSEWORK_FIND_H
#define COURSEWORK_FIND_H

#include "Work_with_nodes.h"
#include"Struct.h"
#include "CheckValues.h"
#ifdef __unix__
#define CLS system("clear");
#elif WIN32
#define  CLS system("cls");
#endif
void Find(LH* Head);

int  Match(LN* Node,char* value,float(*funcName)(LN*,char*));

float NameFind(LN* Node,char* value);
float SpecFind(LN* Node,char* value);
float YearBegFind(LN* Node,char* value);
float GroupFind(LN* Node,char* value);
float AvgFind(LN* Node,char* value);
float AttendanceFind(LN* Node,char* value);
float DataFind(LN* Node,char* value);
#endif //COURSEWORK_FIND_H
