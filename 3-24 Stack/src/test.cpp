#include "Stack.h"

void Test()
{
    Stack st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);

    StackPush(&st, 3);
    StackPush(&st, 4);
    // 1 2 3 4 top指向的是4的下一个位置
    // 栈是先进后出，不能直接按顺序读取，不然就变成先进先出了。
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st); //为了访问下一个元素，必须删掉当前的，让top移动
    }
    StackDestroy(&st);
}
void Test2()
{
    Stack st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    // 入了2个就出1个，顺序就变了。
    printf("%d ", StackTop(&st));
    StackPop(&st); //为了访问下一个元素，必须删掉当前的，让top移动
    StackPush(&st, 3);
    StackPush(&st, 4);
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st); //为了访问下一个元素，必须删掉当前的，让top移动
    }
    StackDestroy(&st);
    // 打印结果2 4 3 1
}
int main(int argc, char const *argv[])
{
    Test();
    system("pause");
    return 0;
}
