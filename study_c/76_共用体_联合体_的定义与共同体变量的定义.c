#include<stdio.h>

/*
	�ṹ�������

		��ͬ�壺����������
		˵���� �������ʹ����ͬһ��洢�ռ�
			���£� -> �µı������ݻḲ�ǵ��ɵ����ݡ��������ڴ�ֻ�ᱣ�����µ����ݱ�����Ϣ 
			���˵���� -> �洢��Сֻ��Ҫ���ڹ������Ա�����洢���ͼ��ɡ�

		�ؼ��֣�union
		�÷���union [name]{ type member;...}[ins]...;
			
*/


typedef int type_a;
typedef char type_b;
typedef int type_c;


typedef struct struct_name 
{
	type_a member_a;
	type_b member_b;
	type_c member_c;
} 
struct_nick_name;

typedef union union_name
{
	type_a member_a;
	type_b member_b;
	type_c member_c;
} 
union_nick_name;


int main76()
{
	struct_nick_name snn;
	printf("struct_type_nomery=%d\n", sizeof(snn));		// 12
	union_nick_name unn;
	printf("union_type_nomery=%d\n", sizeof(unn));		// 4

	return 0;
}