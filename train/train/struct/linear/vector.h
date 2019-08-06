/*
 * 描述：顺序存储的线性表
 * 作者：刘小东
 */

#define boolean unsigned char
#define true 1
#define false 0
#define DEFAULT_CAPACITY 5

typedef struct Vector {
    void * cellArray;
    int cellSize;
    int arraySize;
    int arrayCapacity;
}Vector;

void InitVector(Vector *vec, int cellSize);
boolean IsVectorEmpty(Vector *vec);
void ClearVector(Vector *vec);
void GetVectorElem(Vector *vec,int i,void * elem);
int ContainVectorElem(Vector *vec, void * elem);
void InsertVectorElem(Vector *vec, int i, void * elem);
void DeleteVectorElem(Vector *vec, int i, void * elem);
void ModifyVectorElem(Vector *vec, int i, void * elem);
int  VectorLength(Vector *vec);

