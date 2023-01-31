#include<stdio.h>
#include<stdarg.h>
#pragma warning(disable:4996)
#pragma warning(disable:6387)

/*
	�ļ�����
		1. �ļ��Ĵ���ر�
			FILE* fopen(const char* _FileName, const char* _Mode)		S:address	F: NULL
			int fclose(FILE* stream)									S:0			F:EOF(-1)
		2.�ļ����ַ���ȡд��
			int fgetc(FILE* stream)				S:(int)CHAR		F:EOF(-1)
			int fputc(int c, FILE* stream)		S:(ASCLL)CHAR	F:EOF(-1)
		3.�ļ����ж�ȡд�루'\0',\n,size��
			char* fgets(char* s, int size, FILE* stream)	S:CHAR*			F:(void*)NULL
			int fputs(const char* s, FILE* stream)			S:(int)SIZE		F:EOF(-1)
		4.�ļ���ȡ��д��
			size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream)	return: SIZE_Tʵ�ʶ���
			size_t fwrite(void* ptr, size_t size, size_t nmemb, FILE* stream)	return: SIZE_Tʵ��д��
		5.�ļ��������α����α궨λ���ȡ�α�λ��
			void rewind(FILE* stream)								
			int fseek(FILE* stream, long int offset, int whence)	S:0			F:!0
			long int ftell(FILE* stream)							S:SIZE		F:-1
		6.�ļ������ж�
			EOF					�ı��ļ�ʹ�ã�����ʽ�ж��ļ���������ascll 0-255�� -1	
			feof(FILE* stream)	�����ı��ļ���������ļ���(ͨ���ж��ļ����������ж��ļ��Ƿ����)	�������� 1 δ�������� 0

*/
// �����ļ�����

void check_fopen(int num, FILE* _Stream,...)
{
	// ����һ���ɱ��������
	va_list args;
	va_start(args, num);	// ָ��ָ�� �ɱ������ȷ��size��

	for (int i = 0; i < num; i++) 
	{
		FILE* _Stream= va_arg(args, FILE*);
		if(_Stream==NULL)
		{
			perror("fopen");
			return;
		}
		else 
		{ 
			printf("_Stream address=%p\n",_Stream); 
		}
	}

	va_end(args);			// ����ɱ��������

}

void check_fclose(int num, FILE* _StreamOff, ...)
{
	// ����һ���ɱ��������
	va_list args;
	va_start(args, num);	// ָ��ָ�� �ɱ������ȷ��size��

	for (int i = 0; i < num; i++) 
	{
		FILE* _StreamOff = va_arg(args, FILE*);
		int off = fclose(_StreamOff);
		if ( off != 0) 
		{
			perror("fopen");
			return;
		}
		else 
		{
			printf("_StreamOff off=%d\n", off);
		}
	}

	va_end(args);			// ����ɱ��������
}

void use_fgetc_fputc_implantment_file_cpoy(const char* _OriginFileName, const char* _DestFileName)
{
	/*
		2.�ļ����ַ���ȡд��
			int fgetc(FILE* stream)				S:(int)CHAR		F:EOF(-1)
			int fputc(int c, FILE* stream)		S:(ASCLL)CHAR	F:EOF(-1)
		6.�ļ������ж�
			EOF					�ı��ļ�ʹ�ã�����ʽ�ж��ļ���������ascll 0-255�� -1
	*/
	FILE* _Origin_p, * _Dest_p;
	const char* _OriginMode = "r";
	const char* _DestMode = "w";
	char _Char;

	_Origin_p = fopen(_OriginFileName,_OriginMode);
	_Dest_p = fopen(_DestFileName,_DestMode);
	check_fopen(2,_Origin_p,_Dest_p);

	while ((_Char = fgetc(_Origin_p)) != EOF)	// ASCLL 0-255 -1
	{
		if (fputc(_Char, _Dest_p) == EOF)
		{
			perror("fputc:");
			return;
		};
	}

	check_fclose(2, _Origin_p, _Dest_p);
}

