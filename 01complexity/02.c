#include <time.h>
#include <stdio.h>
long long Fibonacci(size_t N)
{
    return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}
int main()
{
    int begin = clock();
    Fibonacci(40);
    int end = clock();
    printf("The algorithm took %d ms to run.\n", end - begin);
}