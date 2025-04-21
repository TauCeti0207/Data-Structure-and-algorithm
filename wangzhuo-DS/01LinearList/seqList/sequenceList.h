#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef __SEQUENCELIST_H
#define __SEQUENCELIST_H
#define SQLMAXSIZE 100
typedef int SqlElemType;
typedef struct __Sqlist
{
    SqlElemType *base;
    int length;
} Sqlist;
Status InitSL(Sqlist *L, int length);
Status getLinkListElem(Sqlist *L, int position, SqlElemType *e);
int locateElement(Sqlist *L, SqlElemType e);
Status SqlInsert(Sqlist *L, int position, SqlElemType e);
Status SqlDelete(Sqlist *L, int position, SqlElemType *e);
Status SqlDestroy(Sqlist *L);
void SqlClear(Sqlist *L);
Status SqlIsEmpty(Sqlist *L);
void MergeList(Sqlist *La, Sqlist *Lb);
void Traverse(Sqlist *L);
void MergeList_Seq(Sqlist *La, Sqlist *Lb, Sqlist *Lc);
void PrintList(Sqlist L);
void testMergeSeq();
#endif