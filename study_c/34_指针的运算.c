#include<stdio.h>

/*
	指针的运算
		int a[5];
		int *p = a;
		指针加法 
			p = a
			p+2 = a[2]
		指针减法
		int:
			p1 = a[0];
			p2 = a[2];
			p2-p1 = 2;
		指针赋值
			相同类型的指针之间可以相互赋值
		指针比较
			相同类型
			指向同一数组的元素

*/
void pointer_index_add(int* pointer);
void pointer_index_Subtraction(int* pointer1, int* pointer2);
void pointer_compare_condition_use(int* pointer1, int* pointer2);
void pointer_assignment_same_type(int* pointer1, int* pointer2);

int main34()
{
	int a[5];
	int* p1 = &a[0], * p2 = &a[2];

	pointer_index_add(p1);
	printf("pointer *p2 = a[2]: %p\n",p2);
	pointer_index_Subtraction(p1,p2);
	pointer_compare_condition_use(p1,p2);
	pointer_assignment_same_type(p1, p2);

	return 0;
}


void pointer_index_add(int * pointer)
{
	printf("pointer *p1 =a[0] +2 :%p\n",pointer +2);
}

void pointer_index_Subtraction(int* pointer1, int* pointer2)
{
	printf("pointer p2 -p1(get index2-index1): %lld\n",pointer2 - pointer1);
}

void pointer_compare_condition_use(int* pointer1, int* pointer2)
{
	printf("pointer compare p2 > p1: %d\n", pointer2 > pointer1);
}

void pointer_assignment_same_type(int* pointer1, int* pointer2)
{	
	void* temp;
	
	printf("pointer assignment before: p2:%p\n", pointer2);
	printf("pointer assignment before: p1:%p\n", pointer1);

	temp = pointer1;
	pointer1 = pointer2;
	pointer2 = temp;

	printf("pointer assignment p1->p2: p2:%p\n",pointer2);
	printf("pointer assignment p2->p1: p1:%p\n",pointer1);
}
