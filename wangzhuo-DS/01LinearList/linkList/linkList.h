#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef __LINKLIST_H
#define __LINKLIST_H
typedef int LlElemtype;
typedef struct __LNode
{
    LlElemtype data;      // 存放单个节点的数据
    struct __LNode *next; // 存放下个节点的地址
} LNode, *LinkList;

Status initLinkList(LinkList *L); // 需要改变一级指针的值 传二级指针
int isLinklistEmpty(LinkList L);
Status getLinkListElem(LinkList L, int position, LlElemtype *e);
LinkList locateElement(LinkList L, LlElemtype e); // 定位元素
Status insertLinkList(LinkList L, int position, LlElemtype e);
Status deleteLinkList(LinkList L, int position, LlElemtype *e);
void printLinkList(LinkList L);
void createLinkList_Head(LinkList *L, int n);
void createLinkList_Tail(LinkList *L, int n);
void Traverse(LinkList L);
Status destroyLinkList(LinkList *L);
Status clearList(LinkList *L);
int getLinkListLength(LinkList L);
void mergeLinkList(LinkList *La, LinkList *Lb, LinkList *Lc);
#endif