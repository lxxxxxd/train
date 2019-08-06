//
//  vector_test.c
//  train
//
//  Created by xiaodong liu on 2019/8/6.
//  Copyright © 2019 xiaodong liu. All rights reserved.
//

#include "vector_test.h"
#include "vector.h"
#include <stdio.h>

void VectorTest()
{
    printf("vector : linear table struct with sequential storage.\n");
    Vector v;
    //init
    InitVector(&v,sizeof(int));
    //is empty
    if(IsVectorEmpty(&v)) {
        printf("vector is empty.\n");
    } else {
        printf("vector is not empty, length = %d.",VectorLength(&v));
    }
    // insert 0-10
    printf("InsertElem: insert 0-10\n");
    for(int i=0;i<10;i++) {
        InsertVectorElem(&v,i,&i);
    }
    printf("GetElem: print all element length = %d.\n",VectorLength(&v));
    for(int i=0;i<v.arraySize;i++) {
        int elem = 0;
        GetVectorElem(&v,i,&elem);
        printf("i = %d, elem = %d\n",i,elem);
    }
    int dstVal = 100;
    printf("ContainElem: elem = %d, position = %d (-1 = not contain)\n",dstVal,ContainVectorElem(&v,&dstVal));
    dstVal = 5;
    printf("ContainElem: elem = %d, position = %d (-1 = not contain)\n",dstVal,ContainVectorElem(&v,&dstVal));
    
    int delPos=4, delElem = 0;
    DeleteVectorElem(&v,delPos,&delElem);
    printf("DeleteElem: elem = %d, position = %d, length = %d\n",delElem,delPos,VectorLength(&v));
    
    int modPos = 4, modElem =100;
    ModifyVectorElem(&v,modPos,&modElem);
    printf("ModifyElem: elem = %d, position = %d, length = %d\n",modElem,modPos,VectorLength(&v));
    //is empty
    if(IsVectorEmpty(&v)) {
        printf("vector is empty.\n");
    } else {
        printf("vector is not empty, length = %d.",VectorLength(&v));
    }
    
    printf("GetElem: print all element length = %d.\n",VectorLength(&v));
    for(int i=0;i<v.arraySize;i++) {
        int elem = 0;
        GetVectorElem(&v,i,&elem);
        printf("i = %d, elem = %d\n",i,elem);
    }
}
