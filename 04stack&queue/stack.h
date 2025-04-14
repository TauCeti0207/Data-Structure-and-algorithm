/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-10 23:39:21
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-03-10 23:52:09
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *array;
	int top;	  // 栈顶 不要理解成下标
	int capacity; // 容量,方便增容
} Stack;

void StackInit(Stack *pSt);
void StackDestroy(Stack *pSt);
// 性质决定了只能在栈顶出入数据
void StackPush(Stack *pSt, STDataType x);
void StackPop(Stack *pSt);
// 访问栈顶数据
STDataType StackTop(Stack *pSt);
bool StackEmpty(Stack *pSt);
int StackSize(Stack *pSt);