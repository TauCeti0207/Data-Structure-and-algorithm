/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-04-10 21:46:39
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-04-14 12:27:49
 */
/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-04-10 21:46:20
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-04-11 17:04:14
 */
#include "sort.h"
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 冒泡排序
void BubbleSort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			// 前面的比后面的大就交换，升序
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void BubbleSort2(int *arr, int n)
{
	// 用标志位优化一下
	bool exchange = false;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (j = 0; j < n - 1 - i; j++)
		{
			// 前面的比后面的大就交换，升序
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				exchange = true; // 交换过，说明已经有序了
			}
		}
		if (exchange == false)
		{
			// 说明没有发生交换，也就是前面的是有序的，直接退出
			break;
		}
	}
}

// 选择排序
void SelectSort(int *arr, int n)
{
	int i, j, minPos;
	// 外层循环控制比较的趟数 n 个元素，n-1趟
	for (i = 0; i < n - 1; i++)
	{
		// 默认最小值位置就是当前位置
		minPos = i;
		// 每比较一趟，有序序列增加一个，无序序列减少一个
		// 无序序列的起始位置一直往后移动，也就是 i+1
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minPos])
			{
				minPos = j;
			}
		}
		// 如果最小值不是当前位置，则交换
		if (minPos != i)
		{
			Swap(&arr[i], &arr[minPos]);
		}
	}
}

// 插入排序
void InsertSort(int *arr, int n)
{
	int i, j, tmp;
	// 最外层循环还是控制趟数，n个数要比较n-1趟
	// 默认第一个数是有序的
	for (i = 1; i < n; i++)
	{
		// 拿出无序序列第一个元素保存到 tmp
		tmp = arr[i];
		int end = i - 1;
		// [0, end] end+1  把tmp插入到数组[0,end]的有序区间中
		// 内层循环，将满足条件的数据从前面移动到后面
		while (end >= 0 && arr[end] > tmp)
		{
			// 有序数据后移
			arr[end + 1] = arr[end];
			end--;
		}
		// 无序数据前移
		arr[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int *arr, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int tmp = arr[i];
			// j是有序序列的最后一个元素
			int j = i - gap;
			while (j >= 0 && arr[j] > tmp)
			{
				// 前面的数往后移，间隔 gap 位置
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = tmp;
		}
	}
}

// 快排

void _QuickSort(int *arr, int left, int right)
{
	// 递归退出条件
	if (left >= right)
		return;
#if 0
	// 以中间数为基准
	int pivot = arr[(left + right) / 2];
	int begin = left, end = right;
	while (begin <= end)
	{
		// 从左右两边开始比较 注意不要越界
		while (arr[begin] < pivot && begin <= end)
		{
			begin++;
		}
		while (arr[end] > pivot && begin <= end)
		{
			end--;
		}
		if (begin <= end)
		{
			Swap(&arr[begin], &arr[end]);
			begin++;
			end--;
		}
	}
	// 两种情况，1、begin = end 出来，还会有一次 begin++ end--，最终[... end xx begin ...]
	// 2、begin > end 出来，[... end begin ...]
	QuickSort(arr, left, end);	  // 左侧序列
	QuickSort(arr, begin, right); // 右侧序列
#else
	// 另一种优化的写法
	// 以中间数为基准
	int pivot = arr[left + (right - left) / 2];
	int begin = left - 1, end = right + 1;
	while (begin < end)
	{
		do
		{
			begin++;
		} while (arr[begin] < pivot);
		do
		{
			end--;
		} while (arr[end] > pivot);
		if (begin < end)
		{
			Swap(&arr[begin], &arr[end]);
		}
	}
	// 出来之后，2 种情况，1、begin = end, begin、end指向相同位置
	// 2、end 在 begin 前面 [end begin]
	_QuickSort(arr, left, end);
	_QuickSort(arr, end + 1, right);
#endif
}

void QuickSort(int *arr, int n)
{
	_QuickSort(arr, 0, n - 1);
}

// 归并排序
void _MergeSort(int *arr, int left, int right, int *tmp)
{
	// 递归终止条件
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	// 合并 2 个有序子序列
	int tmpIndex = 0;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		// 加上=判定保证排序是稳定的
		if (arr[i] <= arr[j])
		{
			tmp[tmpIndex++] = arr[i++];
		}
		else
		{
			tmp[tmpIndex++] = arr[j++];
		}
	}
	// 剩余部分直接拷贝
	while (i <= mid)
	{
		tmp[tmpIndex++] = arr[i++];
	}
	while (j <= right)
	{
		tmp[tmpIndex++] = arr[j++];
	}
	// 将 tmp 数组拷贝到原数组
	for (int k = 0; k < tmpIndex; k++)
	{
		arr[left + k] = tmp[k];
	}
}
void MergeSort(int *arr, int n)
{
	int *tmp = (int *)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

// 排大根堆
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出大的孩子
		// 先检查是否有越界再访问
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *a, int n)
{
	// 排升序，建大堆，找到最后一个非叶子节点，也就是最后一个叶子节点父亲
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		// 第一次调整的根节点是最后一个非叶子节点，之后每次都是--i
		AdjustDown(a, n, i);
	}
	// 选出最大的数,交换到最后去
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		// 选次大的
		//  下一次调整，不包含最后的节点，根节点是 0
		AdjustDown(a, end, 0);
		end--;
	}
}

