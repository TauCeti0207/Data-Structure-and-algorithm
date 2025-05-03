/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-04-10 21:46:39
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-03 20:16:52
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
#if 0
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

#else
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
#endif
}

// 选择排序
void SelectSort(int *arr, int n)
{
#if 0
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
#else
	// 同时选最大最小
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = left;
		// 选出最大的值和最小的值
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
			if (arr[i] > arr[maxIndex])
			{
				maxIndex = i;
			}
		}
		// 最左边的是最小的
		Swap(&arr[left], &arr[minIndex]);
		// 极端情况下第一个数恰好是最大的数，此时的 maxi 已经被换到原先的 minIndex 的位置
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&arr[right], &arr[maxIndex]);
		++left;
		--right;
	}
#endif
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

// 通过比较数组的左端点、中点、右端点这三个位置的值，返回其中中间值的索引，以减少极端情况下
int GetMidIndex(int *arr, int left, int right)
{
	// int mid = left + ((right - left) >> 1);
	// 使用随机的三数取中
	int mid = left + rand() % (right - left + 1);

#if 0
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
		{
			// left mid right
			return mid;
		}
		else if (arr[left] < arr[right])
		{
			// left right mid
			return right;
		}
		else
		{
			// right left mid
			return left;
		}
	}
	else // arr[left] > arr[mid]
	{
		if (arr[mid] > arr[right])
		{
			// right mid left
			return mid;
		}
		else if (arr[left] < arr[right])
		{
			// 此时说明arr[mid] <= arr[right] 故再判断一下 left 和 right 关系就行
			// mid left right
			return left;
		}
		else //
		{
			// mid right left
			return right;
		}
	}
#elif 1
	if (arr[left] > arr[mid])
		Swap(&arr[left], &arr[mid]); // 保证left ≤ mid
	if (arr[left] > arr[right])
		Swap(&arr[left], &arr[right]); // 此时left 是最小的
	if (arr[mid] > arr[right])
		Swap(&arr[mid], &arr[right]); // 确保mid ≤ right
	return mid;						  // 此时 mid 是中间值
#endif
}

// PartSort1 实现分区逻辑，返回基准最终位置 hoare 版本-左右指针法
int PartSort1(int *arr, int left, int right)
{
	// 三数取中优化
	int mid = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[mid]);

	// 选择左端点作为基准
	int keyi = left;
	while (left < right)
	{
		// 要保证相遇位置的值一定比key先小，因此要让right先走
		// 因为基准在左端点，需要先确保右侧有更小的元素可以换到左边。
		// 右边找小
		while (left < right && arr[right] >= arr[keyi])
		{
			right--;
		}
		// 左边找大 left < right防止越界
		while (left < right && arr[left] <= arr[keyi])
		{
			left++;
		}

		if (left < right)
		{
			// left == right 不需要交换
			Swap(&arr[left], &arr[right]);
		}
	}
	Swap(&arr[keyi], &arr[left]); // 将基准值放到相遇位置
	return left;				  // 返回基准的最终下标
}

// 挖坑法
int PartSort2(int *arr, int left, int right)
{
	// 三数取中优化
	int mid = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[mid]);

	// 选择左端点作为基准
	int key = arr[left];
	int hole = left;
	while (left < right)
	{
		// 右边找小 找到后填入坑，并且自己形成新的坑
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		// 左边找大 left < right防止越界
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	// left和right在坑上相遇
	arr[hole] = key;
	return hole;
}

// 前后指针法
int PartSort3(int *arr, int left, int right)
{
	// 三数取中优化
	int mid = GetMidIndex(arr, left, right);
	Swap(&arr[left], &arr[mid]);

	// 选择左端点作为基准
	int keyi = left; // 最后要进行交换，因此定义 keyi 更好
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			// 自己和自己没必要换，提高效率
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	Swap(&arr[keyi], &arr[prev]);
	keyi = prev;
	return keyi;
}

void _QuickSort2(int *arr, int begin, int end)
{
	// 1、区间只有一个值 2、区间不存在
	if (begin >= end)
		return;
	// 小区间优化
	if (end - begin + 1 < 10)
	{
		InsertSort(arr + begin, end - begin + 1);
		return;
	}
	// int keyi = PartSort1(arr, begin, end);
	// int keyi = PartSort2(arr, begin, end);
	int keyi = PartSort3(arr, begin, end);

	// [begin, keyi-1] keyi [keyi+1, end]
	_QuickSort2(arr, begin, keyi - 1);
	_QuickSort2(arr, keyi + 1, end);
}

