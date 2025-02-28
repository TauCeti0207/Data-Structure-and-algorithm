#include "SeqList.h"
#include <stdio.h>

// 测试顺序表的初始化和销毁操作
void testInitAndDestroy()
{
	SeqList seq;
	SeqListInit(&seq);
	printf("顺序表初始化成功，当前容量: %zu，有效数据个数: %zu\n", seq.capacity, seq.size);
	SeqListDestory(&seq);
	printf("顺序表销毁成功\n");
}

// 测试顺序表的尾插操作
void testPushBack()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的头插操作
void testPushFront()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushFront(&seq, 1);
	SeqListPushFront(&seq, 2);
	SeqListPushFront(&seq, 3);
	printf("头插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的尾删操作
void testPopBack()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListPopBack(&seq);
	printf("尾删后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的头删操作
void testPopFront()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListPopFront(&seq);
	printf("头删后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的查找操作
void testFind()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	int pos = SeqListFind(&seq, 2);
	if (pos != -1)
	{
		printf("找到元素 2，位置为: %d\n", pos);
	}
	else
	{
		printf("未找到元素 2\n");
	}
	SeqListDestory(&seq);
}

// 测试顺序表的中间插入操作
void testInsert()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListInsert(&seq, 1, 4);
	printf("在位置 1 插入 4 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的中间删除操作
void testErase()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListErase(&seq, 1);
	printf("删除位置 1 的元素后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的修改操作
void testModify()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListModify(&seq, 1, 4);
	printf("将位置 1 的元素修改为 4 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

int main()
{
	testInitAndDestroy();
	testPushBack();
	testPushFront();
	testPopBack();
	testPopFront();
	testFind();
	testInsert();
	testErase();
	testModify();
	return 0;
}