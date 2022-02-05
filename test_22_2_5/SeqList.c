#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//初始化
void SeqListInit(SeqList* pseq)
{
	assert(pseq);
	pseq->a = NULL;
	pseq->capacity = 0;
	pseq->size = 0;
}
//销毁
void SeqListDestory(SeqList* pseq)
{
	assert(pseq);
	free(pseq->a);
	pseq->a = NULL;
	pseq->capacity = pseq->size = 0;
}

void SeqCheckCapacity(SeqList* pseq)
{
	//满了需要增容
	if (pseq->size == pseq->capacity)
	{
		//一开始要赋予初识空间
		int newcapacity = pseq->capacity == 0 ? 4 : pseq->capacity * 2;//通常增加2倍
		SeqDataType* newA = realloc(pseq->a, sizeof(SeqDataType) * newcapacity);
		/*
		if (newA == NULL)
		{
			printf("SeqListPushBack::%s\n", strerror(errno));
		}
		*/
		//或者
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pseq->a = newA;
		pseq->capacity = newcapacity;
	}
}

//尾插
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

//头插需要从后往前挪动
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


//尾删
void SeqListPopBack(SeqList* pseq)
{
	/*assert(pseq);
	assert(pseq->size > 0);
	--pseq->size;*/
	SeqListErase(pseq, pseq->size - 1);
}
//头删
void SeqListPopFront(SeqList* pseq)
{
	/*
	assert(pseq);
	assert(pseq->size > 0);
	SeqCheckCapacity(pseq);
	//必须从前往后挪动
	int begin = 0;
	//挪到begin == size-1就停止
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


//中间插入
void SeqListInsert(SeqList* pseq, int pos, SeqDataType x)
{
	assert(pseq);
	assert(pos >= 0 && pos <= pseq->size);//=size时表示的就是尾插
	SeqCheckCapacity(pseq);
	//从后往前挪动
	int end = pseq->size - 1;
	while (end>=pos)
	{
		pseq->a[end + 1] = pseq->a[end];
		--end;
	}

	pseq->a[pos] = x;
	pseq->size++;
}
//中间擦除
void SeqListErase(SeqList* pseq, int pos)
{
	assert(pseq);
	assert(pos >= 0 && pos < pseq->size);//不能=size,=size时没有元素的
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