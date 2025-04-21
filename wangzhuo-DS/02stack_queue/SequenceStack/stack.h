#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>     // 用于isdigit函数
#define STACK_SIZE 100 // 栈的最大容量

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char StackElemType; // 栈数据类型

// 栈的结构体定义
typedef struct __SqStack
{
    StackElemType *top;  // 栈顶指针 指向当前元素的下一个位置
    StackElemType *base; // 栈底指针
    int stackSize;       // 栈的最大容量
} sequenceStack;

// 函数声明
Status initStack(sequenceStack *s);
Status clearStack(sequenceStack *s);
Status destroyStack(sequenceStack *s);
int stackLength(const sequenceStack *s);
Status getTop(const sequenceStack *s, StackElemType *element);
Status push(sequenceStack *s, StackElemType value);
Status pop(sequenceStack *s, StackElemType *element);
Status isEmpty(const sequenceStack *s);

void testFunction();

#endif // STACK_H
