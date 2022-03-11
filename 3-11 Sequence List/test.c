#include "SeqList.h"

void Test1()
{
	SeqList s;//定义结构体变量
	SeqListInit(&s);//必须传址

	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListDestory(&s);
}
void Test2()
{
	SeqList s;//定义结构体变量
	SeqListInit(&s);//必须传址

	SeqListPushBack(&s, 2);
	SeqListPrint(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListInsert(&s, 0, 30);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListModify(&s, 0, 100);
	SeqListPrint(&s);
	int pos = SeqListFind(&s, 4);
	printf("%d\n", pos);

	SeqListDestory(&s);
}
int main()
{
	Test2();
	return 0;
}