#include<stdio.h>
#pragma warning(disable:4996)

/*
	�ļ�����
		�ļ��Ķ�ȡ�����
		��ȡ�����ַ�	int fgetc(FILE* stream)				s:(int)�ַ�		f:EOF
		��������ַ�	int fputc(int c, FILE* stream)		s:(ASCLL)�ַ�	f:EOF
*/

void printf_fopen2(FILE* _Stream)
{
	/*
		fopen:
			- NULL  perror
			- address 
	*/	
	if (_Stream == NULL) perror("printf_fopen:");
	else printf("\nfile open success��	%p\n", _Stream);
}

void printf_fclose2(FILE* _Stream)
{
	/*
		fclose:
			- 0  �ɹ�����
			- EOF δ����
	*/
	int off = fclose(_Stream);
	if (off == 0) printf("\nfile close success��fres=%d\n", off);
	else perror("printf_fclose2:");
}

void standrad_output()
{
	/*
		int fgetc(FILE* _Stream)	
		
	*/

	int _Char;
	int _CharAscll;
	FILE* _Stream;
	const char* _Mode = "r";
	const char* _FileName = "..\\Files\\case.txt";
	
	_Stream = fopen(_FileName, _Mode);
	printf_fopen2(_Stream);
	while ((_Char = fgetc(_Stream)) != EOF)
	{
		// printf("%c",_Char);
		_CharAscll = fputc(_Char, stdout);	// ��׼���������,
	}
	printf_fclose2(_Stream);

}

void implantment_file_copy(const char* _Origin, const char* _Dest)
{
	/*
		const char* _Origin:	origin file path.
		const char* _Dest:		dest file path.
		const char* _Mode:		action file mode.
	*/

	FILE* _Origin_p;
	FILE* _Dest_p;
	const char* _OMode = "r";
	const char* _DMode = "w";
	int _Char, _CharAscll;
	
	_Origin_p = fopen(_Origin, _OMode);
	_Dest_p = fopen(_Dest, _DMode);
	
	printf_fopen2(_Origin_p);
	printf_fopen2(_Dest_p);
	while ((_Char = fgetc(_Origin_p)) != EOF)
	{
		_CharAscll = fputc(_Char,_Dest_p);
	}
	printf_fclose2(_Dest_p);
	printf_fclose2(_Origin_p);
}


int main81(int argc, char* argv[])
{
	// standrad_output();
	const char* _OriginFileName = "..\\Files\\case.txt";
	const char* _DestFileName = "..\\Files\\case2.txt";
	implantment_file_copy(_OriginFileName, _DestFileName);

	return 0;
}




