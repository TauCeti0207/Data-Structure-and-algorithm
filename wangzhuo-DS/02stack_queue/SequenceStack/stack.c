#include "stack.h"

// 初始化栈
Status initStack(sequenceStack *s)
{
	s->base = (StackElemType *)malloc(STACK_SIZE * sizeof(StackElemType));
	if (!s->base)
		exit(OVERFLOW);		   // If allocation fails, exit
	s->top = s->base;		   // Initialize top to be at base, stack is empty
	s->stackSize = STACK_SIZE; // Set the stack's capacity
	return OK;
}

// 清空栈
Status clearStack(sequenceStack *s)
{
	if (!isEmpty(s))
		s->top = s->base; // Simply reset the top pointer to the base
	return OK;
}

// 销毁栈
Status destroyStack(sequenceStack *s)
{
	free(s->base);			 // Free the allocated memory for the stack
	s->base = s->top = NULL; // Avoid dangling pointers
	s->stackSize = 0;		 // Reset stack size
	return OK;
}

// 求栈的长度
int stackLength(const sequenceStack *s)
{
	return s->top - s->base; // The number of elements in the stack
}

Status getTop(const sequenceStack *s, StackElemType *element)
{
	if (s->top == s->base)
	{
		return ERROR; // 栈为空，返回错误状态
	}
	else
	{
		*element = *(s->top - 1); // 通过输出参数返回栈顶元素
		return OK;				  // 操作成功
	}
}

// 入栈操作
Status push(sequenceStack *s, StackElemType value)
{
	if (s->top - s->base >= s->stackSize) // 栈满
		return ERROR;
	*(s->top++) = value; // 将值赋给栈顶，并将栈顶指针上移
	return OK;
}

// 出栈操作
Status pop(sequenceStack *s, StackElemType *element)
{
	if (s->top == s->base) // 栈为空
		return ERROR;
	*element = *(--s->top); // 栈顶指针下移，并获取栈顶元素的值
	return OK;
}

// 检查栈是否为空
Status isEmpty(const sequenceStack *s)
{
	return s->top == s->base ? TRUE : FALSE; // 相等为空返回true
}

void testStackFunction()
{
	sequenceStack s;
	Status status;
	StackElemType element;

	// 初始化栈
	status = initStack(&s);
	if (status != OK)
	{
		printf("Failed to initialize stack.\n");
	}

	// 测试入栈操作
	for (char ch = 'A'; ch <= 'E'; ++ch)
	{
		if (push(&s, ch) == OK)
		{
			printf("Pushed %c onto the stack.\n", ch);
		}
		else
		{
			printf("Failed to push %c onto the stack.\n", ch);
		}
	}

	// 获取栈的长度
	printf("Stack length: %d\n", stackLength(&s));

	// 测试获取栈顶元素
	if (getTop(&s, &element) == OK)
	{
		printf("Top element: %c\n", element);
	}
	else
	{
		printf("Failed to get top element.\n");
	}

	// 测试出栈操作
	while (!isEmpty(&s))
	{
		if (pop(&s, &element) == OK)
		{
			printf("Popped %c from the stack.\n", element);
		}
		else
		{
			printf("Failed to pop from the stack.\n");
		}
	}

	// 销毁栈
	destroyStack(&s);
	printf("Stack destroyed.\n");
}
