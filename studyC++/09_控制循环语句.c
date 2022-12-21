#include<stdio.h>


void control_for() {

	/*
		打印1-10;
		乘法口诀
	*/
		
	for (int i = 1; i <= 10; i++) 
	{
		printf("i=%d\n",i);
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d==%d\t",i,j,i*j);
		}
		printf("\n");
	}
}


void control_while() 
{
	/*
		打印1-10;
		乘法口诀
	*/
	int count = 10;

	while (count > 0)
	{
		printf("count=%d\n", count);
		count--;
	}


	int i=1;
	while (i < 10)
	{
		int j = 1;
		while (j<=i)
		{
			printf("%d*%d==%d\t",i,j,i*j);
			j++;
		}
		printf("\n");
		i++;
	}
}


void control_do_while()
{
	int count = 10;
	
	while(count >11)
	{
		printf("打一巴掌！还不还钱？> %d\n", count);
		count--;
	}
	
	do 
	{
		printf("打一巴掌！还不还钱？> %d\n",count);	// 必须要走一遍，至于是否需要走多次，看条件是否符合。
		count--;
	} while (count > 11);
	
}


int main09() 
{

	/*
		for循环
		while循环
		do...while循环
	
	*/
	control_for();
	control_while();
	control_do_while();

	return 0;
}



























