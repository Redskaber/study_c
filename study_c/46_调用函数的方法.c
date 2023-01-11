#include<stdio.h>

/*
	函数的调用方法
		1.源函数名(args)
		2.(*函数指针)(args)
*/
int max46(int a, int b) { return a > b ? a : b; }

int main46() 
{
	int num;
	
	num = max46(100,200);
	printf("num:%d\n",num);

	int (*p)(int, int);
	p = max46;
	num = (*p)(300, 400);
	printf("num:%d\n", num);

	return 0;
}