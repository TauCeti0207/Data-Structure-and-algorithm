#include "SLinkList.h"
void Test1()
{
    SListNode *sList = NULL;
    SListPrint(sList); // NULL
}
void Test2()
{
    SListNode *sList = NULL; //空链表
    // SListPushBack(&sList, 1);
    // SListPushBack(&sList, 2);
    // SListPushBack(&sList, 3);
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    SListPrint(sList);

    // SListPushFront(&sList, 2);
    // SListPushFront(&sList, 3);
    SListPushFront(sList, 1);
    SListPushFront(sList, 2);
    SListPushFront(sList, 3);
    SListPrint(sList);
}
void Test3()
{
    SListNode *sList = NULL; //空链表
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    // SListPrint(sList);
    // SListPopBack(&sList);
    // SListPrint(sList);
    SListPrint(sList);
    SListPopBack(sList);
    SListPrint(sList);
    // SListPopFront(&sList);
    SListPopFront(sList);
    SListPrint(sList);
}
void Test4()
{
    SListNode *sList = NULL; //空链表
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    SListPrint(sList);
    SListPopFront(sList);
    SListPrint(sList);
    SListPopFront(sList);
    SListPrint(sList);
    SListPopFront(sList);
    SListPrint(sList);
    SListPopFront(sList);
    SListPrint(sList);
}
void Test5()
{
    SListNode *sList = NULL; //空链表
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    SListPrint(sList);
    SListNode *pos = SListFind(sList, 3);
    if (pos)
    {
        pos->data = 30;
        printf("找到了并修改为30\n");
    }
    else
    {
        printf("找不到\n");
    }
    SListPrint(sList);
}
void Test6()
{
    SListNode *sList = NULL; //空链表
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    SListPrint(sList);
    SListNode *pos = SListFind(sList, 2);
    SListInserAfter(pos, 10);
    SListPrint(sList);

    // SListInserBefore(&sList, pos, 20);
    // SListPrint(sList);
    // SListNode *pos2 = SListFind(sList, 1);
    // SListInserBefore(&sList, pos2, 100);
    // SListPrint(sList);

    SListInserBefore(sList, pos, 20);
    SListPrint(sList);
    SListNode *pos2 = SListFind(sList, 1);
    SListInserBefore(sList, pos2, 1000);
    SListPrint(sList);

    SListNode *pos3 = SListFind(sList, 1000);
    SListEraseAfter(pos3);
    SListPrint(sList);
}

void Test7()
{
    SListNode *sList = NULL; //空链表
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    SListPrint(sList);
    // SListNode *pos1 = SListFind(sList, 2);
    // SListEraseCur(&sList, pos1);
    // SListPrint(sList);
    // SListNode *pos2 = SListFind(sList, 1);
    // SListEraseCur(&sList, pos2);
    // SListPrint(sList);
    SListNode *pos1 = SListFind(sList, 2);
    SListEraseCur(sList, pos1);
    SListPrint(sList);
    SListNode *pos2 = SListFind(sList, 3);
    SListEraseCur(sList, pos2);
    SListPrint(sList);
}
int main(int argc, char const *argv[])
{
    Test7();
    system("pause");
    return 0;
}

