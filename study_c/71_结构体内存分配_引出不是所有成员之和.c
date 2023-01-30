#include<stdio.h>

/*
	�ṹ���ڴ� != ���г�Ա�ڴ�֮��
*/

typedef struct {
	int number;
	int age;
} SAME;

typedef struct {
	int number;
	char name;
}NSAME;


void printf_struct_member_sizeof(SAME* _Struct)
{
	printf("sizeof(_Struct.number)=%d\n", (int)sizeof(_Struct->number));	// 4
	printf("sizeof(_Struct.age)=%d\n", (int)sizeof(_Struct->age));			// 4
}

void printf_struct_member_sizeof2(NSAME* _Struct)
{
	printf("sizeof(_Struct.number)=%d\n", (int)sizeof(_Struct->number));	// 4
	printf("sizeof(_Struct.name)=%d\n", (int)sizeof(_Struct->name));		// 1
}

int main71()
{
	SAME same;
	NSAME nsame;

	printf("sizeof(same)=%d\n", (int)sizeof(same));	// 8
	printf("sizeof(nsame)=%d\n", (int)sizeof(nsame));	// 8 ?

	printf_struct_member_sizeof(&same);
	printf_struct_member_sizeof2(&nsame);
	return 0;
} 
