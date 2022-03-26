#include "DoubleLinkList.h"
void Test1()
{
    ListNode *pList = ListInit();
    ListPushBack(pList, 1);
    ListPushBack(pList, 2);
    ListPushBack(pList, 3);
    ListPushBack(pList, 4);
    ListPrint(pList);
}
void Test2()
{
    ListNode *pList;
    ListInit2(pList);
    ListPushBack(pList, 1);
    ListPushBack(pList, 2);
    ListPushBack(pList, 2);
    ListPushBack(pList, 4);
    ListPrint(pList);

    ListPopBack(pList);
    ListPrint(pList);
    ListPopBack(pList);
    ListPrint(pList);
    ListPopBack(pList);
    ListPrint(pList);
    ListPopBack(pList);
    ListPrint(pList);
}

void Test3()
{
    ListNode *pList = ListInit();
    ListPushBack(pList, 1);
    ListPushBack(pList, 2);
    ListPushBack(pList, 3);
    ListPushBack(pList, 4);
    ListPrint(pList);
    ListNode *pos = ListFind(pList, 3);
    if (pos)
    {
        LIstInsert(pos, 20);
    }
    ListPrint(pList);

    ListNode *pos2 = ListFind(pList, 4);
    if (pos2)
    {
        LIstInsert2(pos2, 40);
    }
    ListPrint(pList);
}

void Test4()
{
    ListNode *pList = ListInit();
    ListPushBack(pList, 1);
    ListPushBack(pList, 2);
    ListPushBack(pList, 3);
    ListPushBack(pList, 4);
    ListPrint(pList);
    ListPushFront(pList, 4);
    ListPushFront(pList, 3);
    ListPushFront(pList, 2);
    ListPushFront(pList, 1);
    ListPrint(pList);
    ListPopFront(pList);
    ListPopFront(pList);
    ListPrint(pList);
}
void Test5()
{
    ListNode *pList = ListInit();
    ListPushBack(pList, 1);
    ListPushBack(pList, 2);
    ListPushBack(pList, 3);
    ListPushBack(pList, 4);
    ListPrint(pList);
    ListNode *pos = ListFind(pList, 1);
    if (pos)
    {
        ListErase2(pos);
    }
    ListPrint(pList);
    printf("%d\n", ListSize(pList));
    printf("%d\n", ListIsEmpty(pList));
    ListDestroy(pList);
}
int main(int argc, char const *argv[])
{
    Test4();
    system("pause");
    return 0;
}
