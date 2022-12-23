#include<stdio.h>
#include "普通全局变量.h"
#include "普通全局变量_分文件.h"
/*
	普通全局变量的使用
		int a = number;		没有赋值默认为0；
	测试场景
		1.本文件使用
			func
		2.分文件使用		
			h && c
			include && use						
*/

int number = 100;

int main17()
{
	printf("global int number: %d\n", number);
	number = 200;
	funce();				// 文件内部使用文件全局变量
	other_fun();					// 外部文件函数使用全局变量
	extern_fun(number);		// 外部文件函数使用内部的全局变量
	return 0;
}

void funce()
{
	printf("global int number for fun: %d\n", number);
}

