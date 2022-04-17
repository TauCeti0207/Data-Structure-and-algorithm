#include "BinaryTree.h"
#include "Heap.h"

void TestHeap1()
{
    HP hp;
    HeapInit(&hp);
    HeapPush(&hp, 1);
    HeapPush(&hp, 5);
    HeapPush(&hp, 3);
    HeapPush(&hp, 0);
    HeapPush(&hp, 8);
    HeapPush(&hp, 9);
    HeapPush(&hp, 2);
    HeapPrint(&hp);

    HeapPop(&hp);
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapDestroy(&hp);
}

// 升序 O(N*logN)，向下调整是logN
void HeapSort1(int *a, int size)
{
    HP hp;
    HeapInit(&hp);
    // 时间复杂度O(N*logN)
    for (int i = 0; i < size; i++)
    {
        HeapPush(&hp, a[i]); // 先把数据全部push进去  默认是小堆
    }

    size_t j = 0;
    // 依次取堆顶数据，放到数组里
    // 时间复杂度O(N*logN)
    while (!HeapEmpty(&hp))
    {
        a[j++] = HeapTop(&hp); // 默认是小堆，堆顶数据是最小的
        HeapPop(&hp);
    }
}
// 缺陷，O(N)空间复杂度
// 还得写一个堆，太麻烦了吧！
// 实际中是不会这么取写的。

// 优化：
// 升序要建小堆
// 数组可以看成完全二叉树，直接把数组看成堆，在数组上建堆
void HeapSort2(int *a, int size)
{
    // 建堆 2种方式
    // 1.使用向上调整，插入数据的思想来建堆
    // 第一个数必定为堆，然后一个一个插入的过程中，前2个是堆，前3个也还是堆。。。
    for (int i = 1; i < size; ++i) // 没必要从0开始，第一个数不需要插入
    {
        AdjustUp(a, i);
    }
}

void HeapSort3(int *a, int size)
{
    // 建堆 2种方式
    // 2.使用向下调整建堆，向下调整的前提是左右子树都是堆（这里假设建小堆）
    // 从倒数的第一个非叶子节点开始调整（也就是最后一个节点的父亲节点）
    for (int i = (size - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(a, size, i);
    }

    size_t end = size - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

// 注意向上调整和向下调整建出来的堆其实不一样
// AdjustDown(a, size, i);  0 2 1 6 5 4 7 8
// AdjustUp(a, i);  0 4 1 6 5 7 2 8

// 建大堆：8 6 7 4 5 1 0 2
void TestHeapSort()
{
    int a[] = {2, 6, 7, 4, 5, 1, 0, 8};
    HeapSort3(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// TopK问题
// 找最大的K个，建小堆
void PrintTopK(int *a, int n, int k)
{
    // 1. 建堆，用a中前k个数建堆
    int *KminHeap = (int *)malloc(sizeof(int) * k);
    assert(KminHeap);
    for (size_t i = 0; i < k; i++)
    {
        KminHeap[i] = a[i];
    }
    // 建小堆
    for (int j = (k - 1 - 1) / 2; j >= 0; --j)
    {
        AdjustDown(KminHeap, k, j);
    }

    // 将剩下的n-k个元素依次与堆顶元素比较
    for (int i = k; i < n; ++i)
    {
        if (a[i] > KminHeap[0]) // 只要比10个中最小那个大就替换进去。
        {
            KminHeap[0] = a[i];
            AdjustDown(KminHeap, k, 0); // 从根开始向下调整
        }
    }

    for (size_t i = 0; i < k; i++)
    {
        printf("%d ", KminHeap[i]);
    }
    printf("\n");

    // 找到最大的前10个后，再排序一波
    HeapSort3(KminHeap, 10);
    for (size_t i = 0; i < k; i++)
    {
        printf("%d ", KminHeap[i]);
    }
    printf("\n");
}

void TestTopK()
{
    int n = 10000;
    int *a = (int *)malloc(sizeof(int) * n);
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        a[i] = rand() % 1000000; // 保证随机数都<1000000
    }
    // 用来验证找的10个最大的数是否正确。
    a[5] = 1000000 + 1;
    a[1231] = 1000000 + 2;
    a[523] = 1000000 + 3;
    a[223] = 1000000 + 4;
    a[4545] = 1000000 + 5;
    a[999] = 1000000 + 6;
    a[87] = 1000000 + 7;
    a[993] = 1000000 + 8;
    a[528] = 1000000 + 9;
    a[53] = 1000000 + 10;
    PrintTopK(a, n, 10); // 找最大的前10个
}

int main(int argc, char const *argv[])
{
    // TestHeap1();
    // TestHeapSort();
    TestTopK();
    system("pause");
    return 0;
}
