#include<stdio.h>

/*
	共用体的特点:
	1、同一内存段可以用来存放几种不同类型的成员，但每一瞬时只有一种起作用
	2、共用体变量中起作用的成员是最后一次存放的成员，在存入一个新的成员后原有的成员的值会被覆盖
	3、共用体变量的地址和它的各成员的地址都是同一地址4、共用体变量的初始化
	union data a={123}; 初始化共用体只能为第一个成员赋值，不能给所有成员都赋初值
*/

typedef union 
{
	char a;
	int b;
}
Un_Case;

int main78()
{
	/*
		Un_Case _Case;
		_Case.b = 100;
	*/
	Un_Case _Case = {
		.b = 0xffffffff
	};
	printf("Un_Case _Case.b=%x\n",_Case.b);		// Un_Case _Case.b=ffffffff
	
	_Case.a = 0x00;
	printf("Un_Case _Case.a=%x\n",_Case.a);		// Un_Case _Case.a=0
	printf("Un_Case _Case.b=%x\n",_Case.b);		// Un_Case _Case.b=ffffff00

	return 0;
}