void use_fgetc_fputc_implantment_file_cpoy_through_feof(const char* _OriginFileName, const char* _DestFileName)
{
	/*
		2.�ļ����ַ���ȡд��
			int fgetc(FILE* stream)				S:(int)CHAR		F:EOF(-1)
			int fputc(int c, FILE* stream)		S:(ASCLL)CHAR	F:EOF(-1)
		6.�ļ������ж�
			feof(FILE* stream)	�����ı��ļ���������ļ���(ͨ���ж��ļ����������ж��ļ��Ƿ����)	�������� 1 δ�������� 0	
	*/
	FILE* _Origin_p, * _Dest_p;
	const char* _OriginMode = "r";
	const char* _DestMode = "w";
	char _Char;

	_Origin_p = fopen(_OriginFileName, _OriginMode);
	_Dest_p = fopen(_DestFileName, _DestMode);
	check_fopen(2, _Origin_p, _Dest_p);

	while (!feof(_Origin_p))
	{
		_Char = fgetc(_Origin_p);
		if (fputc(_Char, _Dest_p) == EOF)
		{
			perror("fputc:");
			return;
		};
	}

	check_fclose(2, _Origin_p, _Dest_p);
}

void use_fgets_fputs_implantment_file_cpoy(const char* _OriginFileName, const char* _DestFileName)
{
	/*
		3.�ļ����ж�ȡд�루'\0',\n,size��
			char* fgets(char* s, int size, FILE* stream)	S:CHAR*			F:(void*)NULL
			int fputs(const char* s, FILE* stream)			S:(int)SIZE		F:EOF(-1)
		6.�ļ������ж�
			EOF					�ı��ļ�ʹ�ã�����ʽ�ж��ļ���������ascll 0-255�� -1
	*/
	FILE* _Origin_p, * _Dest_p;
	const char* _OriginMode = "r";
	const char* _DestMode = "w";

	_Origin_p = fopen(_OriginFileName,_OriginMode);
	_Dest_p = fopen(_DestFileName,_DestMode);

	check_fopen(2, _Origin_p, _Dest_p);
	
	char Char[100];
	while ((fgets(Char, 100, _Origin_p)) != NULL)
	{
		if (fputs(Char, _Dest_p) == EOF)
		{
			perror("fputs:");
			return;
		};
	}

	check_fclose(2, _Origin_p, _Dest_p);
}


void use_fgets_fputs_implantment_file_cpoy_through_feof(const char* _OriginFileName, const char* _DestFileName)
{
	/*
		3.�ļ����ж�ȡд�루'\0',\n,size��
			char* fgets(char* s, int size, FILE* stream)	S:CHAR*			F:(void*)NULL
			int fputs(const char* s, FILE* stream)			S:(int)SIZE		F:EOF(-1)
		6.�ļ������ж�
			feof(FILE* stream)	�����ı��ļ���������ļ���(ͨ���ж��ļ����������ж��ļ��Ƿ����)	�������� 1 δ�������� 0
	*/
	FILE* _Origin_p, * _Dest_p;
	const char* _OriginMode = "r";
	const char* _DestMode = "w";

	_Origin_p = fopen(_OriginFileName, _OriginMode);
	_Dest_p = fopen(_DestFileName, _DestMode);
	check_fopen(2, _Origin_p, _Dest_p);

	char Char[100];
	fgets(Char, 100, _Origin_p);
	while (!feof(_Origin_p))
	{
		if (fputs(Char, _Dest_p) == EOF) 
		{
			perror("fputs:");
			return;
		};
		fgets(Char, 100, _Origin_p);
	}

	check_fclose(2, _Origin_p, _Dest_p);
}


// use struct part
typedef struct io_edu 
{
	char name[10];
	int age;
	int number;
} EDU;

