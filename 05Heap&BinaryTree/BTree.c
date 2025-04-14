// #pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "queue.h"
// 定义二叉树节点的数据类型
typedef int BTDataType;
// 定义二叉树节点结构体
struct BTNode
{
	BTDataType data;
	struct BTNode *left;
	struct BTNode *right;
};
// 为了代码简洁，使用 typedef 重命名
typedef struct BTNode BTNode;

// 创建新的二叉树节点
BTNode *BuyBTNote(BTDataType x)
{
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	assert(node);
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

// 前序遍历（根 - 左 - 右）
void PrevOrder(BTNode *root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

// 中序遍历（左 - 根 - 右）
void InOrder(BTNode *root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

// 后序遍历（左 - 右 - 根）
void PostOrder(BTNode *root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// 释放二叉树的内存
void DestroyTree(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	// 一开始不能先干掉根，不然就找不到左右子树了
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

// 计算二叉树的节点数量 分治思想
int TreeSize(BTNode *root)
{
	// 递归调用 TreeSize (root->left) 计算左子树节点数，TreeSize (root->right) 计算右子树节点数，然后加上 1（当前节点）
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void TreeSize2(BTNode *root, int *size)
{
	if (root == NULL)
	{
		return;
	}
	++(*size);
	TreeSize2(root->left, size);
	TreeSize2(root->right, size);
}

static int staticSize = 0;
void TreeSize3(BTNode *root)
{
	// 使用静态变量 size的地址不改变

	printf("%p,%d\n", &staticSize, staticSize);
	if (root == NULL)
	{
		return;
	}
	++staticSize;
	TreeSize3(root->left);
	TreeSize3(root->right);
}

// 求叶子节点个数
int LeafSize(BTNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	// 如果当前节点既不是空节点也不是叶子节点，那么需要递归计算其左子树和右子树的叶子节点数量。
	return LeafSize(root->left) + LeafSize(root->right);
}

// 计算二叉树的高度
// 左子树高度和右子树高度大的那个+1
int TreeHeight(BTNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

	// 这样写不好，重复计算了，上一层节点不保存结果，效率很差，时间复杂度O(N^2)
	// 每个节点的左右子树高度被重复计算，导致每个节点被访问次数超过一次。例如，根节点的左右子节点会被计算两次，孙子节点会被计算四次，依此类推。
	// 等比数列成倍增加，非常恐怖。
	// return TreeHeight(root->left) > TreeHeight(root->right) ? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}

// 求第k层节点个数
int KLevelSize(BTNode *root, int k)
{
	assert(k > 0); // k 必须大于 0
	if (root == NULL)
	{
		return 0; // 1. 空树：当前层无节点
	}
	if (k == 1)
	{
		return 1; // 2. 到达目标层（第1层）：当前节点即为第1层唯一节点
	}
	// 3. 递归求解左右子树的第k-1层节点数之和
	// 第 k 层的节点必然是 root 左子树的第 k-1 层 或 root 右子树的第 k-1 层 的节点（因为 root 本身是第 1 层，其子树的根是第 2 层，依此类推）。
	return KLevelSize(root->left, k - 1) + KLevelSize(root->right, k - 1);
}
/*
root（第1层）
/      \
左子树      右子树（第2层）
/ \        / \
... ...    ... ... （第3层，目标层）
递归过程：
KLevelSize(root, 3)
= KLevelSize(左子树, 2) + KLevelSize(右子树, 2)
= [KLevelSize(左子树的左子树, 1) + KLevelSize(左子树的右子树, 1)]
+ [KLevelSize(右子树的左子树, 1) + KLevelSize(右子树的右子树, 1)]
= 左子树第2层节点数 + 右子树第2层节点数
= 最终第3层节点数
*/

/* 	 1
	/ \
   2   4
  /   / \
 3   5   6
*/
BTNode *BTreeFind(BTNode *root, BTDataType x)
{
	// 前序查找，根 左 右这样找
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	// 左子树查找
	BTNode *leftResult = BTreeFind(root->left, x);
	if (leftResult != NULL)
		return leftResult;
	// 返回空的时候说明左树没找到，右子树继续查找
	BTNode *rightResult = BTreeFind(root->right, x);
	if (rightResult != NULL)
		return rightResult;
	// 左右子树都找不到
	return NULL;
}

// 层序遍历
void LevelOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	// 假设二叉树节点数量不超过 1000 创建数组模拟队列
	BTNode *queue[1000];
	int front = 0, rear = 0;
	queue[rear++] = root;

	while (front < rear) // 只要 front 小于 rear，说明队列中还有节点未处理
	{
		// 取出队头元素 并更新对头
		BTNode *current = queue[front++];
		printf("%d ", current->data);

		if (current->left != NULL)
		{
			queue[rear++] = current->left;
		}
		if (current->right != NULL)
		{
			queue[rear++] = current->right;
		}
	}
}

/**
 * 使用队列实现二叉树的层序遍历
 * 层序遍历是指从树的根节点开始，按照层次顺序依次访问每个节点
 *
 * @param root 指向二叉树根节点的指针
 */
void LevelOrder2(BTNode *root)
{
	// 初始化一个队列用于辅助层序遍历
	Queue q;
	QueueInit(&q);

	// 如果根节点不为空，则将其入队
	if (root != NULL)
		QueuePush(&q, root);

	// 当队列不为空时，循环继续
	while (!QueueEmpty(&q))
	{
		// 获取队首节点并出队
		BTNode *front = QueueFront(&q);
		QueuePop(&q);

		// 打印队首节点的数据
		printf("%d ", front->data);

		// 如果队首节点有左子节点，则将左子节点入队
		if (front->left != NULL)
			QueuePush(&q, front->left);

		// 如果队首节点有右子节点，则将右子节点入队
		if (front->right != NULL)
			QueuePush(&q, front->right);
	}

	// 销毁队列，释放资源
	QueueDestroy(&q);
}

// 判断一棵树是否是完全二叉树
bool IsCompleteTree(BTNode *root)
{
	if (root == NULL) // 空树是完全二叉树
	{
		return true;
	}

	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);
		// 遇到空跳出来 判断后面是否为全空
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	// 判断第一个空后面是否全为空，如果不完为空则说明不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

// 手动构建二叉树
/* 	 1
	/ \
   2   4
  /   / \
 3   5   6
*/
BTNode *CreatBinaryTree()
{
	BTNode *node1 = BuyBTNote(1);
	BTNode *node2 = BuyBTNote(2);
	BTNode *node3 = BuyBTNote(3);
	BTNode *node4 = BuyBTNote(4);
	BTNode *node5 = BuyBTNote(5);
	BTNode *node6 = BuyBTNote(6);

	// 手动链接
	node1->left = node2;
	node2->left = node3;
	// node2->right = NULL;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;

	// 返回根节点
	return node1;
}

int main()
{
	// 构建一个简单的二叉树
	BTNode *root = CreatBinaryTree();

	// 遍历二叉树
	printf("前序遍历: ");
	PrevOrder(root);
	printf("\n");

	printf("中序遍历: ");
	InOrder(root);
	printf("\n");

	printf("后序遍历: ");
	PostOrder(root);
	printf("\n");

	printf("层序遍历1: ");
	LevelOrder(root);
	printf("\n");

	printf("层序遍历2: ");
	LevelOrder2(root);
	printf("\n");

	// 计算节点数量和高度
	printf("节点数量: %d\n", TreeSize(root));
	/* int count = 0;
	TreeSize2(root, &count);
	printf("节点数量: %d\n", count); */
	/* 	TreeSize3(root);
		printf("节点数量: %d\n", staticSize); */
	printf("树的高度: %d\n", TreeHeight(root));

	printf("叶子节点数量: %d\n", LeafSize(root));

	printf("第3层节点数量: %d\n", KLevelSize(root, 3));
	printf("查找节点: %d\n", BTreeFind(root, 5)->data);
	// 判断是否是完全二叉树
	printf("是否是完全二叉树: %d\n", IsCompleteTree(root));
	// 释放二叉树内存
	DestroyTree(root);
	// 手动置空
	root = NULL;
	return 0;
}
