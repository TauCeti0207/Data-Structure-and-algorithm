#pragma once
#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include<string.h>

////静态顺序表(不推荐)
//struct SeqList
//{
//	int a[N];
//	int size;
//};

typedef int SeqDataType;//利用typedef插入任意类型数据

typedef struct SeqList
{
	SeqDataType* a;//指向动态开辟的数组
	int size;//有效数据个数
	int capacity;//容量
}SeqList,SEQ;


//初始化
void SeqListInit(SeqList* pseq);
//销毁
void SeqListDestory(SeqList* pseq);
//打印
void SeqListPrint(SeqList* pseq);

//尾插
void SeqListPushBack(SeqList* pseq, SeqDataType x);
//头插
void SeqListPushFront(SeqList* pseq, SeqDataType x);
//尾删
void SeqListPopBack(SeqList* pseq);
//头删
void SeqListPopFront(SeqList* pseq);
//查找
int SeqListFind(SeqList* pseq,SeqDataType x);
//中间插入
void SeqListInsert(SeqList* pseq, int pos, SeqDataType x);
//中间擦除
void SeqListErase(SeqList* pseq, int pos);
//修改
void SeqListModify(SeqList* pseq, int pos, SeqDataType x);