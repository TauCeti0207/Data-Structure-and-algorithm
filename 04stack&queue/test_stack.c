#include "stack.h"

// 打印测试结果信息
void printTestResult(const char *testName, bool result)
{
	if (result)
	{
		printf("%s: Passed\n", testName);
	}
	else
	{
		printf("%s: Failed\n", testName);
	}
}

// 测试栈的初始化
bool testStackInit()
{
	printf("开始测试栈的初始化...\n");
	Stack st;
	StackInit(&st);
	bool initResult = st.array == NULL && st.top == 0 && st.capacity == 0;
	printf("初始化后: array = %p, top = %d, capacity = %d\n", (void *)st.array, st.top, st.capacity);
	printTestResult("testStackInit", initResult);
	return initResult;
}

// 测试栈的插入操作
bool testStackPush()
{
	printf("\n开始测试栈的插入操作...\n");
	Stack st;
	StackInit(&st);
	printf("插入元素前: 栈大小 = %d\n", StackSize(&st));
	StackPush(&st, 10);
	printf("插入元素 10 后: 栈大小 = %d, 栈顶元素 = %d\n", StackSize(&st), StackTop(&st));
	bool pushResult = StackSize(&st) == 1 && StackTop(&st) == 10;
	printTestResult("testStackPush", pushResult);
	return pushResult;
}

// 测试栈的删除操作
bool testStackPop()
{
	printf("\n开始测试栈的删除操作...\n");
	Stack st;
	StackInit(&st);
	StackPush(&st, 10);
	StackPush(&st, 20);
	printf("插入元素 10 和 20 后: 栈大小 = %d, 栈顶元素 = %d\n", StackSize(&st), StackTop(&st));
	StackPop(&st);
	printf("执行一次出栈操作后: 栈大小 = %d, 栈顶元素 = %d\n", StackSize(&st), StackTop(&st));
	bool popResult = StackSize(&st) == 1 && StackTop(&st) == 10;
	printTestResult("testStackPop", popResult);
	return popResult;
}

// 测试访问栈顶元素
bool testStackTop()
{
	printf("\n开始测试访问栈顶元素...\n");
	Stack st;
	StackInit(&st);
	StackPush(&st, 30);
	printf("插入元素 30 后: 尝试访问栈顶元素\n");
	STDataType topValue = StackTop(&st);
	printf("栈顶元素的值为: %d\n", topValue);
	bool topResult = topValue == 30;
	printTestResult("testStackTop", topResult);
	return topResult;
}

// 测试栈是否为空
bool testStackEmpty()
{
	printf("\n开始测试栈是否为空...\n");
	Stack st;
	StackInit(&st);
	bool isEmptyInitially = StackEmpty(&st);
	printf("初始化后: 栈是否为空 = %s\n", isEmptyInitially ? "是" : "否");
	StackPush(&st, 40);
	bool isNotEmptyAfterPush = !StackEmpty(&st);
	printf("插入元素 40 后: 栈是否为空 = %s\n", isNotEmptyAfterPush ? "否" : "是");
	bool emptyResult = isEmptyInitially && isNotEmptyAfterPush;
	printTestResult("testStackEmpty", emptyResult);
	return emptyResult;
}

// 测试栈的大小
bool testStackSize()
{
	printf("\n开始测试栈的大小...\n");
	Stack st;
	StackInit(&st);
	printf("初始化后: 栈大小 = %d\n", StackSize(&st));
	StackPush(&st, 50);
	StackPush(&st, 60);
	printf("插入元素 50 和 60 后: 栈大小 = %d\n", StackSize(&st));
	bool sizeResult = StackSize(&st) == 2;
	printTestResult("testStackSize", sizeResult);
	return sizeResult;
}

// 测试栈的销毁
bool testStackDestroy()
{
	printf("\n开始测试栈的销毁...\n");
	Stack st;
	StackInit(&st);
	StackPush(&st, 70);
	printf("插入元素 70 后: array = %p, top = %d, capacity = %d\n", (void *)st.array, st.top, st.capacity);
	StackDestroy(&st);
	printf("销毁栈后: array = %p, top = %d, capacity = %d\n", (void *)st.array, st.top, st.capacity);
	bool destroyResult = st.array == NULL && st.top == 0 && st.capacity == 0;
	printTestResult("testStackDestroy", destroyResult);
	return destroyResult;
}

int main()
{
	testStackInit();
	testStackPush();
	testStackPop();
	testStackTop();
	testStackEmpty();
	testStackSize();
	testStackDestroy();

	return 0;
}