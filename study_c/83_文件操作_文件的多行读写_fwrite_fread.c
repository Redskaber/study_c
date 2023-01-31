#include<stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6387)
/*
	文件操作 文件的多行读写操作
	1.fread(void* ptr, size_t size, size_t nmemb, FILE* stream)		<-
	2.fwrite(void* ptr, size_t size, size_t nmemb, FILE* stream)	->
	
	补充：rewind(FILE* stream)	指向重置为文件开始
*/

// case: 将一些结构体数据写入文件并读取到结构体中。


typedef struct io_buf
{
	char name[10];
	int age;
	int number;
} EDU;

void command_input_struct_and_read_struct_data(const char* _StuDataFileName, const char* _Mode)
{
	EDU _StuWrite[2];
	EDU _StuRead[2];
	size_t _StuWriteSize = sizeof(EDU);
	size_t _StuReadSize = sizeof(EDU);
	size_t _StuWriteCount = 2;
	size_t _StuReadCount = 2;
	size_t _StuWSize;
	size_t _StuRSize;

	FILE* _Stream;
	int _StreamOff;

	_Stream = fopen(_StuDataFileName, _Mode);
	if (_Stream == NULL) {
		perror("fopen:");
		return 0;
	}

	// 输入_StuWrite
	for (int i = 0; i < 2; i++)
	{
		scanf_s("%s %d %d", _StuWrite[i].name, 10, &(_StuWrite[i].age), &(_StuWrite[i].number));	// scanf_s( const char* chars, max_size,...)
	}
	printf("_StuWrite[0].name=%s\t_StuWrite[0].age=%d\t_StuWrite[0].number=%d\n", _StuWrite[0].name, _StuWrite[0].age, _StuWrite[0].number);
	printf("_StuWrite[1].name=%s\t_StuWrite[1].age=%d\t_StuWrite[1].number=%d\n", _StuWrite[1].name, _StuWrite[1].age, _StuWrite[1].number);

	// 将数据写入结构体中并重置指向与读取
	_StuWSize = fwrite(_StuWrite, _StuWriteSize, _StuWriteCount, _Stream);
	rewind(_Stream);
	_StuRSize = fread(_StuRead, _StuReadSize, _StuReadCount, _Stream);

	// 输出实际写入与读取的存储块数
	printf("_StuWsize=%d\n", _StuWSize);
	printf("_StuRSize=%d\n", _StuRSize);

	// 打印将文件中的数据读取到结构体中
	printf("_StuRead[0].name=%s\t_StuRead[0].age=%d\t_StuRead[0].number=%d\n", _StuRead[0].name, _StuRead[0].age, _StuRead[0].number);
	printf("_StuRead[1].name=%s\t_StuRead[1].age=%d\t_StuRead[1].number=%d\n", _StuRead[1].name, _StuRead[1].age, _StuRead[1].number);

	_StreamOff = fclose(_Stream);
	if (_StreamOff != 0) perror("fclose:");


}


int main83(int argc, char* argv[])
{
	const char* _StuDataFileName = "..\\Files\\StuData.txt";
	//const char* _StuDataFileName  = "..\\Files\\84case3.txt";
	const char* _WMode = "wb+";	// window 只能使用 二进制
	command_input_struct_and_read_struct_data(_StuDataFileName, _WMode);
	return 0;
}
