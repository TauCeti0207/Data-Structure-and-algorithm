/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-02 22:27:43
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-03-05 21:04:01
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 定义单链表节点的数据类型
typedef int SListDataType;

// 定义单链表节点结构
typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;
} SListNode;

// 修改链表才传二级指针，不修改传一级指针
//  在链表头部插入元素
void singlyLinkedListPushFront(SListNode **pphead, SListDataType data);
// 在链表尾部插入元素
void singlyLinkedListPushBack(SListNode **pphead, SListDataType data);
// 在链表头部删除元素
void singlyLinkedListPopFront(SListNode **pphead);
// 在链表尾部删除元素
void singlyLinkedListPopBack(SListNode **pphead);
// 查找指定值的节点
SListNode *singlyLinkedListFind(SListNode *phead, SListDataType data);
// 在指定节点之前插入元素
void singlyLinkedListInsertBefore(SListNode **pphead, SListNode *pos, SListDataType data);
// 在指定节点之后插入元素
void singlyLinkedListInsertAfter(SListNode *pos, SListDataType data);
// 删除pos位置的元素
void singlyLinkedListErase(SListNode **pphead, SListNode *pos);
// 删除pos位置后面的节点
void singlyLinkedListEraseAfter(SListNode *pos);
// 打印链表
void singlyLinkedListPrint(SListNode *phead);
// 销毁链表
void singlyLinkedListDestroy(SListNode **pphead);