#include<stdio.h>


void control_for() {

	/*
		��ӡ1-10;
		�˷��ھ�
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
		��ӡ1-10;
		�˷��ھ�
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
		printf("��һ���ƣ�������Ǯ��> %d\n", count);
		count--;
	}
	
	do 
	{
		printf("��һ���ƣ�������Ǯ��> %d\n",count);	// ����Ҫ��һ�飬�����Ƿ���Ҫ�߶�Σ��������Ƿ���ϡ�
		count--;
	} while (count > 11);
	
}


int main09() 
{

	/*
		forѭ��
		whileѭ��
		do...whileѭ��
	
	*/
	control_for();
	control_while();
	control_do_while();

	return 0;
}



























