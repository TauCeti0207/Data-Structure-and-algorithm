#include "define.h"
#include "linkList.h"
/* 插入操作的判断条件和问题 */
/*while (p)
{
    p = p->next;
} // 最终p的值为NULL
while (p->next)
{
    p = p->next;
} // 最终p的值为最后一个节点的地址
*/
/*
如果插入操作的 position 不合法，即 position > n+1 (n 为链表长度)，那么 p 一定会指向 NULL。
此时按照退出条件 !p 可以返回 ERROR。但是如果采用 while(p->next)，则最终会指向链表最后一个节点，
即使 position 不合法，那么也会在最后一个节点后方插入新节点。因此，使用 while(p) 更合适。
*/

/* 删除操作的判断条件和问题 */
/*
如果删除操作的 position 不合法，即 position > 链表长度，p 会指向最后一个节点的地址 (position == n+1 时)
或是 NULL (position > n+1)。那么下面的代码会出错：
LinkList pfree = p->next;
如果 p 指向最后一个节点，此时 pfree 指向 NULL。如果 p 指向 NULL，此时 pfree 指向非法空间（不受主程序控制），
从而导致下面的代码报错： *e = pfree->data;
所以需要增加一个判断条件：
if (i > position - 1 || !p || !p->next) return ERROR;
必须保证 !p 要在 !p->next 的左边，即 position > n+1 的情况。这是因为如果 !p->next 在 !p 的左边，
如果 p 指向 NULL，那么 NULL->next 会报错。
*/
/**
 * @brief
 * 彻底理解链表中为何使用二级指针或者一级指针的引用
 * https://zhuanlan.zhihu.com/p/198190623
 *
 * @param L
 * @return Status
 */
Status initLinkList(LinkList *L) // L是个二级指针 要修改指针就得传指针地址，也就是二级指针，或者是一级指针的引用也可以。
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

int isLinklistEmpty(LinkList L)
{
    if (L->next) // 非空
        return 0;
    else
        return 1;
}
Status destroyLinkList(LinkList *L) // 二级指针
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
Status clearList(LinkList *L)
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
int getLinkListLength(LinkList L)
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

/**
 * @brief 查找链表L中首次出现元素e的位置，如果未找到则返回 NULL
 *
 * @param L 链表
 * @param e 元素值
 * @return 返回元素e的位置指针，如果未找到则返回 NULL
 */
LinkList locateElement(LinkList L, LlElemtype e)
{
    if (!L) // 链表为空，直接返回 NULL
        return NULL;

    LinkList p = L->next;

    while (p && p->data != e)
    { // 遍历链表，查找元素值为e的结点
        p = p->next;
    }

    return p; // 返回找到的结点指针，如果未找到则返回 NULL
}

Status getLinkListElem(LinkList L, int position, LlElemtype *e)
{
    LinkList p = L->next;
    int i = 1; // 使i和p的位置同步，即i代表着p在链表中的位置

    if (position < 1 || !p) // 位置小于1或者链表为空时，返回错误状态
        return ERROR;

    while (p && i < position)
    { // 遍历链表，直到找到第position个结点或者遍历结束
        p = p->next;
        i++;
    }

    if (!p || i > position) // 如果链表遍历结束或者i超出position，说明位置无效，返回错误状态
        return ERROR;

    *e = p->data; // 将找到的结点的数据存入e指向的位置
    return OK;    // 返回成功状态
}

Status insertLinkList(LinkList L, int position, LlElemtype e)
{
    LinkList p = L; // 从头结点开始
    int i = 0;      // i从0开始

    while (p && i < position - 1)
    { // 查找插入位置的前一个结点
        i++;
        p = p->next;
    }

    if (!p || i > position - 1) // 如果p为空或者i超过了position-1，说明插入位置无效，返回错误状态
        return ERROR;

    LinkList pnew = (LinkList)malloc(sizeof(LNode)); // 创建新结点
    if (!pnew)                                       // 检查内存分配是否成功
        return ERROR;

    pnew->data = e;       // 设置新结点的数据为e
    pnew->next = p->next; // 新结点的next指向原来位置的下一个结点
    p->next = pnew;       // 前一个结点的next指向新结点

    return OK; // 返回成功状态
}

