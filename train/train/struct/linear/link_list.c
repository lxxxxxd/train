/*
 *描述：链式存储的线性表
 *作者：刘小东
*/
#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define POINTER_LENGTH 4

static inline void * getNext(LinkedList *list,void *node)
{
    unsigned char *bytes = (unsigned char *)node;
    void *next = NULL;
    bytes+=list->cellSize;
    memcpy(&next,bytes,POINTER_LENGTH);
    return next;
}

static inline void setNext(LinkedList *list,void *node,void *next)
{
    unsigned char *bytes = (unsigned char *)node;
    bytes+=list->cellSize;
    memcpy(bytes,&next,POINTER_LENGTH);
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

void Destroy(LinkedList *list)
{
    void *current = getNext(list,list->header);
    for(int i=0;i<list->listSize;i++) {
        void *next = getNext(list,current);
        free(current);
        current = next;
    }
}

boolean IsEmpty(LinkedList *list)
{
    if(list->header == NULL) {
        return true;
    } else {
        return false;
    }
}

void GetElem(LinkedList *list,int i,void * elem)
{
    if(i<=0 ||i>=list->listSize) {
        printf("GetElem out of range.\n");
        return;
    }
    void * next = getNext(list,list->header);
    int j=0;
    for(;j<list->listSize;j++) {
        next = getNext(list,next);
        if(j==i) {
            elem = next;
        }
    }
    if(j == list->listSize){
        elem = NULL;
    }
    return;
}

int ContainElem(LinkedList *list, void * elem)
{
    void * next = getNext(list,list->header);
    for(int i=0;i<list->listSize;i++) {
        next = getNext(list,next);
        if(memcmp(next,elem,list->cellSize) == 0) {
            return i;
        }
    }
    return -1;
}
void InsertElem(LinkedList *list, int i, void * elem)
{
    if(i < 0) {
        printf("InsertElem index <=0 .\n");
        return;
    }
    if(list->header == NULL || i == 0) {
        void *node = malloc(list->cellSize+sizeof(void*));
        memcpy(node,elem,list->cellSize);
        setNext(list,node,list->header);
        list->listSize++;
        list->header = node;
        return;
    }
    void * next = list->header;
    void * pre = next;
    for(int j=0;j<list->listSize;j++) {
        next = getNext(list,next);
        if(j == i) {
            break;
        }
        pre = next;
    }
    void *node = malloc(list->cellSize+sizeof(void*));
    memcpy(node,elem,list->cellSize);
    setNext(list,node,next);
    setNext(list,pre,node);
    list->listSize++;
    return;
}

void DeleteElem(LinkedList *list, int i)
{
    if(i<0 || i>list->listSize) {
        printf("DeleteElem out of range.\n");
    }
    void * next = getNext(list,list->header);
    void * pre = next;
    for(int j=0;j<list->listSize;j++) {
        next = getNext(list,next);
        if(j == i) {
            break;
        }
        pre = next;
    }
    setNext(list,pre,getNext(list,next));
    free(next);
}

void ModifyElem(LinkedList *list, int i, void * elem)
{
    if(i<0 || i>list->listSize) {
        printf("ModifyElem out of range.\n");
    }
    void *next = getNext(list,list->header);
    for(int j=0;j<list->listSize;j++) {
        next = getNext(list,next);
        if(j == i) {
            break;
        }
    }
    setElem(list,next,elem);
}

int  Length(LinkedList *list)
{
    return list->listSize;
}
