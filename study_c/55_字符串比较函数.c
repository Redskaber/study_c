#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6328)

/*
	�ַ����ȽϺ���
		ȫ	int strcmp(const char* s1,const char* s2)
		n	int strncmp(const char* s1,const char* s2, size_t n)
		- ASCLL��Ƚϴ�С
			- ���� 1
			- ���� 0
			- С�� -1
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
	char* str2 = "hello redskaber";	// �Ƚ�λ������ʱ���벻����"\0"��0���Ƚϣ�

	int flag = use_strcmp(str1,str2);
	print(flag);

	int flag2 = use_strncmp(str1, str2, 6);
	print(flag2);

	return 0;
}