#include<stdio.h>
#include "����������.h"
/*
	
	c��ִ��˳���ǣ����ϵ��µġ�

	1.ֱ����������
		�����ĵ�һ��;	�����ڱ���������

	2.�����������

		�����������ݴ�ŵ�ͷ�ļ��С�

		- ����c���ļ�ʹ��<>
			Ĭ�ϵ�ϵͳ��ָ��Ŀ¼����ͷ�ļ���

		- �Լ�д��ͷ�ļ���������ʹ�õ�Ŀ¼�£�ֱ��ʹ�� ""
			""�����ڵ�ǰĿ¼���ң����û�У��ٵ�ϵͳָ��Ŀ¼���ҡ�

*/

void after_fun();	// ֱ������

void before_fun()
{
	printf("before_fun()\n");
}

int main15()
{
	before_fun();
	after_fun(); 
	indirect_after_fun();
	return 0;
}

void after_fun()
{
	printf("after_fun()\n");
}

void indirect_after_fun()
{
	printf("indirect_after_fun()\n");
}
