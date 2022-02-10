#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);