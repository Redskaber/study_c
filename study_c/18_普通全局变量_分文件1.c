#include<stdio.h>
#include "普通全局变量.h"

void other_fun()
{
	printf("void fun print global number: %d\n", number);	// 只要能通过c 编译就是可以 直接找到对应值的
}

void extern_fun(int number)
{
	printf("void fuextern_funn print use file in global number: %d\n", number);
}
