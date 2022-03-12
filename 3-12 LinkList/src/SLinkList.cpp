#include "SLinkList.h"
void SListPrint(SListNode *pList)
{
    //不需要assert(plist)
    SListNode *cur = pList;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next; // cur->next里面存的就是下一个结点的地址
    }
    printf("NULL\n");
}
SListNode *CreateNewNode(SListDataType x)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode == NULL)
    {
        printf("malloc newNode fail\n");
        exit(-1);
    }
    else
    {
        newNode->data = x;
        newNode->next = NULL;
    }
    return newNode;
}
// void SListPushBack(SListNode **ppList, SListDataType x)
// {
//     //同样不需要断言空，因为本来就有可能传空链表
//     SListNode* newNode = CreateNewNode(x);
//     //1.空链表
//     if(*ppList == NULL)
//     {
//         *ppList = newNode;//也就是把newNode的地址覆盖掉pList原来的NULL地址
//         //传进来空链表,要修改plist必须传址调用
//     }
//     //2.正常链表，去找尾
//     else
//     {
//         SListNode* tail = *ppList;//不能直接修改plist，plist一改就找不到链表了
//         while (tail->next != NULL)
//         {
//             tail = tail->next;
//         }
//         //出来时tail->next 指向的是NULL
//         tail->next = newNode;
//     }
// }

void SListPushBack(SListNode *&pList, SListDataType x)
{
    //同样不需要断言空，因为本来就有可能传空链表
    SListNode *newNode = CreateNewNode(x);
    // 1.空链表
    if (pList == NULL)
    {
        pList = newNode; //也就是把newNode的地址覆盖掉pList原来的NULL地址
        //传进来空链表,要修改plist必须传址调用
    }
    // 2.正常链表，去找尾
    else
    {
        SListNode *tail = pList; //不能直接修改plist，plist一改就找不到链表了
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        //出来时tail->next 指向的是NULL
        tail->next = newNode;
    }
}

void SListPushFront(SListNode *&pList, SListDataType x)
{
    //即使传进来的是NULL也能解决
    SListNode *newNode = CreateNewNode(x);
    newNode->next = pList; // pList指向的就是第一个节点，其实存的也就是第一个节点的地址
    pList = newNode;
}

// void SListPopBack(SListNode** ppList)
// {
//     //1.没有节点，无法删除，直接return
//     if(*ppList == NULL)
//     {
//         return;
//     }
//     //2.单个节点
//     else if((*ppList)->next == NULL)
//     {
//         free(*ppList);
//         *ppList = NULL;
//     }
//     //3.多个节点
//     else
//     {
//         SListNode* prev = NULL;
//         SListNode* tail = *ppList;
//         while (tail->next != NULL)
//         {
//             prev = tail;
//             tail = tail->next;
//         }
//         free(tail);
//         tail = NULL;
//         prev->next = NULL;//尾删时要将最后一个结点的上一个结点的next置为NULL才行
//     }
// }

void SListPopBack(SListNode *&pList)
{
    // 1.没有节点，无法删除，直接return
    if (pList == NULL)
    {
        return;
    }
    // 2.单个节点
    else if ((pList)->next == NULL)
    {
        free(pList);
        pList = NULL;
    }
    // 3.多个节点
    else
    {
        SListNode *prev = NULL;
        SListNode *tail = pList;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL; //尾删时要将最后一个结点的上一个结点的next置为NULL才行
    }
}
void SListPopFront(SListNode **ppList)
{
    // 1.没有节点
    if (*ppList == NULL)
    {
        return;
    }
    // 2.单个节点
    // 3.多个节点
    //恰好适用一个节点和多个节点的情况
    //保存plist->next,如果直接free plist就找不到后面的空间了
    SListNode *next = (*ppList)->next;
    free(*ppList);
    *ppList = next;
}