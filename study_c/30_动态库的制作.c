#include<stdio.h>
#include"mylib.h"
/*
	动态连接库的制作
		格式：gcc -shared mylib.c -o mylib.so		// 制作动态链接库

	使用动态链接库
		1.同一目录（使用静态库的文件，静态库，静态头文件）
			gcc mytest.c libmylib.so -o mytest
			export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH   #告诉系统，libmylib.so的位置。（存放在当前目录下）
		2.不同目录（使用静态库的文件，静态库，静态头文件）
			gcc mytest.c -o mytest -L /lib -l mylib -I /include
		3.系统默认目录
			gcc mytest.c -o mytest -l mylib
*/

int main30()
{
	int max_num, min_num, a = 100, b = 20;
	max_num = libmax(a, b);
	min_num = libmin(a, b);
	printf("max_min: %d\n", max_num);
	printf("min_num: %d\n", min_num);

	return 0;
}

