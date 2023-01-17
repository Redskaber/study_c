#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6328)

/*
	字符串比较函数
		全	int strcmp(const char* s1,const char* s2)
		n	int strncmp(const char* s1,const char* s2, size_t n)
		- ASCLL码比较大小
			- 大于 1
			- 等于 0
			- 小于 -1
		- \0 = 0
		
*/

int use_strcmp(const char* s1, const char* s2)
{
	return strcmp(s1,s2);
}

int use_strncmp(const char* s1, const char* s2, size_t n)
{
	return strncmp(s1,s2,n);
}

void print(int flag)
{
	if (flag == 0)
	{
		printf("str1==str2\n");
	}
	else if (flag == 1)
	{
		printf("str1 > str2\n");
	}
	else if (flag == -1)
	{
		printf("str1 < str2\n");
	}
}

int main55()
{
	char* str1 = "hello world";
	char* str2 = "hello redskaber";	// 比较位数不够时，与不够的"\0"（0）比较，

	int flag = use_strcmp(str1,str2);
	print(flag);

	int flag2 = use_strncmp(str1, str2, 6);
	print(flag2);

	return 0;
}