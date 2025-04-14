/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-03-14 12:54:02
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-04-08 21:43:06
 */
#include "heap.h"

// 测试堆的插入操作
void TestHeapPush()
{
	HP hp;
	HeapInit(&hp);

	HeapPush(&hp, 3);
	HeapPush(&hp, 1);
	HeapPush(&hp, 4);
	HeapPush(&hp, 2);

	// 小堆的根节点应该是最小的元素
	assert(hp.a[0] == 1);

	printf("Heap elements after push: \n");
	HeapPrint(&hp);

	HeapDestroy(&hp);
	printf("TestHeapPush passed.\n");
}

void TestHeapPop()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 32);
	HeapPush(&hp, 50);
	HeapPush(&hp, 60);
	HeapPush(&hp, 100);
	HeapPush(&hp, 65);
	printf("Heap elements after push: \n");
	HeapPrint(&hp);
	HeapPop(&hp);
	printf("Heap elements after pop: \n");
	HeapPrint(&hp);
}

// 利用已有的堆来排序：
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

// 这里建的是小堆，降序
// 升序就建大堆，只需要修改AdjustUp、AdjustDown里面的代码
void HeapSort(int *a, int size)
{
	// 向上调整建堆 第一个元素就是堆，直接从第二元素开始调整建堆
	for (int i = 1; i < size; i++)
	{
		AdjustUp(a, i);
	}
	// 升序，需要建大堆，而不是小堆
	// 如果建了小堆，选出第一个数是最小的，要选次小的数，需要把剩下的数据堆化，再选次小的数，这时父子关系就全乱了
	// 交换首尾元素，就选出了最小的，然后不管最后的元素，再向下调整，这时就选出了次小
	for (int i = size - 1; i > 0; i--)
	{
		// 交换首尾元素
		Swap(&a[0], &a[i]);
		// 向下调整，选出次小的数，最后一个数不考虑
		AdjustDown(a, 0, i);
	}
}

void HeapSort2(int *a, int size)
{
	// 使用向下调整建堆，向下调整的前提是左右子树都是堆（这里假设建小堆）降序建小堆
	// 从倒数的第一个非叶子节点开始调整（也就是最后一个节点的父亲节点）
	// O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, i, size);
	}

	// O(N*LogN) 整体逻辑和向上调整类似，也是N*logN
	// 第一次首尾交换，向下调整h-1次，第二次交换的是倒数第二个节点，也要向下调整h-1次，最终就是最后一层调整h-1次，倒数第二层调整h-2次。。。
	// 2^1*1 +2^2*2 + .. + 2^(h-1)*(h-1) 最终推出来就是O(N*logN)
	for (int i = size - 1; i > 0; --i)
	{
		// 交换首尾元素
		Swap(&a[0], &a[i]);
		// 向下调整，选出次小的数，最后一个数不考虑
		// size是在逐渐减小的
		AdjustDown(a, 0, i);
	}
}

void test_heap_sort()
{
	int a[] = {32, 50, 60, 100, 65, 1, 22};
	HeapSort2(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
}

// 生成数据并写入文件
void CreateNDate()
{
	int n = 10000;
	srand(time(0));
	const char *file = "data.txt";
	// 注意，我用的cmake，最终生成的文件在C:\Users\yzq0207\OneDrive\learn\programming\dataStructure\build\05Heap\data.txt
	FILE *fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	// 生成普通随机数
	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000; // 生成0~999999之间的随机数
		fprintf(fin, "%d\n", x);  // 向文件指针 fin 所指向的文件中写入内容
	}

	// 加入用于验证的较大数
	fprintf(fin, "%d\n", 1000000 + 1);
	fprintf(fin, "%d\n", 1000000 + 2);
	fprintf(fin, "%d\n", 1000000 + 3);
	fprintf(fin, "%d\n", 1000000 + 4);
	fprintf(fin, "%d\n", 1000000 + 5);
	fprintf(fin, "%d\n", 1000000 + 6);
	fprintf(fin, "%d\n", 1000000 + 7);
	fprintf(fin, "%d\n", 1000000 + 8);
	fprintf(fin, "%d\n", 1000000 + 9);
	fprintf(fin, "%d\n", 1000000 + 10);

	fclose(fin);
}

// 解决TopK问题（从文件读取数据）
void PrintTopK(const char *file, int k)
{
	FILE *f = fopen(file, "r");
	assert(f);

	// 读取前k个数建小堆
	int *KminHeap = (int *)malloc(sizeof(int) * k);
	assert(KminHeap);
	for (int i = 0; i < k; ++i)
	{
		// fscanf 处理输入时，会自动跳过空白字符（包括空格、换行、制表符）
		fscanf(f, "%d", &KminHeap[i]);
	}

	// 构建小堆 从第一个叶子节点的父亲开始调整
	for (int j = (k - 1 - 1) / 2; j >= 0; --j)
	{
		// parent的位置开始调整，也就是把j传给parent参数
		AdjustDown(KminHeap, j, k);
	}

	// 处理剩余数据
	int num;
	// while (fscanf(f, "%d", &num) != EOF)
	while (!feof(f)) // 当文件指针 f 未到达文件末尾时进行循环 feof如果到达文件末尾则返回非零值，否则返回零
	{
		fscanf(f, "%d", &num);
		// num比小堆堆顶元素大的话，替换堆顶元素，然后向下调整
		if (num > KminHeap[0])
		{
			KminHeap[0] = num;
			AdjustDown(KminHeap, 0, k);
		}
	}

	fclose(f);

	// 输出结果
	printf("Top %d numbers:\n", k);
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", KminHeap[i]);
	}
	printf("\n");

	free(KminHeap);
}

void test_topk()
{
	CreateNDate(); // 生成数据并写入文件
	int k = 10;
	PrintTopK("data.txt", k); // 解决TopK问题
}

int main(int argc, char const *argv[])
{
	// TestHeapPush();
	// TestHeapPop();
	// test_heap_sort();
	test_topk();
	return 0;
}
