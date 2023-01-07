#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
	�ַ����ĸ���
		�ַ�����һ�������Ĵ洢�ռ����ݡ�
		���˿�洢�ռ���׵�ַ��Ϊ�ַ����ĵ�ַ��
	�ַ����Ĵ洢��ʽ
		1.����洢(ջ��)
			int  str[100]="I Love C!";
		2.ָ��(���ֳ�����)		
			int* str="I Love C!";
		3.malloc�ȶ�̬����(����)
			char* str=(char*)malloc(10*sizeof(char));	
			strcpy(str,"I love C");						
	�ַ����Ŀ��޸���
		1.�����޸� ���� ��̬����
		2.�����޸� const�� ���ֳ�����
*/

void str_storage_form();
void str_use_array_storage();
void str_use_pointer_storage();
void str_use_dymanic_get_storage();

void main37()
{
	str_storage_form();
}

void str_storage_form()
{
	str_use_array_storage();
	str_use_pointer_storage();
	str_use_dymanic_get_storage();
}

void str_use_array_storage()
{
	char str[100] = "I Love C!";
	printf("char str[100]: %s\n", str);
	str[0] = 'Y';
	printf("char str[100]: %s\n", str);
}

void str_use_pointer_storage()
{
	// �����޸�
	char* str = "I Love C!";
	printf("char* str:%s\n",str);
	// *str = 'Y';
	// printf("char* str:%s",str);
}

void str_use_dymanic_get_storage()
{
	char* str = (char*)malloc(10 * sizeof(char));
	strcpy(str,"I Love C!");
	printf("strcpy(str,data):%s\n",str);
	*str = 'Y';
	printf("strcpy(str,data):%s\n", str);
}
