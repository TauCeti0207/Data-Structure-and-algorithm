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
        HeapPush(&hp, a[i]); // 先把数据全部push进去
    }
    size_t j = 0;
    // 依次取堆顶数据，放到数组里
    // 时间复杂度O(N*logN)
    while (!HeapEmpty(&hp))
    {
        a[j++] = HeapTop(&hp);
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
}
// 注意向上调整和向下调整建出来的堆其实不一样
// AdjustDown(a, size, i);  0 2 1 6 5 4 7 8
// AdjustUp(a, i);  0 4 1 6 5 7 2 8
void TestHeapSort()
{
    int a[] = {4, 2, 7, 8, 5, 1, 0, 6};
    HeapSort3(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    // TestHeap1();
    TestHeapSort();
    system("pause");
    return 0;
}
// //
// 
// ss