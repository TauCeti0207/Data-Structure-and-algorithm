#include "SLinkList.h"
void SListPrint(SListNode *pList)
{
    //����Ҫassert(plist)
    SListNode *cur = pList;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next; // cur->next�����ľ�����һ�����ĵ�ַ
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
//     //ͬ������Ҫ���Կգ���Ϊ�������п��ܴ�������
//     SListNode* newNode = CreateNewNode(x);
//     //1.������
//     if(*ppList == NULL)
//     {
//         *ppList = newNode;//Ҳ���ǰ�newNode�ĵ�ַ���ǵ�pListԭ����NULL��ַ
//         //������������,Ҫ�޸�plist���봫ַ����
//     }
//     //2.����������ȥ��β
//     else
//     {
//         SListNode* tail = *ppList;//����ֱ���޸�plist��plistһ�ľ��Ҳ���������
//         while (tail->next != NULL)
//         {
//             tail = tail->next;
//         }
//         //����ʱtail->next ָ�����NULL
//         tail->next = newNode;
//     }
// }

void SListPushBack(SListNode *&pList, SListDataType x)
{
    //ͬ������Ҫ���Կգ���Ϊ�������п��ܴ�������
    SListNode *newNode = CreateNewNode(x);
    // 1.������
    if (pList == NULL)
    {
        pList = newNode; //Ҳ���ǰ�newNode�ĵ�ַ���ǵ�pListԭ����NULL��ַ
        //������������,Ҫ�޸�plist���봫ַ����
    }
    // 2.����������ȥ��β
    else
    {
        SListNode *tail = pList; //����ֱ���޸�plist��plistһ�ľ��Ҳ���������
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        //����ʱtail->next ָ�����NULL
        tail->next = newNode;
    }
}

void SListPushFront(SListNode *&pList, SListDataType x)
{
    //��ʹ����������NULLҲ�ܽ��
    SListNode *newNode = CreateNewNode(x);
    newNode->next = pList; // pListָ��ľ��ǵ�һ���ڵ㣬��ʵ���Ҳ���ǵ�һ���ڵ�ĵ�ַ
    pList = newNode;
}

// void SListPopBack(SListNode** ppList)
// {
//     //1.û�нڵ㣬�޷�ɾ����ֱ��return
//     if(*ppList == NULL)
//     {
//         return;
//     }
//     //2.�����ڵ�
//     else if((*ppList)->next == NULL)
//     {
//         free(*ppList);
//         *ppList = NULL;
//     }
//     //3.����ڵ�
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
//         prev->next = NULL;//βɾʱҪ�����һ��������һ������next��ΪNULL����
//     }
// }

void SListPopBack(SListNode *&pList)
{
    // 1.û�нڵ㣬�޷�ɾ����ֱ��return
    if (pList == NULL)
    {
        return;
    }
    // 2.�����ڵ�
    else if ((pList)->next == NULL)
    {
        free(pList);
        pList = NULL;
    }
    // 3.����ڵ�
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
        prev->next = NULL; //βɾʱҪ�����һ��������һ������next��ΪNULL����
    }
}
// void SListPopFront(SListNode **ppList)
// {
//     // 1.û�нڵ�
//     if (*ppList == NULL)
//     {
//         return;
//     }
//     // 2.�����ڵ�
//     // 3.����ڵ�
//     //��д����ڵ���������ȥ�Ƚϵ����ڵ��ܷ����ã�����ǡ�ÿ���ƥ�䡣
//     //����plist->next�����ֱ��free plist���Ҳ�������Ŀռ���
//     SListNode *next = (*ppList)->next;
//     free(*ppList);//����ֻ���ͷ���*ppListָ����ǿ�ռ����ݣ���*ppList����ָ���ǿ�ռ�ġ�
//     *ppList = next;
// }

void SListPopFront(SListNode *&pList)
{
    // 1.û�нڵ�
    if (pList == NULL)
    {
        return;
    }
    // 2.�����ڵ�
    // 3.����ڵ�
    //��д����ڵ���������ȥ�Ƚϵ����ڵ��ܷ����ã�����ǡ�ÿ���ƥ�䡣
    //����plist->next�����ֱ��free plist���Ҳ�������Ŀռ���
    SListNode *next = pList->next;
    free(pList); //����ֻ���ͷ���*ppListָ����ǿ�ռ����ݣ���*ppList����ָ���ǿ�ռ�ġ�
    pList = next;
}

//����������
SListNode *SListFind(SListNode *plist, SListDataType x)
{
    SListNode *cur = plist;
    // while(cur != NULL)
    while (cur)
    {
        if (cur->data == x)
        {
            return cur;
            //���Ҽ���޸ĵ�����
        }
        cur = cur->next;
    }
    return NULL;
}

// //��pos�������
// void SListInserAfter(SListNode *pos, SListDataType x)
// {
//     assert(pos);
//     SListNode *newNode = CreateNewNode(x);
//     //ע��˳��Ҫ����
//     newNode->next = pos->next;
//     pos->next = newNode;
// }

//������ʱ���� pos->next
//��pos�������
void SListInserAfter(SListNode *pos, SListDataType x)
{
    assert(pos);
    SListNode *newNode = CreateNewNode(x);
    SListNode *next = pos->next; //�������������˳��������
    pos->next = newNode;
    newNode->next = next;
}

// void SListInserBefore(SListNode** ppList, SListNode* pos, SListDataType x)
// {
//     assert(pos);
//     SListNode* newNode = CreateNewNode(x);
//     if(*ppList == pos)//�൱��ͷ��
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
    if (pList == pos) //�൱��ͷ��
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
    //ֻ��һ���ڵ�����
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
//     //posָ���һ���ڵ㣬�൱��ͷɾ
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
//         //����ʱcurָ���pos��prevָ��posǰһ��
//         prev->next = cur->next;
//         free(cur);
//         cur = NULL;
//     }
// }

void SListEraseCur(SListNode *&pList, SListNode *pos)
{
    // posָ���һ���ڵ㣬�൱��ͷɾ
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
        //����ʱcurָ���pos��prevָ��posǰһ��
        prev->next = cur->next;
        free(cur);
        cur = NULL;
    }
}