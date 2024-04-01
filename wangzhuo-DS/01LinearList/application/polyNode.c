#include <stdio.h>
#include <stdlib.h>

// 定义多项式的一个项
typedef struct PolyNode
{
    int coefficient;       // 系数
    int exponent;          // 指数
    struct PolyNode *next; // 指向下一个节点的指针
} PolyNode;

// 创建一个新节点 无哨兵节点
PolyNode *createNode(int coefficient, int exponent)
{
    PolyNode *newNode = (PolyNode *)malloc(sizeof(PolyNode));
    if (!newNode)
        return NULL;
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}
void freePoly(PolyNode *poly)
{
    PolyNode *current = poly;
    while (current != NULL)
    {
        PolyNode *nextNode = current->next; // 保存下一个节点的地址
        free(current);                      // 释放当前节点
        current = nextNode;                 // 移动到下一个节点
    }
}

// 添加新项到多项式中 指数从小到大
void addPolyNode(PolyNode **poly, int coefficient, int exponent)
{
    // 创建新的节点
    PolyNode *newNode = createNode(coefficient, exponent);
    if (!newNode)
        return;

    // 如果链表为空，或者新节点的指数小于头节点的指数，则将新节点插入为头节点
    if (*poly == NULL || exponent < (*poly)->exponent)
    {
        newNode->next = *poly; // newNode插在了poly节点前面
        *poly = newNode;
    }
    else
    {
        // 寻找插入位置：遍历链表直到找到指数大于等于新节点指数的节点
        PolyNode *current = *poly;
        while (current->next != NULL && current->next->exponent < exponent)
        {
            current = current->next;
        }
        // 插入新节点到链表中
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 打印多项式
void printPoly(PolyNode *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
            printf("+ ");
    }
    printf("\n");
}

// 多项式加法
PolyNode *addPolynomials(PolyNode *poly1, PolyNode *poly2)
{
    PolyNode *result = NULL, **tail = &result; // 函数中改变指针 需要用二级指针
    while (poly1 && poly2)
    {

        if (poly1->exponent == poly2->exponent)
        {
            // 指数相同，系数相加
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0)
            { // 只有当系数和不为0时才加入结果多项式
                addPolyNode(tail, sum, poly1->exponent);
                tail = &(*tail)->next;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            addPolyNode(tail, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
            tail = &(*tail)->next;
        }
        else
        {
            addPolyNode(tail, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
            tail = &(*tail)->next;
        }
    }

    // 处理剩余的项
    while (poly1)
    {
        addPolyNode(tail, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
        tail = &(*tail)->next;
    }
    while (poly2)
    {
        addPolyNode(tail, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
        tail = &(*tail)->next;
    }
    return result;
}

int main()
{
    PolyNode *poly1 = NULL, *poly2 = NULL;

    // 构造第一个多项式 5x^0 + 2x^3 + 3x^4 + 3x^5
    addPolyNode(&poly1, 5, 0);
    addPolyNode(&poly1, 2, 3);
    addPolyNode(&poly1, 3, 4);
    addPolyNode(&poly1, 3, 5);

    // 构造第二个多项式 1x^0 + 3x^2 + 4x^3 + 4x^6
    addPolyNode(&poly2, 1, 0);
    addPolyNode(&poly2, 3, 2);
    addPolyNode(&poly2, 4, 3);
    addPolyNode(&poly2, 4, 6);

    printf("Poly1: ");
    printPoly(poly1);
    printf("Poly2: ");
    printPoly(poly2);

    PolyNode *sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    freePoly(sum);
    freePoly(poly1);
    freePoly(poly2);
    sum = poly1 = poly2 = NULL;

    return 0;
}