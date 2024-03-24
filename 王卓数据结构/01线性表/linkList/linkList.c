#include "define.h"
#include "linkList.h"
/**
 * @brief
 * 彻底理解链表中为何使用二级指针或者一级指针的引用
 * https://zhuanlan.zhihu.com/p/198190623
 *
 * @param L
 * @return Status
 */
Status InitLL(LinkList *L) // L是个二级指针 要修改指针就得传指针地址，也就是二级指针，或者是一级指针的引用也可以。
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

int ListEmpty(LinkList L)
{
    if (L->next) // 飞空
        return 0;
    else
        return 1;
}
Status LlDestroy(LinkList *L) // 二级指针
{
    if (!(*L))
        return ERROR;
    LinkList p = *L;
    while (p)
    {
        LinkList pfree = p; // pfree保存要释放的节点地址
        p = p->next;        // 此行和下行的顺序不能反
        free(pfree);
        pfree = NULL;
    }
    *L = NULL;
    return OK;
}
/**
 * @brief 将L重置为空表
 *
 * @param L
 * @return Status
 */
Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p) // 没到表尾
    {
        q = p->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL; // 头结点指针域为空
    return OK;
}
int ListLength(LinkList L)
{ // 返回L中数据元素个数
    LinkList p;
    p = L->next;
    int i = 0; // 初始化计数器为0

    while (p != NULL)
    {        // 遍历单链表，统计结点数
        i++; // 每遍历一个结点，计数器加1
        p = p->next;
    }

    return i; // 返回链表长度
}

int main()
{
    /* code */
    return 0;
}
