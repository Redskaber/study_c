#include<stdio.h>
#include"mylib.h"
/*
	��̬���ӿ������
		��ʽ��gcc -c mylib.c -o mylib.o		// ����������ļ�
			  ar rc libmylib.a mylib.o		// ������������Ϊ��̬�����ļ�

		[root@MyCould static]# gcc mylib.c 29_��̬�������.c -o mytest		// ���ɿ�ִ���ļ�
	
	ʹ�þ�̬���ӿ�
		1.ͬһĿ¼��ʹ�þ�̬����ļ�����̬�⣬��̬ͷ�ļ���
			gcc mytest.c libmylib.a -o mytest
		2.��ͬĿ¼��ʹ�þ�̬����ļ�����̬�⣬��̬ͷ�ļ���
			gcc mytest.c -o mytest -L /lib -l mylib -I /include
		3.ϵͳĬ��Ŀ¼
			gcc mytest.c -o mytest -l mylib
*/

int main29()
{
	int max_num, min_num, a=100, b=20;
	max_num = libmax(a,b);
	min_num = libmin(a,b);
	printf("max_min: %d\n", max_num);
	printf("min_num: %d\n", min_num);

	return 0;
}
