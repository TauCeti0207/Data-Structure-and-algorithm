
#include "circular_queue.h"

void test_circular_queue()
{
	int k = 5;
	// 创建循环队列
	MyCircularQueue *obj = myCircularQueueCreate(k);

	// 测试入队操作
	printf("Enqueue 1: %s\n", myCircularQueueEnQueue(obj, 1) ? "Success" : "Failed");
	printf("Enqueue 2: %s\n", myCircularQueueEnQueue(obj, 2) ? "Success" : "Failed");
	printf("Enqueue 3: %s\n", myCircularQueueEnQueue(obj, 3) ? "Success" : "Failed");

	// 测试队首和队尾元素
	printf("Front element: %d\n", myCircularQueueFront(obj));
	printf("Rear element: %d\n", myCircularQueueRear(obj));

	// 测试队列是否为空和已满
	printf("Is empty: %s\n", myCircularQueueIsEmpty(obj) ? "Yes" : "No");
	printf("Is full: %s\n", myCircularQueueIsFull(obj) ? "Yes" : "No");

	// 测试出队操作
	printf("Dequeue: %s\n", myCircularQueueDeQueue(obj) ? "Success" : "Failed");
	printf("Front element after dequeue: %d\n", myCircularQueueFront(obj));

	// 继续入队直到队列满
	printf("Enqueue 4: %s\n", myCircularQueueEnQueue(obj, 4) ? "Success" : "Failed");
	printf("Enqueue 5: %s\n", myCircularQueueEnQueue(obj, 5) ? "Success" : "Failed");
	printf("Enqueue 6: %s\n", myCircularQueueEnQueue(obj, 6) ? "Success" : "Failed");

	// 再次测试队列是否已满
	printf("Is full: %s\n", myCircularQueueIsFull(obj) ? "Yes" : "No");

	// 释放循环队列的内存
	myCircularQueueFree(obj);
}
int main()
{

	test_circular_queue();
	return 0;
}