/*
 *描述：顺序存储的线性表实现
 *作者：刘小东
 */

#include "vector.h"
#include "type.h"
#include "status.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void InitVector(Vector *vec, int cellSize)
{
    vec->cellSize = cellSize;
    vec->arraySize = 0;
    vec->arrayCapacity = DEFAULT_CAPACITY;
    vec->cellArray = malloc(DEFAULT_CAPACITY*cellSize);
}

boolean IsVectorEmpty(Vector *vec)
{
    if(vec->arraySize == 0) {
        return true;
    } else {
        return false;
    }
}

void ClearVector(Vector *vec)
{
    vec->arraySize = 0;
    vec->arrayCapacity = 0;
    free(vec->cellArray);
    vec->cellArray = NULL;
}

void GetVectorElem(Vector *vec,int i,void * elem)
{
    if(vec->arraySize == 0 || vec->cellArray == NULL || i < 0) {
        printf("GetElem function: invalide parameter.\n");
        return;
    }
    memcpy(elem, vec->cellArray+i*vec->cellSize, vec->cellSize);
    return;
}

int ContainVectorElem(Vector *vec, void * elem)
{
    for(int i=0;i<vec->arraySize;i++) {
        if(memcmp(vec->cellArray+i*vec->cellSize,elem,vec->cellSize) == 0) {
            return i;
        }
    }
    return -1;
}

static void Insert(Vector *vec, int i, void * elem)
{
    memcpy(vec->cellArray+(i+1)*vec->cellSize,vec->cellArray+i*vec->cellSize,vec->cellSize*(vec->arraySize-i+1));
    memcpy(vec->cellArray+i*vec->cellSize,elem,vec->cellSize);
    vec->arraySize++;
}

static void Expand(Vector *vec, int i, void * elem)
{
    void * tmp = malloc(vec->arrayCapacity*2*vec->cellSize);
    memcpy(tmp,vec->cellArray,vec->arrayCapacity*vec->cellSize);
    vec->cellArray = tmp;
    vec->arrayCapacity*=2;
    Insert(vec,i,elem);
}

void InsertVectorElem(Vector *vec, int i, void * elem)
{
    if(vec->arraySize < vec->arrayCapacity) {
        Insert(vec,i,elem);
    } else {
        Expand(vec,i,elem);
    }
}
void DeleteVectorElem(Vector *vec, int i, void * elem)
{
    memcpy(elem,vec->cellArray+i*vec->cellSize,vec->cellSize);
    memcpy(vec->cellArray+i*vec->cellSize,vec->cellArray+(i+1)*vec->cellSize,vec->cellSize*(vec->arraySize-i+1));
    vec->arraySize--;
}
void ModifyVectorElem(Vector *vec, int i, void * elem)
{
    memcpy(vec->cellArray+i*vec->cellSize,elem,vec->cellSize);
    memcpy(elem,vec->cellArray+i*vec->cellSize,vec->cellSize);
}
int  VectorLength(Vector *vec)
{
    return vec->arraySize;
}
