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
typedef struct __linkListStack
{
    StackElemType data;           //
    struct __linkListStack *next; //
} linkListStack;

// 函数声明
Status initStack(linkListStack *s);
Status clearStack(linkListStack *s);
Status destroyStack(linkListStack *s);
int stackLength(const linkListStack *s);
Status getTop(const linkListStack *s, StackElemType *element);
Status push(linkListStack *s, StackElemType value);
Status pop(linkListStack *s, StackElemType *element);
Status isEmpty(const linkListStack *s);

void testLinkListStackFunction();

#endif // STACK_H
