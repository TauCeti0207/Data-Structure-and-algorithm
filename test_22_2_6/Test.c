#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void Test() {
	struct SListNode* node1 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node2 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node3 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node4 = (struct SListNode*)malloc(sizeof(struct SListNode));

	printf("%p\n", node1);
	printf("%p\n", node2);
	printf("%p\n", node3);
	printf("%p\n", node4);
}
void Test2() {
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}
void Test3() {
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
}

void Test4() {
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos != NULL) {
		//兼具修改的作用
		pos->data = 30;
		printf("找到了,并修改了\n");
	}
	else
	{
		printf("找不到\n");
	}
	SListPrint(plist);

}

void Test5() {
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SListInserAfter(pos, 30);
	SListPrint(plist);
	SListInserBefore(&plist, pos, 300);
	SListPrint(plist);

}
int main() {
	Test5();
	return 0;
}