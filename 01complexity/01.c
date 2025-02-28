#include <stdio.h>
#include <time.h>

// 假设这是你要测试的算法函数，你可以替换成你自己的函数
void algorithm()
{
    // 这里写你的算法逻辑
    int sum = 0;
    for (int i = 0; i < 100000000; i++)
    {
        sum += i;
    }
}

int main()
{
    // 使用 clock() 函数获取当前的 CPU 时钟
    clock_t start = clock();
    // 调用你要测试的算法函数
    algorithm();
    // 再次获取当前的 CPU 时钟
    clock_t end = clock();
    // 计算算法运行的时间，单位是秒
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // 打印结果
    printf("The algorithm took %f seconds to run.\n", time);
    return 0;
}
