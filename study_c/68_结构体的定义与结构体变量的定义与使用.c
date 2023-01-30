#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"68_结构体的定义与结构体变量的定义与使用.h"
#pragma warning(disable:4996)		// x86 unsafe warning

/*
	结构体的定义
		struct [结构体名]{
			结构体成员;
		} [结构体变量...];
	1结构体的四种定义：
		1.1. 先定义结构体再使用结构体创建结构体变量
			struct student {
				char* name;
				int age;
			};
			struct student boy;
		1.2.定义结构体同时定义结构体变量，后面可以接着定义。
			struct student {
				char* name;
				int age;
			} alex,tom;
			struct student reds;
		1.3.定义未命名结构体，直接表示一种一次性数据结构。
			struct {
				char* name;
				int age;
			} alex;
		1.4.通过 typedef + struct 重命名结构体名称;
			复习： typedef old new;
			typedef struct student{
				char* name;
				int age;
			} ST;
			ST alex;	
	2.结构体变量定义及使用
		2.1.未初始化定义;
			struct student boy;
		2.2.初始化定义;
			struct student boy ={"alex",21};
		2.3.结构体变量的赋值或引用
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

	3.结构体空间大小
		在未学习，内存分配下的结构体空间占用为各个成员大小之和。
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
		使用头文件定义的结构体ST
	*/
	ST alex;		// 未初始化
	ST tom = {		// 初始化部分，注意，必须初始化前面的内容。
	"tom"
	};

	alex.name = "alex";
	// char[] 数组的名是一个常量，不能赋值
	char* info = "this is a infomation.";
	// strncpy(alex.info, info);
	// strncpy(alex.info,info, strlen(info));	// 因为结构体的内存没有初始化，而info内容不够长，只会替换前面的内容，会出现莫名其妙的内容
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
