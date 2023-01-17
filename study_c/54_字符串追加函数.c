#include<stdio.h>
#include<string.h>
#pragma warning(disable:6328)
#pragma warning(disable:4996)
/*
	�ַ���׷�Ӻ���
	string.h
		ȫ		char* strcat(dest,src)			dest Ҫ���㹻�Ŀռ�����src��ͬʱ׷��"\0".
		n<=ȫ	char* strncat(dest,src,n)			dest Ҫ���㹻�Ŀռ�����src��ǰn��Ԫ�أ�ͬʱ׷��"\0".
*/

void use_strcat(char* str, int len)
{
	printf("str:%s\n", str);		// aaaaa
	strcat(str, "hhhhh");
	printf("str:%s\n", str);	// aaaaahhhhh
	for (size_t i = 0; i < len; i++)
	{
		printf("str[%d]=%c\n",i,str[i]);
	}
}

void use_strncat(char* str, int len)
{
	printf("str:%s\n", str);		// aaaaa
	strncat(str, "rrrrr", 3);
	printf("str:%s\n", str);	// aaaaarrr	+ "\0"
	for (size_t i = 0; i < len; i++)
	{
		printf("str[%d]=%c\n", i, str[i]);
	}
}

void use_strncat_out(char* str, int len)
{
	printf("str:%s\n", str);		// aaaaa
	strncat(str, "rrrrr", 10);
	printf("str:%s\n", str);	// aaaaarrrrr	+ "\0" 
	for (size_t i = 0; i < len; i++)
	{
		printf("str[%d]=%c\n", i, str[i]);
	}
}

int main54()
{
	/*
		strcat:	  ����src +"\0"
	*/
	char str[101] = "aaaaa\0aaaaaaaaaaaaa";
	use_strcat(str,20);


	printf("\n\n");


	/*
		strncat:	����src[:n]	+"\0"
	*/
	char str2[101] = "aaaaa\0aaaaaaaaaaaaa";
	use_strncat(str2,20);
	char str3[101] = "aaaaa\0aaaaaaaaaaaaa";
	use_strncat_out(str3,20);

	return 0;
}
