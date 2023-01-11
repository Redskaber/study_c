#include<stdio.h>
#include<stdlib.h>

/*
	内存的动态申请与释放
		1.malloc 申请
		2.free   释放
*/


void free_malloc(int * array)	// &
{
	if (array)printf("指针未释放！\n");
	if (array) {
		free(array);	// 释放内存
		array = NULL;	// 解除“野指针”
	}
	if (array == NULL)printf("指针释放！\n");
}

int main50()
{
	int count;
	printf("请输入动态生成的int空间大小：\n");
	scanf_s("%d",&count);

	int* array = (int*)malloc(sizeof(int) * count);
	if (array == NULL) {
		printf("动态申请地址失败！");
		return 0;
	}

	for (int i = 0; i < count; i++) { array[i] = i; }
	for (int i = 0; i < count; i++){ printf("array[%d]=%d\n",i,array[i]); }

	free_malloc(array);		// &

	return 0;
}

