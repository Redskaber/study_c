#include<stdio.h>
#pragma warning(disable:4996)		// x86 unsafe warning

/*
	sscanf的高级用法 
	
	1.跳过数据	%*d|s...
		注意：匹配的数据遇到空格后会结束此format匹配。
*/

int use_sscanf_jmp_format(char* src, const char* format, char store[])
{
	int flag = sscanf(src,format,store);
	return flag;
}


int main62()
{
	char* src1 = "1234 5678";		// char * string  s
	char* src2 = "1234:5678";		// char * string  s	and have space 
	char* format1 = "%s %*s";
	char* format2 = "%s %*s";	
	char store1[100];
	char store2[100];

	int number1 = use_sscanf_jmp_format(src1,format1,store1);
	printf("store:%s\n",store1);	// 1234
	printf("number:%d\n",number1);

	int number2 = use_sscanf_jmp_format(src2, format2, store2);
	printf("store:%s\n", store2);	//  1234:5678	
	printf("number:%d\n", number2);

	return 0;
}