void QuickSortNonR(int *a, int begin, int end)
{
	// 核心思想是将待排序的子数组的起始和结束位置压入栈中，然后不断从栈中取出子数组进行分区操作，
	// 并将分区后的左右子数组的起始和结束位置（如果存在）压入栈中，直到栈为空
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		// 先入左后入右，出来时就先出右后出左，保证后进先出
		right = StackTop(&st);
		StackPop(&st);
		left = StackTop(&st);
		StackPop(&st);
		// 每次出栈，对出栈的下标区间进行一次部分排序
		// 调用 PartSort3 函数对当前子数组 [left, right] 进行分区操作，得到基准元素的最终位置 keyi。
		// 选出 keyi 之后，左边的元素都比它小，右边的元素都比它大
		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		if (left < keyi - 1) // 左区间元素个数不少于2才入栈
		{
			// 这里始终保持的是先入左后入右，之后出的时候就是先出右后出左
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
		if (keyi + 1 < right) // 右区间元素个数不少于2才入栈
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}

// 三路划分
// 小的甩到左边，大的甩到右边，相等的到中间
void _QuickSort3(int *arr, int begin, int end)
{
	// 1、区间只有一个值 2、区间不存在
	if (begin >= end)
		return;
	// 小区间优化
	if (end - begin + 1 < 10)
	{
		InsertSort(arr + begin, end - begin + 1);
		return;
	}

	// 三数取中优化
	int midIndex = GetMidIndex(arr, begin, end);
	Swap(&arr[begin], &arr[midIndex]);

	// 选择左端点作为基准
	int key = arr[begin];
	// lt最终移动到基准值部分的左边界；gt最终移动到基准值部分的右边界
	int left = begin;
	int right = end;
	int cur = left + 1;

	while (cur <= right)
	{
		if (arr[cur] < key)
		{
			Swap(&arr[cur], &arr[left]);
			left++;
			cur++;
		}
		else if (arr[cur] > key)
		{
			// 注意，比key 大的交换过来后，不能移动 i，因为不确定交换过来的 arr[gt]大小
			// 只要保证大于 key 的值交换到右边就行
			Swap(&arr[cur], &arr[right]);
			right--;
		}
		else // 与 key 相等的情况
		{
			cur++;
		}
	}
	// [begin, left-1] [left, right] [right+1, end] [left, right]这段区间是与 key 相等的值
	// 中间相等这段已经是排好的
	_QuickSort3(arr, begin, left - 1);
	_QuickSort3(arr, right + 1, end);
}

void QuickSort(int *arr, int n)
{
#if 0
	_QuickSort(arr, 0, n - 1);
#elif 0
	_QuickSort2(arr, 0, n - 1);
#elif 1
	// 三路划分
	_QuickSort3(arr, 0, n - 1);
#elif 0
	QuickSortNonR(arr, 0, n - 1);
#endif
}

// 归并排序
void _MergeSort(int *arr, int left, int right, int *tmp)
{
	// 递归终止条件
	if (left >= right)
	{
		return;
	}
#if 1
	// 小区间优化
	if (right - left + 1 < 10)
	{
		InsertSort(arr + left, right - left + 1);
		return;
	}
#elif 0
#endif
	int mid = left + ((right - left) >> 1);
	// 让左右区间有序[left, mid] [mid+1, right]
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	// 合并 2 个有序子序列
	// int i = 0; // 之后从tmp拷贝回原数组的起始位置取决于i的值
	int i = left;
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	// 逐个比较，将较小的值拷贝到 tmp 数组
	while (begin1 <= end1 && begin2 <= end2)
	{
		// 加上=判定保证排序是稳定的
		if (arr[begin1] <= arr[begin2])
		{
			tmp[i++] = arr[begin1++];
		}
		else
		{
			tmp[i++] = arr[begin2++];
		}
	}
	// 剩余部分直接拷贝
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	// 将 tmp 数组拷贝到原数组
#if 0
	// 这里 int i = left
	for (int k = 0; k < right - left + 1; k++)
	{
		arr[left + k] = tmp[k + left];
	}
#elif 1
	// 用库函数也可以 注意拷贝的起始位置，位置不是从 0 开始的
	memcpy(arr + left, tmp + left, sizeof(int) * (right - left + 1));
#elif 0
	// 如果 int i = 0，tmp 也要从 0 位置开始拷贝过去
	for (int k = 0; k < i; k++)
	{
		arr[k + left] = tmp[k];
	}
#endif
}

void MergeSortNonR(int *arr, int n)
{
#if 0
	int *tmp = (int *)malloc(sizeof(int) * n);
	assert(tmp);
	int gap = 1;
	while (gap < n)
	{
		// gap是 1 2 4 8...
		// j 建议放在 for 循环外面，这样每次归并的时候，拷贝到 tmp 数组是从 0 开始顺序拷贝过去
		int j = 0;
		// 每组 gap 个， 第一组归并完去归并第二组，然后再去第三组。。。
		for (int i = 0; i < n; i += 2 * gap)
		{
			// 一组一组来归并
			// 控制好每组的起点和终点位置，因为是坐标，需要-1，每组 gap 个，
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// begin1不会越界，当 end1 或 begin2 超出数组边界时，说明当前已经没有完整的两组子数组可供归并，直接跳出当前内层循环，继续下一次 gap 的归并操作。
			if (end1 >= n || begin2 >= n)
			{
				// 越界直接 break，就不会继续归并，也就不会继续拷贝数据回原数组
				break;
			}
			// 修正 end2，这样可以继续归并，从而把数据拷贝回去
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				// 小的值拷贝到tmp
				if (arr[begin1] <= arr[begin2])
				{
					tmp[j++] = arr[begin1++];
				}
				else
				{
					tmp[j++] = arr[begin2++];
				}
			}
			// 拷贝剩余的值到 tmp
			while (begin1 <= end1)
			{
				tmp[j++] = arr[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = arr[begin2++];
			}
			// 归并一组，拷贝一组 这里其实就是 end2-begin1+1，只不过 begin1 变化了，i就是最开始的起始位置
			memcpy(arr + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		// memcpy(arr, tmp, sizeof(int) * n);
		// 一一归并之后就是两两归并，依次进行
		gap *= 2;
	}
	free(tmp);
#elif 1
	int *tmp = (int *)malloc(sizeof(int) * n);
	assert(tmp);
	int gap = 1;
	while (gap < n)
	{
		// printf("gap=%d\n", gap);
		// gap是 1 2 4 8...
		// j 建议放在 for 循环外面，这样每次归并的时候，拷贝到 tmp 数组是从 0 开始顺序拷贝过去
		int j = 0;
		// 每组 gap 个， 第一组归并完去归并第二组，然后再去第三组。。。
		for (int i = 0; i < n; i += 2 * gap)
		{
			// 一组一组来归并
			// 控制好每组的起点和终点位置，因为是坐标，需要-1，每组 gap 个，
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// printf("修正前：[%d,%d][%d,%d]\n", begin1, end1, begin2, end2);
			if (end1 >= n)
			{
				end1 = n - 1;
				// 将第二个区间修正成不存在的区间，也就是 begin2 > end2
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				// 到这里说明 end1 没越界，begin2 越界
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				// 到这里说明 end1 没越界，begin2 没越界，end2 越界
				end2 = n - 1;
			}
			// printf("修正后：[%d,%d][%d,%d]\n", begin1, end1, begin2, end2);

			while (begin1 <= end1 && begin2 <= end2)
			{
				// 小的值拷贝到tmp
				if (arr[begin1] <= arr[begin2])
				{
					tmp[j++] = arr[begin1++];
				}
				else
				{
					tmp[j++] = arr[begin2++];
				}
			}
			// 拷贝剩余的值到 tmp
			while (begin1 <= end1)
			{
				tmp[j++] = arr[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = arr[begin2++];
			}
		}
		// 这里采用整体拷贝的思路，针对越界的情况就要采取修正的策略，不能直接 break
		// 如果直接 break，然后又整体拷贝，就会导致原来的数组丢失数据
		memcpy(arr, tmp, sizeof(int) * n);
		// 一一归并之后就是两两归并，依次进行
		gap *= 2;
	}
	free(tmp);
#endif
}

void MergeSort(int *arr, int n)
{
#if 0
	int *tmp = (int *)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
#elif 1
	// 非递归归并
	MergeSortNonR(arr, n);
#endif
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

void CountSort(int *a, int n)
{
	// 寻找数组中的最大值和最小值
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	// 计算取值范围并分配计数数组
	int range = max - min + 1;
	int *countArr = (int *)malloc(sizeof(int) * range);
	assert(countArr);
	// 数组初始化为0
	memset(countArr, 0, sizeof(int) * range);
	// 统计次数
	for (int i = 0; i < n; i++)
	{
		// 相对映射
		countArr[a[i] - min]++;
	}
	// 把数据写回去 count数组里放的是数据出现的次数
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArr[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(countArr);
}