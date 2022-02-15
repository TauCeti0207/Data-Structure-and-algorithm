#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
//1.先写单趟
//2.再写多趟
//画图!!
void InsertSort(int* a, int n)
{
	assert(a);
	assert(n >= 0);
	//多糖排序
	//end下标从0~n-2
	for (int i = 0; i < n-1; i++)
	{
		//1.先写单趟排序
	//把tmp插入到数组[0,end]的有序区间中
		int end = i;
		int tmp = a[end+1];
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