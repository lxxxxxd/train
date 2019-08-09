/*
 *描述：链式存储的线性表
 *作者：刘小东
*/

#define POINTER_LENGTH 4

#include "type.h"
#include "status.h"

typedef struct LinkedList {
    void *header;
    int cellSize;
    int listSize;
}LinkedList;

void InitLinkedList(LinkedList *list, int cellSize);
boolean IsListEmpty(LinkedList *list);
void ListDestroy(LinkedList *list);
Status GetListElem(LinkedList *list,int i,void ** elem);
int ContainListElem(LinkedList *list, void * elem);
void AddListElem(LinkedList *list,void * elem);
Status DeleteListElem(LinkedList *list, int i);
Status ModifyListElem(LinkedList *list, int i, void * elem);
int  ListLength(LinkedList *list);
