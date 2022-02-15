#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void Test()
{
	int arr[] = { 1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArray(arr, sz);
}
int main()
{
	Test();
	return 0;
}