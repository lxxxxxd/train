//
//  static_list.h
//  train
//  静态链表，游标实现法
//  Created by xiaodong liu on 2019/8/10.
//  Copyright © 2019 xiaodong liu. All rights reserved.
//
/*
 优点：在插入和删除时，只需要修改游标，不需要移动元素，
 从而改进了在顺序存储结构中插入和删除操作需要移动大量
 元素的缺点
 缺点：
 （1）不能解决连续存储分配带来的表长度难以确定的问题
 （2）失去了顺序存储结构的随机存取的特性
 */
#ifndef static_list_h
#define static_list_h

#include <stdio.h>
#include "type.h"
#include "status.h"

#define CURSOR_SIZE 4

typedef struct {
    byte *poolSpace;
    int cellSize;
    int capacity;
    int elemSize;
    int listSize;
} StaticList;

Status InitStaticList(StaticList *list,int cellSize,int capacity);
Status InsertStaticList(StaticList *list,int i,void *elem);
Status DeleteStaticList(StaticList *list,int i,void *elem);
void PrintStaticList(StaticList *list);

#endif /* static_list_h */
