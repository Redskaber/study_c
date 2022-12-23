#include<stdio.h>


int main12()
{
	/*
	数组的定义：
		数组是一段连续的内存。多维是逻辑上的多维，本质是连续的地址块。
	
	数组分类：
		 元素类型分类
		 维度分类
	数组初始化：
		完全初始化
		部分初始化（只能最末，未初始化部分默认0填充）
	*/

	element_classifaction();
	dimension_classifaction();
	initial_case();

	int a[5] = { 1,2,3 };
	int size = (int)sizeof(a);
	int step = size / sizeof(int);

	printf("sizeof(a[5]={1,2,3}) %d\n", size);
	part_initial_case(a, step);

	return 0;

}

int element_classifaction()
{
	// 元素分类
	/*
		char
		short int long
		float double
		
		*point		// 指针类型 8字节 64位
		struct

		char c[10];  // 定长
		char c2[] = { 1,2,3,4,5 };	// 未init数组size大小的，默认将初次赋值的size作为zise。
	*/

	char c[10];  // 定长
	char c2[] = { 1,2,3,4,5 };	// 未init数组size大小的，默认将初次赋值的size作为zise。	
	short s[10];
	int i[10];
	float f[10];

	printf("char c[10] sizeof: %d\n", (int)sizeof(c)); //10	
	printf("char c2[] sizeof: %d\n", (int)sizeof(c2)); //5
	printf("short s[10] sizeof: %d\n", (int)sizeof(s)); //20
	printf("int i[10] sizeof: %d\n", (int)sizeof(i));	//40
	printf("float f[10] sizeof: %d\n", (int)sizeof(f)); //40

	char* p = &c;	// point 
	char* cp[10];
	char* cp2[] = {p};

	printf("char* cp[10] sizeof: %d\n", (int)sizeof(cp)); //80
	printf("char* cp2[] sizeof: %d\n", (int)sizeof(cp2)); //8
	
	// struct

	return 0;
}

int dimension_classifaction()
{
	/*
		一维	char a[A];
		二维	char a[A][B];
		多维	char a[A]...[...];
	*/

	char a[100];		//一维
	char b[10][10];		//二维
	char c[2][5][10];	//三维...

	return 0;
}

int initial_case()
{
	/*
		完全初始化
		部分初始化（末尾填充0）
	*/

	int a[5] = { 1,2,3,4,5 };	// all
	int c[5] = { 1,2,3 };		// part

	return 0;
}

int part_initial_case(int a[], int step)
{
	// 8,注意: 原因是这里的a是a[]的指针，所以求的是a[]指针的大小，而不是a[]的size。
	printf("sizeof(a[5]={1,2,3}) %d\n", (int)sizeof(a));	

	for (int i = 0; i < step; i++)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}
	return 0;
}








