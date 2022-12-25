#include<stdio.h>
#include"mylib.h"
/*
	静态连接库的制作
		格式：gcc -c mylib.c -o mylib.o		// 编译二进制文件
			  ar rc libmylib.a mylib.o		// 将二进制制作为静态链接文件

		[root@MyCould static]# gcc mylib.c 29_静态库的制作.c -o mytest		// 生成可执行文件
	
	使用静态链接库
		1.同一目录（使用静态库的文件，静态库，静态头文件）
			gcc mytest.c libmylib.a -o mytest
		2.不同目录（使用静态库的文件，静态库，静态头文件）
			gcc mytest.c -o mytest -L /lib -l mylib -I /include
		3.系统默认目录
			gcc mytest.c -o mytest -l mylib
*/

int main29()
{
	int max_num, min_num, a=100, b=20;
	max_num = libmax(a,b);
	min_num = libmin(a,b);
	printf("max_min: %d\n", max_num);
	printf("min_num: %d\n", min_num);

	return 0;
}
