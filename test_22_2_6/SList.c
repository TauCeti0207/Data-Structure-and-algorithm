#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListPrint(SLTNode* plist) {
	SLTNode* cur = plist;
	while (cur != NULL){
		printf("%d->", cur->data); 
		cur = cur->next;//cur->next�����ľ�����һ�����ĵ�ַ
	}
	printf("NULL\n");
}


//�������
SLTNode* BuySLTNode(SLTDataType x) {
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	//����ʧ��
	if (node == NULL) {
		printf("BuySLTNode Failed");
		return;
	}
	node->data = x;
	node->next = NULL;
	return node;
}

//��ַ���ò���,����ָ��
void SListPushBack(SLTNode** pplist, SLTDataType x) {
	SLTNode* newnode = BuySLTNode(x);
	//���ǿ����������
	if (*pplist == NULL) {
		*pplist = newnode;
	}
	else {
		//��β���ַ
		SLTNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//����ʱtail->next ָ�����NULL
		tail->next = newnode;
	}
}


void SListPushFront(SLTNode** pplist, SLTDataType x) {
	//��ʹ����������NULLҲ�ܽ��
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;//*pplist ��ʵ����plist
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist) {
	//1.û�нڵ�
	//2.һ���ڵ�
	//3.����ڵ�
	if (*pplist == NULL) {
		return;
	}
	else if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;//�����ʹﵽ��ɾ��һ���ڵ��Ŀ��
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
		prev->next = NULL;//βɾʱҪ�����һ��������һ������next��ΪNULL����
	}
}