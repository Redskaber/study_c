#include<stdio.h>

void case_pointer_or_ppointer();
int main36()
{
	case_pointer_or_ppointer();
	return 0;
}

void case_pointer_or_ppointer()
{
	/*
	 ע�⣺
        int a=100; // int���� ��a ֵ100
        int *a=100; // int���� ָ������* ��a ֵ100
        int **a=100; // int*���� ָ������* ��a ֵ100
	*/
	int a = 100;
	int* b = &a;
	int** c = &b;
	int*** d = &c;
	/*	
		b = &a		һ��ָ��
		c = &b		����ָ��
		d = &c		����ָ��
		...
		z = &y		�߼�ָ��

		=> 
		*d	= c     ����->����	(3-2)��ȡֵ
		**d	= b		����->һ��	(3-1)��ȡֵ
		***d= a		����->����	(3-0)��ȡֵ
				
		=>
		(n)*p = a		n��->����	(n-0)��ȡֵ
		(n)*p = (m)*p	n��->m��	(n-m)��ȡֵ

		һ��ָ�����η�����һ��ָ�뼶��
		�Ӹ߼�ָ���ȡ����ֵ��
		�߶��ټ�������Ҫȡ���ٴ�ֵ��

	*/
	printf("a:%d,\t&a:%p\n",a,&a);
	printf("b:%p,\t&b:%p,\t*b:%d\n",b,&b,*b);
	printf("c:%p,\t&c:%p,\t*c:%p,\t**c:%d\n",c,&c,*c,**c);
	printf("d:%p,\t&d:%p,\t*d:%p,\t**d:%p,\t***d:%d\n",d,&d,*d,**d,***d);

}