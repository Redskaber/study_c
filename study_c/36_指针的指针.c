#include<stdio.h>

void case_pointer_or_ppointer();
int main36()
{
	case_pointer_or_ppointer();
	return 0;
}

void case_pointer_or_ppointer()
{
	/*
	 注意：
        int a=100; // int类型 名a 值100
        int *a=100; // int类型 指针修饰* 名a 值100
        int **a=100; // int*类型 指针修饰* 名a 值100
	*/
	int a = 100;
	int* b = &a;
	int** c = &b;
	int*** d = &c;
	/*	
		b = &a		一级指针
		c = &b		二级指针
		d = &c		三级指针
		...
		z = &y		高级指针

		=> 
		*d	= c     三级->二级	(3-2)次取值
		**d	= b		三级->一级	(3-1)次取值
		***d= a		三级->变量	(3-0)次取值
				
		=>
		(n)*p = a		n级->变量	(n-0)次取值
		(n)*p = (m)*p	n级->m级	(n-m)次取值

		一个指针修饰符等于一个指针级别，
		从高级指针获取变量值，
		高多少级，就需要取多少次值。

	*/
	printf("a:%d,\t&a:%p\n",a,&a);
	printf("b:%p,\t&b:%p,\t*b:%d\n",b,&b,*b);
	printf("c:%p,\t&c:%p,\t*c:%p,\t**c:%d\n",c,&c,*c,**c);
	printf("d:%p,\t&d:%p,\t*d:%p,\t**d:%p,\t***d:%d\n",d,&d,*d,**d,***d);

}