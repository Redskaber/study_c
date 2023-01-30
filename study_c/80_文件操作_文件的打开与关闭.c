#include<stdio.h>
#pragma warning(disable:4996)

/*
	�ļ�����
		1.c���ļ���������һ�� �������� ��һ������ṹ�塣
		2.���ļ���ȡ����ʱ��c�ᴴ��һ���ļ�����ṹ�岢���ٿռ���Ϊ���棻�ļ������������洦���ļ�������c����ȫ���棨���������ͣ�
		3.���ļ��رգ�c���ͷŵ��������ļ��ṹ��ռ䡣
		4.����ͨ���жϿ��ٻ��߹رպ����ķ���ֵ���ж��Ƿ�����ɹ���
			error ʹ��perror ������ȡ������Ϣ perror([val])	val���Զ���˵�������ȳ���
			1.fopen	->	NULL
			2.fcolse -> !0
*/


void printf_fopen(FILE* _File)
{
	if (_File == NULL)
	{
		/*
		    _ACRTIMP void __cdecl perror(
			_In_opt_z_ char const* _ErrorMessage
			);
		*/
		char const* _ErrorMessage = "printf_fopen��";
		perror(_ErrorMessage);
	}
	else
	{
		printf("�ļ��򿪳ɹ��������ļ���ַ=%p\n", _File);
	}
}

void printf_fclose(FILE* _File)
{
	int fres = fclose(_File);
	if (fres == 0)
	{
		printf("�ļ��رճɹ���fres=%d\n", fres);
	}
	else
	{
		printf("�ļ��ر�ʧ�ܣ�fres=%d\n", fres);

	}
}


int main80()
{
	FILE* file;

	/*
	    _ACRTIMP FILE* __cdecl fopen(
        _In_z_ char const* _FileName,
        _In_z_ char const* _Mode
        );
	*/
	char* const _FileName= "..\\Files\\case.txt";
	// char* const _FileName= ".\\File\\case.txt";		// printf_fopen: No such file or directory
	char* const _Mode= "w";

	file = fopen(_FileName, _Mode);
	printf_fopen(file);
	printf_fclose(file);




	return 0;
}
