#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//�Ѵ����������鿽������
	memcpy(php->a, a, sizeof(HPDataType) * n);
	php->size = n;
	php->capacity = n;

	//����
	for (int i = (php->size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, php->size, i);
	}
}

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
		//ѡ�����Һ��Ӵ����һ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			//child + 1 < n ��ֹ�������һ���Һ���ʱ(����û�������Һ���)����Խ��
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
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	//������Ҫ����
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	//�������ݺ�,��Ҫ��Ӧ�ı�·��,���ϵ����㷨
	php->size++;
	AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	//ɾ�������������ԭ�Ѷ�����
	php->size--;
	//��0��ʼ���µ���
	AdjustDown(php->a, php->size, 0);
	//���ƶ������˼��,ֻ����������ɾ�������һ��λ���ϵ�����,��������������
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void HeapPrint(HP* php)
{

	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");

	int num = 0;
	int levelSize = 1;
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
		num++;
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

void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)  chile=0ʱ,�������parentҲ����0 parent����<0
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}