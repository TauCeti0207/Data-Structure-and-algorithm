#include "SinglyLinkedList.h"

void singlyLinkedListTest1()
{
	SListNode *list = NULL;
	singlyLinkedListPushBack(&list, 1);
	singlyLinkedListPushBack(&list, 2);
	printf("尾插 1, 2 后链表元素为: ");
	singlyLinkedListPrint(list);
}
void singlyLinkedListTest2()
{
	SListNode *list = NULL;
	singlyLinkedListPushFront(&list, 1);
	singlyLinkedListPushFront(&list, 2);
	printf("头插 1, 2 后链表元素为: ");
	singlyLinkedListPrint(list);
}

void singlyLinkedListTest3()
{
	SListNode *list = NULL;
	singlyLinkedListPushBack(&list, 1);
	singlyLinkedListPushBack(&list, 2);
	singlyLinkedListPushBack(&list, 3);
	printf("尾插 1, 2, 3 后链表元素为: ");
	singlyLinkedListPrint(list);
	singlyLinkedListPopBack(&list);
	printf("尾删后链表元素为: ");
	singlyLinkedListPrint(list);
	singlyLinkedListPopFront(&list);
	printf("头删后链表元素为: ");
	singlyLinkedListPrint(list);
	printf("头删后链表元素为: ");
	singlyLinkedListPopFront(&list);
	singlyLinkedListPrint(list);
	printf("头删后链表元素为: ");
	singlyLinkedListPopFront(&list);
	singlyLinkedListPrint(list);
}

void singlyLinkedListTest4()
{
	SListNode *list = NULL;
	singlyLinkedListPushBack(&list, 1);
	singlyLinkedListPushBack(&list, 2);
	singlyLinkedListPushBack(&list, 3);
	printf("尾插 1, 2, 3 后链表元素为: ");
	singlyLinkedListPrint(list);
	SListNode *pos = singlyLinkedListFind(list, 2);
	if (pos)
		pos->data = 30;

	printf("修改后链表元素为: ");
	singlyLinkedListPrint(list);
}

void singlyLinkedListTest5()
{
	SListNode *list = NULL;
	singlyLinkedListPushBack(&list, 1);
	singlyLinkedListPushBack(&list, 2);
	singlyLinkedListPushBack(&list, 3);
	printf("尾插 1, 2, 3 后链表元素为: ");
	singlyLinkedListPrint(list);
	SListNode *pos = singlyLinkedListFind(list, 2);
	if (pos)
	{
		singlyLinkedListInsertBefore(&list, pos, 20);
	}

	printf("在pos之前插入后链表元素为: ");
	singlyLinkedListPrint(list);
	singlyLinkedListInsertAfter(pos, 21);
	printf("在pos之后插入后链表元素为: ");
	singlyLinkedListPrint(list);
}

void singlyLinkedListTest6()
{
	// 测试destroy
	SListNode *list = NULL;
	singlyLinkedListPushBack(&list, 1);
	singlyLinkedListPushBack(&list, 2);
	singlyLinkedListPushBack(&list, 3);
	printf("尾插 1, 2, 3 后链表元素为: ");
	singlyLinkedListPrint(list);
	singlyLinkedListDestroy(&list);
	printf("销毁后链表元素为: ");
	singlyLinkedListPrint(list);
}

int main(int argc, char const *argv[])
{
	return 0;
}
