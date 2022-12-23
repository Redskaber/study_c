#include<stdio.h>
#include"case_min.h"
#include"case_max.h"

/*
	Linux ��GCC�������������

	gcc	-E	hello.c	-o	hello.i			1��Ԥ����
	gcc	-S	hello.i	 -o	hello.s			2������
	gcc	-c	hello.s	 -o	hello.o			3�����
	gcc	hello.o	-o	hello_elf			4������

	���ж��.c�ļ�ʱ�������.c�ļ��ֱ�����.oĿ���ļ�,
	��󽫶��.o�ļ�һ�����ӳɿ�ִ���ļ�

*/

// max min main c h
int main()
{
	int num;

	num = case_min(20, 10);
	printf("min num: %d\n", num);

	num = case_max(100, 200);
	printf("max num: %d\n", num);

	return 0;
}

