/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-14 12:32:51
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-03-14 15:07:45
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef int HPDataType;
// 底层其实就是数组实现
typedef struct Heap
{
	HPDataType *a;
	size_t size;
	size_t capacity;
} HP;

void HeapInit(HP *php);
void HeapDestroy(HP *php);
void HeapPush(HP *php, HPDataType x);
void HeapPrint(HP *php);
bool HeapEmpty(HP *php);
int HeapSize(HP *php);
HPDataType HeapTop(HP *php);
void HeapPop(HP *php);
void AdjustUp(HPDataType *a, size_t child);
void AdjustDown(HPDataType *a, size_t parent, size_t size);
void Swap(HPDataType *pa, HPDataType *pb);