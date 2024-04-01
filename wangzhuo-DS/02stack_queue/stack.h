// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // 用于isdigit函数

#define STACK_SIZE 100 // 栈的最大容量

// 栈的结构体定义
typedef struct
{
    int data[STACK_SIZE]; // 栈的存储空间
    int top;              // 栈顶指针
} Stack;

// 函数声明
void initStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int isEmpty(Stack *s);

#endif // STACK_H
