#include<stdio.h>
#include<stdlib.h>		// malloc
#include<string.h>		// strcpy
/*
	指针作为函数返回值
		static 修饰
		pointer 文字常量区
		mollac 堆区（free|程序结束）+ strcpy  | strcpy_s 

*/


char* func_through_static_state()
{
	/*
		char str[] = "hello world!";	// 错误演示，原因：str[] 只作用func内部，外部使用，可能此内存已经被释放或修改。	
		
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
	char* str = (char*)malloc(sizeof(char) * 21);		// \0结束符；
	// strcpy(str, "hello world(malloc)!");				// 不安全，可能会出现内存不够,内存溢出的可能
	strcpy_s(str, 21,"hello world(malloc)!");
	// free(str);		// 直接释放堆中的内存
	return str;
}

int main44()
{
	char* p;
	typedef char* cp;		// 复习
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
