#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//    int a, b, c;//a，b作为两个整数，c反复使用，有点像找个中间变量t那个
//    scanf("%d %d", &a, &b);
//    while (c = a % b)//c=a%b这是辗转相除法的内容，注意这里是%而不是/，初学者易错；
//    {
//        //下一步实现辗转
//        a = b;//将除数的值赋值给被除数 小知识--被除数（除以）除数=结果
//        b = c;//将余数的值赋值给被除数 
//        //这样你会发现a，b进入了一个新的值，因此利用循环进行 进一步运算
//        //在哪里打印呢？
//        //假如放在while循环里，而c为0（假），则while循环被跳过，打印个寂寞
//
//    }
//    //打印谁？
//    //1.我们其实可以采用特殊值法确定打印谁,比如将a=40，b=20；则c=0；跳出while，b为最大公约数
//    //因此在使用的时候打印b
//    //2.程序的最后一定是相除余下0，即退出while，此时除数与被除数中最小的数即为最大公约数
//    //例如58/29==2余0；
//    printf("%d\n", b);//找出最大公约数
//    return 0;
//}

//int max(int x, int y)
//
//{
//	return x > y ? x : y;
//}
//
//int min(int x, int y)
//
//{
//	return x < y ? x : y;
//}
//
//int main()
//
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int A = 0;
//	int B = 0;
//	scanf("%d %d", &a, &b);
//	A = max(a, b);
//	B = min(a, b);
//	c = A % B;
//	while (c != 0)
//	{
//		A = B;
//		B = c;
//		c = A % B;
//	}
//	printf("最大公约数为:%d\n", B);
//	return 0;
//}

//int max(int x, int y)
//
//{
//	return x > y ? x : y;
//}
//
//int min(int x, int y)
//
//{
//	return x < y ? x : y;
//}

//int main()
//
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	//int A = 0;
//	//int B = 0;
//	scanf("%d %d", &a, &b);
//	//A = max(a, b);
//	//B = min(a, b);
//	//c = A % B;
//	c = a % b;
//	while (c)
//	{
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	printf("最大公约数为:%d\n", b);
//	return 0;
//}
#include<time.h>
long long Fibonacci(size_t N)
{
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}
int main()
{
	int begin = clock();
	Fibonacci(45);
	int end = clock();
	printf("%d\n", end - begin);
}