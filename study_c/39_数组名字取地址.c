#include<stdio.h>

/*
	数组名取地址-> 数组指针
	 ps:
		int a[10];
		&a	-> int(*a)[10]类型的数组指针
		(&a +1) - (&a) == 4*10
	

	int a[3][4];
		- &a是int(*a)[3][4]类型的二维数组指针。
		-  a是int(*a)[4]类型的一维数组指针。
		- *a是int类型的元素(地址)。

		指针移动：外    <-     ->      内
			跨度：大                   小
		  标识符: &a        a          *a

*/
void array_name_get_address_change_array_pointer();
void two_dimension_array_get_address_change_array_pointer();
void more_dimension_array_name_get_address_change_array_pointer();

int main39()
{
	array_name_get_address_change_array_pointer();
	printf("\n");
	two_dimension_array_get_address_change_array_pointer();
	printf("\n");
	more_dimension_array_name_get_address_change_array_pointer();
	return 0;
}


void array_name_get_address_change_array_pointer()
{
	int a[10];
	printf("&a:%p\n", &a);
	printf("&a+1:%p\n", &a + 1);

	/*
		base: x64
		int 4
		int a[10] 40
		->	{...}    ==>		{...}
			{...}			->	{...}		40
	*/

	printf("(int)(& a + 1)-(int)(&a):%d\n", (int)(&a + 1) - (int)(&a));
}

void two_dimension_array_get_address_change_array_pointer()
{
	int b[3][4];

	// get int(*b)[3] type of array pointer
	printf("b:%p\n",b);			
	printf("b+1:%p\n",b+1);		
	printf("b+2:%p\n",b+2);		

	/*
		{					(int)*(cloumn)
			{1,2,3,4},		4*4
		}
	*/

	printf("(int)(b+1)-(int)(b):%d\n", (int)(b + 1) - (int)(b));		// 16	


	// get int(*b)[3][4] type of array pointer
	printf("&b:%p\n",&b);
	printf("&b+1:%p\n",&b+1);

	/*
		{
		 {},{},{}		(int)*(column)*(row)	4*4*3
		}
	*/

	printf("(int)(&b+1)-(int)(&b):%d\n", (int)(&b + 1) - (int)(&b));		// 48	

}

void more_dimension_array_name_get_address_change_array_pointer()
{
	int c[3][4][5][6];
	/*
		base x64
		&c		=> int(*c)[3][4][5][6]			int*3*4*5*6 == 1440
		c		=> int(*c)[4][5][6]				int*4*5*6 == 480
		*c		=> int(*c)[5][6]				int*5*6 == 120
		**c		=> int(*c)[6]					int*6 == 24
		***c	=> int							int == 4
	
	=> int c[1][2]...[...];
		&c		=> int(*c)[1][2]...[...]
		...
	*/

	printf("&c\t\t=> int(*c)[3][4][5][6]:%d\n",(int)(&c+1)-(int)(&c));
	printf("c\t\t=> int(*c)[4][5][6]:%d\n",(int)(c+1)-(int)(c));
	printf("*c\t\t=> int(*c)[5][6]:%d\n",(int)(*c+1)-(int)(*c));
	printf("**c\t\t=> int(*c)[6]:%d\n",(int)(**c+1)-(int)(**c));
	printf("***c\t\t=> int:%d\n",(int)(***c+1)-(int)(*c));
	
}
