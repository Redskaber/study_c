#include<stdio.h>

/*
	����ָ��ȡ *
		����ָ��ȡ *������ȡֵ����˼����ָ������ͷ��ͱ����
	
*/
void single_dimension_array();
void more_dimension_array();

int main42()
{

	single_dimension_array();
	printf("\n");
	more_dimension_array();
	return 0;
}


void single_dimension_array()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p = a;

	printf("a:%p\n", a);		//add
	printf("&a:%p\n", &a);		//add
	printf("*a:%d\n", *a);		//val

	printf("a+2:%p\n", a + 2);	//add
	printf("p+2:%p\n", p + 2);	//add
	printf("a[2]:%d\n", a[2]);	//val
	printf("p[2]:%d\n", p[2]);	//val

	printf("*(a+2):%d\n", *(a + 2));	//val
	printf("*(p+2):%d\n", *(p + 2));	//val
}


void more_dimension_array()
{
	/*	
		&			*
		ȡ��ַ		ȡֵ(��������)
	*/

	int a[3][4] = { {111,12,2,3},{4,5,6,7},{8,9,10,11} };
	int* p;
	p=a;
	/*
		&a �� int(* )[4]����
	*/

	printf("a:%p\n", a);		// int(*)[4]	����ָ��
	printf("p:%p\n",p);			// int*			ָ��


	printf("a+1:%p\n", a+1);		// int*4		16
	printf("p+1:%p\n", p+1);		// int*1		4


	printf("sizeof(p):%d\n", sizeof(p));		// int*			8	pointer type
	printf("sizeof(*p):%d\n", sizeof(*p));		// int			4	address


	printf("*a:%p\n",*a);		// *a ��ȡ��һ��Ԫ�ص�ֵ����Ҳ���� {0,1,2,3}�ĵ�ַ����һ��4�ֽڡ�   ���ͣ� a:int(*)[4]	*a:int
	printf("*a:%p\n",*a+1);		// *a+1 ��ȡ��һ��Ԫ�صĵڶ���ֵ����Ҳ���� 1 �ĵ�ַ����һ��4�ֽڡ�  step�� *a+1: int		4 

	// ����ַ�洢��ֵ��һ��������ʱ�������ָ����������Դͷ,�����ٴ���Դ��
	printf("*(*a + 1):%d\n",*( *a + 1));	//12
	printf("*(*p + 1):%d\n",*(p + 1));		//12


	printf("**a:%d\n", **a);	 //��һ����ַ��ֵ

}