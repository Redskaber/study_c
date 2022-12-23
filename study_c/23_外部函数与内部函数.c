#include<stdio.h>

static void in_fun();
void out_fun()		// 外部函数
{
	printf("void out_fun\n");
	in_fun();
}

static void in_fun()	// 内部函数
{
	printf("void in_fun\n");
}
