#include<stdio.h>
#include<stdlib.h>		// malloc
#include<string.h>		// strcpy
/*
	ָ����Ϊ��������ֵ
		static ����
		pointer ���ֳ�����
		mollac ������free|���������+ strcpy  | strcpy_s 

*/


char* func_through_static_state()
{
	/*
		char str[] = "hello world!";	// ������ʾ��ԭ��str[] ֻ����func�ڲ����ⲿʹ�ã����ܴ��ڴ��Ѿ����ͷŻ��޸ġ�	
		
	=>  static
		pointer
	*/
	static char str[] = "hello world(static)!";
	return str;
}
char* func_through_pointer_state()
{
	char* str = "hello world(pointer)!";
	return str;
}

char* func_through_malloc_state()
{
	char* str = (char*)malloc(sizeof(char) * 21);		// \0��������
	// strcpy(str, "hello world(malloc)!");				// ����ȫ�����ܻ�����ڴ治��,�ڴ�����Ŀ���
	strcpy_s(str, 21,"hello world(malloc)!");
	// free(str);		// ֱ���ͷŶ��е��ڴ�
	return str;
}

int main44()
{
	char* p;
	typedef char* cp;		// ��ϰ
	p = func_through_static_state();
	printf("p:%s\n",p);

	cp pr = func_through_pointer_state();
	printf("p:%s\n", pr);

	p = func_through_malloc_state();
	printf("p:%s\n", p);
	free(p);
	printf("p:%s\n", p);
	return 0;
}
