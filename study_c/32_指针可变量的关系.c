#include<stdio.h>
/*
	指针和变量的关系
		int a = 100;
		int *p;

		1. p = &a;
			指针用于存放普通变量的地址。
		2.*p = a = 100;
			*指针引用到普通变量。
	
	注意:
	- 1:* + 指针==> 取值，取几个字节，由指针类型决定
		- 指针为字符指针则取1个字节，
		- 指针为整型指针则取4个字节
		- 指针为double型指针则取8个字节。
	- 2:指针++ ==> 指向下个对应类型的数据
		- 字符指针++，指向下个字符数据，指针存放的地址编号加1
		- 整型指针++,  指向下个整型数据，指针存放的地址编号加4
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

	printf("char*pa=> *pa=%0x\n",*pa);	// 44 低位作为指针地址(多字节时)
	printf("int*pa=> *pb=%0x\n",*pb);	// 11223344

}

void pointer_incre()
{
	int a = 0x11223344;
	int b = 0x11223344;
	char* pa;

	pa = (char*) & a;		// 可以自动转化，但是最好手动强制转化

	printf("\nchar*pa=> *pa=%0x\n", *pa);	// 44 低位作为指针地址(多字节时)
	pa++;
	printf("char*pa=> *pa=%0x\n", *pa);	// 33 低位作为指针地址(多字节时)
}
