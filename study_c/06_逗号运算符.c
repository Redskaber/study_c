#include<stdio.h>
/*
	逗号运算符
	(),() => 默认后面的优先级更高

*/

int main06()
{
	int a = (1, 2);
	printf("int a = %d\n", a);

	return 0;
}