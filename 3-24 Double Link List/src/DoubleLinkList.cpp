#include "DoubleLinkList.h"
ListNode *CreatListNode(LTDataType x)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL)
    {
        printf("CreatListNode Fail\n");
        exit(-1);
    }
    node->data = x;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
void ListInit2(ListNode *&pHead)
{
    //Ҫ�޸��ڱ�λͷ��㣬��˴�����ָ����ߴ�����
    assert(pHead);
    pHead = CreatListNode(0);
    pHead->next = pHead;
    pHead->prev = pHead;
}
ListNode *ListInit()
{
    ListNode *pHead = CreatListNode(0); //����һ��ֵ����
    //ָ���Լ�����������һ���ڵ�
    pHead->next = pHead;
    pHead->prev = pHead;
    return pHead;
}
void ListPushBack(ListNode *pHead, LTDataType x)
{
    assert(pHead);
    ListNode *tail = pHead->prev;
    ListNode *newNode = CreatListNode(x);
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = pHead;
    pHead->prev = newNode;
}

void ListPrint(ListNode *pHead)
{
    assert(pHead);
    ListNode *cur = pHead->next;
    printf("Head ");
    // cur�ߵ�pHeadʱ�ͽ���
    while (cur != pHead)
    {
        printf("<-> %d ", cur->data);
        cur = cur->next;
    }
    printf("<-> Head\n");
}

void ListPopBack(ListNode *pHead)
{
    assert(pHead);
    assert(pHead != pHead->next); //ֻ��һ��ͷ���ʱ�޷�ɾ��
    //��β���͵����ڶ������
    ListNode *tail = pHead->prev;
    ListNode *tailPrev = tail->prev;
    free(tail);
    tail = NULL;
    tailPrev->next = pHead;
    pHead->prev = tailPrev;
}

ListNode *ListFind(ListNode *pHead, LTDataType x)
{
    assert(pHead);
    ListNode *cur = pHead->next;
    while (cur != pHead)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//��pos֮ǰ����
void LIstInsert(ListNode *pos, LTDataType x)
{
    assert(pos);
    ListNode *newNode = CreatListNode(x);
    // prev newNode pos
    // ����pos��prev��nextָ��newNode
    // ����newNode��prevָ��pos��prev
    pos->prev->next = newNode;
    newNode->prev = pos->prev;
    newNode->next = pos;
    pos->prev = newNode;
}

//��pos֮ǰ����
void LIstInsert2(ListNode *pos, LTDataType x)
{
    assert(pos);
    //��ǰ����pos��ǰһ��λ��
    ListNode *posPrev = pos->prev;
    ListNode *newNode = CreatListNode(x);
    // posPrev newNode pos
    posPrev->next = newNode;
    newNode->prev = posPrev;
    newNode->next = pos;
    pos->prev = newNode;
}

void ListPushFront(ListNode *pHead, LTDataType x)
{
    assert(pHead);
    //��ǰ����pHead����һ���ڵ�ȽϷ���
    ListNode *first = pHead->next;
    ListNode *newNode = CreatListNode(x);
    // pHead newNode first
    // ��pHead��nextָ��newNode��newNode��prevָ��pHead
    // newNode��nextָ��first��first��prevָ��newNode
    pHead->next = newNode;
    newNode->prev = pHead;
    newNode->next = first;
    first->prev = newNode;
}

void ListPopFront(ListNode *pHead)
{
    assert(pHead);
    assert(pHead != pHead->next); //ֻ��һ��ͷ�ڵ�û��ɾ
    //��ǰ�����Ҫɾ���Ľڵ�
    ListNode *toDelete = pHead->next;
    ListNode *first = toDelete->next;
    // pHead toDelete first
    free(toDelete);
    toDelete = NULL;
    //ɾ��ֻʣͷ�ڵ�ʱ�������Լ�ָ���Լ�
    pHead->next = first;
    first->prev = pHead;
}