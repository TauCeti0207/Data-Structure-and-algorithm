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
int main(int argc, char const *argv[])
{
    TestHeap1();
    system("pause");
    return 0;
}
