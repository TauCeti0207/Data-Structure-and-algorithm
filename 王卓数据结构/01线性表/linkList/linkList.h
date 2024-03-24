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

Status InitLL(LinkList *L); // 需要改变一级指针的值 传二级指针
int ListEmpty(LinkList L);
void CreatLL_H(LinkList L, int n);
void CreatLL_R(LinkList L, int n);
Status GetElem(LinkList L, int position, LlElemtype *e);
LinkList LocateElem(LinkList L, LlElemtype e);
Status LlInsert(LinkList L, int position, LlElemtype e);
Status LlDelete(LinkList L, int position, LlElemtype *e);
void Traverse(LinkList L);
Status LlDestroy(LinkList *L);
Status ClearList(LinkList *L);
int ListLength(LinkList L);
void Merge_LinkedList(LinkList *La, LinkList *Lb, LinkList *Lc);
#endif