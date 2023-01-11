#include<stdio.h>
/*
	函数指针
		保存函数地址的指针
	定义：
		类型 (*名)(参数列表);
		int (*p)(int,int);
*/

int max45(int a, int b)
{
	return a > b ? a : b;
}

int min45(int a, int b)
{
	return a < b ? a : b;
}

int main45()
{	
	int a = 10, b = 20;
	int (*p)(int, int);		// 定义函数指针参数 int,int

	p = max45;
	int max_ = p(a, b);
	printf("max_:%d\n", max_);

	p = min45;
	int min_ = p(a, b);
	printf("min_:%d\n", min_);
	return 0;
}
