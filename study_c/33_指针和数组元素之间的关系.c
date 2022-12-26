#include<stdio.h>

/*
	ָ�������Ԫ��֮��Ĺ�ϵ
		1.ָ���뵥������Ԫ��
			ps:int a[5];
			1.1 ����ͬʱ���ٿռ�
				int* p = &a[0];
			1.2 ����Ұָ���ֵ
				int* p;
				p = &a[0];
			ָ�����p����������a�ĵ�һ��Ԫ��a[0]�ĵ�ַ��
		2.ָ��������֮��Ĺ�ϵ
			ǰ��֪ʶ��
				int ��������4���ֽڣ�ͬʱ���ֽڴ洢ʱ����λ��ַ��Ϊ���������ַ��
				������һ�������ĵ�ַ�顣
				������ʱһ���������±�Ϊ0�ĵ�ַ��
				ָ����һ���洢��ַ������
				&p ȡַ
				*p ȡֵ
			
			�Ƶ���
			=> �� int* p = a;	//�����������ǵ�һ���±��ַ�����Կ���ֱ�Ӹ�ֵ 
				1. p == a == &a[0];
					-> p[n] = a[n];
				��1 -> p+n = a+n = &a[n];
					-> *(p+n) = *(a+n) = a[n];
				ps:
					p == a == &a[0];
				    *(p+n) = *(a+n) = p[n] = a[n];

			����ȡֵ�ķ���
				1.a[n]		��ȡ����Ԫ��
				2.p[n]		��ȡ����Ԫ��
				3.*(a+n)	��ȡ����Ԫ��
				4.*(p+n)	��ȡ����Ԫ��
							
*/

void array_variable_address_is_array_zreo_address(int array[]);
void through_index_get_array_val(int array[]);
void through_pointer_index_get_array_val(int* pointer);
void through_array_address_operation_and_index_get_array_val(int array[]);
void through_pointer_operation_and_index_get_array_val(int* pointer);

int main33()
{

	int a[5] = {1,2,3,4,5};
	int* p = a;
	array_variable_address_is_array_zreo_address(a);
	through_index_get_array_val(a);
	through_pointer_index_get_array_val(p);
	through_array_address_operation_and_index_get_array_val(a);
	through_pointer_operation_and_index_get_array_val(p);

	return 0;
}


void array_variable_address_is_array_zreo_address(int array[])
{
	printf("int a[5]-> print a :%p\n", array);		// a:00000034E7FFFA38  a[0] address  <==> &array
	printf("int a[5]-> print a :%d\n", *array);		// a:00000034E7FFFA38  a[0] value
}

void through_index_get_array_val(int array[])
{
	printf("through index get array val: array[2]=%d\n",array[2]);
}

void through_pointer_index_get_array_val(int* pointer)
{
	printf("through pointer get array val: array[2]=%d\n", pointer[2]);
}

void through_array_address_operation_and_index_get_array_val(int array[])
{
	printf("through array address operation and index get array val: array[2]=%d\n", *(array + 2));
}

void through_pointer_operation_and_index_get_array_val(int* pointer)
{
	printf("through pointer operation and index get array val: array[2]=%d\n", *(pointer + 2));
}

