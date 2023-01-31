#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6387)

/*
	练习
	将一个未知大小的文件(文本文件)全部读入内存，并显示在屏幕上
		参考:fseek ftellrewind fread malloc
		1、打开文件fopen，注意用b 的方式打开
		2、定位文件的读写位置到文件的末尾fseek.
		3、测文件的字节数len ftell
		4、复位读写位置到文件的开始rewind
		5、根据第3步得到的字节书，申请内存malloc注意多申请一个字节存放'\0'
		6、从文件中读取内容，存到申请的空间里 fread
		7、最后一个字节变成'\0'
		8、打印读出来的内容到屏幕上 printf()、
		9、关闭文件fclose
		10、释放内存free
*/


void Read_MusicWords_to_Memory(const char* _ReadFileName, const char* _ReadMode)
{
	FILE* _Read_p;
	size_t _RSize;
	char* _ReadStore;
	int _ReadOff;

	_Read_p = fopen(_ReadFileName, _ReadMode);
	if (_Read_p == NULL) { perror("fopen"); return; }

	fseek(_Read_p,0, SEEK_END);
	_RSize = ftell(_Read_p);
	rewind(_Read_p);

	_ReadStore = (char*)malloc(_RSize + 1);
	if (_ReadStore == NULL) { perror("malloc"); return; }

	fread(_ReadStore, _RSize, 1, _Read_p);
	_ReadStore[_RSize] = '\0';

	printf("_ReadStore:\n%s\n",_ReadStore);
	free(_ReadStore);
	_ReadStore = NULL;

	_ReadOff = fclose(_Read_p);
	if (_ReadOff != 0) { perror("fclose"); return; }
}


int main(int argc, char* argv[])
{
	const char* _ReadFileName = "..\\Files\\简单爱.lrc";
	const char* _ReadMode = "rb";
	Read_MusicWords_to_Memory(_ReadFileName,_ReadMode);
	return 0;
}
