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
//#include<time.h>
//long long Fibonacci(size_t N)
//{
//	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//}
//int main()
//{
//	int begin = clock();
//	Fibonacci(45);
//	int end = clock();
//	printf("%d\n", end - begin);
//}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //returnSize 表示找出来的2个数得返回,以数组的形式返回

//int* singleNumbers(int* nums, int numsSize, int* returnSize)
//{
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret ^= nums[i];
//    }
//    //从低到高去找ret里一个为1的位
//    int j = 0;
//    for (; j < 32; ++j)
//    {
//        if (ret & (1 << j)) // if(ret>>j & 1)
//        {
//            break;
//        }
//        // ret的第j位为1,说明x y两个的第j位一个为1,一个为0
//    }
//    // 将原数组分为2组,第j位为1的一组,第j位为0的一组
//    //x y一定会分别进入a b组,其他出现2次的数要么进a组,要么进b组
//    //a组和b组数据就会变成其他数出现2次,只有一个数出现1次,再分别异或就行
//    int x = 0;
//    int y = 0;
//    for (int k = 0; k < numsSize; ++k)
//    {
//        if (nums[k] & (1 << j))    //a组
//        {
//            x ^= nums[k];
//        }
//        else                    //b组
//        {
//            y ^= nums[k];
//        }
//    }
//    int* arr = (int*)malloc(sizeof(int) * 2);
//    arr[0] = x;
//    arr[1] = y;
//    *returnSize = 2;//输出型参数
//    return arr;
//}

int singleNumber(int* nums, int numsSize)
{
    int arr[32] = { 0 };
    int count = 0;
    int k = 31;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            count += ((nums[j] >> i) & 1);
        }
        arr[k] = count;
        count = 0;
        k--;
    }
    for (int i = 0; i < 32; i++)
    {
        arr[i] %= 3;
    }
    int ret = 0;
    for (int i = 0; i < 32; i++)
    {
        ret |= (arr[31] << i);
    }
    return ret;
}