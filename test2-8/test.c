#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
  struct ListNode {
    int val;
      struct ListNode *next;
  };
 
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //���ǿ�����
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    //����2����������
    int lenA = 0;
    int lenB = 0;
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while (curA->next != NULL)
    {
        curA = curA->next;
        lenA++;
    }
    //���Զ��ټ���һ��,���ûӰ��,������������ж��Ƿ��ཻ
    while (curB->next != NULL)
    {
        curB = curB->next;
        lenB++;
    }
    //���ཻ,��ʱcurA->nxet == NULL
    if (curA != curB)
    {
        return NULL;
    }

    //�ó��������ȰѶ�����ĳ�������,��һ����
    if (lenA > lenB)
    {
        int len = lenA - lenB;
        while (len--)
        {
            curA = curA->next;
        }
    }
    //lenA = lenB ʱҲ�е�,len=0�������ѭ��
    if (lenA < lenB)
    {
        int len = lenB - lenA;
        while (len--)
        {
            curB = curB->next;
        }
    }

    //һ����,��˭��ָ����ͬ
    while (curA != curB)
    {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}