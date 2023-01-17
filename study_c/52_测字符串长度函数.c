#include<stdio.h>
#include<string.h>	// strlen

#pragma warning(disable:4996)
#pragma warning(disable:6328)
/*
	vs:指定计算机或操作系统特定的编译器功能
	
		#pragma
		#pragma warning(disable:4996)	// 在c文件开始处写上这句话，即告诉编译器忽略4996警告，strcpy、scanf等一些不安全的标准c库函数在vs中可以用了。

	测字符串长度函数
		size_t strlen()  string.h	（字符串字符）个数。
		sizeof	  关键字	 数组容量 / 指针大小
*/


void for_each_string(char* string)
{	
	printf("string=%s\n",string);
	printf("sizeof(string)=%d\n", sizeof(string));	// int*	 8
	printf("strlen(string)=%d\n", strlen(string));	// strlen(string)
}



int main52( int argc, char* argv[])
{
	char a[20] = { "hello!"};
	char* p = "hello!";

	printf("sizeof(a)=%d\n",sizeof(a));	// 20	数组容量
	printf("sizeof(p)=%d\n",sizeof(p));	// 8	指针大小

	printf("strlen(a)=%d\n",strlen(a));	// 6
	printf("strlen(p)=%d\n",strlen(p));	// 6

	printf("\n\n");

	char array[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char *string = "0123456789";
	for_each_string(string);
	return 0;
}

