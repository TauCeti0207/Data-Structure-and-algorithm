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
// void SListPopFront(SListNode **ppList)
// {
//     // 1.没有节点
//     if (*ppList == NULL)
//     {
//         return;
//     }
//     // 2.单个节点
//     // 3.多个节点
//     //先写多个节点的情况，再去比较单个节点能否适用，发现恰好可以匹配。
//     //保存plist->next，如果直接free plist就找不到后面的空间了
//     SListNode *next = (*ppList)->next;
//     free(*ppList);//这里只是释放了*ppList指向的那块空间内容，但*ppList还是指向那块空间的。
//     *ppList = next;
// }

void SListPopFront(SListNode *&pList)
{
    // 1.没有节点
    if (pList == NULL)
    {
        return;
    }
    // 2.单个节点
    // 3.多个节点
    //先写多个节点的情况，再去比较单个节点能否适用，发现恰好可以匹配。
    //保存plist->next，如果直接free plist就找不到后面的空间了
    SListNode *next = pList->next;
    free(pList); //这里只是释放了*ppList指向的那块空间内容，但*ppList还是指向那块空间的。
    pList = next;
}

//单链表查找
SListNode *SListFind(SListNode *plist, SListDataType x)
{
    SListNode *cur = plist;
    // while(cur != NULL)
    while (cur)
    {
        if (cur->data == x)
        {
            return cur;
            //查找兼具修改的作用
        }
        cur = cur->next;
    }
    return NULL;
}

// //在pos后面插入
// void SListInserAfter(SListNode *pos, SListDataType x)
// {
//     assert(pos);
//     SListNode *newNode = CreateNewNode(x);
//     //注意顺序不要反了
//     newNode->next = pos->next;
//     pos->next = newNode;
// }

//或者临时保存 pos->next
//在pos后面插入
void SListInserAfter(SListNode *pos, SListDataType x)
{
    assert(pos);
    SListNode *newNode = CreateNewNode(x);
    SListNode *next = pos->next; //这样就无需关心顺序问题了
    pos->next = newNode;
    newNode->next = next;
}

// void SListInserBefore(SListNode** ppList, SListNode* pos, SListDataType x)
// {
//     assert(pos);
//     SListNode* newNode = CreateNewNode(x);
//     if(*ppList == pos)//相当于头插
//     {
//         newNode->next = pos;
//         *ppList = newNode;
//     }
//     else
//     {
//         SListNode* prev = NULL;
//         SListNode* cur = *ppList;
//         while (cur != pos)
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//         prev->next = newNode;
//         newNode->next = cur;
//     }
// }

void SListInserBefore(SListNode *&pList, SListNode *pos, SListDataType x)
{
    assert(pos);
    SListNode *newNode = CreateNewNode(x);
    if (pList == pos) //相当于头插
    {
        newNode->next = pos;
        pList = newNode;
    }
    else
    {
        SListNode *prev = NULL;
        SListNode *cur = pList;
        while (cur != pos)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = newNode;
        newNode->next = cur;
    }
}

void SListEraseAfter(SListNode *pos)
{
    assert(pos);
    //只有一个节点的情况
    if (pos->next == NULL)
    {
        return;
    }
    else
    {
        SListNode *next = pos->next;
        pos->next = next->next;
        free(next);
        next = NULL;
    }
}

// void SListEraseCur(SListNode** ppList, SListNode* pos)
// {
//     //pos指向第一个节点，相当于头删
//     if(pos == *ppList)
//     {
//         SListNode* next = (*ppList)->next;
//         free(*ppList);
//         *ppList = next;
//     }
//     else
//     {
//         SListNode* prev = NULL;
//         SListNode* cur = *ppList;
//         while (cur != pos)
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//         //出来时cur指向的pos，prev指向pos前一个
//         prev->next = cur->next;
//         free(cur);
//         cur = NULL;
//     }
// }

void SListEraseCur(SListNode *&pList, SListNode *pos)
{
    // pos指向第一个节点，相当于头删
    if (pos == pList)
    {
        SListNode *next = pList->next;
        free(pList);
        pList = next;
    }
    else
    {
        SListNode *prev = NULL;
        SListNode *cur = pList;
        while (cur != pos)
        {
            prev = cur;
            cur = cur->next;
        }
        //出来时cur指向的pos，prev指向pos前一个
        prev->next = cur->next;
        free(cur);
        cur = NULL;
    }
}