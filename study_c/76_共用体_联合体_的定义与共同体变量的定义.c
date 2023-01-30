#include<stdio.h>

/*
	结构体体变形

		共同体：作用如其名
		说明： 多个变量使用相同一块存储空间
			导致： -> 新的变量数据会覆盖掉旧的数据。共用体内存只会保存最新的数据变量信息 
			间接说明： -> 存储大小只需要等于共用体成员中最大存储类型即可。

		关键字：union
		用法：union [name]{ type member;...}[ins]...;
			
*/


typedef int type_a;
typedef char type_b;
typedef int type_c;


typedef struct struct_name 
{
	type_a member_a;
	type_b member_b;
	type_c member_c;
} 
struct_nick_name;

typedef union union_name
{
	type_a member_a;
	type_b member_b;
	type_c member_c;
} 
union_nick_name;


int main76()
{
	struct_nick_name snn;
	printf("struct_type_nomery=%d\n", sizeof(snn));		// 12
	union_nick_name unn;
	printf("union_type_nomery=%d\n", sizeof(unn));		// 4

	return 0;
}