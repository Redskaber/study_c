#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6387)

/*
	��ϰ
	��һ��δ֪��С���ļ�(�ı��ļ�)ȫ�������ڴ棬����ʾ����Ļ��
		�ο�:fseek ftellrewind fread malloc
		1�����ļ�fopen��ע����b �ķ�ʽ��
		2����λ�ļ��Ķ�дλ�õ��ļ���ĩβfseek.
		3�����ļ����ֽ���len ftell
		4����λ��дλ�õ��ļ��Ŀ�ʼrewind
		5�����ݵ�3���õ����ֽ��飬�����ڴ�mallocע�������һ���ֽڴ��'\0'
		6�����ļ��ж�ȡ���ݣ��浽����Ŀռ��� fread
		7�����һ���ֽڱ��'\0'
		8����ӡ�����������ݵ���Ļ�� printf()��
		9���ر��ļ�fclose
		10���ͷ��ڴ�free
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
	const char* _ReadFileName = "..\\Files\\�򵥰�.lrc";
	const char* _ReadMode = "rb";
	Read_MusicWords_to_Memory(_ReadFileName,_ReadMode);
	return 0;
}
