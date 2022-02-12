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

////思路一,遍历计数器
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

//分治算法思想,把大问题拆成小问题
int TreeSize(BTNode* root)
{
	//结点个数 = 左+右+我自己
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//叶子结点个数
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
//第k层结点个数
//左子树的第k-1层+右子树的第k-1层
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
//查找树里面值为x的那个结点



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
	//2.root 节点不是要找的,先到左树去找,左树没有就去右树找
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
	//3.左右都没有,返回NULL
	return NULL;
}

//一般选择一级指针,为了保持接口一致性,使用者要注意置空
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

//广度优先遍历
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
		QueuePop(&q);//只是把结点指针pop出去,没有销毁结点
		printf("%c ", front->data);
		//如果左不为空,把左边的带进去
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

//判断一棵树是不是完全二叉树
//借助层序遍历,层序走,结点是连续的,当出到空之后,后面全空就是完全二叉树
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
		//遇到第一个NULL 跳出来去检查剩下的是否全为空
		if (front == NULL)
		{
			break;
		}
		//不为空就继续传进去
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	//检查剩下的是否全为空
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			//不全为空就不是完全二叉树
			return false;
		}
	}
	QueueDestroy(&q);
	//后面全是空
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
	//广度优先遍历
	//TreeLevelOrder(A);//A B C D E F
	
	//判断是否为完全二叉树
	printf("BinaryTreeComplete::%d\n", BinaryTreeComplete(A));//0

	//销毁
	BinaryTreeDestroy(A);
	A = NULL;
	return 0;
}