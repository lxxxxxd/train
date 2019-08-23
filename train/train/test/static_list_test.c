//
//  static_list_test.c
//  train
//
//  Created by xiaodong liu on 2019/8/10.
//  Copyright © 2019 xiaodong liu. All rights reserved.
//

#include "static_list_test.h"
#include "static_list.h"

typedef struct {
    char c;
}Char;

void StaticListTest(void)
{
    StaticList list;
    //test init
    InitStaticList(&list, sizeof(Char), 10);
    //test insert element
    Char c1 = {'a'};
    Char c2 = {'b'};
    Char c3 = {'d'};
    Char c4 = {'e'};
    Char c5 = {'f'};
    InsertStaticList(&list, 1, &c1);
    InsertStaticList(&list, 2, &c2);
    InsertStaticList(&list, 3, &c3);
    InsertStaticList(&list, 4, &c4);
    InsertStaticList(&list, 5, &c5);
    Char c6 = {'c'};
    InsertStaticList(&list, 3, &c6);
    PrintStaticList(&list);
    //test delete element
    printf("test delete element. \n");
    Char tmp;
    DeleteStaticList(&list, 1, &tmp);
    PrintStaticList(&list);
}
