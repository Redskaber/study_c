#include<stdio.h>

/*
	µÝ¹é²Ù×÷

	int recursion()
	{
		statement...
		recursion();
		...
	}

*/

int recursion(int num)
{
	return (num != 1) ? (num * recursion(num - 1)) : (num);
}

int main87() 
{
	int num = recursion(10);
	printf("%d\n",num);
	return 0;
}
