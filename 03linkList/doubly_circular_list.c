/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-09 21:20:28
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-03-10 16:33:19
 */
#include "doubly_circular_list.h"

// 创建新节点
ListNode *DCListCreateNode(DCListDataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

// 初始化链表
DoublyCircularList *DCListInit()
{
	DoublyCircularList *list = (DoublyCircularList *)malloc(sizeof(DoublyCircularList));
	if (list == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	list->head = DCListCreateNode(0); // 创建头节点
	list->head->prev = list->head;
	list->head->next = list->head;
	list->size = 0;
	return list;
}

// 在链表头部插入节点
void DCListPushFront(DoublyCircularList *list, DCListDataType data)
{
	assert(list);
	ListNode *newNode = DCListCreateNode(data);
	ListNode *next = list->head->next;
	// head -> newNode -> next
	newNode->next = next;
	newNode->prev = list->head;
	next->prev = newNode;
	list->head->next = newNode;
	list->size++;
}

// 在链表尾部插入节点
void DCListPushBack(DoublyCircularList *list, DCListDataType data)
{
	assert(list);
	ListNode *newNode = DCListCreateNode(data);
	// head   tail   newNode
	ListNode *tail = list->head->prev;
	newNode->prev = tail;
	newNode->next = list->head;
	tail->next = newNode;
	list->head->prev = newNode;
	list->size++;
}

// 删除链表头部节点
void DCListPopFront(DoublyCircularList *list)
{
	assert(list);
	assert(list->size > 0);
	// head toDelete second
	ListNode *toDelete = list->head->next;
	ListNode *second = toDelete->next;
	list->head->next = second;
	second->prev = list->head;
	free(toDelete);
	list->size--;
}

// 删除链表尾部节点
void DCListPopBack(DoublyCircularList *list)
{
	assert(list);
	assert(list->size > 0);
	// head tailPrev tail
	ListNode *tail = list->head->prev;
	ListNode *tailPrev = tail->prev;
	tailPrev->next = list->head;
	list->head->prev = tailPrev;
	free(tail);
	list->size--;
}

// 在指定位置之前插入节点
void DCListInsert(ListNode *pos, DCListDataType data)
{
	assert(pos);
	// prev newNode pos
	ListNode *newNode = DCListCreateNode(data);
	ListNode *prev = pos->prev;
	newNode->next = pos;
	newNode->prev = prev;
	prev->next = newNode;
	pos->prev = newNode;
}

// 删除指定位置的节点
void DCListErase(ListNode *pos)
{
	assert(pos);
	// prev pos next
	ListNode *prev = pos->prev;
	ListNode *next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

// 查找指定值的节点
ListNode *DCListFind(DoublyCircularList *list, DCListDataType data)
{
	assert(list);
	ListNode *current = list->head->next;
	while (current != list->head)
	{
		if (current->data == data)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// 获取链表的大小
int DCListSize(DoublyCircularList *list)
{
	assert(list);
	return list->size;
}

// 判断链表是否为空
int DCListEmpty(DoublyCircularList *list)
{
	if (list == NULL)
		return 1;
	return list->size == 0;
}

// 打印链表元素
void DCListPrint(DoublyCircularList *list)
{
	assert(list);
	printf("head<=>");
	ListNode *current = list->head->next;
	while (current != list->head)
	{
		printf("%d<=>", current->data);
		current = current->next;
	}
	printf("\n");
}

// 销毁链表
void DCListDestroy(DoublyCircularList *list)
{
	assert(list);
	ListNode *current = list->head->next;
	ListNode *next;
	while (current != list->head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(list->head);
	free(list);
}

/* // 尾插 头插 尾删 头删 都可以复用 Insert 和 Erase
// 头插
void DCListPushFront(DoublyCircularList *list, DCListDataType data)
{
	// 复用DCListInsert函数
	assert(list);
	DCListInsert(list->head->next, data);
}
// 尾插
void DCListPushBack(DoublyCircularList *list, DCListDataType data)
{
	// 复用DCListInsert函数
	assert(list);
	DCListInsert(list->head, data);
}
// 头删
void DCListPopFront(DoublyCircularList *list)
{
	// 复用DCListErase函数
	assert(list);
	DCListErase(list->head->next);
}
// 尾删
void DCListPopBack(DoublyCircularList *list)
{
	// 复用DCListErase函数
	assert(list);
	DCListErase(list->head->prev);
}
 */