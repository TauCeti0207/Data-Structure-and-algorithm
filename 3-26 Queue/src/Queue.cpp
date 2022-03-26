#include "Queue.h"

void QueueInit(Queue *pq)
{
    // 队列可以为空，但结构体指针不能为空
    assert(pq);
    pq->head = pq->tail = NULL;
}
void QueueDestroy(Queue *pq)
{
    assert(pq);
    QueueNode *cur = pq->head;
    while (cur)
    {
        QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    assert(newNode); // 暴力检查开辟失败的情况
    newNode->data = x;
    newNode->next = NULL;
    // 考虑队列为空的情况插入
    if (pq->tail == NULL)
    {
        assert(pq->head == NULL); //
        pq->head = pq->tail = newNode;
    }
    else
    {
        pq->tail->next = newNode;
        // 注意更新tail
        pq->tail = newNode;
    }
}
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(pq->head && pq->tail); // 头尾不能为空
    //考虑删到只剩一个节点的情况，尾和头都要置空
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
}
//取队头数据
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}
//取队尾数据
QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}
bool QueueEmpty(Queue *pq)
{
    assert(pq);
    return pq->head == NULL && pq->tail == NULL;
    // return pq->head == NULL; // 只判断一个也行
}
size_t QueueSize(Queue *pq)
{
    assert(pq);
    QueueNode* cur = pq->head;
    size_t size = 0;
    while (cur)
    {
        ++size;
        cur = cur->next;
    }
    return size;
    // size每次计算都要遍历一遍链表。
    // 如果不想遍历，可以在结构体定义时增加一个size计数，每次插入++size，每次删除--size
}