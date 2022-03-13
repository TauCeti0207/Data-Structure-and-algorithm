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

// void SListPopFront(SListNode **ppList);
void SListPopFront(SListNode *&pList);

SListNode *SListFind(SListNode *plist, SListDataType x);

void SListInserAfter(SListNode *pos, SListDataType x);

// void SListInserBefore(SListNode** ppList, SListNode* pos, SListDataType x);
void SListInserBefore(SListNode *&pList, SListNode *pos, SListDataType x);

void SListEraseAfter(SListNode *pos);

void SListEraseCur(SListNode *&pList, SListNode *pos);
// void SListEraseCur(SListNode** ppList, SListNode* pos);