#include<stdio.h>
/*
	普通的局部变量
		作用范围 定义的函数或复合语句中
			int a =1;
			for(int i =1;;)
		生命周期：一次调用完全函数或复合语句
	静态局部变量
		作用范围 定义的函数或复合语句中
		生命周期：第一次声明后，直到程序结束。
*/

void case_for_part_val(void)
{
	int number=1; // 每一次函数的生命周期
	printf("part val: number=%d\n",number);
	number++;
}

void case_for_part_static_val()
{
	static int number = 5;	// 从被注册到程序结束
	printf("part val: number=%d\n", number);
	number++;
}

int main21()
{
	for (short i = 0; i < 3; i++)
	{
		case_for_part_val();
	}
	for (short i = 0; i < 3; i++)
	{
		case_for_part_static_val();
	}
	return 0;
}