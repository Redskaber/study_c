#include<stdio.h>

/*
	数组指针取 *
		数组指针取 *，不是取值的意思，是指针的类型发送变更。
	
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
		取地址		取值(任意类型)
	*/

	int a[3][4] = { {111,12,2,3},{4,5,6,7},{8,9,10,11} };
	int* p;
	p=a;
	/*
		&a 是 int(* )[4]类型
	*/

	printf("a:%p\n", a);		// int(*)[4]	数组指针
	printf("p:%p\n",p);			// int*			指针


	printf("a+1:%p\n", a+1);		// int*4		16
	printf("p+1:%p\n", p+1);		// int*1		4


	printf("sizeof(p):%d\n", sizeof(p));		// int*			8	pointer type
	printf("sizeof(*p):%d\n", sizeof(*p));		// int			4	address


	printf("*a:%p\n",*a);		// *a 是取第一个元素的值，这也就是 {0,1,2,3}的地址，是一个4字节。   类型： a:int(*)[4]	*a:int
	printf("*a:%p\n",*a+1);		// *a+1 是取第一个元素的第二个值，这也就是 1 的地址，是一个4字节。  step： *a+1: int		4 

	// 当地址存储的值是一个常量的时候，则此条指针链到达了源头,不可再次溯源。
	printf("*(*a + 1):%d\n",*( *a + 1));	//12
	printf("*(*p + 1):%d\n",*(p + 1));		//12


	printf("**a:%d\n", **a);	 //第一个地址的值

}