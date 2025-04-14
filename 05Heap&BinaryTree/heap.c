#include "heap.h"

void HeapInit(HP *php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HeapDestroy(HP *php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void Swap(HPDataType *pa, HPDataType *pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// 向上调整
void AdjustUp(HPDataType *a, size_t child)
{
	size_t parent = (child - 1) / 2;
	while (child > 0) // child = 0 时结束
	{
		// 要保持小堆，父亲必须比孩子小
		if (a[child] < a[parent]) // 小堆
		// if (a[child] > a[parent]) // 大堆
		{
			Swap(&a[child], &a[parent]);
			// 迭代
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break; // 满足小堆时直接break
		}
	}
}

// 向下调整 前提：左右子树都是大堆或小堆 这里以小堆举例
void AdjustDown(HPDataType *a, size_t parent, size_t size)
{
	assert(a);
	size_t child = parent * 2 + 1;
	while (child < size) // child < size 时结束
	{
		// 找到左右子树中较小的那个 考虑右子树不存在情况
		if (child + 1 < size && a[child + 1] < a[child]) // 小堆
		// if (child + 1 < size && a[child + 1] > a[child]) // 大堆
		{
			child++;
		}
		if (a[child] < a[parent]) // 小堆
		// if (a[child] > a[parent]) // 大堆
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			// 父亲比孩子小，满足小堆，结束
			break;
		}
	}
}

void HeapPush(HP *php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		size_t newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType *newa = (HPDataType *)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (newa == NULL)
		{
			perror("realloc");
			return;
		}
		php->a = newa;
		php->capacity = newcapacity;
	}
	php->a[php->size++] = x;
	// 向上调整
	AdjustUp(php->a, php->size - 1);
}

void HeapPrint(HP *php)
{
	assert(php);
	int num = 0;
	int levelSize = 1; // 第一层1个数，第二个2个数。。。
	for (size_t i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		++num;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n");
	printf("\n");
}

bool HeapEmpty(HP *php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(HP *php)
{
	assert(php);
	return php->size;
}

HPDataType HeapTop(HP *php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}

void HeapPop(HP *php)
{
	assert(php);
	assert(!HeapEmpty(php));
	// 最后一个元素和第一个元素交换
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	// 向下调整
	AdjustDown(php->a, 0, php->size);
}
