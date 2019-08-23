//
//  static_list.c
//  train
//  静态链表，游标实现
//  Created by xiaodong liu on 2019/8/10.
//  Copyright © 2019 xiaodong liu. All rights reserved.
//

#include "static_list.h"
#include "type.h"
#include "status.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

static inline void setCursor(StaticList *list,int i,int cur)
{
    int *cursor = (int *)(list->poolSpace+i*(list->cellSize)+list->elemSize);
    *cursor =cur;
}

static inline int getCursor(StaticList *list,int i)
{
    int *cursor = (int *)(list->poolSpace+i*(list->cellSize)+list->elemSize);
    return *cursor;
}

static inline void setElem(StaticList *list,int i,void *elem)
{
    void *elemData = (void *)(list->poolSpace+i*(list->cellSize));
    memcpy(elemData, elem, list->elemSize);
}

static inline void copyElem(StaticList *list,int i,void *elem)
{
    void *elemData = (void *)(list->poolSpace+i*(list->cellSize));
    memcpy(elem,elemData,list->elemSize);
}

static inline void cleanElem(StaticList *list,int i)
{
    void *elemData = (void *)(list->poolSpace+i*(list->cellSize));
    memset(elemData,0,list->elemSize);
}

Status InitStaticList(StaticList *list,int elemSize,int capacity)
{
    list->elemSize = elemSize;
    list->cellSize = elemSize + CURSOR_SIZE;
    list->capacity = capacity;
    list->listSize = 0;
    list->poolSpace = (byte *)malloc((list->cellSize)*capacity);
    memset(list->poolSpace, 0, list->cellSize*capacity);
    if(list->poolSpace == NULL) {
        printf("init static list fail, malloc return null.");
        return NONE_POINTOR_ERROR;
    }
    for(int i=0;i<capacity-1;i++) {
        setCursor(list, i, i+1);
    }
    setCursor(list, capacity-1, 0);
    return SUCCESS;
}

static inline int MallocCell(StaticList *list)
{
    int cur = getCursor(list, 0);
    setCursor(list, 0, getCursor(list, cur));
    return cur;
}
Status InsertStaticList(StaticList *list,int i,void *elem)
{
    if(i < 1 || i > list->listSize+1) {
        return OUT_RNAGE_ERROR;
    }
    /*if(getCursor(list, 0) == 1) {
        return OVER_FLOW_ERROR;
    }*/
    int idle = MallocCell(list);
    if(idle) {
        setElem(list, idle, elem);
        int pos = list->capacity-1;
        for(int j=1;j<i;j++) {
            pos = getCursor(list, pos);
        }
        setCursor(list, idle, getCursor(list, pos));
        setCursor(list, pos, idle);
        list->listSize++;
    }
    return SUCCESS;
}

static inline void FreeCell(StaticList *list,int i)
{
    setCursor(list, i, getCursor(list, 0));
    setCursor(list, 0, i);
    list->listSize--;
}

Status DeleteStaticList(StaticList *list,int i,void *elem)
{
    if(i<1 || i > list->listSize) {
        return OUT_RNAGE_ERROR;
    }
    int k = list->capacity-1;
    for(int j=1;j<i-1;j++) {
        k = getCursor(list, k);
    }
    int dest = getCursor(list, k);
    copyElem(list, dest, elem);
    setCursor(list, k, getCursor(list, dest));
    cleanElem(list, dest);
    FreeCell(list, dest);
    return SUCCESS;
}

static inline void PrintCell(StaticList *list,int i)
{
    printf("element index = %d \n",i);
    printf("element data:\n");
    for(int j=0;j<list->elemSize;j++) {
        printf("%x ",list->poolSpace[i*(list->cellSize)+j]);
    }
    printf("\n");
    printf("cursor : %d\n",getCursor(list, i));
    printf("-----------------\n");
}

void PrintStaticList(StaticList *list)
{
    for(int i=0;i<list->capacity;i++) {
        PrintCell(list,i);
    }
}
