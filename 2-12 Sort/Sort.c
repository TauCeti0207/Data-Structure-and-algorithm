#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
//1.先写单趟
//2.再写多趟
//画图!!
void InsertSort(int* a, int n)
{
	assert(a);
	assert(n >= 0);
	//多糖排序
	//end下标从0~n-2
	for (int i = 0; i < n - 1; i++)
	{
		//1.先写单趟排序
	//把tmp插入到数组[0,end]的有序区间中
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		//end移到-1时,需要把tmp放到a[0]里面
		//tmp>=a[end]也需要把tmp放到a[end]后面
		a[end + 1] = tmp;
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -》 3^x = n  x就是这个while循环跑的次数
	{
		//+1保证最后依次gap是1
		gap = (gap / 3 + 1);
		//先预排序,gap=1时直接插入排序
		// 最坏的情况：逆序，gap很大的时-》O(N)
		// ...
		//gap很小时本来应该是O(N*N),但是经过前面的预排序，数组已经很接近有序的，所这里还是O(N)
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				//end移到<0时,需要把tmp放到a[end+gap]里面
				//tmp>=a[end]也需要把tmp放到a[end+gap]后面
				a[end + gap] = tmp;
			}
		}
	}
}
//平均复杂度O(N^1.3)  因为gap不确定
// gap为3的情况：O(log3(N) * N) 这里log3(N)是以3为底N的对数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = left;
		//选出最大的值和最小的值
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		Swap(&a[left], &a[minIndex]);
		//极端情况下需要修正,第一个数恰好是最大的数,但它又要进行交换,改变了maxIndex的位置
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出大的孩子
		//先检查是否有越界再访问
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

void HeapSort(int* a, int n)
{
	//排升序,建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//选出最大的数,交换到最后去
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		//选次大的
		//左右子树均为大堆,只需一次向下调整就能从n-1选出原来n里面次大的数
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)
{
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n-i; j++)
		{
			if (a[i-1]>a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
	}*/

	//或者优化一下
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			//说明没有发生交换,也就是前面的恰好是有序的
			break;
		}
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//位运算效率比除法高
	//left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}



//单趟排序 hoare版本 -- 左右指针法
int PartSort1(int* a, int left, int right)
{
	//三数取中优化
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	while (left < right)
	{
		//要保证相遇位置的值一定比key先小,要让right先走
		//找小
		//left < right防止越界 
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		//交换
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	//三数取中优化
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	//先把left作为key保存起来,left的位置天生是一个坑
	int key = a[left];
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//放到左边的hole中,右边就形成新的hole
		a[left] = a[right];

		//找大
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//放到右边的hole中,左边就形成新的hole
		a[right] = a[left];
	}
	//相遇
	a[left] = key;
	return left;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	//三数取中优化
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			//prev++;
			//prev和cur相同时,交换也没影响
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	//区间有多个值时才继续,一个值都没有就return
	if (begin >= end)
		return;

	//1.如果这个子区间数据较多,继续选key单趟,分割子区间分治递归
	//2.如果子区间数据较少,再去分治递归不太划算
	if (end - begin > 10)
	{
		int keyi = PartSort3(a, begin, end);

		//[begin,keyi-1] keyi [keyi+1,end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}

	else
	{
		//考虑到分割中间的较小子区间
		InsertSort(a + begin, end - begin + 1);
	}
}
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		//先入左后入右,出来时就先出左
		right = StackTop(&st);
		StackPop(&st);
		left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}
void _Merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	//两段有序子区间归并到tmp再拷贝回去

	int i = begin1;
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//一个先结束,就把另一个的全放进去
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//拷贝回去
	for (; j <= end2; j++)
	{
		a[j] = tmp[j];
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	//[left, mid] [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	_Merge(a, tmp, left, mid, mid + 1, right);
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;//gap=1表示一一归并
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1] [i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + 2 * gap - 1;
			//分析知,如果第二个小区间不存在就不需要归并
			if (begin2 >= n)
			{
				break;
			}
			//如果第二个小区间存在,但是不够gap个,结束位置越界
			//修正一下
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			_Merge(a, tmp, begin1, end1, begin2, end2);
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//数组初始化为0
	memset(count, 0, sizeof(int) * range);
	//统计次数
	for (int i = 0; i < n; i++)
	{
		//相对映射
		count[a[i] - min]++;
	}
	//把数据写回去 count数组里放的是数据出现的次数
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count);
}