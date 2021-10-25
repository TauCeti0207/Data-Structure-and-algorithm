#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
//int main()
//{
//	int n = 100000000;
//	int begin = clock();
//	for (int i = 0; i < n; ++i)
//	{
//
//	}
//	int end = clock();
//	printf("%d\n", end - begin);
//	//clock 显示的程序执行开始的时间戳,单位是毫秒
//	//1亿次只花了39ms
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    char ch;
//    scanf("%c", &ch);
//    printf("    %c\n,ch");
//    printf("   %c %c\n,ch,ch");
//    printf("  %c %c %c\n,ch,ch,ch");
//    printf(" %c %c %c %c\n,ch,ch,ch,ch");
//    printf("%c %c %c %c %c\n,ch,ch,ch,ch,ch");
//    return 0;
//}
//#include<stdio.h>//辗转相除法求最大公约数和最小公倍数
//int main()
//{
//	int m = 0, n = 0;
//	int x = 0, y = 0;
//	int z = 0;
//	scanf("%d %d", &m, &n);
//	x = m, y = n;
//	while (n)
//	{
//		z = m % n;
//		m = n;
//		n = z;
//	}
//	printf("%d\n%d\n", m, x * y / m);
//	return 0;
//}