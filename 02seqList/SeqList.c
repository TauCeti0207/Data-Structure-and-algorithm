#include "SeqList.h"

// 初始化顺序表
// 此函数用于将顺序表的各项属性初始化为初始状态
// 参数: pseq - 指向顺序表结构体的指针
void SeqListInit(SeqList *pseq)
{
	// 断言确保传入的指针不为空，避免对空指针进行操作
	assert(pseq);
	pseq->a = (SeqDataType *)malloc(sizeof(SeqDataType) * 4);
	if (pseq->a == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	pseq->size = 0;
	pseq->capacity = 4;
}

// 销毁顺序表
// 该函数用于释放顺序表所占用的动态内存，防止内存泄漏
// 参数: pseq - 指向顺序表结构体的指针
void SeqListDestory(SeqList *pseq)
{
	// 断言确保传入的指针不为空
	assert(pseq);
	// 检查顺序表是否分配了内存
	if (pseq->a)
	{
		// 释放动态分配的内存
		free(pseq->a);
		// 释放内存后，将指针置为 NULL，避免成为野指针
		pseq->a = NULL;
		// 销毁后，有效数据个数置为 0
		pseq->size = 0;
		// 销毁后，容量置为 0
		pseq->capacity = 0;
	}
}

// 打印顺序表中的元素
// 此函数用于遍历顺序表并打印出其中的所有有效元素
// 参数: pseq - 指向顺序表结构体的指针
void SeqListPrint(SeqList *pseq)
{
	// 断言确保传入的指针不为空
	assert(pseq);
	// 遍历顺序表中的有效元素
	for (size_t i = 0; i < pseq->size; i++)
	{
		// 打印每个元素
		printf("%d ", pseq->a[i]);
	}
	// 打印完所有元素后换行
	printf("\n");
}

// 检查顺序表的容量并在需要时进行扩容
// 当顺序表的有效数据个数达到容量时，该函数会将容量扩大
// 参数: pseq - 指向顺序表结构体的指针
void SeqCheckCapacity(SeqList *pseq)
{
	// 断言确保传入的指针不为空
	assert(pseq);
	// 检查有效数据个数是否等于当前容量
	if (pseq->size == pseq->capacity)
	{
		// 若容量为 0，初始分配 4 个元素的空间；否则将容量扩大为原来的两倍
		size_t newCapacity = pseq->capacity == 0 ? 4 : pseq->capacity * 2;
		// malloc 的局限性：malloc 函数用于分配指定大小的内存块，但它不会复用已有的内存空间。当顺序表需要扩容时，如果使用 malloc，需要先分配一块新的足够大的内存空间，然后将原内存空间中的数据逐个复制到新的内存空间，最后释放原内存空间。这样做不仅增加了代码的复杂度，还会产生额外的内存复制开销。
		// realloc 的优势：realloc 函数可以在原有的内存块基础上进行调整，它会尝试在原内存块的后面扩展内存空间。如果原内存块后面有足够的连续空闲空间，realloc 会直接在原内存块后面扩展，避免了数据的复制，提高了内存分配的效率。即使原内存块后面没有足够的空间，realloc 也会自动分配一块新的内存空间，并将原内存块中的数据复制到新的内存空间，然后释放原内存块，这个过程对用户是透明的，简化了代码的实现。
		// 如果使用 malloc 实现扩容功能，需要手动进行内存分配、数据复制和原内存释放等操作，代码会变得更加复杂。
		// 使用 realloc 函数重新分配内存
		SeqDataType *tmp = (SeqDataType *)realloc(pseq->a, newCapacity * sizeof(SeqDataType));
		// 检查内存分配是否成功
		if (tmp == NULL)
		{
			// 若分配失败，输出错误信息
			perror("realloc failed");
			// 程序异常退出
			exit(EXIT_FAILURE);
		}
		// 内存分配成功，更新顺序表的指针
		pseq->a = tmp;
		// 更新顺序表的容量
		pseq->capacity = newCapacity;
	}
}

// 在顺序表的尾部插入一个元素
// 此函数会将指定元素添加到顺序表的末尾
// 参数: pseq - 指向顺序表结构体的指针
// 参数: x - 要插入的元素
void SeqListPushBack(SeqList *pseq, SeqDataType x)
{
	// 断言确保传入的指针不为空
	assert(pseq);
	// 插入元素前，先检查是否需要扩容
	SeqCheckCapacity(pseq);
	// 将元素插入到顺序表的末尾
	pseq->a[pseq->size] = x;
	// 插入元素后，有效数据个数加 1
	pseq->size++;
}

// 在顺序表的头部插入一个元素
// 该函数会将指定元素插入到顺序表的开头位置
// 参数: pseq - 指向顺序表结构体的指针
// 参数: x - 要插入的元素
void SeqListPushFront(SeqList *pseq, SeqDataType x)
{
	// 断言确保传入的指针不为空
	assert(pseq);
	// 插入元素前，先检查是否需要扩容
	SeqCheckCapacity(pseq);
	// 将顺序表中的元素依次向后移动一位
	for (size_t i = pseq->size; i > 0; i--)
	{
		pseq->a[i] = pseq->a[i - 1];
	}
	// 将元素插入到顺序表的头部
	pseq->a[0] = x;
	// 插入元素后，有效数据个数加 1
	pseq->size++;
}

// 删除顺序表尾部的元素
// 此函数会移除顺序表中的最后一个元素
// 参数: pseq - 指向顺序表结构体的指针
void SeqListPopBack(SeqList *pseq)
{
	// 断言确保传入的指针不为空且顺序表中有元素
	assert(pseq && pseq->size > 0);
	// 直接将有效数据个数减 1，相当于删除最后一个元素
	pseq->size--;
}

// 删除顺序表头部的元素
// 该函数会移除顺序表中的第一个元素
// 参数: pseq - 指向顺序表结构体的指针
void SeqListPopFront(SeqList *pseq)
{
	// 断言确保传入的指针不为空且顺序表中有元素
	assert(pseq && pseq->size > 0);
	// 将顺序表中的元素依次向前移动一位
	for (size_t i = 0; i < pseq->size - 1; i++)
	{
		pseq->a[i] = pseq->a[i + 1];
	}
	// 删除元素后，有效数据个数减 1
	pseq->size--;
}

// 在顺序表中查找指定元素
// 此函数会遍历顺序表，查找是否存在指定元素
// 参数: pseq - 指向顺序表结构体的指针
// 参数: x - 要查找的元素
// 返回值: 若找到元素，返回其下标；若未找到，返回 -1
int SeqListFind(SeqList *pseq, SeqDataType x)
{
	// 断言确保传入的指针不为空
	assert(pseq);
	// 遍历顺序表中的有效元素
	for (size_t i = 0; i < pseq->size; i++)
	{
		// 检查当前元素是否等于要查找的元素
		if (pseq->a[i] == x)
		{
			// 若找到，返回元素的下标
			return (int)i;
		}
	}
	// 未找到元素，返回 -1
	return -1;
}

// 在顺序表的指定位置插入一个元素
// 此函数会将指定元素插入到顺序表的指定位置
// 参数: pseq - 指向顺序表结构体的指针
// 参数: pos - 要插入元素的位置
// 参数: x - 要插入的元素
void SeqListInsert(SeqList *pseq, size_t pos, SeqDataType x)
{
	// 断言确保传入的指针不为空且插入位置合法
	assert(pseq && pos <= pseq->size && pos >= 0);
	// 插入元素前，先检查是否需要扩容
	SeqCheckCapacity(pseq);
	// 将指定位置及之后的元素依次向后移动一位
	for (size_t i = pseq->size; i > pos; i--)
	{
		pseq->a[i] = pseq->a[i - 1];
	}
	// 这样写不可以 有坑 当顺序表为空，即 pseq->size 的值为 0 时，会执行 size_t end = pseq->size - 1; 这行代码。由于 end 被定义为 size_t 类型，它是无符号整数类型。在计算机中，无符号整数不能表示负数，当执行 0 - 1 操作时，会发生溢出。
	// 以 32 位系统为例，无符号整数 size_t 的取值范围是 0 到 4294967295（2^32 - 1）。当 0 - 1 时，结果会变成 4294967295 这个非常大的数。
	// 接下来，进入 while (end >= pos) 循环，由于 end 是一个极大的数，而 pos 为 0，所以 end >= pos 这个条件始终为真。并且在循环体中，每次执行 --end 操作，因为 end 是无符号类型，它不会变成负数，而是会从 4294967295 依次递减到 0，之后又会重新从 4294967295 开始，从而导致程序陷入死循环，无法正常完成插入操作。
	/* 	size_t end = pseq->size - 1;
		while (end >= pos)
		{
			pseq->a[end + 1] = pseq->a[end];
			end--;
		} */

	// 将元素插入到指定位置
	pseq->a[pos] = x;
	// 插入元素后，有效数据个数加 1
	pseq->size++;
}

// 删除顺序表中指定位置的元素
// 此函数会移除顺序表中指定位置的元素
// 参数: pseq - 指向顺序表结构体的指针
// 参数: pos - 要删除元素的位置
void SeqListErase(SeqList *pseq, size_t pos)
{
	// 断言确保传入的指针不为空且删除位置合法
	assert(pseq && pos < pseq->size);
	// 将指定位置之后的元素依次向前移动一位
	for (size_t i = pos; i < pseq->size - 1; i++)
	{
		pseq->a[i] = pseq->a[i + 1];
	}
	// 删除元素后，有效数据个数减 1
	pseq->size--;
}

// 修改顺序表中指定位置的元素
// 此函数会将顺序表中指定位置的元素修改为新的值
// 参数: pseq - 指向顺序表结构体的指针
// 参数: pos - 要修改元素的位置
// 参数: x - 新的值
void SeqListModify(SeqList *pseq, size_t pos, SeqDataType x)
{
	// 断言确保传入的指针不为空且修改位置合法
	assert(pseq && pos < pseq->size);
	// 将指定位置的元素修改为新的值
	pseq->a[pos] = x;
}