#include<stdio.h>
#include<string.h>

/*
	结构体
		1.相同类型，相互赋值
	结构体数组
		1.结构体数组的定义	类型 名称[];
		2.结构体数组的赋值	类型 变量 = 变量;
		3.结构体数组的使用	结构体变量.成员

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
