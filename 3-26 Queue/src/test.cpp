#include "Queue.h"
void Test1()
{
    Queue q;
    QueueInit(&q); // Ҫ�ı�ṹ�����ݣ�Ҫ���ṹ��ָ��
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    while (!QueueEmpty(&q))
    {
        //ֻ�ܳ���ͷ
        printf("%d ", QueueFront(&q));
        QueuePop(&q); // pop��֮�����ȡ��һ��
    }
    printf("\n");
    // printf("%d ", QueueFront(&q));
    // QueuePop(&q);
    // QueuePush(&q, 3);
    // QueuePush(&q, 4);
    // printf("%d ", QueueFront(&q));
    // QueuePop(&q);
    // QueuePush(&q, 5);

    // while (!QueueEmpty(&q))
    // {
    //     //ֻ�ܳ���ͷ
    //     printf("%d ", QueueFront(&q));
    //     QueuePop(&q);
    // }
    // printf("\n");
    // QueueDestroy(&q);
}
int main(int argc, char const *argv[])
{
    Test1();
    return 0;
}