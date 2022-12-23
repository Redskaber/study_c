#include<stdio.h>
#include"内部函数与外部函数.h"
/*
	外部函数：自己写的普通函数
		可以在定义文件外进行调用的函数。
		int out_fun(){}
	内部函数：有static 修饰的函数。
		只可以在本定义的文件中使用。
		static int in_fun(){}
*/	


int main22()
{
	out_fun();
	// in_fun();  // 无法使用
	return 0;
}
