#include<stdio.h>

/*
	指针与数组的关系
		1.指针存储数组元素地址
		2.数组是相同一类型的变量
	指针数组的概念
		定义：由指针组成的数组为指针数组，存放指针地址的数组。
		格式：
			int *p[5];
			int *p1 = &a;
			p[0] = p1
	指针数组的运用
*/
void array_origin_address(int*pointer);
void array_element_more_bits_relation();
void pointer_and_value_and_pointer_address_and_value_address_relation();

int main35(int args, char * argv[])
{	
	pointer_and_value_and_pointer_address_and_value_address_relation();

	int* pointer[5];
	int a = 100, b = 200;
	int *p1 = &a, *p2 = &b;
	printf("a address: %p,\nb address: %p\n",p1,p2);
	array_origin_address(pointer);

	pointer[0] = p1;		
	*(pointer+1) = p2;

	printf("pointer[5]: pointer[0]: %p, *(pointer[0]): %d\n",pointer[0],*(pointer[0]));
	printf("pointer[5]: pointer[1]: %p, *(pointer[1]): %d\n",pointer[1],*(pointer[1]));
	array_origin_address(pointer);


	array_element_more_bits_relation();

	return 0;
}

void pointer_and_value_and_pointer_address_and_value_address_relation()
{
	/*

	address			value
	pointer			pointer[0]
	pointer+1		pointer[1]

	address's address	value's address
	&pointer			&(pointer[0])
	&(pointer+1)        &(pointer[1])

*/
	int a = 100, b = 200, c = 300, d = 400, e = 500;
	int *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e;
	int* pointer[5] = {
		pa,pb,pc,pd,pe
	};	
	/*
		==> pointer[0] == pa == &a;
			*(pointer[0]) == *(pa) == a;
		又：*(pointer+n) == a[n]
			*(*(pointer+n)) == *(a[n])
 	*/
	printf("pointer[0]:%p, &a:%p\n",pointer[0],&a);
	printf("*(pointer[0]):%d, *(ar[0]):%d\n", *(pointer[0]),a);
	printf("*(*(pointer + 1)) :%d, *(ar[1]):%d\n", *(*(pointer + 1)),b);


	printf("array_address:%p --> array(first_element_aadress)\n", pointer);
	for (short i = 0; i < 5; i++)
	{
		printf(
			"[pointer element_address:%p, pointer value_address:%p]\n",
			(pointer+i), pointer[i]
		);
	}

	for (short i = 0; i < 5; i++)
	{
		printf(
			"【array_value_value(*array_value|*pointer_element):%d"
			"-->"
			"arrray(|element_address|value_address --> (velement_address,vvalue) (va_addr(%p)==vele_addr(%p)))】\n",
			*(pointer[i]),
			pointer[i], &a
		);
	}
	printf("\n");

}

void array_origin_address(int *pointer)
{
	printf("pointer[0]: %p\n", pointer);
	printf("pointer[1]: %p\n", pointer+1);
	printf("pointer[2]: %p\n", pointer+2);
	printf("pointer[3]: %p\n", pointer+3);
	printf("pointer[4]: %p\n", pointer+4);
}


void array_element_more_bits_relation()
{	
	// char * more = int;
	char* pale[5] = { "Hunan","Shanghai","Beijing","Guangzhou","Shicuan" };
	int step = sizeof(pale) / sizeof(int*);
	for (int i = 0; i < step; i++)
	{
		printf("print address: %p, values: %s\n",pale+i, pale[i]);
	}
	
}
