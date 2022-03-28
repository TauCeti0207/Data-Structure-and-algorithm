#include "Queue.h"
void Test1()
{
    Queue q;
    QueueInit(&q); // 要改变结构体内容，要传结构体指针
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    while (!QueueEmpty(&q))
    {
        //只能出队头
        printf("%d ", QueueFront(&q));
        QueuePop(&q); // pop掉之后才能取下一个
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    Test1();
    system("pause");
    return 0;
}
