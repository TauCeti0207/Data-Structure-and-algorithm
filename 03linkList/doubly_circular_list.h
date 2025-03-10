#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 定义链表存储的数据类型，方便后续修改
typedef int DCListDataType;

// 定义链表节点结构体
typedef struct ListNode
{
	DCListDataType data;
	struct ListNode *prev;
	struct ListNode *next;
} ListNode;

// 定义链表结构体，包含头节点指针和链表大小
typedef struct DoublyCircularList
{
	ListNode *head;
	int size;
} DoublyCircularList;

// 创建新节点
ListNode *DCListCreateNode(DCListDataType data);

// 初始化链表
DoublyCircularList *DCListInit();

// 在链表头部插入节点
void DCListPushFront(DoublyCircularList *list, DCListDataType data);

// 在链表尾部插入节点
void DCListPushBack(DoublyCircularList *list, DCListDataType data);

// 删除链表头部节点
void DCListPopFront(DoublyCircularList *list);

// 删除链表尾部节点
void DCListPopBack(DoublyCircularList *list);

// 在指定位置之前插入节点
void DCListInsert(ListNode *pos, DCListDataType data);

// 删除指定位置的节点
void DCListErase(ListNode *pos);

// 查找指定值的节点
ListNode *DCListFind(DoublyCircularList *list, DCListDataType data);

// 获取链表的大小
int DCListSize(DoublyCircularList *list);

// 判断链表是否为空
int DCListEmpty(DoublyCircularList *list);

// 打印链表元素
void DCListPrint(DoublyCircularList *list);

// 销毁链表
void DCListDestroy(DoublyCircularList *list);
