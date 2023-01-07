#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
	字符串的概念
		字符串是一块连续的存储空间数据。
		将此块存储空间的首地址作为字符串的地址。
	字符串的存储形式
		1.数组存储(栈区)
			int  str[100]="I Love C!";
		2.指针(文字常量区)		
			int* str="I Love C!";
		3.malloc等动态申请(堆区)
			char* str=(char*)malloc(10*sizeof(char));	
			strcpy(str,"I love C");						
	字符串的可修改性
		1.可以修改 数组 动态申请
		2.不可修改 const、 文字常量区
*/

void str_storage_form();
void str_use_array_storage();
void str_use_pointer_storage();
void str_use_dymanic_get_storage();

void main37()
{
	str_storage_form();
}

void str_storage_form()
{
	str_use_array_storage();
	str_use_pointer_storage();
	str_use_dymanic_get_storage();
}

void str_use_array_storage()
{
	char str[100] = "I Love C!";
	printf("char str[100]: %s\n", str);
	str[0] = 'Y';
	printf("char str[100]: %s\n", str);
}

void str_use_pointer_storage()
{
	// 不能修改
	char* str = "I Love C!";
	printf("char* str:%s\n",str);
	// *str = 'Y';
	// printf("char* str:%s",str);
}

void str_use_dymanic_get_storage()
{
	char* str = (char*)malloc(10 * sizeof(char));
	strcpy(str,"I Love C!");
	printf("strcpy(str,data):%s\n",str);
	*str = 'Y';
	printf("strcpy(str,data):%s\n", str);
}
