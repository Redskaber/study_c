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


EDU* struct_array_define_assignment()
{
	/*
		define struct type
	*/
	EDU struct_array[3] = {
		{"tom",21},
		{"alex",22},
		{"jane",23}
	};
	printf("struct_array=%p\n",struct_array);
	printf("struct_array=%p\n",struct_array[0]);
	printf("struct_array=%p\n",struct_array[1]);
	printf("struct_array=%p\n",struct_array[2]);
	printf("struct_array[0].name=%s\n",struct_array[0].name);
	return struct_array;
}

int main69(int argc, char* argv[])
{

	ST bom = {"bon",21};
	ST tom = {""};
	same_struct_type_can_assignment(&bom,&tom);
	printf("tom.name=%s\n",tom.name);
	printf("tom.age=%d\n",tom.age);

	EDU* dest = struct_array_define_assignment();
	printf("dest=%p\n", dest);
	printf("dest=%s\n", dest[0].name);
	printf("dest=%s\n", dest[1].name);
	printf("dest=%s\n", dest[2].name);

	return 0;
}
