#include "DoubleLinkList.h"
ListNode *CreatListNode(LTDataType x)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    assert(newNode); //暴力判空
    // if (node == NULL) //温柔判空
    // {
    //     printf("CreatListNode Fail\n");
    //     exit(-1);
    // }
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 2种初始化方式
//要修改哨兵位头结点，因此传二级指针或者传引用
void ListInit(ListNode *&pHead)
{
    assert(pHead);
    pHead = CreatListNode(0);
    //要指向自己
    pHead->next = pHead;
    pHead->prev = pHead;
}

ListNode *ListInit()
{
    ListNode *pHead = CreatListNode(0); //任意一个值都行
    //指向自己，方便插入第一个节点
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
    // cur走到pHead时就结束
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
    assert(pHead != pHead->next); //只有一个头结点时无法删除
    //找尾结点和倒数第二个结点
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

//在pos之前插入
void LIstInsert(ListNode *pos, LTDataType x)
{
    assert(pos);
    ListNode *newNode = CreatListNode(x);
    // prev newNode pos
    // 先让pos的prev的next指向newNode
    // 再让newNode的prev指向pos的prev
    pos->prev->next = newNode;
    newNode->prev = pos->prev;
    newNode->next = pos;
    pos->prev = newNode;
}

//在pos之前插入
void LIstInsert2(ListNode *pos, LTDataType x)
{
    assert(pos);
    //提前保存pos的前一个位置
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
    //提前保存pHead的下一个节点比较方便
    ListNode *first = pHead->next;
    ListNode *newNode = CreatListNode(x);
    // pHead newNode first
    // 让pHead的next指向newNode，newNode的prev指向pHead
    // newNode的next指向first，first的prev指向newNode
    pHead->next = newNode;
    newNode->prev = pHead;
    newNode->next = first;
    first->prev = newNode;
}

void ListPopFront(ListNode *pHead)
{
    assert(pHead);
    assert(pHead != pHead->next); //只有一个头节点没法删
    //提前保存好要删除的节点
    ListNode *toDelete = pHead->next;
    ListNode *first = toDelete->next;
    // pHead toDelete first
    free(toDelete);
    toDelete = NULL;
    //删到只剩头节点时，满足自己指向自己
    pHead->next = first;
    first->prev = pHead;
}

void ListErase2(ListNode *pos)
{
    assert(pos);
    // posPrev pos next
    ListNode *posPrev = pos->prev, *next = pos->next;
    free(pos);
    // pos = NULL; // 其实不起作用，需要在外面再手动置空
    //  让pos的prev指向next，next的prev指向pos的prev
    posPrev->next = next;
    next->prev = posPrev;
}

// void ListErase2(ListNode *pos)
// {
//     assert(pos);
//     //提前记录pos的prev
//     ListNode *posPrev = pos->prev;
//     ListNode *next = pos->next;
//     // posPrev pos next
//     //  让pos的prev指向next，next的prev指向pos的prev
//     posPrev->next = next;
//     next->prev = posPrev;
//     free(pos);
//     pos = NULL;
// }
void ListErase(ListNode *&pos)
{
    assert(pos);
    //提前记录pos的prev
    ListNode *posPrev = pos->prev;
    ListNode *next = pos->next;
    // posPrev pos next
    //  让pos的prev指向next，next的prev指向pos的prev
    posPrev->next = next;
    next->prev = posPrev;
    free(pos);
    pos = NULL;
}

int ListSize(ListNode *pHead)
{
    assert(pHead);
    ListNode *cur = pHead->next;
    int size = 0;
    while (cur != pHead)
    {
        ++size;
        cur = cur->next;
    }
    return size;
}

bool ListIsEmpty(ListNode *pHead)
{
    assert(pHead);
    return pHead->next == pHead ? true : false;
}

void ListDestroy2(ListNode *pHead)
{
    assert(pHead);
    ListNode *cur = pHead;
    while (cur != pHead)
    {
        ListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(pHead); //链表的摧毁是要连哨兵位都要摧毁的。
    // pHead = NULL; // 不起作用
}

//复用Erase，且传引用
// void ListDestroy(ListNode *&pHead)
// {
//     assert(pHead);
//     ListNode *cur = pHead;
//     while (cur != pHead)
//     {
//         ListNode *next = cur->next;
//         ListErase(cur);
//         cur = next;
//     }
//     free(pHead);
//     pHead = NULL;
// }

void ListDestroy(ListNode *&pHead)
{
    assert(pHead);
    ListNode *cur = pHead;
    while (cur != pHead)
    {
        ListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(pHead);
    pHead = NULL;
}