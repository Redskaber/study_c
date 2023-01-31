#include<stdio.h>
#include<errno.h>
#include<string.h>
#pragma warning(disable:4996)
/*
	������
		1.errno	int								errno.h
		2.void	perror(char* _ErrorMessage)		stdio.h
		3.char* strerror(int _ErrorMessage)		string.h
	��׼����
		stderr

	_ACRTIMP int* __cdecl _errno(void);
	#define errno (*_errno())	// int 0

	_ACRTIMP char* __cdecl strerror(
	_In_ int _ErrorMessage
	);

*/

void use_fprintf_case()
{
	FILE* fp;
	fp = fopen("..\\Files\\file.txt", "w+");
	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);		// fp <-format- data
	fclose(fp);
}

void printf_errno_val()
{
	printf("errno_val:%d\n",errno);	// defaults 0
}

void printf_strerror_val()
{
	FILE* pf;
	int errnum;
	pf = fopen("..\\Files\\unexist.txt", "rb");
	if (pf == NULL)
	{
		errnum = errno;
		fprintf(stderr, "�����: %d\n", errno);
		perror("ͨ�� perror �������");
		printf("%s\n", strerror(errnum));
		fprintf(stderr, "���ļ�����: %s\n", strerror(errnum));	// �������strӳ��
	}
	else
	{
		fclose(pf);
	}
}

int main86()
{
	printf_errno_val();
	printf_strerror_val();
	return 0;
}

