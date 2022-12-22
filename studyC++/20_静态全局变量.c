#include<stdio.h>		// printf
#include"19_静态全局变量.h"

/*
void use_case_for_static_number()
{
	printf("this case for static number: %d", static_number);		// 无法使用 其他文件 static 定义的
}
*/

void extern_case_for_static_number(int static_number)
{
	printf("this case for static number: %d",static_number);
}
