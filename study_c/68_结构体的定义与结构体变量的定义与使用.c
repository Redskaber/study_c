#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"68_�ṹ��Ķ�����ṹ������Ķ�����ʹ��.h"
#pragma warning(disable:4996)		// x86 unsafe warning

/*
	�ṹ��Ķ���
		struct [�ṹ����]{
			�ṹ���Ա;
		} [�ṹ�����...];
	1�ṹ������ֶ��壺
		1.1. �ȶ���ṹ����ʹ�ýṹ�崴���ṹ�����
			struct student {
				char* name;
				int age;
			};
			struct student boy;
		1.2.����ṹ��ͬʱ����ṹ�������������Խ��Ŷ��塣
			struct student {
				char* name;
				int age;
			} alex,tom;
			struct student reds;
		1.3.����δ�����ṹ�壬ֱ�ӱ�ʾһ��һ�������ݽṹ��
			struct {
				char* name;
				int age;
			} alex;
		1.4.ͨ�� typedef + struct �������ṹ������;
			��ϰ�� typedef old new;
			typedef struct student{
				char* name;
				int age;
			} ST;
			ST alex;	
	2.�ṹ��������弰ʹ��
		2.1.δ��ʼ������;
			struct student boy;
		2.2.��ʼ������;
			struct student boy ={"alex",21};
		2.3.�ṹ������ĸ�ֵ������
			typedef struct student {
				char* name;
				char[200] info;
				int age;
				char sex;
				struct date birthday;	// year,month,day
			} ST;
			
			ST alex;
			alex.name = "alex";
			strcpy(alex.info, "infomation");
			alex.age = 21;
			alex.sex = '1';
			alex.birthday.year = 2001;
			alex.birthday.month = 10;
			alex.birthday.day = 24;

	3.�ṹ��ռ��С
		��δѧϰ���ڴ�����µĽṹ��ռ�ռ��Ϊ������Ա��С֮�͡�
*/

struct date {
	short year;
	short month;
	short day;
};

typedef struct  {
	char* name;
	struct date birthday;
} MemberCard;

struct {
	char* meta_class_name;
	struct {
		char* class_name;
	};
};


void printf_info(ST data)
{
	printf("data.name=%s\n",data.name);
	printf("data.info=%s\n",data.info);
	printf("data.age=%d\n",data.age);
	printf("data.phone=%s\n",data.phone);
	printf("data.sex=%d\n",data.sex);
}

void printf_membercard(MemberCard member)
{
	printf("member.name=%s\n",member.name);
	printf("member.birthday.year=%d\n",member.birthday.year);
	printf("member.birthday.month=%d\n",member.birthday.month);
	printf("member.birthday.day=%d\n",member.birthday.day);
}

void printf_struct_sizeof(ST st)
{
	printf("st=%d\n",(int)sizeof(st));
}

void printf_struct_sizeofs(MemberCard st)
{
	printf("st=%d\n", (int)sizeof(st));
}


int main68(int argc, char* argv[])
{
	/*
		ʹ��ͷ�ļ�����Ľṹ��ST
	*/
	ST alex;		// δ��ʼ��
	ST tom = {		// ��ʼ�����֣�ע�⣬�����ʼ��ǰ������ݡ�
	"tom"
	};

	alex.name = "alex";
	// char[] ���������һ�����������ܸ�ֵ
	char* info = "this is a infomation.";
	// strncpy(alex.info, info);
	// strncpy(alex.info,info, strlen(info));	// ��Ϊ�ṹ����ڴ�û�г�ʼ������info���ݲ�������ֻ���滻ǰ������ݣ������Ī�����������
	strncpy(alex.info,info, 200);
	alex.age = 21;
	// strcpy(alex.phone, "17845678901");
	alex.phone = "17845678901";
	alex.sex = 1;

	printf_info(alex);
	printf("\n");
	printf_info(tom);

	struct date birthday = {2001,10,24};
	MemberCard redis = {
		"redis",
		birthday
	};
	printf_membercard(redis);

	printf_struct_sizeof(alex);	// 232
	printf_struct_sizeofs(redis);
	return 0;
}
