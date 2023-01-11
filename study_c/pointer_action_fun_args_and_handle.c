#include<stdio.h>
/*
	ָ����Ϊ�����������ٺ����е�ʹ��
		��߶�*��һ��
		��߶�&��һ��

		���*�����ڽ��������Ϊֵ��
		���*�����ڽ���-1�����Ϊֵ��ַ��
*/


void only_one_fun_use()
{
	/*
		ֻ��һ��������ʹ��:

			int*** r		int** q		int* p		int a
		&	r�ĵ�ַ			q�ĵ�ַ		p�ĵ�ַ		a�ĵ�ַ
		*	q�ĵ�ַ			p�ĵ�ַ		a�ĵ�ַ		a��ֵ

		> int*** r	== &&&a;	��ȡ��ַ�� *
		> ***r	== a;			��ȡֵ��   &
	*/

	int a = 100;
	int* p = &a;
	int** q = &p;
	int*** r = &q;

	printf("&r=%p\t", &r);
	printf("r=%p\n", r);

	printf("&q=%p\t", &q);
	printf("q=%p\n", q);

	printf("&p=%p\t", &p);
	printf("p=%p\n", p);

	printf("&a=%p\t",&a);
	printf("a=%d\n",a);

	printf("\n\n");
	printf("**r:%p\t&a:%p\n",**r,&a);
	printf("***r:%d\ta:%d\n",***r,a);

	/*
		&r=0000009226AFFAF8     r=0000009226AFFAD8
		&q=0000009226AFFAD8     q=0000009226AFFAB8
		&p=0000009226AFFAB8     p=0000009226AFFA94
		&a=0000009226AFFA94     a=100


		**r:0000009226AFFA94    &a:0000009226AFFA94
		***r:100        a:100
	*/
}

void use_const(int *p)		// ���� const -> int *
{
	// int* p => &a
	printf("p:%p\n",p);
	printf("*p:%d\n",*p);	
	*p = 200;
}

void use_first_pointer(int** p)	// ���� int * -> int **
{
	// int** p => &p
	printf("*p:%p\n", *p);		// &a
	printf("**p:%d\n", **p);	// a
	**p = 400;
}

void use_second_pointer(int*** p)	// ���� int ** -> int ***
{
	// int*** p => &q
	printf("**p:%p\n", **p);		// &a
	printf("***p:%d\n", ***p);		// a
	***p = 600;
}

void use_thrid_pointer(int**** p)	// ���� int *** -> int ****
{
	// int*** p => &q
	printf("***p:%p\n", ***p);		// &a
	printf("****p:%d\n", ****p);	// a
	****p = 800;
}

void more_fun_use()
{
	int a = 100;
	int* p = &a;
	int** q = &p;
	int*** r = &q;

	printf("a:%d\n", a);
	use_const(&a);
	printf("a:%d\n",a);

	printf("a:%d\n", a);
	use_first_pointer(&p);
	printf("a:%d\n", a);

	printf("a:%d\n", a);
	use_second_pointer(&q);
	printf("a:%d\n", a);

	printf("a:%d\n", a);
	use_thrid_pointer(&r);
	printf("a:%d\n", a);
}

int main_other()
{
	only_one_fun_use();
	more_fun_use();
	return 0;
}