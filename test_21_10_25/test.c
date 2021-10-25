#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
int main()
{
	int n = 100000000;
	int begin = clock();
	for (int i = 0; i < n; ++i)
	{

	}
	int end = clock();
	printf("%d\n", end - begin);
	//clock 显示的程序执行开始的时间戳,单位是毫秒
	//1亿次只花了39ms
	return 0;
}