//
// Created by Artem_Taksheev on 03.05.2019.
//

#ifndef COURSEWORK_FILES_H
#define COURSEWORK_FILES_H

#ifdef __unix__
#define CLS system("clear");
#elif WIN32
#define  CLS system("cls");
#endif
#include "Work_with_nodes.h"
#include"Struct.h"
#include "CheckValues.h"

void Save(LH* Head);
int Read(LH*Head);
void Info();
#endif //COURSEWORK_FILES_H
