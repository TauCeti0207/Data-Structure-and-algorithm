#include "circular_queue.h"

MyCircularQueue *myCircularQueueCreate(int k)
{
	MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	assert(obj);
	obj->arr = (int *)malloc(sizeof(int) * (k + 1));
	assert(obj->arr);
	obj->front = obj->rear = 0;
	obj->k = k;
	return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
	assert(obj);
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
	assert(obj);
	// rear+1 % k+1 == front 满 k+1是实际的空间大小
	// 考虑rear溢出
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
	assert(obj);
	if (myCircularQueueIsFull(obj))
		return false;
	// 没满，继续插入
	obj->arr[obj->rear] = value;
	obj->rear++;
	// 考虑溢出
	obj->rear %= (obj->k + 1);
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
		return false;
	// 不为空才能删
	obj->front++;
	obj->front %= obj->k + 1;
	return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
		return -1;
	// 考虑rear=0时
	return obj->arr[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
	// if(obj->rear == 0)  //这样分情况也可以
	//     return obj->arr[obj->k];
	// else
	//     return obj->a[obj->rear-1];
}

void myCircularQueueFree(MyCircularQueue *obj)
{
	assert(obj);
	free(obj->arr);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/