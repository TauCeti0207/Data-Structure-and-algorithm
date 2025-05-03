/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-04-10 21:56:11
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-03 20:31:42
 */
#include "sort.h"
void printArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test_sort_is_true()
{
	// 初始化随机数种子
	srand(time(NULL));

	int size = 10;
	int data[size];

	int data2[] = {7, 19, 10, 25, 17};

	printf("排序前的原始数据: ");
	for (int i = 0; i < size; ++i)
	{
		data[i] = rand() % 100;
		printf("%d ", data[i]);
	}
	printf("\n");

	// 调用插入排序函数
	// InsertSort(data, size);
	// BubbleSort(data, size);
	// BubbleSort2(data, size);
	// SelectSort(data, size);
	// ShellSort(data, size);
	// QuickSort(data, size);
	// MergeSort(data, size);
	// HeapSort(data, size);
	// BucketSort(data, size);
	// RadixSort(data, size);
	CountSort(data, size);
	printf("排序之后的数据  : ");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

// 生成随机数组
void generate_random_array(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

// 生成有序数组
void generate_sorted_array(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

// 复制数组
void copy_array(int *dst, int *src, int n)
{
	for (int i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
}

// 测试随机数组排序
void test_random_array_sort()
{
	int array_sizes[] = {1000, 5000, 10000, 50000};
	int num_sizes = sizeof(array_sizes) / sizeof(array_sizes[0]);
	int i, n;

	srand(time(NULL));

	for (i = 0; i < num_sizes; i++)
	{
		n = array_sizes[i];
		int *arr = (int *)malloc(n * sizeof(int));
		int *arr_insertion = (int *)malloc(n * sizeof(int));
		int *arr_bubble = (int *)malloc(n * sizeof(int));
		int *arr_select = (int *)malloc(n * sizeof(int));
		int *arr_shell = (int *)malloc(n * sizeof(int));
		int *arr_quick = (int *)malloc(n * sizeof(int));
		int *arr_merge = (int *)malloc(n * sizeof(int));
		int *arr_heap = (int *)malloc(n * sizeof(int));
		int *arr_bucket = (int *)malloc(n * sizeof(int));
		int *arr_radix = (int *)malloc(n * sizeof(int));
		int *arr_count = (int *)malloc(n * sizeof(int));

		generate_random_array(arr, n);

		// 测试插入排序
		copy_array(arr_insertion, arr, n);
		clock_t start_time = clock();
		InsertSort(arr_insertion, n);
		clock_t end_time = clock();
		double insertion_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试冒泡排序
		copy_array(arr_bubble, arr, n);
		start_time = clock();
		BubbleSort(arr_bubble, n);
		end_time = clock();
		double bubble_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试选择排序
		copy_array(arr_select, arr, n);
		start_time = clock();
		SelectSort(arr_select, n);
		end_time = clock();
		double select_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试希尔排序
		copy_array(arr_shell, arr, n);
		start_time = clock();
		ShellSort(arr_shell, n);
		end_time = clock();
		double shell_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试快速排序
		copy_array(arr_quick, arr, n);
		start_time = clock();
		QuickSort(arr_quick, n);
		end_time = clock();
		double quick_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试归并排序
		copy_array(arr_merge, arr, n);
		start_time = clock();
		MergeSort(arr_merge, n);
		end_time = clock();
		double merge_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试堆排序
		copy_array(arr_heap, arr, n);
		start_time = clock();
		HeapSort(arr_heap, n);
		end_time = clock();
		double heap_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试桶排序
		copy_array(arr_bucket, arr, n);
		start_time = clock();
		BucketSort(arr_bucket, n);
		end_time = clock();
		double bucket_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试基数排序
		copy_array(arr_radix, arr, n);
		start_time = clock();
		RadixSort(arr_radix, n);
		end_time = clock();
		double radix_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试计数排序
		copy_array(arr_count, arr, n);
		start_time = clock();
		CountSort(arr_count, n);
		end_time = clock();
		double count_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		printf("数组大小: %d\n", n);
		printf("随机数组插入排序耗时: %.3f ms\n", insertion_time);
		printf("随机数组冒泡排序耗时: %.3f ms\n", bubble_time);
		printf("随机数组选择排序耗时: %.3f ms\n", select_time);
		printf("随机数组希尔排序耗时: %.3f ms\n", shell_time);
		printf("随机数组快速排序耗时: %.3f ms\n", quick_time);
		printf("随机数组归并排序耗时: %.3f ms\n", merge_time);
		printf("随机数组堆排序耗时: %.3f ms\n", heap_time);
		printf("随机数组桶排序耗时: %.3f ms\n", bucket_time);
		printf("随机数组基数排序耗时: %.3f ms\n", radix_time);
		printf("随机数组计数排序耗时: %.3f ms\n", count_time);
		printf("\n");

		free(arr);
		free(arr_insertion);
		free(arr_bubble);
		free(arr_select);
		free(arr_shell);
		free(arr_quick);
		free(arr_merge);
		free(arr_heap);
		free(arr_bucket);
		free(arr_radix);
		free(arr_count);
	}
}

// 测试有序数组排序
void test_sorted_array_sort()
{
	int array_sizes[] = {1000, 5000, 10000, 50000};
	int num_sizes = sizeof(array_sizes) / sizeof(array_sizes[0]);
	int i, n;

	srand(time(NULL));

	for (i = 0; i < num_sizes; i++)
	{
		n = array_sizes[i];
		int *arr = (int *)malloc(n * sizeof(int));
		int *arr_insertion = (int *)malloc(n * sizeof(int));
		int *arr_bubble = (int *)malloc(n * sizeof(int));
		int *arr_select = (int *)malloc(n * sizeof(int));
		int *arr_shell = (int *)malloc(n * sizeof(int));
		int *arr_quick = (int *)malloc(n * sizeof(int));
		int *arr_merge = (int *)malloc(n * sizeof(int));
		int *arr_heap = (int *)malloc(n * sizeof(int));
		int *arr_bucket = (int *)malloc(n * sizeof(int));
		int *arr_radix = (int *)malloc(n * sizeof(int));
		int *arr_count = (int *)malloc(n * sizeof(int));

		generate_sorted_array(arr, n);

		// 测试插入排序
		copy_array(arr_insertion, arr, n);
		clock_t start_time = clock();
		InsertSort(arr_insertion, n);
		clock_t end_time = clock();
		double insertion_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试冒泡排序
		copy_array(arr_bubble, arr, n);
		start_time = clock();
		BubbleSort(arr_bubble, n);
		end_time = clock();
		double bubble_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试选择排序
		copy_array(arr_select, arr, n);
		start_time = clock();
		SelectSort(arr_select, n);
		end_time = clock();
		double select_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试希尔排序
		copy_array(arr_shell, arr, n);
		start_time = clock();
		ShellSort(arr_shell, n);
		end_time = clock();
		double shell_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试快速排序
		copy_array(arr_quick, arr, n);
		start_time = clock();
		QuickSort(arr_quick, n);
		end_time = clock();
		double quick_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试归并排序
		copy_array(arr_merge, arr, n);
		start_time = clock();
		MergeSort(arr_merge, n);
		end_time = clock();
		double merge_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试堆排序
		copy_array(arr_heap, arr, n);
		start_time = clock();
		HeapSort(arr_heap, n);
		end_time = clock();
		double heap_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试桶排序
		copy_array(arr_bucket, arr, n);
		start_time = clock();
		BucketSort(arr_bucket, n);
		end_time = clock();
		double bucket_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试基数排序
		copy_array(arr_radix, arr, n);
		start_time = clock();
		RadixSort(arr_radix, n);
		end_time = clock();
		double radix_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		// 测试计数排序
		copy_array(arr_count, arr, n);
		start_time = clock();
		CountSort(arr_count, n);
		end_time = clock();
		double count_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

		printf("数组大小: %d\n", n);
		printf("有序数组插入排序耗时: %.3f ms\n", insertion_time);
		printf("有序数组冒泡排序耗时: %.3f ms\n", bubble_time);
		printf("有序数组选择排序耗时: %.3f ms\n", select_time);
		printf("有序数组希尔排序耗时: %.3f ms\n", shell_time);
		printf("有序数组快速排序耗时: %.3f ms\n", quick_time);
		printf("有序数组归并排序耗时: %.3f ms\n", merge_time);
		printf("有序数组堆排序耗时: %.3f ms\n", heap_time);
		printf("有序数组桶排序耗时: %.3f ms\n", bucket_time);
		printf("有序数组基数排序耗时: %.3f ms\n", radix_time);
		printf("有序数组计数排序耗时: %.3f ms\n", count_time);
		printf("\n");

		free(arr);
		free(arr_insertion);
		free(arr_bubble);
		free(arr_select);
		free(arr_shell);
		free(arr_quick);
		free(arr_merge);
		free(arr_heap);
		free(arr_bucket);
		free(arr_radix);
		free(arr_count);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	test_random_array_sort();
	test_sorted_array_sort();
	// test_sort_is_true();
	return 0;
}
