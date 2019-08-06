/*
 *描述：链式存储的线性表
 *作者：刘小东
*/

#define boolean unsigned char
#define true 1
#define false 0


typedef struct LinkedList {
    void *header;
    int cellSize;
    int listSize;
}LinkedList;

void InitLinkedList(LinkedList *list, int cellSize);
boolean IsEmpty(LinkedList *list);
void Destroy(LinkedList *list);
void GetElem(LinkedList *list,int i,void * elem);
int ContainElem(LinkedList *list, void * elem);
void InsertElem(LinkedList *list, int i, void * elem);
void DeleteElem(LinkedList *list, int i);
void ModifyElem(LinkedList *list, int i, void * elem);
int  Length(LinkedList *list);
