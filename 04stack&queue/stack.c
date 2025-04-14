#include "stack.h"

void StackInit(Stack *pSt)
{
	assert(pSt != NULL);
	pSt->array = NULL;
	pSt->top = -1; // top初始化为-1表示指向栈顶数据
	pSt->top = 0;  // top初始化为0表示指向栈顶元素的下一个位置
	pSt->capacity = 0;
}
void StackDestroy(Stack *pSt)
{
	assert(pSt != NULL);
	free(pSt->array);
	pSt->array = NULL;
	pSt->top = 0;
	pSt->capacity = 0;
}
// 性质决定了只能在栈顶出入数据
void StackPush(Stack *pSt, STDataType x)
{
	assert(pSt != NULL);
	if (pSt->top == pSt->capacity)
	{
		int newCapacity = pSt->capacity == 0 ? 4 : pSt->capacity * 2;
		STDataType *tmp = (STDataType *)realloc(pSt->array, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			return;
		}
		pSt->array = tmp;
		pSt->capacity = newCapacity;
	}
	pSt->array[pSt->top++] = x;
}
void StackPop(Stack *pSt)
{
	assert(pSt != NULL);
	assert(!StackEmpty(pSt)); // 栈为空不能出栈
	--pSt->top;
	// 只需--top即可，无需将要删除元素置0等无谓操作，只要读取不到就认为删除了。
}
// 访问栈顶数据
STDataType StackTop(Stack *pSt)
{
	assert(pSt != NULL);
	assert(!StackEmpty(pSt)); // 栈为空不能访问栈顶元素
	return pSt->array[pSt->top - 1];
}
bool StackEmpty(Stack *pSt)
{
	assert(pSt != NULL);
	return pSt->top == 0;
}
int StackSize(Stack *pSt)
{
	assert(pSt != NULL);
	return pSt->top;
}