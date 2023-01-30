#include<stdio.h>

/*
	结构体的存储单位的确定
		1.顺序性，从struct上到下
		2.哪个基本类型的成员占字节数多，就以它大大小为单位开辟内存，（在gcc中出现了double类型的，例外） 4*2
		- X64 8*8
		char 1
		short 2
		int float long 4
		double (long double) (long long) pointer 8

		-X86  4*8
		char 1
		short 2
		int float long  pointer 4
		double (long double) (long long) 8

*/

typedef struct {
	short card;
	int number;

}CASE;
// 4个字节，4个字节的开辟空间，short 2 字节，浪费了2个字节，后在拓展4个字节。

typedef struct {
	double mard;
	char number;

}DCASE;


void printf_struct_member_size(CASE* _Struct_pointer)
{
	printf("_Struct_pointer->number=%d\n", _Struct_pointer->number);
	printf("_Struct_pointer->card=%d\n", _Struct_pointer->card);
}

void printf_struct_member_sizeD(DCASE* _Struct_pointer)
{
	printf("_Struct_pointer->number=%d\n", _Struct_pointer->number);
	printf("_Struct_pointer->mard=%lf\n", _Struct_pointer->mard);
}

int main72()
{
	CASE c;		// 根据最大的基础类型为存储单位，这(char, short, int)-> （max)int   (x86|x64) 4字节 4*2=8
	printf("CASE struct sizeof: %d\n",sizeof(c));
	
	DCASE d = {
		.number=127,
		.mard=27
	};
	printf("DCASE struct sizeof: %d\n", sizeof(d));	// 16 浪费7个字节
	
	c.number = 100;
	c.card = 1;
	printf_struct_member_size(&c);
	printf_struct_member_sizeD(&d);

	return 0;
}


