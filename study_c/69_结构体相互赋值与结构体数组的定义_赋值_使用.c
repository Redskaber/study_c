#include<stdio.h>
#include<string.h>

/*
	�ṹ��
		1.��ͬ���ͣ��໥��ֵ
	�ṹ������
		1.�ṹ������Ķ���	���� ����[];
		2.�ṹ������ĸ�ֵ	���� ���� = ����;
		3.�ṹ�������ʹ��	�ṹ�����.��Ա

*/

typedef struct {
	char* name;
	int age;
} ST;


void same_struct_type_can_assignment(ST *stu1, ST *stu2)
{
	*stu2 = *stu1;
}


typedef struct {
	char* name;
	int age;
} EDU;


int main69(int argc, char* argv[])
{

	ST bom = {"bon",21};
	ST tom = {""};
	same_struct_type_can_assignment(&bom,&tom);
	printf("tom.name=%s\n",tom.name);
	printf("tom.age=%d\n",tom.age);

	return 0;
}
