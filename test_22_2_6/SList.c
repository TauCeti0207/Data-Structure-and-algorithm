<<<<<<< HEAD
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

void SListPopFront(SLTNode** pplist) {
	//1.没有节点
	//2.一个节点
	//3.多个节点
	if (*pplist == NULL) {
		return;
	}
	else {
		//恰好适用一个节点和多个节点的情况
		//保存plist->next,如果直接free plist就找不到后面的空间了
		SLTNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;//因为要修改plist必须传址调用
	}
}


//单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x) {
	SLTNode* cur = plist;
	//while(cur != NULL)
	while (cur) {
		if (cur->data == x) {
			return cur;
			//查找兼具修改的作用
		}
		cur = cur->next;
	}
	return NULL;
}


//在pos后面插入
void SListInserAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	//注意顺序不要反了
	newnode->next = pos->next;
	pos->next = newnode;
}

//反了需要将pos->nxet提前保存起来
//在pos后面插入
/* void SListInserAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	SLTNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
*/



//在pos之前插入
void SListInserBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	//如果pos在第一个呢?
	if (pos == *pplist) {//相当于头插
		newnode->next = pos;
		*pplist = newnode;
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos) {
			prev = cur;
			cur = cur->next;
		}
		//避免prev为空
		if (prev == NULL) {
			return;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}


//在pos之后擦除
void SListEraseAfter(SLTNode* pos) {
	assert(pos);
	//pos之后无节点
	if (pos->next == NULL) {
		return;
	}
	else {
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
=======
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

void SListPopFront(SLTNode** pplist) {
	//1.没有节点
	//2.一个节点
	//3.多个节点
	if (*pplist == NULL) {
		return;
	}
	else {
		//恰好适用一个节点和多个节点的情况
		//保存plist->next,如果直接free plist就找不到后面的空间了
		SLTNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;//因为要修改plist必须传址调用
	}
}


//单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x) {
	SLTNode* cur = plist;
	//while(cur != NULL)
	while (cur) {
		if (cur->data == x) {
			return cur;
			//查找兼具修改的作用
		}
		cur = cur->next;
	}
	return NULL;
}


//在pos后面插入
void SListInserAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	//注意顺序不要反了
	newnode->next = pos->next;
	pos->next = newnode;
}

//反了需要将pos->nxet提前保存起来
//在pos后面插入
/* void SListInserAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	SLTNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
*/



//在pos之前插入
void SListInserBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	//如果pos在第一个呢?
	if (pos == *pplist) {//相当于头插
		newnode->next = pos;
		*pplist = newnode;
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos) {
			prev = cur;
			cur = cur->next;
		}
		//避免prev为空
		if (prev == NULL) {
			return;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}


//在pos之后擦除
void SListEraseAfter(SLTNode* pos) {
	assert(pos);
	//pos之后无节点
	if (pos->next == NULL) {
		return;
	}
	else {
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
>>>>>>> 49a0505b11c1299d916b87fd976d64f96eafa62a
}