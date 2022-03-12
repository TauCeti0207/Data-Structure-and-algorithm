#include "SLinkList.h"
void Test1()
{
    SListNode *sList = NULL;
    SListPrint(sList); // NULL
}
void Test2()
{
    SListNode *sList = NULL; //ø’¡¥±Ì
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
    SListNode *sList = NULL; //ø’¡¥±Ì
    SListPushBack(sList, 1);
    SListPushBack(sList, 2);
    SListPushBack(sList, 3);
    // SListPrint(sList);
    // SListPopBack(&sList);
    // SListPrint(sList);
    SListPrint(sList);
    SListPopBack(sList);
    SListPrint(sList);
}
int main(int argc, char const *argv[])
{
    Test3();
    system("pause");
    return 0;
}
