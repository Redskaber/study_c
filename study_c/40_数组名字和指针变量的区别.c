#include<stdio.h>

/*

	int a[10];
	int *p=a;

	数组名字和指针变量的相同点
		- 数组索引
		=> 指针索引、数组索引
			a[2]	p[2]
			*(a+2)	*(p+2)

	数组名字和指针变量的不同点
		- 数据类型
			-> 范围、运算、结果
		=> 常量&&变量、数组指针&&指针的指针
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
		数组索引
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
		数据类型=> range,opreac,resp
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