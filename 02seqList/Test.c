#include "SeqList.h"
#include <stdio.h>

// 测试顺序表的初始化和销毁操作
void testInitAndDestroy()
{
	SeqList seq;
	SeqListInit(&seq);
	printf("顺序表初始化成功，当前容量: %zu，有效数据个数: %zu\n", seq.capacity, seq.size);
	SeqListDestory(&seq);
	printf("顺序表销毁成功\n");
}

// 测试顺序表的尾插操作
void testPushBack()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的头插操作
void testPushFront()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushFront(&seq, 1);
	SeqListPushFront(&seq, 2);
	SeqListPushFront(&seq, 3);
	printf("头插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的尾删操作
void testPopBack()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListPopBack(&seq);
	printf("尾删后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的头删操作
void testPopFront()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListPopFront(&seq);
	printf("头删后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试删除空顺序表的头删操作
void testPopFront2()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListPopFront(&seq);
	printf("头删后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListPopFront(&seq);
	SeqListPopFront(&seq);
	printf("头删后顺序表元素为: ");
	SeqListPrint(&seq);
	// 继续删，此时顺序表为空 assert报错
	SeqListPopFront(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的查找操作
void testFind()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	int pos = SeqListFind(&seq, 2);
	if (pos != -1)
	{
		printf("找到元素 2，位置为: %d\n", pos);
	}
	else
	{
		printf("未找到元素 2\n");
	}
	SeqListErase(&seq, pos);
	printf("删除pos元素后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的中间插入操作
void testInsert()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListInsert(&seq, 1, 4);
	printf("在位置 1 插入 4 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的中间删除操作
void testErase()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListErase(&seq, 1);
	printf("删除位置 1 的元素后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

// 测试顺序表的修改操作
void testModify()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	printf("尾插 1, 2, 3 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListModify(&seq, 1, 4);
	printf("将位置 1 的元素修改为 4 后顺序表元素为: ");
	SeqListPrint(&seq);
	SeqListDestory(&seq);
}

/* int main()
{
	// testInitAndDestroy();
	// testPushBack();
	// testPushFront();
	// testPopBack();
	// testPopFront();
	// testFind();
	// testInsert();
	// testErase();
	// testModify();
	// testPopFront2();
	testFind();
	return 0;
} */

// 显示菜单
void showMenu()
{
	printf("1. 初始化顺序表 | 2. 销毁顺序表 | 3. 打印顺序表 | 4. 尾插元素 | 5. 头插元素\n");
	printf("6. 尾删元素 | 7. 头删元素 | 8. 查找元素 | 9. 中间插入元素 | 10. 中间擦除元素\n");
	printf("11. 修改元素 | 0. 退出\n");
	printf("请输入你的选择: ");
}

int main()
{
	SeqList sl;
	int choice;
	SeqDataType x;
	size_t pos;

	while (1)
	{
		showMenu();
		/* 当你在 scanf("%d", &choice); 语句中输入字符 'a' 时，scanf 函数会尝试将输入转换为整数。由于 'a' 不是有效的整数字符，scanf 转换失败。scanf会返回 0，表示没有成功匹配到整数。 */
		if (scanf("%d", &choice) != 1)
		{
			// 清除输入缓冲区中的无效输入
			int c;
			// while 循环会不断调用 getchar 函数从输入缓冲区中读取字符，直到遇到换行符或文件结束符为止。这样就可以清空输入缓冲区中残留的无效输入，确保下一次输入操作不会受到影响。
			while ((c = getchar()) != '\n' && c != EOF)
				;
			printf("输入无效，请输入一个整数！\n");
			continue;
		}

		switch (choice)
		{
		case 1:
			SeqListInit(&sl);
			printf("顺序表初始化成功！\n");
			break;
		case 2:
			SeqListDestory(&sl);
			printf("顺序表销毁成功！\n");
			break;
		case 3:
			SeqListPrint(&sl);
			break;
		case 4:
			printf("请输入要插入的元素: ");
			scanf("%d", &x);
			SeqListPushBack(&sl, x);
			printf("尾插元素 %d 成功！\n", x);
			break;
		case 5:
			printf("请输入要插入的元素: ");
			scanf("%d", &x);
			SeqListPushFront(&sl, x);
			printf("头插元素 %d 成功！\n", x);
			break;
		case 6:
			if (sl.size > 0)
			{
				SeqListPopBack(&sl);
				printf("尾删元素成功！\n");
			}
			else
			{
				printf("顺序表为空，无法尾删！\n");
			}
			break;
		case 7:
			if (sl.size > 0)
			{
				SeqListPopFront(&sl);
				printf("头删元素成功！\n");
			}
			else
			{
				printf("顺序表为空，无法头删！\n");
			}
			break;
		case 8:
			printf("请输入要查找的元素: ");
			scanf("%d", &x);
			int index = SeqListFind(&sl, x);
			if (index != -1)
			{
				printf("元素 %d 在顺序表中的位置是 %d\n", x, index);
			}
			else
			{
				printf("元素 %d 不在顺序表中！\n", x);
			}
			break;
		case 9:
			printf("请输入要插入的位置和元素（用空格分隔）: ");
			scanf("%zu %d", &pos, &x);
			SeqListInsert(&sl, pos, x);
			printf("在位置 %zu 插入元素 %d 成功！\n", pos, x);
			break;
		case 10:
			printf("请输入要擦除的位置: ");
			// zu 表示 size_t 类型
			scanf("%zu", &pos);
			if (pos < sl.size)
			{
				SeqListErase(&sl, pos);
				printf("在位置 %zu 擦除元素成功！\n", pos);
			}
			else
			{
				printf("位置 %zu 超出顺序表范围，无法擦除！\n", pos);
			}
			break;
		case 11:
			printf("请输入要修改的位置和新元素（用空格分隔）: ");
			scanf("%zu %d", &pos, &x);
			if (pos < sl.size)
			{
				SeqListModify(&sl, pos, x);
				printf("将位置 %zu 的元素修改为 %d 成功！\n", pos, x);
			}
			else
			{
				printf("位置 %zu 超出顺序表范围，无法修改！\n", pos);
			}
			break;
		case 0:
			SeqListDestory(&sl);
			printf("退出程序！\n");
			return 0;
		default:
			printf("无效的选择，请重新输入！\n");
		}
	}

	return 0;
}