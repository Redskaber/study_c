#include<stdio.h>
#include"20_��̬ȫ�ֱ���.h"
/*
	��̬ȫ�ֱ�����static ���Ƶ�ȫ�ֱ�����
		static int a = number;	
		�������ļ���ʹ��
	���ԣ�
		���ļ�����ʹ��
		���ļ�ʹ��
*/
static int static_number = 200;		// ����java�е�static��java�е�static�Ƕ�����class�е��ڴ������c�Ƕ�����.c�ļ��е��ڴ�������Ƕ����������÷�Χ�������ڴ�ʹ�á�
void case_for_static_number();

int main19()
{
	printf("static int static_number: %d\n", static_number);
	
	static_number = 1000;
	case_for_static_number();
	// use_case_for_static_number();
	extern_case_for_static_number(static_number);

	return 0;
}

void case_for_static_number()
{
	printf("this case for static number: %d\n", static_number);
}