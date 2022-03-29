#include "Stack.h"

void StackInit(Stack *pSt)
{
    assert(pSt);
    pSt->a = NULL;
    pSt->capacity = pSt->top = 0;
}
void StackDestroy(Stack *pSt)
{
    assert(pSt);
    free(pSt->a);
    pSt->a = NULL;
    pSt->capacity = pSt->top = 0;
}
// 性质决定了只能在栈顶出入数据
// 选top一开始指向0的方式

void StackPush(Stack *pSt, STDataType x)
{
    assert(pSt);
    // 满了要扩容，
    if (pSt->top == pSt->capacity)
    {
        int newCapacity = pSt->capacity == 0 ? 4 : pSt->capacity * 2;
        // realloc传的新空间的整体大小，如果pSt->a 为空，那么realloc等价于malloc
        pSt->a = (STDataType *)realloc(pSt->a, newCapacity * sizeof(STDataType));
        if (pSt->a == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        pSt->capacity = newCapacity;
    }
    pSt->a[pSt->top++] = x;
}

void StackPop(Stack *pSt)
{
    assert(pSt);
    assert(pSt->top > 0); // 有数据才能pop
    --pSt->top;
    //只需--top即可，无需将要删除元素置0等无谓操作，只要读取不到就认为删除了。
}

// 访问栈顶数据
STDataType StackTop(Stack *pSt)
{
    assert(pSt);
    assert(pSt->top > 0);
    return pSt->a[pSt->top - 1];
}

bool StackEmpty(Stack *pSt)
{
    assert(pSt);
    return pSt->top == 0;
}

int StackSize(Stack *pSt)
{
    assert(pSt);
    return pSt->top;
}