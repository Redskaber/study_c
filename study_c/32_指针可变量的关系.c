#include<stdio.h>
/*
	ָ��ͱ����Ĺ�ϵ
		int a = 100;
		int *p;

		1. p = &a;
			ָ�����ڴ����ͨ�����ĵ�ַ��
		2.*p = a = 100;
			*ָ�����õ���ͨ������
	
	ע��:
	- 1:* + ָ��==> ȡֵ��ȡ�����ֽڣ���ָ�����;���
		- ָ��Ϊ�ַ�ָ����ȡ1���ֽڣ�
		- ָ��Ϊ����ָ����ȡ4���ֽ�
		- ָ��Ϊdouble��ָ����ȡ8���ֽڡ�
	- 2:ָ��++ ==> ָ���¸���Ӧ���͵�����
		- �ַ�ָ��++��ָ���¸��ַ����ݣ�ָ���ŵĵ�ַ��ż�1
		- ����ָ��++,  ָ���¸��������ݣ�ָ���ŵĵ�ַ��ż�4
*/

void inter_change_val(int *pointer1, int * pointer2);
void pointer_transform();
void pointer_incre();

int main()
{
	int* p1, * p2, a = 100, b = 200;
	p1 = &a;
	p2 = &b;

	printf("&a=%p,a=%d,&b=%p,b=%d,	p1=%p,p2=%p,*p1=%d,*p2=%d\n", &a, a, &b, b, p1, p2, *p1, *p2);
	inter_change_val(p1,p2);
	printf("&a=%p,a=%d,&b=%p,b=%d,	p1=%p,p2=%p,*p1=%d,*p2=%d\n", &a, a, &b, b, p1, p2, *p1, *p2);
	pointer_transform();
	pointer_incre();

	return 0;
}


void inter_change_val(int* pointer1, int* pointer2)
{
	int temp;
	temp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = temp;
}


void pointer_transform()
{
	int a = 0x11223344;
	int b = 0x11223344;
	char* pa;
	int* pb;
	
	pa = (char*) & a;
	pb = &b;

	printf("char*pa=> *pa=%0x\n",*pa);	// 44 ��λ��Ϊָ���ַ(���ֽ�ʱ)
	printf("int*pa=> *pb=%0x\n",*pb);	// 11223344

}

void pointer_incre()
{
	int a = 0x11223344;
	int b = 0x11223344;
	char* pa;

	pa = (char*) & a;		// �����Զ�ת������������ֶ�ǿ��ת��

	printf("\nchar*pa=> *pa=%0x\n", *pa);	// 44 ��λ��Ϊָ���ַ(���ֽ�ʱ)
	pa++;
	printf("char*pa=> *pa=%0x\n", *pa);	// 33 ��λ��Ϊָ���ַ(���ֽ�ʱ)
}
