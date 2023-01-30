#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)		// x86 unsafe warning

/*
	const ����ָ��
	
	char* str;	-> [] char* [] str;

	1. char* str;				ָ��
	2. const char* str			ֵ��
	3. char* cosnt str			ָ��
	4. const char* const str	ֵָ
*/


int main66(int argc, char* argv[])
{

	// char* str = "helloworld!";			// ������
	char str[20] = "helloworld!";		    // ����
	printf("char* str=%s\n", str);
	strcpy(str, "redskabers");				// ����
	printf("char* str=%s\n", str);

	/*
		if: char* str => *str  value
		so:const char* str => const value		��ֵ�̶���
	test:
	*/
	const char* cstr = "helloworld!";
	printf("const char* cstr=%s\n",cstr);
	cstr = "redskabers";				// �ı�ָ��
	printf("const char* cstr=%s\n", cstr);
	// cstr[0] = "w";					// const value
	printf("const char* cstr=%s\n", cstr);

	/*
		if: char* str => str address	pointer address
		char* const str => str const address  pointer const address		(ָ��̶�)
	*/

	// char* const strc = "helloworld!";		// ������
	char const strc[] = "helloworld!";			// ����
	printf("const char* cstr=%s\n", strc);
	// strc = "redskabers";					// �ı�ָ��
	printf("const char* cstr=%s\n", strc);
	strcpy(strc,"redskaber");				// const value
	printf("const char* cstr=%s\n", strc);

	/*
		const char* conat str =>
			const (char* const str)		�̶�ֵ
			char* (const str)			�̶�ָ��
	*/

	const char const cstrc[] = "helloworld!";	// ����
	printf("const char* cstr=%s\n", cstrc);
	// cstrc = "redskabers";			// �ı�ָ��
	printf("const char* cstr=%s\n", cstrc);
	strcpy(cstrc, "redskaber");					
	printf("const char* cstr=%s\n", cstrc);
	// cstrc[0] = "r";					// const value
	printf("const char* cstr=%s\n", cstrc);



	return 0;
}
