#include "Queue.h"

void QueueInit(Queue *pq)
{
    // ���п���Ϊ�գ����ṹ��ָ�벻��Ϊ��
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
    assert(newNode); // ������鿪��ʧ�ܵ����
    newNode->data = x;
    newNode->next = NULL;
    // ���Ƕ���Ϊ�յ��������
    if (pq->tail == NULL)
    {
        assert(pq->head == NULL); //
        pq->head = pq->tail = newNode;
    }
    else
    {
        pq->tail->next = newNode;
        // ע�����tail
        pq->tail = newNode;
    }
}
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(pq->head && pq->tail); // ͷβ����Ϊ��
    //����ɾ��ֻʣһ���ڵ�������β��ͷ��Ҫ�ÿ�
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
//ȡ��ͷ����
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}
//ȡ��β����
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
    // return pq->head == NULL; // ֻ�ж�һ��Ҳ��
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
    // sizeÿ�μ��㶼Ҫ����һ��������
    // �����������������ڽṹ�嶨��ʱ����һ��size������ÿ�β���++size��ÿ��ɾ��--size
}