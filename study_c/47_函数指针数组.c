#include<stdio.h>

/*
	����ָ������
		�ɺ���ָ����ɵļ�����
		����ָ�� + ���� �ӽ������Ľ��

		����:
			int(*p[5])(int,int);
		use:
			num = (*p[2])(10,10);

*/

int min47(int a, int b) { return a < b ? a : b; }
int sum47(int a, int b) { return a + b; }
int max47(int a, int b) { return a > b ? a : b; }
int mux47(int a, int b) { return a * b; }
int avg47(int a, int b) { return (a + b) / 2; }

int proccess(int (*p)(int,int), int a, int b)
{
	return (*p)(a, b);
}

int main47()
{
	int (*p[5])(int, int) = {max47,min47,sum47,mux47,avg47};	// init && define
	int num = (*p[2])(10, 20);
	printf("num:%d\n",num);		// 30

	num = proccess(mux47,10,20);
	printf("num:%d\n",num);

	return 0;
}
