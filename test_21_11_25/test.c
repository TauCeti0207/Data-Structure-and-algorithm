#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_SIZE 5
//
//typedef struct Table
//{
//	int* head;
//	int length;
//	int size;
//}table;
//
//table init_table()
//{
//	int elem = 0;
//	table t;
//	t.head = (int*)malloc(MAX_SIZE * sizeof(int));
//	if (!t.head)
//	{
//		printf("����ռ�ʧ��\n");
//		exit(0);
//	}
//	t.length = 0;
//	t.size = MAX_SIZE;
//	printf("������Ԫ��>:\n");
//	for (int i = 0; i < MAX_SIZE; i++)
//	{
//		scanf("%d", &elem);
//		if (elem == -1)
//		{
//			break;
//		}
//		t.head[i] = elem;
//		t.length++;
//	}
//
//	//���˳���
//	for (int i = 0; i < t.length; i++)
//	{
//		printf("%d ", t.head[i]);
//	}
//	printf("\n");
//	return t;
//}
//
////void display_table(table t)
////{
////	for (int i = 0; i < t.length; i++)
////	{
////		printf("%d ", t.head[i]);
////	}
////	printf("\n");
////}
//
//table insert_table(table t, int elem, int position)
//{
//	int i = 0;
//	//������λ���Ƿ���ȷ
//	if (position > t.length || position < 1)
//	{
//		printf("����λ������\n");
//		return t;
//	}
//
//	//���˳���Ƿ��п���,��û�����·���
//	if (t.length == t.size)
//	{
//		t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
//		if (!t.head)
//		{
//			printf("����ʧ��\n");
//			return t;
//		}
//		t.size += 1;
//	}
//
//	//������λ�ÿ�ʼ�ĺ���Ԫ�غ���
//	for (i = t.length - 1; i >= position - 1; i--)
//	{
//		t.head[i + 1] = t.head[i];
//	}
//
//	//����Ԫ��
//	t.head[position - 1] = elem;
//	t.length++;
//	//���˳���
//	for (int i = 0; i < t.length; i++)
//	{
//		printf("%d ", t.head[i]);
//	}
//	printf("\n");
//
//	return t;
//}
//
//table delet_table(table t, int position)
//{
//	int i = 0;
//	//�ж�ɾ��λ���Ƿ���ȷ
//	if (position > t.length || position < 1)
//	{
//		printf("ɾ��λ�ô���\n");
//		exit(0);
//	}
//
//	//ɾ��
//	for (i = position; i < t.length; i++)
//	{
//		t.head[i - 1] = t.head[i];
//	}
//	t.length--;
//
//	//���˳���
//	for (int i = 0; i < t.length; i++)
//	{
//		printf("%d ", t.head[i]);
//	}
//	printf("\n");
//
//	return t;
//}
//int main()
//{
//	int elem = 0;
//	int position = 0;
//	int dele_position = 0;
//	table t = init_table();
//
//	printf("����������Ԫ�غ�λ��>:\n");
//	//���������
//	getchar();
//	getchar();
//	getchar();
//	scanf("%d %d", &elem, &position);
//	t = insert_table(t, elem, position);
//
//	printf("������Ҫɾ����Ԫ�ص�λ��>:\n");
//	scanf("%d", &dele_position);
//	t = delet_table(t, dele_position);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//typedef struct LinkList
//{
//	int elem;
//	struct LinkList* next;
//}LinkList;
//
//void display_list(LinkList* head_node)
//{
//	LinkList* temp = head_node;
//	while (temp->next)
//	{
//		temp = temp->next;
//		printf("%d ", temp->elem);
//	}
//	printf("\n");
//}
//
//LinkList* init_LinkList()
//{
//	LinkList* head_node = (LinkList*)malloc(sizeof(LinkList));//ͷ���
//	LinkList* temp = head_node;
//	for (int i = 1; i <= 5; i++)
//	{
//		LinkList* a = (LinkList*)malloc(sizeof(LinkList));
//		a->elem = i;
//		a->next = NULL;
//		temp->next = a;
//		temp = temp->next;
//	}
//	printf("�Ѵ�������:\n");
//	display_list(head_node);
//	return head_node;
//}
//
//
//
//LinkList* insert_list(LinkList* head_node, int elem, int position)
//{
//	LinkList* temp = head_node;
//	LinkList* node = NULL;
//	int i = 0;
//	for (i = 1; i < position; i++)
//	{
//		if (temp == NULL)
//		{
//			printf("����λ������\n");
//			return head_node;
//		}
//		temp = temp->next;
//	}
//
//	//����������
//	node = (LinkList*)malloc(sizeof(LinkList));
//	node->elem = elem;
//	node->next = temp->next;
//	temp->next = node;
//	display_list(head_node);
//	return head_node;
//}


#include <stdio.h>
int main()
{
    int i = 1;
    while (i <= 10)
    {
        if (5 == i)
            continue;
        printf("%d ", i);
        i++;
    }
    return 0;
}