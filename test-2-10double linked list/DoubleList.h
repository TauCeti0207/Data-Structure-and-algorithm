#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListInit();
void ListPushBack(ListNode* phead, LTDataType x);
void ListPrint(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void LIstInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
int ListEmpty(ListNode* phead);//¿Õ·µ»Ø1,·Ç¿Õ·µ»Ø0
int ListSize(ListNode* phead);
void ListDestroy(ListNode* phead);