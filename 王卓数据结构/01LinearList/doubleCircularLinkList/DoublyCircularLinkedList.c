#include "DoublyCircularLinkedList.h"
void initList(DoublyCircularLinkedList *L)
{
    *L = (DuLNode *)malloc(sizeof(DuLNode)); // Allocate memory for the sentinel node
    if (*L != NULL)
    {                    // Check if memory allocation was successful
        (*L)->next = *L; // Point next to itself
        (*L)->prev = *L; // Point prev to itself
    }
}
void printList(DoublyCircularLinkedList L)
{
    // 确保链表不为空
    if (L == NULL || L->next == L)
    {
        printf("The list is empty.\n");
        return;
    }
    DuLNode *current = L->next; // 从第一个实际节点开始遍历
    printf("List Contents: ");
    while (current != L)
    { // 当未回到哨兵节点时继续
        printf("%d ", current->data);
        current = current->next; // 移动到下一个节点
    }
    printf("\n");
}
void insertList(DoublyCircularLinkedList *L, int position, ElemType e)
{
    DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
    if (newNode == NULL)
        return; // Failed to allocate memory

    newNode->data = e; // Assign data to the new node

    DuLNode *current = *L;
    for (int i = 0; i < position; ++i)
    {
        current = current->next;
        if (current == *L)
            break; // Reached the end/sentinel node
    }
    // current newNode  插在了current后面
    newNode->next = current->next; // Insert newNode before current
    newNode->prev = current;
    current->next->prev = newNode; // 更新current的下一个节点的prev指针
    current->next = newNode;
}
void deleteList(DoublyCircularLinkedList *L, int position, ElemType *e)
{
    if (*L == (*L)->next)
        return; // List is empty

    DuLNode *current = (*L)->next; // Start from the first element
    for (int i = 1; i < position && current != *L; ++i)
    {
        current = current->next;
    }
    if (current == *L)
        return; // Position out of bounds

    *e = current->data; // Retrieve the data
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current); // Free the node
}

void destroyList(DoublyCircularLinkedList *L)
{
    DuLNode *current = (*L)->next, *temp;
    while (current != *L)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(*L);  // Free the sentinel node
    *L = NULL; // Set the list pointer to NULL
}
void mergeList(DoublyCircularLinkedList list1, DoublyCircularLinkedList list2)
{
    if (!list1 || !list2)
        return; // 确保两个链表都不为空

    // list1不能跳过哨兵节点 不然合并后没有哨兵节点，打印会无限循环
    //  找到list1的尾节点
    DuLNode *tail1 = list1->prev;

    // 找到list2的第一个实际节点和尾节点（跳过哨兵节点）
    DuLNode *head2 = list2->next;
    DuLNode *tail2 = list2->prev;

    if (head2 == list2)
        return; // 如果list2为空（只有哨兵节点），则不做任何操作

    // 将list1的尾部与list2的头部相连
    tail1->next = head2;
    head2->prev = tail1;

    // 将list2的尾部与list1的哨兵节点相连
    tail2->next = list1;
    list1->prev = tail2;

    // 使list2的哨兵节点成为孤立的节点，可以进一步删除或回收
    list2->next = list2->prev = list2;
    free(list2);
}

// 测试功能的函数
void testFunction()
{
    DoublyCircularLinkedList list1, list2;
    ElemType e;

    // 初始化两个链表
    initList(&list1);
    initList(&list2);

    // 向list1插入元素
    insertList(&list1, 0, 1);
    insertList(&list1, 1, 2);
    insertList(&list1, 2, 3);

    // 向list2插入元素
    insertList(&list2, 0, 4);
    insertList(&list2, 1, 5);
    insertList(&list2, 2, 6);

    // 打印插入元素后的链表内容
    printf("Before merging:\n");
    printList(list1);
    printList(list2);

    // 合并链表
    mergeList(list1, list2);

    // 打印合并后的链表内容
    printf("After merging:\n");
    printList(list1);

    // 删除合并后链表中的某些元素
    deleteList(&list1, 2, &e); // 删除位置2的元素
    printf("After deleting an element (value=%d):\n", e);
    printList(list1);

    // 销毁合并后的链表
    destroyList(&list1);

    // 验证销毁
    if (list1 == NULL)
    {
        printf("List has been successfully destroyed.\n");
    }
}
int main()
{
    testFunction();
    return 0;
}
