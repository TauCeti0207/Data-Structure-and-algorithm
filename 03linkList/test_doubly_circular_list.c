#include "doubly_circular_list.h"

// 测试函数：测试链表的初始化和插入操作
void testInitializationAndInsertion()
{
	DoublyCircularList *list = DCListInit();

	// 测试在头部插入元素
	DCListPushFront(list, 10);
	DCListPushFront(list, 20);
	printf("在头部插入元素后的链表: ");
	DCListPrint(list);

	// 测试链表大小
	printf("当前链表大小: %d\n", DCListSize(list));

	// 测试在尾部插入元素
	DCListPushBack(list, 30);
	DCListPushBack(list, 40);
	printf("在尾部插入元素后的链表: ");
	DCListPrint(list);

	// 测试链表大小
	printf("当前链表大小: %d\n", DCListSize(list));

	DCListDestroy(list);
}

// 测试函数：测试链表的删除操作
void testDeletion()
{
	DoublyCircularList *list = DCListInit();
	DCListPushBack(list, 1);
	DCListPushBack(list, 2);
	DCListPushBack(list, 3);
	DCListPushBack(list, 4);

	printf("原始链表: ");
	DCListPrint(list);

	// 测试删除头部元素
	DCListPopFront(list);
	printf("删除头部元素后的链表: ");
	DCListPrint(list);

	// 测试删除尾部元素
	DCListPopBack(list);
	printf("删除尾部元素后的链表: ");
	DCListPrint(list);

	// 测试删除指定位置元素
	ListNode *pos = DCListFind(list, 2);
	if (pos != NULL)
	{
		DCListErase(pos);
	}
	printf("删除元素 2 后的链表: ");
	DCListPrint(list);

	DCListDestroy(list);
}

// 测试函数：测试链表的查找操作
void testFinding()
{
	DoublyCircularList *list = DCListInit();
	DCListPushBack(list, 100);
	DCListPushBack(list, 200);
	DCListPushBack(list, 300);

	printf("当前链表: ");
	DCListPrint(list);

	ListNode *found = DCListFind(list, 200);
	if (found != NULL)
	{
		printf("找到元素 200\n");
	}
	else
	{
		printf("未找到元素 200\n");
	}

	found = DCListFind(list, 400);
	if (found != NULL)
	{
		printf("找到元素 400\n");
	}
	else
	{
		printf("未找到元素 400\n");
	}

	DCListDestroy(list);
}

// 测试函数：测试在指定位置插入元素
void testInsertAtPosition()
{
	DoublyCircularList *list = DCListInit();
	DCListPushBack(list, 1);
	DCListPushBack(list, 3);

	printf("原始链表: ");
	DCListPrint(list);

	ListNode *pos = DCListFind(list, 3);
	if (pos != NULL)
	{
		DCListInsert(pos, 2);
	}
	printf("在元素 3 前插入元素 2 后的链表: ");
	DCListPrint(list);

	DCListDestroy(list);
}

// 测试函数：测试链表是否为空
void testEmpty()
{
	DoublyCircularList *list = DCListInit();
	if (DCListEmpty(list))
	{
		printf("链表初始为空\n");
	}
	else
	{
		printf("链表初始不为空，测试错误\n");
	}

	DCListPushBack(list, 1);
	if (DCListEmpty(list))
	{
		printf("插入元素后链表仍为空，测试错误\n");
	}
	else
	{
		printf("插入元素后链表不为空\n");
	}

	DCListDestroy(list);
}

int main()
{
	testInitializationAndInsertion();
	printf("\n");
	testDeletion();
	printf("\n");
	testFinding();
	printf("\n");
	testInsertAtPosition();
	printf("\n");
	testEmpty();

	return 0;
}