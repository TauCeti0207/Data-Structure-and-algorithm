#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
static int count = 0;//计数器
void move(int n,char A,char C)
{
	printf("将%d号盘子从%c移动到%c\n", n, A, C);
	count++;
}
void hannio(int n, char A, char B, char C)
{
	int count = 0;
	int i = 0;
	if (n == 1)
	{
		move(n,A,C);
		printf("将%d号盘子从%c移动到%c\n", n,A,C);
	}
	else
	{
		hannio(n - 1,A,C,B);//借助C将n-1个从A移到B
		move(n, A, C);//将最大那个从A移到C
		hannio(n - 1, B, A, C);//借助A将n-1个从B移到C
	}
}
int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n = 0;
	scanf("%d", &n);
	hannio(n,'A','B','C');
	printf("总共移动%d次\n", count);
	return 0;
}

//代码分析:
//n = 3为例
//n = 3不满足n = 1条件, 进入else
//hannio(3, A, B, C) A - A B - B C - C
//	hannio(2, A, C, B) A - A B - C, C - B 此时B里面是C, C里面是B
//		hannio(1, A, C, B)  A - A B - B C - C
//			printf 将1号从A移动到C n = 1 执行if语句
//		printf("将%d号盘子从%c移动到%c\n", n, A, C)此时n为2  A - A B - C, C - B 将2号从A移到B
//		hannio(1, B, A, C); B里面存放的是C, A里面存放的是A, C里面存放的是B 把C传给A, 把A传给B, 把B传给C A - C B - A C - B
//			printf 将1号从A移到C 即从C移到B
//printf n = 3执行完毕, 此时n = 3, 将3号从A移到C
//	hannio(2, B, A, C) A-B B-A C-C
//		hannio(1, A, C, B) A-B B-C C-A A里面是B赋给A C里面是C赋给C B里面是A赋给C
//			printf 将1号从B移到A
//		printf 此时n=2 将2号从B移到C
//		hannio(1, B, A, C); A-A B-B C-C 将一号从A移到C

