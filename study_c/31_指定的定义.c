#include<stdio.h>

/*
	ָ�붨�壺
		�������
			& ȡַ
			* ȡֵ
		��ʽ��ָ������ * ָ����� [= ֵ];
			  ָ������ * ָ�����1, * ָ�����2, ... [= ֵ];

		˵��: *����Ϊ���η�

		ps: int a = 100;
			int *p = &a;

		ָ���ϵ:
				p			rela			a
		address		value			address		value	
		&p			p		->		&a | p		a | *p


		p -> &a
		*p -> a		
		
		ָ��Ĵ�С sizeof(*p);
			64->8
			32->4
			����ϵͳ������
*/

int main31()
{
	int a = 100;
	int* p;		// Ұָ�룬û�г�ʼ������ֵ��ָ��һ������ĵ�ַ
	p = &a;
	

	printf("a=%d,	&a=%x\n",a,&a);
	printf("p=%x,	&p=%x,	*p=%d\n",p,&p,*p);
	printf("p=%x,	&a=%x\n",p,&a);		// ָ�� p ��ֵ�洢 ����a�ĵ�ַ��&a��	


	return 0;
}
