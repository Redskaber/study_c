#include<stdio.h>

/*
	指针定义：
		相关运算
			& 取址
			* 取值
		格式：指针类型 * 指针变量 [= 值];
			  指针类型 * 指针变量1, * 指针变量2, ... [= 值];

		说明: *被称为修饰符

		ps: int a = 100;
			int *p = &a;

		指针关系:
				p			rela			a
		address		value			address		value	
		&p			p		->		&a | p		a | *p


		p -> &a
		*p -> a		
		
		指针的大小 sizeof(*p);
			64->8
			32->4
			根据系统决定。
*/

int main31()
{
	int a = 100;
	int* p;		// 野指针，没有初始化定义值，指向一个随机的地址
	p = &a;
	

	printf("a=%d,	&a=%x\n",a,&a);
	printf("p=%x,	&p=%x,	*p=%d\n",p,&p,*p);
	printf("p=%x,	&a=%x\n",p,&a);		// 指针 p 的值存储 对象a的地址（&a）	


	return 0;
}
