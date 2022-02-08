#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单向-不带头-不循环
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);
void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);
//单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//在pos后面插入
void SListInserAfter(SLTNode* pos, SLTDataType x);

//在pos之前插入
void SListInserBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x);

//在pos之后擦除
void SListEraseAfter(SLTNode* pos);