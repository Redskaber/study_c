#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

/*
	�ռ��趨����
		void* memset(char* ptr, int value, size_t num)

	��һ���ڴ��num������ֵ����Ϊvalue��
	
	����ֵ��
		- �����׵�ַ
*/

char* use_memset_init_memory(char* ptr, int value, size_t num)	// value ascll
{
	return memset(ptr,value,num);
}



int main58()
{
	char origin_memory[100] = "0000000000";
	printf("origin_memory:%s\n",origin_memory);
	char* init_memory1 = use_memset_init_memory(origin_memory,'\0',100);
	printf("init_memory1:%s\n", init_memory1);
	char* init_memory2 = use_memset_init_memory(init_memory1, 65, 10);
	printf("init_memory2:%s\n", init_memory2);
	return 0;
}

