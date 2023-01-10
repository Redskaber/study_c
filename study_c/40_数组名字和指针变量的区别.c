#include<stdio.h>

/*

	int a[10];
	int *p=a;

	�������ֺ�ָ���������ͬ��
		- ��������
		=> ָ����������������
			a[2]	p[2]
			*(a+2)	*(p+2)

	�������ֺ�ָ������Ĳ�ͬ��
		- ��������
			-> ��Χ�����㡢���
		=> ����&&����������ָ��&&ָ���ָ��
			a != xxx	p = xxx
			&a		int(* )[10]		40
			&p		int**			8
*/	
void val_name_and_pointer_same();
void val_name_and_pointer_diff();

int main40()
{
	val_name_and_pointer_same();
	printf("\n");
	val_name_and_pointer_diff();
	return 0;
}


void val_name_and_pointer_same()
{	
	/*
		��������
	*/
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	int* p = a;

	printf("a[2]:%d\n",a[2]);
	printf("*(a+2):%d\n",*(a + 2));

	printf("p[2]:%d\n", p[2]);
	printf("*(p+2):%d\n", *(p + 2));
}

void val_name_and_pointer_diff()
{	
	/*
		��������=> range,opreac,resp
	*/
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p = a;
	
	printf("a not = xxx\n");
	printf("p can = xxx\n");

	printf("&a:%p\n",&a);		// int(* )[10]		(step)
	printf("&a+1:%p\n",&a+1);
	printf("(int)(&a+1)-(int)(&a):%d\n\n", (int)(&a + 1) - (int)(&a));

	printf("&p:%p\n", &p);		// int*
	printf("&p+1:%p\n", &p + 1);
	printf("(int)(&p+1)-(int)(&p):%d\n\n", (int)(&p + 1) - (int)(&p));

}