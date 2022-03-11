#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//初始化
void SeqListInit(SeqList* pseq)
{
	assert(pseq);
	pseq->a = NULL;//pseq->对指针的解引用
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
        //一开始要赋予初始空间
        int newcapacity = pseq->capacity == 0 ? 4 : pseq->capacity * 2;//通常增加2倍
        SeqDataType* newA = realloc(pseq->a, sizeof(SeqDataType) * newcapacity);//第一次进来的时候，size=capacity=0，pseq->a=NULL, 此时realloc等价于malloc
        //或者
        if (newA == NULL)//判空
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

////尾插
//void SeqListPushBack(SeqList* pseq, SeqDataType x)
//{
//    assert(pseq);
//    SeqCheckCapacity(pseq);
//    pseq->a[pseq->size] = x;
//    pseq->size++;
//}

////头插 数据需要往后挪，往后挪的过程中可能产生越界，因此先检查空间是否足够
//void SeqListPushFront(SeqList* pseq, SeqDataType x)
//{
//    assert(pseq);
//    SeqCheckCapacity(pseq);
//    int end = pseq->size - 1;//size的值恰好就是最后一个值的下一个
//    while (end >= 0)//把第一个位置的数据也挪走时就结束
//    {
//        pseq->a[end + 1] = pseq->a[end];
//        --end;
//    }
//    //结束时，end指向-1
//    pseq->a[0] = x;
//    pseq->size++;
//}
////头插时间复杂度O(N)
////尾插时间复杂度O(1)

//尾插
void SeqListPushBack(SeqList* pseq, SeqDataType x)
{
    SeqListInsert(pseq, pseq->size, x);
}
//头插
void SeqListPushFront(SeqList* pseq, SeqDataType x)
{
    SeqListInsert(pseq, 0, x);
}

////尾删
//void SeqListPopBack(SeqList* pseq)
//{
//    assert(pseq);//防止传空指针
//    assert(pseq->size > 0);//用断言比较暴力，可以用if限制size<
//    --pseq->size;
//}
////头删
//void SeqListPopFront(SeqList* pseq)
//{
//    assert(pseq);
//    assert(pseq->size > 0);//避免顺序表里都没元素了，还在删除
//    //必须从前往后挪动
//    int begin = 0;
//    //挪到begin == size-1就停止
//    while (begin < pseq->size - 1)
//    {
//        pseq->a[begin] = pseq->a[begin + 1];
//        begin++;
//    }
//    --pseq->size;
//}
////头删时间复杂度O(N)
////尾删时间复杂度O(1)


//尾删
void SeqListPopBack(SeqList* pseq)
{
    SeqListErase(pseq, pseq->size - 1);
}
//头删
void SeqListPopFront(SeqList* pseq)
{
    SeqListErase(pseq, 0);
}

////中间插入
//void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x)
//{
//    assert(pseq);
//    assert(pos <= pseq->size);//=size时表示的就是尾插
//    SeqCheckCapacity(pseq);
//    //从后往前挪动
//    size_t end = pseq->size - 1;
//    while (end >= pos)
//    {
//        pseq->a[end + 1] = pseq->a[end];
//        --end;
//    }
//    pseq->a[pos] = x;
//    pseq->size++;
//}

////中间插入
//void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x)
//{
//    assert(pseq);
//    assert(pos <= pseq->size);//=size时表示的就是尾插
//    SeqCheckCapacity(pseq);
//    //从后往前挪动
//    size_t end = pseq->size - 1;
//    while ((int)end >= (int)pos)
//    {
//        pseq->a[end + 1] = pseq->a[end];
//        --end;
//    }
//    pseq->a[pos] = x;
//    pseq->size++;
//}

//中间插入
void SeqListInsert(SeqList* pseq, size_t pos, SeqDataType x)
{
    assert(pseq);
    assert(pos <= pseq->size);//=size时表示的就是尾插
    SeqCheckCapacity(pseq);
    //从后往前挪动
    size_t end = pseq->size;
    while (end > pos)
    {
        pseq->a[end] = pseq->a[end - 1];
        --end;
    }
    pseq->a[pos] = x;
    pseq->size++;
}

//中间擦除
void SeqListErase(SeqList* pseq, size_t pos)
{
    assert(pseq);
    assert(pos < pseq->size);//不能=size，=size时没有元素的
    size_t begin = pos + 1;
    while (begin < pseq->size)
    {
        pseq->a[begin - 1] = pseq->a[begin];
        ++begin;
    }
    pseq->size--;
}

//查找
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

//修改
void SeqListModify(SeqList* pseq, size_t pos, SeqDataType x)
{
    assert(pseq);
    assert(pos < pseq->size);
    pseq->a[pos] = x;
}