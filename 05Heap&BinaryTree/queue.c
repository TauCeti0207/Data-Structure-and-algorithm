/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-11 16:33:33
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-03-11 16:56:24
 */
#include "queue.h"

// pq表示pointer queue
void QueueInit(Queue *pq)
{
	assert(pq != NULL);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue *pq)
{
	assert(pq != NULL);
	QueueNode *cur = pq->head;
	while (cur != NULL)
	{
		QueueNode *next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueuePush(Queue *pq, QDataType x)
{
	assert(pq != NULL);
	QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("malloc failed");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->tail == NULL) // 第一次插入
	{
		assert(pq->head == NULL); // 两者要么同时为空，要么同时不为空
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
	pq->size++;
}
void QueuePop(Queue *pq)
{
	assert(pq != NULL);
	assert(!QueueEmpty(pq)); // 队列为空不能出队
	// 只有一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode *next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}
// 取队头数据
QDataType QueueFront(Queue *pq)
{
	assert(pq != NULL);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
// 取队尾数据
QDataType QueueBack(Queue *pq)
{
	assert(pq != NULL);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
bool QueueEmpty(Queue *pq)
{
	assert(pq != NULL);
	return pq->head == NULL && pq->tail == NULL;
}
size_t QueueSize(Queue *pq)
{
	assert(pq != NULL);
	return pq->size;
}