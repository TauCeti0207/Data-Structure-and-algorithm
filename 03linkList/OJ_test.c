#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct ListNode
{
	int val;
	struct ListNode *next;
};

// 反转链表的函数
struct ListNode *reverseList(struct ListNode *head)
{
	// 空链表或只有一个节点
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *n1 = NULL, *n2 = head, *n3 = head->next;

	// n2 走到尾节点就结束，此时 n3 是 NULL
	while (n3 != NULL)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		n3 = n3->next;
	}
	// 处理最后一个节点
	n2->next = n1;
	return n2;
}

// 创建链表的辅助函数
struct ListNode *createList(int arr[], int size)
{
	if (size == 0)
		return NULL;
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = arr[0];
	head->next = NULL;
	struct ListNode *current = head;
	for (int i = 1; i < size; i++)
	{
		struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->val = arr[i];
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}
	return head;
}

// 打印链表的辅助函数
void printList(struct ListNode *head)
{
	struct ListNode *current = head;
	while (current != NULL)
	{
		printf("%d -> ", current->val);
		current = current->next;
	}
	printf("NULL\n");
}

// 释放链表内存的辅助函数
void freeList(struct ListNode *head)
{
	struct ListNode *current = head;
	struct ListNode *next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	// 测试用例数组
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	// 创建链表
	struct ListNode *head = createList(arr, size);

	// 打印原始链表
	printf("Original list: ");
	printList(head);

	// 反转链表
	struct ListNode *reversedHead = reverseList(head);

	// 打印反转后的链表
	printf("Reversed list: ");
	printList(reversedHead);

	// 释放链表内存
	freeList(reversedHead);

	return 0;
}