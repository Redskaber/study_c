#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)		// x86 unsafe warning


/*
	�ַ����и��
		char* strtok(char* s, const char* delim)
		ƥ��s�е�delim�е��ַ��������滻��'\0',
	
	�״ε�һ������ʹ�õ���s������ʹ��NULL����ʾ���������������ݽ��н�ȡ��
	�����delim�ַ�����ʱ��ֻ���׸��ַ��滻��'\0'�������������

	����ֵ��
		- ָ���ȡ��ַָ�� char*
*/

void case_only_one_toend(char** store)	// char** -> [char*,char*,...]
{
	/*
		�״ε�һ������ʹ�õ���s������ʹ��NULL����ʾ���������������ݽ��н�ȡ��
		�����delim�ַ�����ʱ��ֻ���׸��ַ��滻��'\0'�������������
	*/
	printf("store[0]:%s\t%p\n", store[0], store[0]);
	printf("store[0]+5:%s\t%p\n", store[0]+5, store[0]+5);
	printf("store[1]:%s\t%p\n", store[1], store[1]);
	
}

void case_exercise();
int msg_deal(char* msg_src, char* msg_done[], char* str);

int main60()
{
	char* store[10];
	char str_template[100] = { "yang:,,,2001-10-24...:male:hunan:..,:20e..,..china" };	// V s[] | X char*
	char* delim = ":.,";

	for (size_t i = 0; i < 7; i++)	// 6 + NULL 
	{
		if (i==0) store[i] = strtok(str_template, delim);
		else store[i] = strtok(NULL, delim);
	}

	for (size_t i = 0; i < 7; i++)
	{
		printf("store[%d]=%s\n",i,store[i]);
	}

	case_only_one_toend(store);		// char* store[]  == char** store
	case_exercise();

	return 0;
}

void case_exercise() {
	char msg_src[] = "+CMGR:REC UNREAD,+8613466630259,98/10/01,18:22:11+00,ABCdefGHI";
	char* store[100];
	int length = msg_deal(msg_src, store, ",");

	for (size_t i = 0; i < length; i++)
	{
		printf("store[%d]=%s\n",i,store[i]);
	}
}

int msg_deal(char* msg_src, char* msg_done[], char* str)
{	
	int i = 0;
	msg_done[i] = strtok(msg_src, str);
	 while (msg_done[i] != NULL)
	{
		i++;
		msg_done[i] = strtok(NULL, str);
	}
	return i;
}
