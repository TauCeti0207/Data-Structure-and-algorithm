#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        //借助哨兵位
        struct ListNode* lessHead = NULL;
        struct ListNode* lessTail = NULL;
        struct ListNode* greaterHead = NULL;
        struct ListNode* greaterTail = NULL;

        //开辟哨兵位
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (lessTail == NULL)
        {
            return 0;
        }
        if (lessHead == NULL)
        {
            return 0;
        }
        if (greaterHead == NULL)
        {
            return 0;
        }
        if (greaterTail == NULL)
        {
            return 0;
        }
        lessTail->next = NULL;
        greaterTail->next = NULL;
        //把小于x的插到一个链表,大于x的插到一个链表
        while (pHead != NULL) {
            if (pHead->val < x) {
                lessTail->next = pHead;
                pHead = pHead->next;
                lessTail = lessTail->next;
            }
            else {
                greaterTail->next = pHead;
                pHead = pHead->next;
                greaterTail = greaterTail->next;
            }
        }

        //链接2个链表
        lessTail->next = greaterHead->next;

        //防止成环,要让最后的那个值指向NULL
        greaterTail->next = NULL;

        pHead = lessHead->next;
        //释放空间
        free(lessHead);
        lessHead = NULL;
        free(greaterHead);
        greaterHead = NULL;
        return pHead;
    }
};

void PrintList(struct ListNode* cur) 
{
    while (cur)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n8 = (struct ListNode*)malloc(sizeof(struct ListNode));

    if (n1 && n2 && n3 && n4 && n5 && n6 && n7 && n8)//防止开辟失败返回NULL程序崩溃
    {
        n1->val = 2;
        n2->val = 4;
        n3->val = 9;
        n4->val = 3;
        n5->val = 2;
        n6->val = 1;
        n7->val = 6;
        n8->val = 3;

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n6;
        n6->next = n7;
        n7->next = n8;
        n8->next = NULL;
    }
    

    struct ListNode* head = Partition().partition(n1, 5);
    PrintList(head);

    return 0;
}