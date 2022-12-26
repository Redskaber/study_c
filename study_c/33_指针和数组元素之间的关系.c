#include<stdio.h>

/*
	指针和数组元素之间的关系
		1.指针与单个数组元素
			ps:int a[5];
			1.1 定义同时开辟空间
				int* p = &a[0];
			1.2 定义野指针后赋值
				int* p;
				p = &a[0];
			指针变量p保存了数组a的第一个元素a[0]的地址。
		2.指针与数组之间的关系
			前提知识：
				int 类类型是4个字节，同时多字节存储时，低位地址作为量的虚拟地址。
				数组是一段连续的地址块。
				数组名时一个常量，下标为0的地址。
				指针是一个存储地址的容器
				&p 取址
				*p 取值
			
			推导：
			=> 当 int* p = a;	//由于数组名是第一个下标地址，所以可以直接赋值 
				1. p == a == &a[0];
					-> p[n] = a[n];
				由1 -> p+n = a+n = &a[n];
					-> *(p+n) = *(a+n) = a[n];
				ps:
					p == a == &a[0];
				    *(p+n) = *(a+n) = p[n] = a[n];

			数组取值的方法
				1.a[n]		获取数组元素
				2.p[n]		获取数组元素
				3.*(a+n)	获取数组元素
				4.*(p+n)	获取数组元素
							
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

