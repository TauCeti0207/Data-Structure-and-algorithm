#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
//1.��д����
//2.��д����
//��ͼ!!
void InsertSort(int* a, int n)
{
	assert(a);
	assert(n >= 0);
	//��������
	//end�±��0~n-2
	for (int i = 0; i < n-1; i++)
	{
		//1.��д��������
	//��tmp���뵽����[0,end]������������
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
		//end�Ƶ�-1ʱ,��Ҫ��tmp�ŵ�a[0]����
		//tmp>=a[end]Ҳ��Ҫ��tmp�ŵ�a[end]����
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