Status deleteLinkList(LinkList L, int position, LlElemtype *e)
{
    LinkList p = L;
    int i = 0;

    while (p && i < position - 1)
    {
        i++;
        p = p->next;
    }

    if (i > position - 1 || !p || !(p->next)) // 多增加了判断条件 !(p->next)，用于处理位置为链表末尾的情况
        return ERROR;

    LinkList pfree = p->next;
    *e = pfree->data;
    p->next = pfree->next; // 删除结点的前一个结点的next指向删除结点的后一个结点，即跳过删除结点
    free(pfree);           // 释放删除结点的内存

    return OK;
}

/**
 * @brief Print all elements of a singly linked list
 *
 * @param L The linked list to be printed
 */
void printLinkList(LinkList L)
{
    /* Start from the first node */
    LinkList p = L->next;
    /* Print all elements */
    printf("List elements: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// 创建链表的函数，n为链表的长度
void createLinkList_Head(LinkList *L, int n)
{
    *L = (LinkList)malloc(sizeof(LNode)); // 创建头节点
    (*L)->next = NULL;                    // 初始化为空链表
    printf("Please input %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode)); // 创建新节点
        int data;
        scanf(" %d", &data);  // 读取用户输入
        p->data = data;       // 设置节点数据
        p->next = (*L)->next; // 将新节点插入到头节点之后
        (*L)->next = p;
    }
}
/**
 * @brief Create a LinkList Tail object
 *
 *
Function Call: The scanf function is called with two arguments: a format string "%d" and the address of the data member of the p node (&p->data). The format string "%d" indicates that scanf expects to read an integer from the standard input.

Waiting for Input: scanf waits for the user to enter an input that matches the expected format. In this case, it's waiting for an integer. The program execution pauses at this point until input is provided.

User Input: The user types an integer value followed by the enter key (\n). This input is temporarily stored in the input buffer of the standard input stream.

Reading Input: scanf reads the input from the buffer. If the input matches the format specified (%d for an integer), scanf attempts to convert the input to an integer.

Storing the Result: If the conversion is successful, scanf stores the integer value in the location specified by the second argument, which is &p->data. This means the input integer is stored in the data field of the p node.

Return Value: After storing the input, scanf returns. The return value of scanf is the number of successfully read items. In this case, if an integer is successfully read and stored, scanf returns 1. If the input does not match the expected format, it might return 0 (indicating failure to read an integer) or EOF if an input failure occurs before any data could be read.

Continuation of Program Execution: After the scanf operation completes, the program execution continues to the next statement.

`scanf` 在读取输入时，其行为受到格式字符串指定的类型以及标准输入缓冲区的工作方式的影响。当使用 `%d` 格式字符串让 `scanf` 读取一个整数时，这里是几个关键点来解释为什么按空格（而不是回车）也能让 `scanf` 成功读取数值：

1. **空白字符的跳过**：在默认情况下，`scanf` 会自动跳过输入字符串中的任何空白字符，包括空格 (` `)、制表符 (`\t`) 和换行符 (`\n`)，直到它遇到一个非空白字符。这意味着输入前面的空格不会影响 `scanf` 读取数值。

2. **数值读取**：当你输入一个数值并按下空格时，`scanf` 已经开始读取这个数值。因为 `%d` 期待的是整数输入，所以只要 `scanf` 能从已输入的字符中识别出一个有效的整数，它就会停止等待更多的输入并处理这个整数。

3. **终止条件**：对于 `%d`，`scanf` 会继续读取并解析输入，直到遇到一个非数字字符。空格就是一个这样的非数字字符，它告诉 `scanf` 数字输入已经结束，这时 `scanf` 就会停止读取输入流，并将之前读取到的数字作为结果返回。这就是为什么你在输入数值后按空格 `scanf` 也能成功读取数值的原因。

4. **输入缓冲区**：按下空格后，数值和紧随其后的空格都会被放入输入缓冲区。`scanf` 读取并解析缓冲区中的数值直到遇到非数字字符（这里是空格），然后它将解析的数值存储在指定的变量中。因为空格被视为数值输入的终止，所以在这种情况下它起到了和回车类似的效果。

因此，在使用 `scanf` 读取数值时，无论是按空格还是回车，只要 `scanf` 能从输入中解析出一个符合期望格式的数值，它就会成功读取。回车通常用于标识一次完整的输入结束，但对于单独的数值读取，空格和回车都可以作为输入结束的标志。

 * @param L
 * @param n
 */
void createLinkList_Tail(LinkList *L, int n)
{
    // 初始化一个空链表，L指向头节点
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode *tail = *L; // tail作为尾指针，初始时指向头节点

    printf("Please input %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode)); // 为新节点分配内存
        scanf("%d", &p->data);                     // 输入节点的数据 ->优先级大于&
        p->next = NULL;                            // 新节点的next指向NULL

        tail->next = p; // 将新节点链接到尾部
        tail = p;       // 更新尾指针为新的节点
    }
}
void testLinkedListFunctions1()
{
    LinkList L;
    initLinkList(&L); // 初始化链表

    // 手动构造链表
    LinkList node1 = (LinkList)malloc(sizeof(LNode));
    node1->data = 10;
    node1->next = NULL;

    LinkList node2 = (LinkList)malloc(sizeof(LNode));
    node2->data = 20;
    node2->next = NULL;

    L->next = node1;
    node1->next = node2;

    // 测试链表操作函数
    printf("Length of the list: %d\n", getLinkListLength(L));

    LlElemtype searchValue = 20;
    LinkList foundNode = locateElement(L, searchValue);
    if (foundNode)
    {
        printf("Element %d found in the list.\n", searchValue);
    }
    else
    {
        printf("Element %d not found in the list.\n", searchValue);
    }

    int position = 1;
    LlElemtype elemValue;
    if (getLinkListElem(L, position, &elemValue) == OK)
    {
        printf("Element at position %d: %d\n", position, elemValue);
    }
    else
    {
        printf("Invalid position.\n");
    }

    // 清空链表
    clearList(&L);
    printf("Length of the list after clearing: %d\n", getLinkListLength(L));

    // 销毁链表
    destroyLinkList(&L);
}
void testLinkedListFunctions2()
{
    LinkList L;
    Status status;
    LlElemtype e;

    // 1. Initialize the linked list
    status = initLinkList(&L);
    printf("Initialization: %s\n", (status == OK) ? "Success" : "Failure");

    // 2. Test for empty list
    printf("List empty after initialization: %s\n", isLinklistEmpty(L) ? "Yes" : "No");

    // 3. Insert elements into the list and print
    status = insertLinkList(L, 1, 10); // Insert at beginning
    printf("Insert element 10 at position 1: %s\n", (status == OK) ? "Success" : "Failure");
    printLinkList(L);

    status = insertLinkList(L, 2, 20); // Insert at second position
    printf("Insert element 20 at position 2: %s\n", (status == OK) ? "Success" : "Failure");
    printLinkList(L);

    status = insertLinkList(L, 3, 30); // Insert at end
    printf("Insert element 30 at position 3: %s\n", (status == OK) ? "Success" : "Failure");
    printLinkList(L);

    // 4. Check the length
    printf("List length after insertions: %d\n", getLinkListLength(L));

    // 5. Retrieve an element
    status = getLinkListElem(L, 2, &e);
    printf("Element at position 2: %d, Status: %s\n", e, (status == OK) ? "Found" : "Not Found");

    // 6. Locate an element by value and print
    LinkList foundNode = locateElement(L, 20);
    printf("Element 20 found: %s\n", (foundNode != NULL) ? "Yes" : "No");
    printLinkList(L);

    // 7. Delete an element and print
    status = deleteLinkList(L, 2, &e); // Delete the second element
    printf("Delete element at position 2 (value: %d): %s\n", e, (status == OK) ? "Success" : "Failure");
    printLinkList(L);

    // 8. Clear the list and print
    status = clearList(&L);
    printf("Clear list: %s\n", (status == OK) ? "Success" : "Failure");
    printLinkList(L);
    printf("List length after clearing: %d\n", getLinkListLength(L));

    // 9. Destroy the list
    status = destroyLinkList(&L);
    printf("Destroy list: %s\n", (status == OK) ? "Success" : "Failure");
}
void testLinkedListFunctions3()
{
    LinkList L;
    Status status;

    // Initialize the linked list
    status = initLinkList(&L);
    printf("Initialization: %s\n", (status == OK) ? "Success" : "Failure");

    // Create a linked list by inserting elements at the head
    int n = 3; // Number of elements to insert
    printf("Creating list with insert at head:\n");
    createLinkList_Head(&L, n);
    printLinkList(L);

    // Clear the list to reset it
    status = clearList(&L);
    printf("Clear list after head insertions: %s\n", (status == OK) ? "Success" : "Failure");

    // Create a linked list by inserting elements at the tail
    printf("Creating list with insert at tail:\n");
    createLinkList_Tail(&L, n);
    printLinkList(L);

    // Destroy the list
    status = destroyLinkList(&L);
    printf("Destroy list: %s\n", (status == OK) ? "Success" : "Failure");
}
int main()
{
    /* code */
    testLinkedListFunctions2();
    return 0;
}
