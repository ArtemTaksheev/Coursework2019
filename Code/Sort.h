#ifndef COURSEWORK_SORT_H
#define COURSEWORK_SORT_H

#include "Work_with_nodes.h"
#include"Struct.h"
#include "CheckValues.h"

#ifdef __unix__
#define CLS system("clear");
#elif WIN32
#define  CLS system("cls");
#endif
void Sort(LH* Head);
void SortKind(LH*Head,float(*funcName)(LN*,LN*));

float IdValue(LN* Node1,LN*Node2);
float NameValue(LN* Node1,LN*Node2);
float SpecValue(LN* Node1,LN*Node2);
float YearBegValue(LN* Node1,LN*Node2);
float GroupValue(LN* Node1,LN*Node2);
float AvgValue(LN *Node1, LN *Node2);
float AttendanceValue(LN *Node1, LN *Node2);
float DataLook (LN *Node1, LN *Node2);


#endif //COURSEWORK_SORT_H
