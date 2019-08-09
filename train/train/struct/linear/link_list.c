/*
 *描述：链式存储的线性表
 *作者：刘小东
*/
#include "link_list.h"
#include "type.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static inline void * getNext(LinkedList *list,void *node)
{
    unsigned char *bytes = (unsigned char *)node;
    bytes+=list->cellSize;
    void *next = *((void **)bytes);
    return next;
}

static inline void setNext(LinkedList *list,void *node,void *next)
{
    unsigned char *bytes = (unsigned char *)node;
    bytes+=list->cellSize;
    void **nextFild = (void **)bytes;
    *nextFild = next;
}

static inline void setElem(LinkedList *list,void *node,void *elem)
{
    memcpy(node,elem,list->cellSize);
}

void InitLinkedList(LinkedList *list, int cellSize)
{
    list->cellSize = cellSize;
    list->header = NULL;
    list->listSize = 0;
}

void ListDestroy(LinkedList *list)
{
    void *current = list->header;
    for(int i=0;i<list->listSize;i++) {
        void * next = getNext(list,current);
        free(current);
        current = next;
        list->listSize--;
    }
    list->header = NULL;
}

boolean IsListEmpty(LinkedList *list)
{
    if(list->header == NULL) {
        return true;
    } else {
        return false;
    }
}

Status GetListElem(LinkedList *list,int i,void ** elem)
{
    if(i<0 ||i>=list->listSize) {
        printf("GetElem out of range.\n");
        return OUT_RNAGE_ERROR;
    }
    void * next = list->header;
    int j=0;
    for(;j<list->listSize;j++) {
        if(j==i) {
            *elem = next;
            break;
        }
        next = getNext(list,next);
    }
    if(j == list->listSize){
        *elem = NULL;
        return NOT_FOUND_ELEM_ERROR;
    }
    return SUCCESS;
}

int ContainListElem(LinkedList *list, void * elem)
{
    if(elem == NULL) {
        return NONE_POINTOR_ERROR;
    }
    void * next = list->header;
    for(int i=0;i<list->listSize;i++) {
        if(memcmp(next,elem,list->cellSize) == 0) {
            return i;
        }
        next = getNext(list,next);
    }
    return NOT_FOUND_ELEM_ERROR;
}
void AddListElem(LinkedList *list,void * elem)
{
    void *node = malloc(list->cellSize+sizeof(void*));
    memcpy(node,elem,list->cellSize);
    setNext(list,node,list->header);
    list->listSize++;
    list->header = node;
    return;
}

Status DeleteListElem(LinkedList *list, int i)
{
    if(i<0 || i>list->listSize) {
        printf("DeleteElem out of range.\n");
        return OUT_RNAGE_ERROR;
    }
    void * next = list->header;
    void * pre = next;
    int j=0;
    for(;j<list->listSize;j++) {
        if(j == i) {
            break;
        }
        pre = next;
        next = getNext(list,next);
    }
    setNext(list,pre,getNext(list,next));
    free(next);
    list->listSize--;
    return SUCCESS;
}

Status ModifyListElem(LinkedList *list, int i, void * elem)
{
    if(i<0 || i>list->listSize) {
        printf("ModifyElem out of range.\n");
        return OUT_RNAGE_ERROR;
    }
    void *next = list->header;
    for(int j=0;j<list->listSize;j++) {
        if(j == i) {
            break;
        }
        next = getNext(list,next);
    }
    setElem(list,next,elem);
    return SUCCESS;
}

int  ListLength(LinkedList *list)
{
    return list->listSize;
}
