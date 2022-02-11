#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	//parent走到叶子节点就终止,也就是child坐标>=n
	while (child < n)
	{
		//选出左右孩子小的那一个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			//child + 1 < n 防止访问最后一个右孩子时(假设没有最后右孩子)发生越界
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			//a[child] >= a[parent]
			break;
		}
	}
}
//堆升序,应该建大堆,如果建小堆,会改变父子关系,需要重新建堆,效率太低
HeapSort(int* arr, int sz)
{
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		//只需向下调整即可,时间复杂度O(logN)
		AdjustDown(arr, sz, i);
	}
	int end = sz - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		//选次大的
		AdjustDown(arr, end, 0);
		end--;
	}
}
int main()
{
	int arr[] = { 15,18,28,34,65,19,49,25,37,27 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	return 0;
}