#include <iostream>

// 定义链表节点结构
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *partition(ListNode *pHead, int x)
{
	// 处理空链表的情况
	if (pHead == nullptr)
	{
		return nullptr;
	}

	// 创建两个虚拟头节点
	ListNode *list1 = new ListNode(0);
	ListNode *list2 = new ListNode(0);
	ListNode *cur = pHead;
	ListNode *list1Tail = list1; // 记录list1的尾节点
	ListNode *list2Tail = list2; // 记录list2的尾节点

	while (cur != nullptr)
	{
		ListNode *nextNode = cur->next; // 保存下一个节点
		if (cur->val < x)
		{
			list1Tail->next = cur;
			list1Tail = list1Tail->next;
			list1Tail->next = nullptr; // 断开原链表连接，防止成环 此时这里已经不能通过cur = cur->next;来移动cur了，因为cur->next已经被断开了
		}
		else
		{
			list2Tail->next = cur;
			list2Tail = list2Tail->next;
			list2Tail->next = nullptr; // 断开原链表连接，防止成环
		}
		cur = nextNode; // 移动到下一个节点
	}

	list1Tail->next = list2->next; // 链接两个链表
	ListNode *result = list1->next;

	// 释放虚拟头节点
	delete list1;
	delete list2;

	return result;
}

// 辅助函数：打印链表
void printList(ListNode *head)
{
	ListNode *cur = head;
	while (cur != nullptr)
	{
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

int main()
{
	// 创建测试链表: 1 -> 4 -> 3 -> 2 -> 5
	ListNode *head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = nullptr;

	int x = 3;
	ListNode *newHead = partition(head, x);
	printList(newHead);

	// 释放链表内存
	while (newHead != nullptr)
	{
		ListNode *temp = newHead;
		newHead = newHead->next;
		delete temp;
	}

	return 0;
}