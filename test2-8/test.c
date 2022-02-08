#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
  struct ListNode {
    int val;
      struct ListNode *next;
  };
 
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //考虑空链表
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    //先算2个链表长度
    int lenA = 0;
    int lenB = 0;
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while (curA->next != NULL)
    {
        curA = curA->next;
        lenA++;
    }
    //各自都少计算一步,相减没影响,这样方便后面判断是否相交
    while (curB->next != NULL)
    {
        curB = curB->next;
        lenB++;
    }
    //不相交,此时curA->nxet == NULL
    if (curA != curB)
    {
        return NULL;
    }

    //让长的链表先把多出来的长度走了,再一起走
    if (lenA > lenB)
    {
        int len = lenA - lenB;
        while (len--)
        {
            curA = curA->next;
        }
    }
    //lenA = lenB 时也行的,len=0不会进入循环
    if (lenA < lenB)
    {
        int len = lenB - lenA;
        while (len--)
        {
            curB = curB->next;
        }
    }

    //一起走,看谁的指针相同
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}