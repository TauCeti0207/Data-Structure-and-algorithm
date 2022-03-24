#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int LTDataType; // ListDateType
typedef struct ListNode
{
	struct ListNode *next;
	struct ListNode *prev;
	LTDataType data;
} ListNode;

ListNode *ListInit();
void ListInit2(ListNode *&pHead); //第二种初始化方式
void ListPrint(ListNode *pHead);
void ListPushBack(ListNode *pHead, LTDataType x);
void ListPushFront(ListNode *pHead, LTDataType x);
void ListPopBack(ListNode *pHead);
void ListPopFront(ListNode *pHead);
ListNode *ListFind(ListNode *pHead, LTDataType x);
void LIstInsert(ListNode *pos, LTDataType x);
void LIstInsert2(ListNode *pos, LTDataType x);
void ListErase(ListNode *pos);
bool ListIsEmpty(ListNode *pHead);
int ListSize(ListNode *pHead);
void ListDestroy(ListNode *pHead);