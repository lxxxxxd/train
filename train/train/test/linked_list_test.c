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
    char *empty = IsListEmpty(list) ? "empty" : "not empty";
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
        if(*(bytes+i) >= ' ' && *(bytes+i) <= '~' && i<100) {
            printf("%c ",*(bytes+i));
        } else {
            printf("%x ",*(bytes+i));
        }
    }
    printf("\n");
}

static inline void * getNext(LinkedList *list,void *node)
{
    unsigned char *bytes = (unsigned char *)node;
    void *next = NULL;
    bytes+=list->cellSize;
    next = *((void **)bytes);
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

void printPerson(Person *p)
{
    printf("person name :%s\n",p->name);
    printf("person birth :%ld\n",p->birth);
    printf("person gender :%d\n",p->gender);
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
        FEMALE
    };
    AddListElem(&list,&p1);
    lengthAssert(&list,1);
    printLinkedList(&list);
    Person p2 = {
        "li si",
        20170308,
        MALE
    };
    AddListElem(&list,&p2);
    lengthAssert(&list, 2);
    printLinkedList(&list);
    
    //test get a certain element
    Person *elem;
    Status status = GetListElem(&list, 0, (void **)&elem);
    if(status != SUCCESS) {
        printf("GetListElem error code = %d.\n",status);
    }
    printPerson(elem);
    
    status = GetListElem(&list, 1, (void **)&elem);
    if(status != SUCCESS) {
        printf("GetListElem error code = %d.\n",status);
    }
    printPerson(elem);
    
    status = GetListElem(&list, 2, (void **)&elem);
    if(status != SUCCESS) {
        printf("GetListElem error code = %d.\n",status);
    }
    
    //test contain elem
    int index = ContainListElem(&list, &p1);
    printf("the index of p1 :%d\n",index);
    index = ContainListElem(&list, NULL);
    printf("the index of p1 :%d\n",index);
    
    //test modify element
    Person p3 = {
        "liu xiaodong",
        19910518,
        0
    };
    ModifyListElem(&list, 0, &p3);
    status = GetListElem(&list, 0, (void **)&elem);
    if(status != SUCCESS) {
        printf("GetListElem error code = %d.\n",status);
    }
    printPerson(elem);
    
    //test delete element
    DeleteListElem(&list, 1);
    printLinkedList(&list);
    lengthAssert(&list, 1);
    
    //test list destroy
    ListDestroy(&list);
    lengthAssert(&list, 0);
    printLinkedList(&list);
    return;
}
