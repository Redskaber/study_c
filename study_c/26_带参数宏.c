#include<stdio.h>

/*
	带参数宏
		格式： #define 宏名称(形参,...) 表达式
		ps： #define S(a,b) a*b	
	
	预处理：
		gcc -E hello.c -o hello.i		(使用宏的形参的实参，“替换“表达式中的形参)
		ps：
			origin： number = S(2,4);
			target： number = 2 * 4 ;
	注意：
		宏参数是没有类型的。
		宏定义结尾不需要“;”。
		宏只是替换形参参数。会出现下面情况。
		ps：
			origin： number = S(2+5,4);
			target： number = 2+5 * 4 ;		// 运算符优先级 -> 22;
	
	避免宏的坑：
		ps： #define S(a,b) (a)*(b)	
*/

#define S(a,b) (a)*(b)

int main26()
{
	int number = S(10+10, 20);
	printf("#define S(a,b) a*b: %d",number);
	return 0;
}
