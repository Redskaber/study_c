#include<stdio.h>
#include"20_静态全局变量.h"
/*
	静态全局变量（static 限制的全局变量）
		static int a = number;	
		仅定义文件中使用
	测试：
		本文件定义使用
		分文件使用
*/
static int static_number = 200;		// 类似java中的static，java中的static是定义在class中的内存管理，而c是定义在.c文件中的内存管理，他们都是限制作用范围，控制内存使用。
void case_for_static_number();

int main19()
{
	printf("static int static_number: %d\n", static_number);
	
	static_number = 1000;
	case_for_static_number();
	// use_case_for_static_number();
	extern_case_for_static_number(static_number);

	return 0;
}

void case_for_static_number()
{
	printf("this case for static number: %d\n", static_number);
}