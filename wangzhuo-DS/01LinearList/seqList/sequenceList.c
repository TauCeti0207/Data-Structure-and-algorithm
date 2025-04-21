#include "define.h"
#include "sequenceList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief 在position前面插入元素e
 * 考虑平均移动次数为n/2，时间复杂度O(n)
 *
 * @param L
 * @param position
 * @param e
 * @return Status
 */
Status SqlInsert(Sqlist *L, int position, SqlElemType e)
{
    if (position < 1 || position > L->length + 1)
        return ERROR;
    if (L->length == SQLMAXSIZE)
        return OVERFLOW;
    for (
        int i = L->length - 1; i >= position - 1;
        i--)
    { // 注意需要把数组中的元素全部向右移动，需要从数组最右边的元素开始移动
        L->base[i + 1] = L->base[i];
    }
    L->base[position - 1] = e;
    L->length++;
    return OK;
}
/**
 * @brief 初始化顺序线性表
 *
 * @param L
 * @param length
 * @return Status
 */
Status InitSL(Sqlist *L, int length)
{
    L->base = (SqlElemType *)malloc(sizeof(SqlElemType) * SQLMAXSIZE);
    if (!L->base)
        return OVERFLOW;
    L->length = 0;
    for (int i = 1; i < length + 1; i++)
    {
        SqlElemType e;
        scanf(" %d", &e);
        SqlInsert(L, i, e);
    }
    return OK;
}
/**
 * @brief Get the Elem object
 *
 * @param L
 * @param position
 * @param e
 * @return Status
 */
Status getLinkListElem(Sqlist *L, int position, SqlElemType *e)
{
    if (position < 1 || position > L->length)
        return ERROR;
    *e = L->base[position - 1];
    return OK;
}
/**
 * @brief 顺序查找，时间复杂度通过算平均查找长度可知为O(N)
 *
 * @param L
 * @param e
 * @return int
 */
int locateElement(Sqlist *L, SqlElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (e == L->base[i])
            return i + 1;
    }
    return 0; // 0代表查找元素不在循序表中
}
/**
 * @brief 删除第position个元素，将要删除的元素后面的元素依次移动到前面
 *
 * @param L
 * @param position
 * @param e
 * @return Status
 */
Status SqlDelete(Sqlist *L, int position, SqlElemType *e)
{
    if (position < 1 || position > L->length)
        return ERROR;
    for (int i = position; i < L->length; i++)
    {
        L->base[i - 1] = L->base[i];
    }
    *e = L->base[position - 1];
    L->length--;
    return OK;
}

/**
 * @brief 销毁顺序表
 *
 * @param L
 * @return Status
 */
Status SqlDestroy(Sqlist *L)
{
    if (!L->base)
        return ERROR;
    else
    {
        free(L->base);
        return OK;
    }
}

/**
 * @brief 清空线性表
 *
 * @param L
 */
void SqlClear(Sqlist *L) { L->length = 0; }
/**
 * @brief 判断顺序表是否为空
 *
 * @param L
 * @return Status
 */
Status SqlIsEmpty(Sqlist *L)
{
    if (0 == L->length)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief MergeList
 *
 * @param La
 * @param Lb
 */
void MergeList(Sqlist *La, Sqlist *Lb)
{
    for (int i = 1; i < Lb->length + 1; i++)
    {
        SqlElemType e;
        getLinkListElem(Lb, i, &e);
        if (!locateElement(La, e))
        {
            La->base[La->length++] = e;
        }
    }
}

/**
 * @brief 已知线性表La 和Lb中的数据元素按值非递减有序排列，现要求将La和Lb归并为一个新的线性表Lc，且Lc中的数据元素仍按值非递减有序排列。
 *(1)创建一个空表Lc
 *(2)依次从 La 或 Lb 中“摘取”元素值较小的结点插入到 Lc 表的最后，直至其中一个表变空为止
 *(3)继续将 La 或 Lb 其中一个表的剩余结点插入在 Lc 表的最后
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeList_Seq(Sqlist *La, Sqlist *Lb, Sqlist *Lc)
{
    Lc->length = La->length + Lb->length;
    SqlElemType *pa = La->base, *pa_last = pa + La->length - 1;
    // pa指向La->base的首地址，pa_last指向base中最后一个元素的地址，下面同理
    SqlElemType *pb = Lb->base, *pb_last = pb + Lb->length - 1;
    SqlElemType *pc = Lc->base;
    while (pa <= pa_last && pb <= pb_last)
    {
        // 当pa>pa_last时说明，有集合中的元素已经全部加入到Lc中
        if (*pa < *pb)
            *(pc++) = *(pa++);
        else
            *(pc++) = *(pb++);
    }
    while (pa <= pa_last)
        *(pc++) = *(pa++); // 判断La的元素是否全部加入Lc中，下面同理
    while (pb <= pb_last)
        *(pc++) = *(pb++);
}
/**
 * @brief 打印顺序表内容
 *
 * @param L
 */
void PrintList(Sqlist L)
{
    if (L.length == 0)
    {
        printf("sequenceList is Null\n");
    }
    else
    {
        printf("sequenceList length: %d,members as follow:\n", L.length);
        for (int i = 0; i < L.length; ++i)
        {
            printf("%d ", L.base[i]);
        }
        printf("\n");
    }
}

void testMergeSeq()
{
    Sqlist La, Lb, Lc;
    La.base = (SqlElemType *)malloc(5 * sizeof(SqlElemType));
    La.length = 5;
    La.base[0] = 1;
    La.base[1] = 3;
    La.base[2] = 5;
    La.base[3] = 7;
    La.base[4] = 9;

    Lb.base = (SqlElemType *)malloc(4 * sizeof(SqlElemType));
    Lb.length = 4;
    Lb.base[0] = 2;
    Lb.base[1] = 4;
    Lb.base[2] = 6;
    Lb.base[3] = 8;

    Lc.base = (SqlElemType *)malloc((La.length + Lb.length) * sizeof(SqlElemType));

    MergeList_Seq(&La, &Lb, &Lc);

    printf("La: ");
    PrintList(La);
    printf("Lb: ");
    PrintList(Lb);
    printf("Merged List Lc: ");
    PrintList(Lc);

    free(La.base);
    free(Lb.base);
    free(Lc.base);
}
int main()
{
    testMergeSeq();
    return 0;
}
