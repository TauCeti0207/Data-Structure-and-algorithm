#include "Heap.h"

void HeapInit(HP *php)
{
    assert(php);
    php->a = NULL;
    php->capacity = php->size = 0;
}
void HeapDestroy(HP *php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}
void Swap(HPDataType *pa, HPDataType *pb)
{
    HPDataType tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
void AdjustUp(HPDataType *a, size_t child)
{
    size_t parent = (child - 1) / 2;
    while (/* condition */)
        ;
    {
        // 要保持小堆，父亲必须比孩子小
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            // 迭代
            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

// 假设一开始是小堆
// 插入之后要尽可能不影响堆，还要保持堆的性质，因此尾插最好，头插不可取
// 如果有影响，只会影响他的祖先节点，因此需要和祖先节点依次比较。
void HeapPush(HP *php, HPDataType x)
{
    assert(php);
    // 先判断是否满
    if (php->size == php->capacity)
    {
        size_t newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
        HPDataType *tmp = (HPDataType *)realloc(php->a, sizeof(HPDataType) * newCapacity);
        assert(tmp);
        php->a = tmp;
        php->capacity = newCapacity;
    }
    php->a[php->size++] = x;
    // 插完之后考虑向上调整
    AdjustUp(php->a, php->size - 1); // 最后一个元素的坐标
}
void HeapPop(HP *php);