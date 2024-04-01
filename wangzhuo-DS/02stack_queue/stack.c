
#include "stack.h"

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 压栈操作
void push(Stack *s, int value)
{
    if (s->top < STACK_SIZE - 1)
    {
        s->top++; // 从-1开始的
        s->data[s->top] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

// 弹栈操作
int pop(Stack *s)
{
    if (s->top >= 0)
    {
        int value = s->data[s->top];
        s->top--;
        return value;
    }
    else
    {
        printf("Stack underflow\n");
        return -1; // 栈空时返回-1，调用者需要检查这种情况
    }
}

// 检查栈是否为空
int isEmpty(Stack *s)
{
    return s->top == -1;
}
