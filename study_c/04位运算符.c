#include<stdio.h>
/*
	正数：
		正数：符号位 0
		内存中存储的就是原码,
	负数：
		负数：符号位 1
		内存中存储的是补码。
		原码 -(10换)-> 反码 -(+1)-> 补码
*/


int main04()
{	

	/*
		+5（int）4 * 8
			原码：0000 0000 0000 0000 0000 0000 0000 0101;
			反码：0000 0000 0000 0000 0000 0000 0000 0101;
			补码：0000 0000 0000 0000 0000 0000 0000 0101;

		-5（int）4 * 8
			原码：1000 0000 0000 0000 0000 0000 0000 0101;
			反码：1111 1111 1111 1111 1111 1111 1111 1010;
			补码：1111 1111 1111 1111 1111 1111 1111 1011; => 0x(fffffffb)
		
	*/

	printf("%x\n", 5);
	printf("%x\n", -5);

	int res1,res2,res3,res4,res5;
	
	res1 = bit_opreation_and(10,3);
	/*
		0000 0000 0000 0000 0000 0000 0000 1010 &
		0000 0000 0000 0000 0000 0000 0000 0011
		0000 0000 0000 0000 0000 0000 0000 0010 > 2
	*/
	printf("res1 = bit_opreation_and(10,3); > %d \n",res1);

	res2 = bit_opreation_or(10,3);
	/*
		0000 0000 0000 0000 0000 0000 0000 1010 |
		0000 0000 0000 0000 0000 0000 0000 0011
		0000 0000 0000 0000 0000 0000 0000 1011 > 11
	*/
	printf("res2 = bit_opreation_or(10,3); > %d \n", res2);	
	
	res3 = bit_opreation_not(10);
	/*
		0000 0000 0000 0000 0000 0000 0000 1010 ~
		1111 1111 1111 1111 1111 1111 1111 0101 > -11

		-11（int）4 * 8
			原码：1000 0000 0000 0000 0000 0000 0000 1011;
			反码：1111 1111 1111 1111 1111 1111 1111 0100;
			补码：1111 1111 1111 1111 1111 1111 1111 0101; => 0x(fffffff5)
	*/
	printf("res3 = bit_opreation_not(10); > %d ， %x\n", res3, res3);

	res4 = bit_opreation_leftmove(10,3);
	/*
		0000 0000 0000 0000 0000 0000 0000 1010 << 3
		0000 0000 0000 0000 0000 0000 0101 0000 > 80
	*/
	printf("res4 = bit_opreation_leftmove(10,3); > %d \n", res4);

	res5 = bit_opreation_rightmove(-1,3);
	/*
				1111 1111 1111 1111 1111 1111 1111 1111 >> 3
		if逻辑  0001 1111 1111 1111 1111 1111 1111 1111 
		if算术  1111 1111 1111 1111 1111 1111 1111 1111 > -1
	*/
	printf("res5 = bit_opreation_rightmove(-1,3); > %d \n", res5);

	return 0;
}


int bit_opreation_and(int a, int b)
{
	// &
	return a & b;
}

int bit_opreation_or(int a , int b)
{
	return a | b;
}

int bit_opreation_not(int a)
{
	return ~a;
}

int bit_opreation_leftmove(int a, int move)
{
	return a << move;
}

int bit_opreation_rightmove(int a, int move)
{
	return a >> move;
}
