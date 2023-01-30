#include<stdio.h>

/*
	�ṹ��Ĵ洢��λ��ȷ��
		1.˳���ԣ���struct�ϵ���
		2.�ĸ��������͵ĳ�Առ�ֽ����࣬���������СΪ��λ�����ڴ棬����gcc�г�����double���͵ģ����⣩ 4*2
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
// 4���ֽڣ�4���ֽڵĿ��ٿռ䣬short 2 �ֽڣ��˷���2���ֽڣ�������չ4���ֽڡ�

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
	CASE c;		// �������Ļ�������Ϊ�洢��λ����(char, short, int)-> ��max)int   (x86|x64) 4�ֽ� 4*2=8
	printf("CASE struct sizeof: %d\n",sizeof(c));
	
	DCASE d = {
		.number=127,
		.mard=27
	};
	printf("DCASE struct sizeof: %d\n", sizeof(d));	// 16 �˷�7���ֽ�
	
	c.number = 100;
	c.card = 1;
	printf_struct_member_size(&c);
	printf_struct_member_sizeD(&d);

	return 0;
}


