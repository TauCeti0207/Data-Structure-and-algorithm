#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int HPDataType;
// �ײ���ʵ��������ʵ��
typedef struct Heap
{
    HPDataType* a;
    size_t size;
    size_t capacity;
}HP;

void Swap(HPDataType* pa, HPDataType* pb);
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
void HeapPrint(HP* php);