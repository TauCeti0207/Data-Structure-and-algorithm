#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"
void Test()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	//栈不支持print接口,因为只能后进先出
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		//只能出队头
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}
int main()
{
	TestQueue();
	return 0;
}