void use_fread_fwrite_implantment_command_write_struct_read_struct(const char* _OriginFileName, const char* _DestFileName)
{
	/*
		4.�ļ���ȡ��д��
			size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream)	return: SIZE_Tʵ�ʶ���
			size_t fwrite(void* ptr, size_t size, size_t nmemb, FILE* stream)	return: SIZE_Tʵ��д��
		6.�ļ������ж�
			EOF					�ı��ļ�ʹ�ã�����ʽ�ж��ļ���������ascll 0-255�� -1
			feof(FILE* stream)	�����ı��ļ���������ļ���(ͨ���ж��ļ����������ж��ļ��Ƿ����)	�������� 1 δ�������� 0
	*/
	EDU _StuRead[2];
	int _ReadSize = sizeof(EDU);
	int _ReadCount = 2;
	int _RealSize;
	
	int _FtellSize;

	FILE* _Origin_p, * _Dest_p;
	const char* _OriginMode = "rb";
	const char* _DestMode = "wb";

	_Origin_p = fopen(_OriginFileName, _OriginMode);
	_Dest_p = fopen(_DestFileName, _DestMode);
	check_fopen(2, _Origin_p, _Dest_p);

	//��_OriginFileName��ȡ���ݵ� _StuRead
	_RealSize = fread(_StuRead, _ReadSize,_ReadCount, _Origin_p);
	printf("fread _RealSize=%d\n", _RealSize);

	// ��ӡ����
	printf("_StuRead[0].name=%s\t_StuRead[0].age=%d\t_StuRead[0].number=%d\n", _StuRead[0].name, _StuRead[0].age, _StuRead[0].number);
	printf("_StuRead[1].name=%s\t_StuRead[1].age=%d\t_StuRead[1].number=%d\n", _StuRead[1].name, _StuRead[1].age, _StuRead[1].number);

	_FtellSize = ftell(_Origin_p);
	printf("_FtellSize=%d\n", _FtellSize);
	rewind(_Origin_p);
	_FtellSize = ftell(_Origin_p);
	printf("_FtellSize=%d\n", _FtellSize);
	fseek(_Origin_p, 10, SEEK_SET);
	_FtellSize = ftell(_Origin_p);
	printf("_FtellSize=%d\n", _FtellSize);
	rewind(_Origin_p);

	_RealSize = fwrite(_StuRead, _ReadSize, _ReadCount, _Dest_p);
	printf("fwrite _RealSize=%d\n", _RealSize);

	check_fclose(2, _Origin_p, _Dest_p);
}

int main84()
{
/*
	const char* _OriginFileName="..\\Files\\84case1.txt";
	const char* _DestFileName= "..\\Files\\84copy1.txt";
	use_fgetc_fputc_implantment_file_cpoy(_OriginFileName, _DestFileName);
*/
/*
	const char* _OriginFileName = "..\\Files\\84case1.dat";
	const char* _DestFileName = "..\\Files\\84copy1.dat";
	use_fgetc_fputc_implantment_file_cpoy_through_feof(_OriginFileName, _DestFileName);
*/
/*
	const char* _OriginFileName = "..\\Files\\84case2.txt";
	const char* _DestFileName = "..\\Files\\84copy2.txt";
	use_fgets_fputs_implantment_file_cpoy(_OriginFileName, _DestFileName);
*/

/*
	const char* _OriginFileName = "..\\Files\\84case2.dat";
	const char* _DestFileName = "..\\Files\\84copy2.dat";
	use_fgets_fputs_implantment_file_cpoy_through_feof(_OriginFileName, _DestFileName);
*/

/*
	const char* _OriginFileName = "..\\Files\\84case3.txt";
	const char* _DestFileName = "..\\Files\\84copy3.txt";
	use_fread_fwrite_implantment_command_write_struct_read_struct(_OriginFileName, _DestFileName);
*/
	return 0;
}

