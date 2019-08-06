//
//  linked_list_test.c
//  train
//
//  Created by xiaodong liu on 2019/8/6.
//  Copyright © 2019 xiaodong liu. All rights reserved.
//

#include "linked_list_test.h"
#include "link_list.h"
#include <stdio.h>
#include <memory.h>

typedef enum {
    MALE,
    FEMALE
}Gender;

typedef struct {
    char name[100];
    long birth;
    Gender gender;
}Person;

void emptyTest(LinkedList *list)
{
    //test empty
    char *empty = IsEmpty(list) ? "empty" : "not empty";
    printf("test linked list is %s .\n",empty);
}

boolean lengthAssert(LinkedList *list,int length)
{
    boolean assert = list->listSize == length ? true : false;
    printf("linked list length = %d.\n",list->listSize);
    if(assert) {
        printf("test length OK! \n");
    } else {
        printf("test length Failed! \n");
    }
    return assert;
}

void printNode(void *node,int size)
{
    unsigned char *bytes = (unsigned char *)node;
    for(int i=0;i<size;i++){
        printf("%x ",*(bytes+i));
    }
    printf("\n");
}

static inline void * getNext(LinkedList *list,void *node)
{
    unsigned char *bytes = (unsigned char *)node;
    void *next = NULL;
    bytes+=list->cellSize;
    memcpy(&next,bytes,4);
    return next;
}
               
void printLinkedList(LinkedList *list)
{
    void *next = list->header;
    while(next!=NULL) {
        printNode(next,list->cellSize);
        next = getNext(list,next);
    }
}
               
void LinkedListTest(void)
{
    LinkedList list;
    printf("test create linked list.\n");
    //init
    InitLinkedList(&list,sizeof(Person));
    emptyTest(&list);
    lengthAssert(&list,0);
    //insert
    Person p1 = {
        "zhang san",
        20000102,
        MALE
    };
    InsertElem(&list,0,&p1);
    lengthAssert(&list,1);
    printLinkedList(&list);
    return;

}
