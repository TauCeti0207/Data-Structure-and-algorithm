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
	//parent�ߵ�Ҷ�ӽڵ����ֹ,Ҳ����child����>=n
	while (child < n)
	{
		//ѡ�����Һ���С����һ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			//child + 1 < n ��ֹ�������һ���Һ���ʱ(����û������Һ���)����Խ��
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
//������,Ӧ�ý����,�����С��,��ı丸�ӹ�ϵ,��Ҫ���½���,Ч��̫��
HeapSort(int* arr, int sz)
{
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		//ֻ�����µ�������,ʱ�临�Ӷ�O(logN)
		AdjustDown(arr, sz, i);
	}
	int end = sz - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		//ѡ�δ��
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