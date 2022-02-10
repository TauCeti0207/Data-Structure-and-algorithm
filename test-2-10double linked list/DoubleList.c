#define _CRT_SECURE_NO_WARNINGS 1
#include"DoubleList.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		printf("BuyListNode Failed\n");
		exit(-1);
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	//指向自己,方便插入第一个节点
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//void ListPushBack(ListNode* phead, LTDataType x)
//{
//	assert(phead);
//	//phead->prev就是尾
//	ListNode* tail = phead->prev;
//	ListNode* newnode = BuyListNode(x);
//
//	tail->next = newnode;
//	newnode->prev = tail;
//	newnode->next = phead;
//	phead->prev = newnode;
//}

void ListPushBack(ListNode* phead, LTDataType x)
{
	LIstInsert(phead, x);
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//void ListPushFront(ListNode* phead, LTDataType x)
//{
//	assert(phead);
//	ListNode* first = phead->next;
//	ListNode* newnode = BuyListNode(x);
//	//phead newnode first
//	phead->next = newnode;
//	newnode->prev = phead;
//	newnode->next = first;
//	first->prev = newnode;
//}

void ListPushFront(ListNode* phead, LTDataType x)
{
	LIstInsert(phead->next, x);
}
//void ListPopBack(ListNode* phead)
//{
//	assert(phead);
//	assert(phead != phead->next);//只有一个头节点没法删
//	ListNode* tail = phead->prev;
//	ListNode* tailPrev = tail->prev;
//	free(tail);
//	tail = NULL;
//	tailPrev->next = phead;
//	phead->prev = tailPrev;
//}
void ListPopBack(ListNode* phead)
{
	ListErase(phead->prev);
}
//void ListPopFront(ListNode* phead)
//{
//	assert(phead);
//	assert(phead != phead->next);//只有一个头节点没法删
//	ListNode* toDelete = phead->next;
//	ListNode* first = toDelete->next;
//	free(toDelete);
//	toDelete = NULL;
//	//删到只剩头节点时,满足自己指向自己
//	phead->next = first;
//	first->prev = phead;
//}

void ListPopFront(ListNode* phead)
{
	ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void LIstInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	//在pos前面插入
	//prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	//prev pos next
	prev->next = next;
	next->prev = prev;
	free(pos);
}


int ListEmpty(ListNode* phead)//空返回1,非空返回0
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}
int ListSize(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	free(phead);
	phead = NULL;//这样不起作用的,除非传二级指针或者调用之后再手动置空
	//不用二级保持接口一致性
}