#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//��ʼ��
void SeqListInit(SeqList* pseq)
{
	assert(pseq);
	pseq->a = NULL;
	pseq->capacity = 0;
	pseq->size = 0;
}
//����
void SeqListDestory(SeqList* pseq)
{
	assert(pseq);
	free(pseq->a);
	pseq->a = NULL;
	pseq->capacity = pseq->size = 0;
}

void SeqCheckCapacity(SeqList* pseq)
{
	//������Ҫ����
	if (pseq->size == pseq->capacity)
	{
		//һ��ʼҪ�����ʶ�ռ�
		int newcapacity = pseq->capacity == 0 ? 4 : pseq->capacity * 2;//ͨ������2��
		SeqDataType* newA = realloc(pseq->a, sizeof(SeqDataType) * newcapacity);
		/*
		if (newA == NULL)
		{
			printf("SeqListPushBack::%s\n", strerror(errno));
		}
		*/
		//����
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pseq->a = newA;
		pseq->capacity = newcapacity;
	}
}

//β��
void SeqListPushBack(SeqList* pseq, SeqDataType x)
{
	/*assert(pseq);
	SeqCheckCapacity(pseq);
	pseq->a[pseq->size] = x;
	pseq->size++;*/
	SeqListInsert(pseq, pseq->size, x);
}

void SeqListPrint(SeqList* pseq)
{
	assert(pseq);
	for (int i = 0; i < pseq->size; i++)
	{
		printf("%d ", pseq->a[i]);
	}
	printf("\n");
}

//ͷ����Ҫ�Ӻ���ǰŲ��
void SeqListPushFront(SeqList* pseq, SeqDataType x)
{
	/*assert(pseq);
	SeqCheckCapacity(pseq);
	int end = pseq->size - 1;
	while (end >= 0)
	{
		pseq->a[end + 1] = pseq->a[end];
		--end;
	}
	pseq->a[0] = x;
	pseq->size++;*/
	SeqListInsert(pseq, 0, x);
}


//βɾ
void SeqListPopBack(SeqList* pseq)
{
	/*assert(pseq);
	assert(pseq->size > 0);
	--pseq->size;*/
	SeqListErase(pseq, pseq->size - 1);
}
//ͷɾ
void SeqListPopFront(SeqList* pseq)
{
	/*
	assert(pseq);
	assert(pseq->size > 0);
	SeqCheckCapacity(pseq);
	//�����ǰ����Ų��
	int begin = 0;
	//Ų��begin == size-1��ֹͣ
	while (begin < pseq->size - 1)
	{
		pseq->a[begin] = pseq->a[begin+1];
		begin++;
	}
	pseq->size--;
	*/

	SeqListErase(pseq, 0);
}

int SeqListFind(SeqList* pseq, SeqDataType x)
{
	assert(pseq);
	for (int i = 0; i < pseq->size; i++)
	{
		if (pseq->a[i] == x)
		{
			return i;
		}
		return -1;
	}
}


//�м����
void SeqListInsert(SeqList* pseq, int pos, SeqDataType x)
{
	assert(pseq);
	assert(pos >= 0 && pos <= pseq->size);//=sizeʱ��ʾ�ľ���β��
	SeqCheckCapacity(pseq);
	//�Ӻ���ǰŲ��
	int end = pseq->size - 1;
	while (end>=pos)
	{
		pseq->a[end + 1] = pseq->a[end];
		--end;
	}

	pseq->a[pos] = x;
	pseq->size++;
}
//�м����
void SeqListErase(SeqList* pseq, int pos)
{
	assert(pseq);
	assert(pos >= 0 && pos < pseq->size);//����=size,=sizeʱû��Ԫ�ص�
	int begin = pos;
	while (begin <= pseq->size-1)
	{
		pseq->a[begin] = pseq->a[begin + 1];
		++begin;
	}
	pseq->size--;
}

void SeqListModify(SeqList* pseq, int pos, SeqDataType x)
{
	assert(pseq);
	assert(pos >= 0 && pos < pseq->size);
	pseq->a[pos] = x;
}