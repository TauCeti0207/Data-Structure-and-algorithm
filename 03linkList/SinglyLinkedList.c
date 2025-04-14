/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-02 22:27:43
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-04-07 10:08:19
 */
#include "SinglyLinkedList.h"

// 创建新节点
SListNode *createNewNode(SListDataType data)
{
	SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// 在链表头部插入元素
// 头指针 -> 1 -> 2 -> 3 -> NULL
// 头指针 -> 4 -> 1 -> 2 -> 3 -> NULL
void singlyLinkedListPushFront(SListNode **pphead, SListDataType data)
{
	assert(pphead); // 如果链表为空，那就是*pphead为空
	SListNode *newNode = createNewNode(data);
	newNode->next = *pphead; // 新节点的next指向原头节点
	*pphead = newNode;		 // 更新头指针
}

// 在链表尾部插入元素
void singlyLinkedListPushBack(SListNode **pphead, SListDataType data)
{
	SListNode *newNode = createNewNode(data);
	if (*pphead == NULL) // 链表为空，需要改变结构体指针plist
	{
		*pphead = newNode;
	}
	else // 链表不为空，需要找到链表的尾节点（即 next 指针为 NULL 的节点），然后改变尾节点的 next 指针，使其指向新节点。
	{
		SListNode *tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

// 在链表头部删除元素
void singlyLinkedListPopFront(SListNode **pphead)
{
	assert(pphead);
	assert(*pphead); // 链表为空 不能头删 暴力检查
	/* 	if (*pphead == NULL) //温柔检查
		{
			fprintf_s(stderr, "The list is empty!\n");
			return;
		} */
	/* 	if ((*pphead)->next == NULL) // 只有一个节点 可以合并
		{
			free(*pphead);
			*pphead = NULL;
			return;
		} */
	// 1 2 3
	// 先写多个节点的情况，再去比较单个节点能否适用，发现恰好可以匹配。
	SListNode *temp = *pphead;
	*pphead = (*pphead)->next;
	free(temp);
}

// 在链表尾部删除元素
void singlyLinkedListPopBack(SListNode **pphead)
{
	// assert(*pphead); 也可以这样暴力检查
	if (*pphead == NULL) // 链表为空
	{
		fprintf(stderr, "The list is empty!\n");
		return;
	}
	if ((*pphead)->next == NULL) // 只有一个节点
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	// 保留倒数第二个节点
	SListNode *prev = NULL;
	SListNode *current = *pphead;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	free(current);
	prev->next = NULL;
}

// 查找指定值的节点
SListNode *singlyLinkedListFind(SListNode *phead, SListDataType data)
{
	SListNode *current = phead;
	while (current != NULL)
	{
		if (current->data == data)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// 在指定节点之前插入元素
void singlyLinkedListInsertBefore(SListNode **pphead, SListNode *pos, SListDataType data)
{
	assert(pphead);
	assert(pos); // pos 不能为空
	SListNode *newNode = createNewNode(data);
	// 如果 pos 是头节点，直接插入到头部
	if (*pphead == pos)
	{
		newNode->next = *pphead;
		*pphead = newNode;
	}
	else
	{
		// 找到 pos 的前一个节点
		SListNode *prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		// pre newNode pos
		newNode->next = pos;
		prev->next = newNode;
	}
}

// 在指定节点之后插入元素
void singlyLinkedListInsertAfter(SListNode *pos, SListDataType data)
{
	assert(pos); // pos 不能为空
	SListNode *newNode = createNewNode(data);
	// pos newNode pos->next
	newNode->next = pos->next;
	pos->next = newNode;
}

// 删除 pos 位置的元素
void singlyLinkedListErase(SListNode **pphead, SListNode *pos)
{
	assert(pphead);
	assert(pos);
	// 如果要删除的是头节点
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		// 找到 pos 的前一个节点
		SListNode *prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		// prev pos
		prev->next = pos->next;
		free(pos);
	}
}
void singlyLinkedListEraseAfter(SListNode *pos)
{
	assert(pos);
	// pos pos->next pos->next->next
	SListNode *tail = pos->next;
	pos->next = tail->next;
	free(tail);
}
// 打印链表
void singlyLinkedListPrint(SListNode *phead)
{
	SListNode *current = phead;
	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

// 销毁链表
void singlyLinkedListDestroy(SListNode **pphead)
{
	assert(pphead);
	SListNode *current = *pphead;
	SListNode *next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*pphead = NULL;
}
