#include<stdio.h>

static void in_fun();
void out_fun()		// �ⲿ����
{
	printf("void out_fun\n");
	in_fun();
}

static void in_fun()	// �ڲ�����
{
	printf("void in_fun\n");
}
