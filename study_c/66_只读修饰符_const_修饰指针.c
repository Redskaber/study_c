#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)		// x86 unsafe warning

/*
	const 修饰指针
	
	char* str;	-> [] char* [] str;

	1. char* str;				指针
	2. const char* str			值定
	3. char* cosnt str			指向
	4. const char* const str	值指
*/


int main66(int argc, char* argv[])
{

	// char* str = "helloworld!";			// 常量区
	char str[20] = "helloworld!";		    // 堆区
	printf("char* str=%s\n", str);
	strcpy(str, "redskabers");				// 内容
	printf("char* str=%s\n", str);

	/*
		if: char* str => *str  value
		so:const char* str => const value		（值固定）
	test:
	*/
	const char* cstr = "helloworld!";
	printf("const char* cstr=%s\n",cstr);
	cstr = "redskabers";				// 改变指向
	printf("const char* cstr=%s\n", cstr);
	// cstr[0] = "w";					// const value
	printf("const char* cstr=%s\n", cstr);

	/*
		if: char* str => str address	pointer address
		char* const str => str const address  pointer const address		(指向固定)
	*/

	// char* const strc = "helloworld!";		// 常量区
	char const strc[] = "helloworld!";			// 堆区
	printf("const char* cstr=%s\n", strc);
	// strc = "redskabers";					// 改变指向
	printf("const char* cstr=%s\n", strc);
	strcpy(strc,"redskaber");				// const value
	printf("const char* cstr=%s\n", strc);

	/*
		const char* conat str =>
			const (char* const str)		固定值
			char* (const str)			固定指向
	*/

	const char const cstrc[] = "helloworld!";	// 堆区
	printf("const char* cstr=%s\n", cstrc);
	// cstrc = "redskabers";			// 改变指向
	printf("const char* cstr=%s\n", cstrc);
	strcpy(cstrc, "redskaber");					
	printf("const char* cstr=%s\n", cstrc);
	// cstrc[0] = "r";					// const value
	printf("const char* cstr=%s\n", cstrc);



	return 0;
}
