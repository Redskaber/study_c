#include<stdio.h>

/*
	共同体使用的是同一块存储内存，使用同一块存储地址

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


void printf_struct_nick_name_member_address(struct_nick_name* _Struct)
{
	printf("member_a=%p\n",&(_Struct->member_a));
	printf("member_b=%p\n",&(_Struct->member_b));
	printf("member_c=%p\n",&(_Struct->member_c));
}

void printf_union_nick_name_member_address(union_nick_name* _Union)
{
	printf("member_a=%p\n", &(_Union->member_a));
	printf("member_b=%p\n", &(_Union->member_b));
	printf("member_c=%p\n", &(_Union->member_c));
}
int main77()
{
	struct_nick_name snn;
	printf("struct_type_nomery=%d\n", sizeof(snn));		// 12
	union_nick_name unn;
	printf("union_type_nomery=%d\n", sizeof(unn));		// 4

	printf_struct_nick_name_member_address(&snn);		// struct 不同
	printf_union_nick_name_member_address(&unn);		// union 相同
	return 0;
}
