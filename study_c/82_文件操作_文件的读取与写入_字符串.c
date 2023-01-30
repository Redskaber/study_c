#include<stdio.h>
#pragma warning(disable:4996)
/*
	文件操作
		文件的读取与写入 （字符串）
		1. fgets(char* s, int size, FILE* stream )		s: return s_address		f:return NULL
		2. fputs(char* s, FILE* stream)					s: return len(s)		f: -1
*/

void use_fgets_fputs_implantment_file_copy(const char* _ReadFileName, const char* _WriteFileName)
{
	FILE* Read_p, * Write_p;
	const char* _ReadMode = "r";
	const char* _WriteMode = "w";

	Read_p = fopen(_ReadFileName, _ReadMode);
	Write_p = fopen(_WriteFileName, _WriteMode);

	int ReadSize = 100;
	char ReadStore[100];
	int StoreOff;
	while ((fgets(ReadStore, ReadSize, Read_p)) != NULL)
	{
		StoreOff = fputs(ReadStore, Write_p);
	}

	fclose(Write_p);
	fclose(Read_p);
}

int main82(int argc, const char* argv[])
{
	/*
		argc: count
		argv[]: .exe + argv[1~...]
	*/
	//const char* _ReadFileName = "..\\Files\\case.txt";
	//const char* _WriteFileName = "..\\Files\\case3.txt";
	const char* _ReadFileName = argv[1];
	const char* _WriteFileName = argv[2];

	use_fgets_fputs_implantment_file_copy(_ReadFileName, _WriteFileName);
	printf("文件从:%s,拷贝到:%s,已经完成！", _ReadFileName, _WriteFileName);
	
	return 0;
}
