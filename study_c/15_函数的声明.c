#include<stdio.h>
#include "函数的声明.h"
/*
	
	c的执行顺序是：从上到下的。

	1.直接声明法：
		函数的第一行;	类似于变量的声明

	2.间接声明法：

		将声明的内容存放到头文件中。

		- 调用c库文件使用<>
			默认到系统的指定目录下找头文件。

		- 自己写的头文件，包含在使用的目录下，直接使用 ""
			""：先在当前目录下找，如果没有，再到系统指定目录下找。

*/

void after_fun();	// 直接声明

void before_fun()
{
	printf("before_fun()\n");
}

int main15()
{
	before_fun();
	after_fun(); 
	indirect_after_fun();
	return 0;
}

void after_fun()
{
	printf("after_fun()\n");
}

void indirect_after_fun()
{
	printf("indirect_after_fun()\n");
}
