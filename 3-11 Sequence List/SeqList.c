#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//��ʼ��
void SeqListInit(SeqList* pseq)
{
	assert(pseq);
	pseq->a = NULL;//pseq->��ָ��Ľ�����
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
        //һ��ʼҪ�����ʼ�ռ�
        int newcapacity = pseq->capacity == 0 ? 4 : pseq->capacity * 2;//ͨ������2��
        SeqDataType* newA = realloc(pseq->a, sizeof(SeqDataType) * newcapacity);//��һ�ν�����ʱ��size=capacity=0��pseq->a=NULL, ��ʱrealloc�ȼ���malloc
        //����
        if (newA == NULL)//�п�
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            pseq->a = newA;
            pseq->capacity = newcapacity;
        }
    }
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

////β��
//void SeqListPushBack(SeqList* pseq, SeqDataType x)
//{
//    assert(pseq);
//    SeqCheckCapacity(pseq);
//    pseq->a[pseq->size] = x;
//    pseq->size++;
//}

////ͷ�� ������Ҫ����Ų������Ų�Ĺ����п��ܲ���Խ�磬����ȼ��ռ��Ƿ��㹻
//void SeqListPushFront(SeqList* pseq, SeqDataType x)
//{
//    assert(pseq);
//    SeqCheckCapacity(pseq);
//    int end = pseq->size - 1;//size��ֵǡ�þ������һ��ֵ����һ��
//    while (end >= 0)//�ѵ�һ��λ�õ�����ҲŲ��ʱ�ͽ���
//    {
//        pseq->a[end + 1] = pseq->a[end];
//        --end;
//    }
//    //����ʱ��endָ��-1
//    pseq->a[0] = x;
//    pseq->size++;
//}
////ͷ��ʱ�临�Ӷ�O(N)
////β��ʱ�临�Ӷ�O(1)

//β��
void SeqListPushBack(SeqList* pseq, SeqDataType x)
{
    SeqListInsert(pseq, pseq->size, x);
}
//ͷ��
void SeqListPushFront(SeqList* pseq, SeqDataType x)
{
    SeqListInsert(pseq, 0, x);
}

////βɾ
//void SeqListPopBack(SeqList* pseq)
//{
//    assert(pseq);//��ֹ����ָ��
//    assert(pseq->size > 0);//�ö��ԱȽϱ�����������if����size<
//    --pseq->size;
//}
////ͷɾ
//void SeqListPopFront(SeqList* pseq)
//{
//    assert(pseq);
//    assert(pseq->size > 0);//����˳����ﶼûԪ���ˣ�����ɾ��
//    //�����ǰ����Ų��
//    int begin = 0;
//    //Ų��begin == size-1��ֹͣ
//    while (begin < pseq->size - 1)
//    {
//        pseq->a[begin] = pseq->a[begin + 1];
//        begin++;
//    }
//    --pseq->size;
//}
////ͷɾʱ�临�Ӷ�O(N)
////βɾʱ�临�Ӷ�O(1)


//βɾ
void SeqListPopBack(SeqList* pseq)
{
    SeqListErase(pseq, pseq->size - 1);
}
//ͷɾ
void SeqListPopFront(SeqList* pseq)
{
    SeqListErase(pseq, 0);
}

////�м����
//void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x)
//{
//    assert(pseq);
//    assert(pos <= pseq->size);//=sizeʱ��ʾ�ľ���β��
//    SeqCheckCapacity(pseq);
//    //�Ӻ���ǰŲ��
//    size_t end = pseq->size - 1;
//    while (end >= pos)
//    {
//        pseq->a[end + 1] = pseq->a[end];
//        --end;
//    }
//    pseq->a[pos] = x;
//    pseq->size++;
//}

////�м����
//void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x)
//{
//    assert(pseq);
//    assert(pos <= pseq->size);//=sizeʱ��ʾ�ľ���β��
//    SeqCheckCapacity(pseq);
//    //�Ӻ���ǰŲ��
//    size_t end = pseq->size - 1;
//    while ((int)end >= (int)pos)
//    {
//        pseq->a[end + 1] = pseq->a[end];
//        --end;
//    }
//    pseq->a[pos] = x;
//    pseq->size++;
//}

//�м����
void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x)
{
    assert(pseq);
    assert(pos <= pseq->size);//=sizeʱ��ʾ�ľ���β��
    SeqCheckCapacity(pseq);
    //�Ӻ���ǰŲ��
    size_t end = pseq->size;
    while (end > pos)
    {
        pseq->a[end] = pseq->a[end - 1];
        --end;
    }
    pseq->a[pos] = x;
    pseq->size++;
}

//�м����
void SeqListErase(SeqList* pseq, size_t pos)
{
    assert(pseq);
    assert(pos < pseq->size);//����=size��=sizeʱû��Ԫ�ص�
    size_t begin = pos + 1;
    while (begin < pseq->size)
    {
        pseq->a[begin - 1] = pseq->a[begin];
        ++begin;
    }
    pseq->size--;
}

//����
int SeqListFind(SeqList* pseq, SeqDataType x)
{
    assert(pseq);
    for (int i = 0; i < pseq->size; i++)
    {
        if (x == pseq->a[i])
            return i;
    }
    return -1;
}

//�޸�
void SeqListModify(SeqList* pseq, size_t pos, SeqDataType x)
{
    assert(pseq);
    assert(pos < pseq->size);
    pseq->a[pos] = x;
}