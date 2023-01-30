#include<stdio.h>
#pragma warning(disable:4996)

/*
	文件操作
		1.c中文件的类型是一个 构造类型 是一个构造结构体。
		2.当文件读取数据时，c会创建一个文件构造结构体并开辟空间作为缓存；文件操作经过缓存处理。文件操作在c中是全缓存（缓存满推送）
		3.当文件关闭，c会释放掉创建的文件结构与空间。
		4.可以通过判断开辟或者关闭函数的返回值来判断是否操作成功。
			error 使用perror 函数获取出错信息 perror([val])	val是自定义说明，会先出现
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
		char const* _ErrorMessage = "printf_fopen！";
		perror(_ErrorMessage);
	}
	else
	{
		printf("文件打开成功！返回文件地址=%p\n", _File);
	}
}

void printf_fclose(FILE* _File)
{
	int fres = fclose(_File);
	if (fres == 0)
	{
		printf("文件关闭成功！fres=%d\n", fres);
	}
	else
	{
		printf("文件关闭失败！fres=%d\n", fres);

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
