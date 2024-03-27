#include <stdio.h>
#include <stdlib.h>

#ifndef __DOUBLYCIRCULARLINKEDLIST_H
#define __DOUBLYCIRCULARLINKEDLIST_H

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prev, *next;
} DNode, *DoublyCircularLinkedList;

// 基本操作函数声明
void initList(DoublyCircularLinkedList *L);
void insertList(DoublyCircularLinkedList *L, int position, ElemType e);
void deleteList(DoublyCircularLinkedList *L, int position, ElemType *e);
void printList(DoublyCircularLinkedList L);
void destroyList(DoublyCircularLinkedList *L);
void clearList(DoublyCircularLinkedList *L);

#endif
