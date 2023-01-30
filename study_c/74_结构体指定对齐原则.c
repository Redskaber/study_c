#include<stdio.h>
#pragma pack(1)
/*
	结构体指定对齐原则
		#pragma pack(val)	用val 与结构体最大对齐方式取其小
*/

typedef struct {
	int number;		
	char sex;
} Explame;

void pack_eq_1()
{
	Explame _Case;
	printf("case=%d\n", sizeof(_Case));	//  5

}

void pack_eq_2()
{
	Explame _Case;
	printf("case=%d\n", sizeof(_Case));	//  6

}

void pack_eq_8()
{
	Explame _Case;
	printf("case=%d\n", sizeof(_Case));	//  8

}

int main74()
{
	Explame _Case;
	printf("case=%d\n",sizeof(_Case));	//  原 8
	pack_eq_1();
	pack_eq_2();
	pack_eq_8();
	return 0;
}
