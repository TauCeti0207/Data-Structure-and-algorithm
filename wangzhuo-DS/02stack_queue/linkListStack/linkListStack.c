#include "linkListStack.h"

// 初始化栈
Status initStack(linkListStack *s)
{
    s->next = NULL; // 栈顶指针指向NULL，表示栈为空
    return OK;
}

// 清空栈
Status clearStack(linkListStack *s)
{
    linkListStack *temp, *p = s->next;
    while (p)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
    s->next = NULL; // 重置栈顶指针
    return OK;
}

// 销毁栈
Status destroyStack(linkListStack *s)
{
    clearStack(s); // 首先清空栈
    return OK;
}

// 获取栈的长度
int stackLength(const linkListStack *s)
{
    int length = 0;
    const linkListStack *p = s->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 获取栈顶元素
Status getTop(const linkListStack *s, StackElemType *element)
{
    if (s->next == NULL)
        return ERROR;         // 栈为空
    *element = s->next->data; // 栈顶元素赋值给element
    return OK;
}

// 入栈操作
// s本身不直接存储数据，而是作为一个固定的头节点存在，其next属性指向栈的顶部
// 这样设计不需要使用二级指针了 如果直接操作栈顶指针，就需要二级指针。
// 第一个Push函数的实现方式需要使用二级指针，主要是因为它直接修改传入的栈顶指针。在这个上下文中，栈顶指针本身需要被更新（指向新的栈顶元素），而这个操作只能通过二级指针（即指针的指针）实现。
Status push(linkListStack *s, StackElemType value)
{
    linkListStack *p = (linkListStack *)malloc(sizeof(linkListStack));
    if (!p)
        return OVERFLOW; // 内存分配失败
    p->data = value;     // 节点数据赋值
    p->next = s->next;   // 插入节点到链表头部（栈顶） s->next就是真正的头节点
    s->next = p;
    return OK;
}

// 出栈操作
Status pop(linkListStack *s, StackElemType *element)
{
    if (s->next == NULL)
        return ERROR; // 栈为空
    linkListStack *p = s->next;
    *element = p->data; // 栈顶元素赋值给element
    s->next = p->next;  // 移除栈顶元素
    free(p);            // 释放节点内存
    return OK;
}

// 判断栈是否为空
Status isEmpty(const linkListStack *s)
{
    return s->next == NULL ? TRUE : FALSE;
}

// 测试栈功能
void testLinkListStackFunction()
{
    linkListStack stack;
    initStack(&stack);
    char element1;

    printf("Pushing elements onto stack\n");
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        push(&stack, c);
        if (getTop(&stack, &element1) == OK)
            printf("%c ", element1);
    }
    printf("\n");
    printf("Current stack length: %d\n", stackLength(&stack));

    printf("Popping elements from stack: ");
    char element2;
    while (!isEmpty(&stack))
    {
        pop(&stack, &element2);
        printf("%c ", element2);
    }
    printf("\n");

    printf("Stack is now empty, length = %d\n", stackLength(&stack));

    destroyStack(&stack);
}

// 确保包含main函数进行测试
int main()
{
    testLinkListStackFunction();
    return 0;
}
