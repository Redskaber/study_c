#include<stdio.h>
#include<string.h>	// strlen

#pragma warning(disable:4996)
#pragma warning(disable:6328)
/*
	vs:ָ������������ϵͳ�ض��ı���������
	
		#pragma
		#pragma warning(disable:4996)	// ��c�ļ���ʼ��д����仰�������߱���������4996���棬strcpy��scanf��һЩ����ȫ�ı�׼c�⺯����vs�п������ˡ�

	���ַ������Ⱥ���
		size_t strlen()  string.h	���ַ����ַ���������
		sizeof	  �ؼ���	 �������� / ָ���С
*/


void for_each_string(char* string)
{	
	printf("string=%s\n",string);
	printf("sizeof(string)=%d\n", sizeof(string));	// int*	 8
	printf("strlen(string)=%d\n", strlen(string));	// strlen(string)
}



int main52( int argc, char* argv[])
{
	char a[20] = { "hello!"};
	char* p = "hello!";

	printf("sizeof(a)=%d\n",sizeof(a));	// 20	��������
	printf("sizeof(p)=%d\n",sizeof(p));	// 8	ָ���С

	printf("strlen(a)=%d\n",strlen(a));	// 6
	printf("strlen(p)=%d\n",strlen(p));	// 6

	printf("\n\n");

	char array[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char *string = "0123456789";
	for_each_string(string);
	return 0;
}

