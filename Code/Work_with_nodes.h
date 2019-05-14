#ifndef COURSEWORK_WORK_WITH_NODES_H
#define COURSEWORK_WORK_WITH_NODES_H

#include "Struct.h"
typedef struct LN//Односвязный список
{
    int id;
    ST* data;
    struct  LN *next;
}LN;
typedef struct LH//Голова односвязного списка
{
    int cnt;
    struct LN *first;
    struct LN*last;
}LH;

void Show(LH* Head);/*Выыод всего массива структур*/
/*Для работы со списком*/
LH *MakeHead(); /* Создание головы */
LN *CreateNode(char **NewData);/* Создание узла списка*/
void ClearNodes(LH* Head);/* Очистка списка*/
void InsertAfter(LH *MyHead, LN *NewNode, LN *CurrentNode);/* Вставка после передаваемого узла */
void AddFirst(LH *MyHead, LN *NewNode);/* Вставка первого элемента списка */
void DeleteNode(LH *MyHead,LN * CurrentNode);/* Удаление элемента списка */
void SwapNodes(LN* Node1,LN*Node2);
int CountOfElem(LH*Head);
#endif //COURSEWORK_WORK_WITH_NODES_H
