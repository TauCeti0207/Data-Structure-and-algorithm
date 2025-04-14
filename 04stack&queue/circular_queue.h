#pragma once

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// 定义循环队列结构体
typedef struct
{
	int *arr;
	int k; // 队列最多能存储的数据个数
	int front;
	int rear;
} MyCircularQueue;

// 创建循环队列
MyCircularQueue *myCircularQueueCreate(int k);

// 判断队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue *obj);

// 判断队列是否已满
bool myCircularQueueIsFull(MyCircularQueue *obj);

// 入队操作
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value);

// 出队操作
bool myCircularQueueDeQueue(MyCircularQueue *obj);

// 获取队首元素
int myCircularQueueFront(MyCircularQueue *obj);

// 获取队尾元素
int myCircularQueueRear(MyCircularQueue *obj);

// 释放循环队列的内存
void myCircularQueueFree(MyCircularQueue *obj);