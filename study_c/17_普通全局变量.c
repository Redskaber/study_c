#include<stdio.h>
#include "��ͨȫ�ֱ���.h"
#include "��ͨȫ�ֱ���_���ļ�.h"
/*
	��ͨȫ�ֱ�����ʹ��
		int a = number;		û�и�ֵĬ��Ϊ0��
	���Գ���
		1.���ļ�ʹ��
			func
		2.���ļ�ʹ��		
			h && c
			include && use						
*/

int number = 100;

int main17()
{
	printf("global int number: %d\n", number);
	number = 200;
	funce();				// �ļ��ڲ�ʹ���ļ�ȫ�ֱ���
	other_fun();					// �ⲿ�ļ�����ʹ��ȫ�ֱ���
	extern_fun(number);		// �ⲿ�ļ�����ʹ���ڲ���ȫ�ֱ���
	return 0;
}

void funce()
{
	printf("global int number for fun: %d\n", number);
}

