#include<stdio.h>
#include"mylib.h"
/*
	��̬���ӿ������
		��ʽ��gcc -shared mylib.c -o mylib.so		// ������̬���ӿ�

	ʹ�ö�̬���ӿ�
		1.ͬһĿ¼��ʹ�þ�̬����ļ�����̬�⣬��̬ͷ�ļ���
			gcc mytest.c libmylib.so -o mytest
			export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH   #����ϵͳ��libmylib.so��λ�á�������ڵ�ǰĿ¼�£�
		2.��ͬĿ¼��ʹ�þ�̬����ļ�����̬�⣬��̬ͷ�ļ���
			gcc mytest.c -o mytest -L /lib -l mylib -I /include
		3.ϵͳĬ��Ŀ¼
			gcc mytest.c -o mytest -l mylib
*/

int main30()
{
	int max_num, min_num, a = 100, b = 20;
	max_num = libmax(a, b);
	min_num = libmin(a, b);
	printf("max_min: %d\n", max_num);
	printf("min_num: %d\n", min_num);

	return 0;
}

