#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return size;
//}

////˼·һ,����������
//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	++(*psize);
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

//�����㷨˼��,�Ѵ�������С����
int TreeSize(BTNode* root)
{
	//������ = ��+��+���Լ�
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//Ҷ�ӽ�����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//��k�������
//�������ĵ�k-1��+�������ĵ�k-1��
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (1 == k)
	{
		return 1;
	}
	return TreeKLevelSize(root->left, k - 1) +
		TreeKLevelSize(root->right, k - 1);
}
//����������ֵΪx���Ǹ����



BTNode* TreeFind(BTNode* root, BTDataType x)
{
	//1,root == NULL return NULL
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}
	//2.root �ڵ㲻��Ҫ�ҵ�,�ȵ�����ȥ��,����û�о�ȥ������
	BTNode* lret = TreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}
	BTNode* rret = TreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}
	//3.���Ҷ�û��,����NULL
	return NULL;
}

//һ��ѡ��һ��ָ��,Ϊ�˱��ֽӿ�һ����,ʹ����Ҫע���ÿ�
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//������ȱ���
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//ֻ�ǰѽ��ָ��pop��ȥ,û�����ٽ��
		printf("%c ", front->data);
		//�����Ϊ��,����ߵĴ���ȥ
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);
}

//�ж�һ�����ǲ�����ȫ������
//�����������,������,�����������,��������֮��,����ȫ�վ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//������һ��NULL ������ȥ���ʣ�µ��Ƿ�ȫΪ��
		if (front == NULL)
		{
			break;
		}
		//��Ϊ�վͼ�������ȥ
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//���ʣ�µ��Ƿ�ȫΪ��
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			//��ȫΪ�վͲ�����ȫ������
			return false;
		}
	}
	QueueDestroy(&q);
	//����ȫ�ǿ�
	return true;
}
int main()
{
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');
	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);//A B D NULL NULL NULL C E NULL NULL F NULL NULL
	printf("\n");

	InOrder(A);//NULL D NULL B NULL A NULL E NULL C NULL F NULL
	printf("\n");

	PostOrder(A);//NULL NULL D NULL B NULL NULL E NULL NULL F C A
	printf("\n");

	printf("TreeSize::%d\n", TreeSize(A));//6
	printf("TreeLeafSize::%d\n", TreeLeafSize(A));//3
	printf("TreeKLevelSize::%d\n", TreeKLevelSize(A, 3));//3
	printf("TreeFind::%p\n", TreeFind(A, 'X'));
	printf("TreeFind::%p\n", TreeFind(A, 'C'));
	//������ȱ���
	//TreeLevelOrder(A);//A B C D E F
	
	//�ж��Ƿ�Ϊ��ȫ������
	printf("BinaryTreeComplete::%d\n", BinaryTreeComplete(A));//0

	//����
	BinaryTreeDestroy(A);
	A = NULL;
	return 0;
}