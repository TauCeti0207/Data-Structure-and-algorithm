#pragma once
#include<stdio.h>
#include<stdlib.h>
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