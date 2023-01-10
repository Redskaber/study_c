#include<stdio.h>

/*
	ָ����Ϊ������������
		- ֵ
		- ��ַ
		- ָ���ַ
		- �����ַ
		...

	�ֲ����ã�
		- ʹ�����󣺵�ĳ������£�ֻ��Ҫ������ֵʱ
		- ���ݣ�a
	ȫ���޸ģ�
		- ʹ�����󣺵���Ҫ��ԭ�����ݽ��г��״���ʱ
		- ���ݵ�ַ��&a
		- ����ָ�룺p -> &a
*/

void transfer_val_action_local(int a, int b)
{
	/*
		�ⲿ���ݵ�ֵ�������µľֲ�����a,b,������ֻ�ں���֮�С�
	*/
	int temp = a;
	a = b;
	b = temp;
}

void transfer_address_action_global(int *p1, int *p2)
{
	/*
		�ⲿ���ݵĵ�ַ�����ֲ�ָ��ָ�򣬾ֲ�����ͨ��ָ���ҵ����ݴ洢�ĵ�ַ�飬��������޸ģ��Ӷ�ʵ�������޸ĵ�Ч����
		��Ӧ��ϵ��	param	transfer
					*p		&(����)
					**p		&(*p)
					***p	&(**p)
					****p	&(***p)
					......	......
		
		=> (type)(*����) == (type)a
	*/

	int temp = *p1;		// *p1 == a
	*p1 = *p2;			// *p2 == b
	*p2 = temp;
}

void transfer_single_pointer_address_action_global(char** p, char * string)
{
	/*
		char* p;
		&(p) ==> **p	����
	*/

	// p �Ƕ���ָ��
	// *p��һ��ָ���ַ
	printf("p:%p\n",p);
	printf("*p:%p\n",*p);
	
	*p = string;		// (int**) *p	���� == (int*) p
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
	transfer_single_pointer_address_action_global(&p, "hello king!");	// ����ָ�� ָ�� һ��ָ���ַ	int**p -> &(int*p)
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



