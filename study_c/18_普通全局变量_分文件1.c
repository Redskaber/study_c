#include<stdio.h>
#include "��ͨȫ�ֱ���.h"

void other_fun()
{
	printf("void fun print global number: %d\n", number);	// ֻҪ��ͨ��c ������ǿ��� ֱ���ҵ���Ӧֵ��
}

void extern_fun(int number)
{
	printf("void fuextern_funn print use file in global number: %d\n", number);
}
