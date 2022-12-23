#include<stdio.h>
#include"case_min.h"
#include"case_max.h"

/*
	Linux 下GCC编译器编译过程

	gcc	-E	hello.c	-o	hello.i			1、预处理
	gcc	-S	hello.i	 -o	hello.s			2、编译
	gcc	-c	hello.s	 -o	hello.o			3、汇编
	gcc	hello.o	-o	hello_elf			4、链接

	当有多个.c文件时，将多个.c文件分别生成.o目标文件,
	最后将多个.o文件一起链接成可执行文件

*/

// max min main c h
int main()
{
	int num;

	num = case_min(20, 10);
	printf("min num: %d\n", num);

	num = case_max(100, 200);
	printf("max num: %d\n", num);

	return 0;
}

