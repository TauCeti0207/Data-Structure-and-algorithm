#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void TestInsertSort()
{
	int arr[] = { 1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArray(arr, sz);
}
void TestShellSort()
{
	int arr[] = { 1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArray(arr, sz);
}
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a4, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
void TestSelectSort()
{
	int arr[] = { 22,1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	PrintArray(arr, sz);
}
void TestHeapSort()
{
	int arr[] = { 22,1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	PrintArray(arr, sz);
}
void TestBubbleSort()
{
	int arr[] = { 22,1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	PrintArray(arr, sz);
}
void TestQuickSort()
{
	int arr[] = { 22,1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0,sz-1);
	PrintArray(arr, sz);
}
void TestQuickSortNonR()
{
	int arr[] = { 22,1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, sz - 1);
	PrintArray(arr, sz);
}
void TestMergeSort()
{
	int arr[] = { 22,1,2,32,4,2,3,1,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr,  sz);
	PrintArray(arr, sz);
}
void TestMergeSortNonR()
{
	int arr[] = { 10,6,7,1,3,9,4,2,5,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSortNonR(arr, sz);
	PrintArray(arr, sz);
}
void TestCountSort()
{
	int arr[] = { 10,6,7,1,3,9,4,2,5,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, sz);
	PrintArray(arr, sz);
}
int main()
{
	//TestQuickSort();QuickSortNonR
	//TestOP();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	TestCountSort();
	return 0;
}