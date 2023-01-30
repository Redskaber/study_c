#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)		// x86 unsafe warning

/*
	字符串拷贝函数
		char* strcpy(dest,src)		同时会将"\0" 也一同拷贝过去。
		char* strncpy(dest,src,n)		不会拷贝"\0" n超过src长度补"\0".
	注意：小心内存污染
*/

void use_strcpy(char * str)
{
	printf("str:%s\n", str);
	strcpy(str, "000000000");
	printf("str:%s\n", str);
	printf("str+11:%s\n", str + 11);	// 10+ '\0' -> 11
}

void* small_strncpy(char* str, int number)
{
	return strncpy(str, "1111111111", number);	// 1*10+"\0"
}

void* super_strncpy(char* str, int number)
{
	return strncpy(str, "2222222222", number);	// 2*10+"\0"
}

void use_strncpy(char* str, int len)
{
	char* temp = str;
	printf("str:%s\n", str);
	printf("str:%p\n\n", str);


	int* a = (int*)small_strncpy(str,5);
	/*
		strncpy 不超过src长度字符，直接覆盖原始数据，替换数据值。
	*/
	printf("a:%p\n",a);
	printf("str:%s\n", str);
	printf("str+10:%s\n\n", str+10);
	for (size_t i = 0; i < len; i++)
	{
		printf("str[%d]=%c\n", i, str[i]);
	}


	str = temp;

	int* b = (int*)super_strncpy(str,15);
	/*
		strncpy 超过src长度字符，超过部分使用"\0"填充。
	*/
	printf("b:%p\n", b);
	printf("str:%s\n", str);
	printf("str+15:%s\n\n", str+15);
	for (size_t i = 0; i < len; i++)
	{
		printf("str[%d]=%c\n",i,str[i]);
	}
}

int main53()
{
	char str[100] = "aaaaaaaaaaaaaaaaaaaa";	// 99a+"\0"
	use_strcpy(str);

	printf("\n\n");

	char str2[100] = "aaaaaaaaaaaaaaaaaaaa";		// 99a+"\0"
	int len = strlen(str2);
	use_strncpy(str2,len);
	return 0;
}