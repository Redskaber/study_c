#include<stdio.h>
#pragma pack(1)
/*
	�ṹ��ָ������ԭ��
		#pragma pack(val)	��val ��ṹ�������뷽ʽȡ��С
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
	printf("case=%d\n",sizeof(_Case));	//  ԭ 8
	pack_eq_1();
	pack_eq_2();
	pack_eq_8();
	return 0;
}
