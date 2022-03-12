#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int SListDataType;
typedef struct SListNode // Single Link List
{
    SListDataType data;
    struct SListNode *next; //存储下一个节点的地址
} SListNode;

void SListPrint(SListNode *pList);
SListNode *CreateNewNode(SListDataType x);
// void SListPushBack(SListNode **ppList, SListDataType x);
void SListPushBack(SListNode *&pList, SListDataType x);
void SListPushFront(SListNode *&pList, SListDataType x);
// void SListPushFront(SListNode** pplist, SListDataType x);

// void SListPopBack(SListNode** ppList);
void SListPopBack(SListNode *&pList);
