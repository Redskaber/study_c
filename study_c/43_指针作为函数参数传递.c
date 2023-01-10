#include<stdio.h>

/*
	指针作为函数参数传递
		- 值
		- 地址
		- 指针地址
		- 数组地址
		...

	局部作用：
		- 使用需求：当某种情况下，只需要数据数值时
		- 传递：a
	全局修改：
		- 使用需求：当需要对原本数据进行彻底处理时
		- 传递地址：&a
		- 传递指针：p -> &a
*/

void transfer_val_action_local(int a, int b)
{
	/*
		外部传递的值被赋予新的局部变量a,b,作用域只在函数之中。
	*/
	int temp = a;
	a = b;
	b = temp;
}

void transfer_address_action_global(int *p1, int *p2)
{
	/*
		外部传递的地址，被局部指针指向，局部可以通过指针找到数据存储的地址块，对其进行修改，从而实现永久修改的效果。
		对应关系：	param	transfer
					*p		&(常量)
					**p		&(*p)
					***p	&(**p)
					****p	&(***p)
					......	......
		
		=> (type)(*参数) == (type)a
	*/

	int temp = *p1;		// *p1 == a
	*p1 = *p2;			// *p2 == b
	*p2 = temp;
}

void transfer_single_pointer_address_action_global(char** p, char * string)
{
	/*
		char* p;
		&(p) ==> **p	升阶
	*/

	// p 是二级指针
	// *p是一级指针地址
	printf("p:%p\n",p);
	printf("*p:%p\n",*p);
	
	*p = string;		// (int**) *p	降级 == (int*) p
}

void handle_transfer_val_add_pointer_add()
{
	int a = 10, b = 20;

	transfer_val_action_local(a, b);
	printf("a:%d\n", a);
	printf("b:%d\n", b);	// a = 10 b = 20

	transfer_address_action_global(&a, &b);
	printf("a:%d\n", a);
	printf("b:%d\n", b);	// a = 20 b = 10

	char* p = "hello world!";

	printf("p:%p\n", p);
	printf("p:%s\n", p);
	transfer_single_pointer_address_action_global(&p, "hello king!");	// 二级指针 指向 一级指针地址	int**p -> &(int*p)
	printf("p:%s\n", p);

}

transfer_single_array_through_single_pointer(int *array, int step)
{	
	/*
		int *array	/	int array[]
			
	*/
	printf("array:%p\n",array);
	printf("step:%d\n",step);
	for (short i = 0; i < step; i++)
	{
		printf("array[%d]=%d\n",i,array[i]);
	}

}

void transfer_more_array_through_array_pointer(int (*array)[4], int step)
{
	/*
		int a[1][2] => int (*array)[2]
		...
	*/
	printf("array:%p\n", array);
	printf("step:%d\n", step);
	
	short column=4, row = step / column;
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < column; j++)
		{
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}

}


void handle_transfer_array()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int step = sizeof(a) / sizeof(int);
	transfer_single_array_through_single_pointer(a,step);		// a -> 0 address int => int * | int []
	
	int b[3][4] = {
		{0,1,2,3},{4,5,6,7},{8,9,10,11} 
	};
	step = sizeof(b) / sizeof(int);
	transfer_more_array_through_array_pointer(b,step);
}



int main()
{	
	handle_transfer_val_add_pointer_add();
	handle_transfer_array();
	
	return 0;
}