// 桶排序
void BucketSort(int arr[], int n)
{
	// 若数组为空或只有一个元素，无需排序
	if (n <= 1)
	{
		return;
	}

	// 找到数组中的最大值和最小值，用于计算桶的范围
	int max = arr[0], min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	// 动态确定桶的数量
	int numBuckets = (int)sqrt((double)n);

	// 计算每个桶的范围 例如，范围是 4，表示第一个桶涵盖区间[1,5)的数 第二个桶[5,9)...
	// 加上 1 是为了保证即使在除法运算有小数部分的情况下，所有数据都能被分配到相应的桶中，避免出现数据遗漏。
	int range = (max - min) / numBuckets + 1;

	// 创建桶
	int **buckets = (int **)malloc(numBuckets * sizeof(int *));
	for (int i = 0; i < numBuckets; i++)
	{
		buckets[i] = (int *)malloc(n * sizeof(int));
		buckets[i][0] = 0; // 每个桶的第一个元素用于记录桶中元素的数量
	}

	// 将元素分配到桶中
	for (int i = 0; i < n; i++)
	{
		// 计算当前元素应该被分配到哪个桶中
		int bucketIndex = (arr[i] - min) / range;
		// 获取当前桶中元素的数量
		int bucketSize = buckets[bucketIndex][0];
		// 将元素插入到桶中
		buckets[bucketIndex][bucketSize + 1] = arr[i];
		buckets[bucketIndex][0]++;
	}

	// 对每个桶中的元素进行排序，并合并到原数组中
	int index = 0;
	for (int i = 0; i < numBuckets; i++)
	{
		int bucketSize = buckets[i][0];
		// buckets[i][0] 是计数器，真正的元素从 buckets[i][1] 开始
		InsertSort(&buckets[i][1], bucketSize);
		for (int j = 1; j <= bucketSize; j++)
		{
			arr[index++] = buckets[i][j];
		}
		free(buckets[i]);
	}
	free(buckets);
}

void RadixSort(int arr[], int n)
{
	// 找到数组最大值
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	// 计算最大值位数
	int len = 0;
	int tmp = max;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}

	// 创建桶
	int **buckets = (int **)malloc(sizeof(int *) * 10);
	for (int i = 0; i < 10; i++)
	{
		buckets[i] = (int *)malloc(sizeof(int) * n);
	}
	// 记录每个桶中元素的数量
	int bucketSize[10] = {0};
	int mod = 10, div = 1;
	// 外层 for 循环根据最大值的位数 len 进行迭代，每一轮处理一个数位。
	for (int i = 0; i < len; i++, mod *= 10, div *= 10)
	{
		// 清空桶大小
		for (int j = 0; j < 10; j++)
		{
			bucketSize[j] = 0;
		}
		// 将元素分配到桶中
		/* 假设当前要处理的数组 arr 为 [12, 25, 37, 4, 18]，并且正在处理个位，num 是当前元素个位上的数字。
		当 j = 0 时，arr[0] 为 12，num = 2，这表明该元素要放到编号为 2 的桶里。如果此时 bucketSize[2] 为 0，那么 arr[0] 就会被存放在 buckets[2][0] 这个位置，接着 bucketSize[2] 变为 1。
		当 j = 1 时，arr[1] 为 25，num = 5，该元素会被放到编号为 5 的桶里。若此时 bucketSize[5] 为 0，那么 arr[1] 就会被存放在 buckets[5][0] 位置，随后 bucketSize[5] 变为 1。 */
		for (int j = 0; j < n; j++)
		{
			// 一开始是个位，然后是十位，百位。。。
			int num = (arr[j] % mod) / div;
			// 当前元素 arr[j] 放到编号为 num 的桶里，具体位置是该桶内当前最后一个元素的下一个位置。
			buckets[num][bucketSize[num]] = arr[j];
			bucketSize[num]++;
		}

		// 将桶中元素放回原数组
		int index = 0;
#if 1
		// 升序排列
		for (int j = 0; j < 10; j++)
		{
			if (bucketSize[j] != 0)
			{
				for (int k = 0; k < bucketSize[j]; k++)
				{
					arr[index++] = buckets[j][k];
				}
			}
		}
#else
		// 降序排列 从最大编号的桶开始遍历到最小编号的桶
		for (int j = 9; j >= 0; j--)
		{
			if (bucketSize[j] != 0)
			{
				for (int k = 0; k < bucketSize[j]; k++)
				{
					arr[index++] = buckets[j][k];
				}
			}
		}
#endif
	}
	// 释放桶内存
	for (int j = 0; j < 10; j++)
	{
		free(buckets[j]);
	}
	free(buckets);
}
