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
void HeapSort(int *a, int size)
{
    HP hp;
    HeapInit(&hp);
    for (int i = 0; i < size; i++)
    {
        HeapPush(&hp, a[i]); // 先把数据全部push进去
    }
    size_t j = 0;
    // 依次取堆顶数据，放到数组里
    while (!HeapEmpty(&hp))
    {
        a[j++] = HeapTop(&hp);
        HeapPop(&hp);
    }
}
// 缺陷，O(N)空间复杂度

void TestHeapSort()
{
    int a[] = {4, 2, 7, 8, 5, 1, 0, 6};
    HeapSort(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        printf("%d ", a[i]);
    }
}
int main(int argc, char const *argv[])
{
    // TestHeap1();
    TestHeapSort();
    system("pause");
    return 0;
}
