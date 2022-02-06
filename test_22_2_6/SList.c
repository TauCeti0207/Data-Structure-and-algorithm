#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListPrint(SLTNode* plist) {
	SLTNode* cur = plist;
	while (cur != NULL){
		printf("%d->", cur->data); 
		cur = cur->next;//cur->next里面存的就是下一个结点的地址
	}
	printf("NULL\n");
}


//创建结点
SLTNode* BuySLTNode(SLTDataType x) {
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	//开辟失败
	if (node == NULL) {
		printf("BuySLTNode Failed");
		return;
	}
	node->data = x;
	node->next = NULL;
	return node;
}

//传址调用才行,二级指针
void SListPushBack(SLTNode** pplist, SLTDataType x) {
	SLTNode* newnode = BuySLTNode(x);
	//考虑空链表的情况
	if (*pplist == NULL) {
		*pplist = newnode;
	}
	else {
		//找尾插地址
		SLTNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//出来时tail->next 指向的是NULL
		tail->next = newnode;
	}
}


void SListPushFront(SLTNode** pplist, SLTDataType x) {
	//即使传进来的是NULL也能解决
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;//*pplist 其实就是plist
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist) {
	//1.没有节点
	//2.一个节点
	//3.多个节点
	if (*pplist == NULL) {
		return;
	}
	else if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;//这样就达到了删除一个节点的目的
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;//尾删时要将最后一个结点的上一个结点的next置为NULL才行
	}
}