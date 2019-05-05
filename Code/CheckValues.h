//
// Created by Artem_Taksheev on 03.05.2019.
//

#ifndef COURSEWORK_CHECKVALUES_H
#define COURSEWORK_CHECKVALUES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Work_with_nodes.h"
#include"Struct.h"

int IntCheck();

char* NameCheck(char* value);
char* SpecCheck(char* value);
char* YearBegCheck(char* value);
char* GroupCheck(char* value);
char* AvgCheck(char* value);
char* AttendanceCheck(char* value);
char* DateCheck(char* value);
char* DoCheck(char* value,char*(*funcName)(char*));

int CheckFile(FILE* df);
int CheckList(LH* Head);
#endif //COURSEWORK_CHECKVALUES_H
