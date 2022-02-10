#define _CRT_SECURE_NO_WARNINGS 1
#include"DoubleList.h"


void Test()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);


	ListDestroy(plist);
	plist = NULL;

}

void Test2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 4);
	if (pos)
	{
		LIstInsert(pos, 40);
	}
	ListPrint(plist);


}
int main()
{
	Test();
	return 0;
}