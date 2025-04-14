/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-04-06 00:31:12
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-04-07 10:08:44
 */
#include "queue.h"

void Test1()
{
	Queue q;
	QueueInit(&q); // 要改变结构体内容，要传结构体指针
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("size = %zu\n", QueueSize(&q));
	// 1 2 3 4
	while (!QueueEmpty(&q))
	{
		// 只能出队头
		printf("%d ", QueueFront(&q));
		QueuePop(&q); // pop掉之后才能取下一个
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	Test1();
	return 0;
}
