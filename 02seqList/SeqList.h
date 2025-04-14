#pragma once // 防止头文件重复包含
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

typedef int SeqDataType; // 利用typedef插入任意类型数据
typedef struct SeqList
{
	SeqDataType *a;	 // 指向动态开辟的数组
	size_t size;	 // 有效数据个数
	size_t capacity; // 容量
} SeqList;

// 初始化
void SeqListInit(SeqList *pseq);
// 销毁
void SeqListDestory(SeqList *pseq);
// 打印
void SeqListPrint(SeqList *pseq);
// 扩容
void SeqCheckCapacity(SeqList *pseq);
// 尾插
void SeqListPushBack(SeqList *pseq, SeqDataType x);
// 头插
void SeqListPushFront(SeqList *pseq, SeqDataType x);
// 尾删
void SeqListPopBack(SeqList *pseq);
// 头删
void SeqListPopFront(SeqList *pseq);
// 查找
int SeqListFind(SeqList *pseq, SeqDataType x);
// 中间插入
void SeqListInsert(SeqList *pseq, size_t pos, SeqDataType x);
// 中间擦除
void SeqListErase(SeqList *pseq, size_t pos);
// 修改
void SeqListModify(SeqList *pseq, size_t pos, SeqDataType x);