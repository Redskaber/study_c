#include<stdio.h>
#include<string.h>

/*
	结构体指针变量的定义与成员对象的访问

		结构体指针变量定义
		     结构体类型	指针修饰符 名;	ST * stu;	
		结构体指针变量成员的访问
			1.结构体.成员
			
			2.结构体指针
				(*结构体指针).成员
				结构体指针->成员
*/

typedef struct {
	char* name;
	int age;
}ST;


ST* struct_pointer_val_define()
{
	/*
	char* xxxx()
	{
		char name="alex";
		char* p;
		p = &name;
		return p;
	}
	外部想要局部数据，必须要声明 static,或者外部传入
	*/

	// 结构体变量的定义与初始化
	ST local_alex = { "alex",22 };					
	static ST global_alex = { "alex",11 };


	// 结构体指针变量的定义与初始化
	ST* g_stu, *l_stu;
	l_stu = &local_alex;
	g_stu = &global_alex;

	// global
	printf("ST* student=%p\n", g_stu);
	printf("(*g_stu).name=%s\n", (*g_stu).name);
	printf("g_stu->age=%d\n", g_stu->age);
	return g_stu;		// 结构体指针
}

void use_struct_pointer_get_member(ST* student)
{
	printf("ST* student=%p\n", student);
	printf("student is struct, so can use \"(*pointer).member\" get name=%s\n", (*student).name);
	printf("student is struct, so can use \"pointer->member\" get age=%d\n", student->age);
}

void single_struct_pointer()
{
	/*
		结构体变量与结构体指针（定义，初始化，函数传参，函数返回，成员访问）
	*/


	ST* student = struct_pointer_val_define();

	printf("\n");
	printf("\"(*pointer).member\" get name=%s\n", (*student).name);
	printf("\"pointer->member\" get age=%d\n", student->age);
	printf("\n");

	use_struct_pointer_get_member(student);		// ST*
}

ST* get_struct_pointer_array_address()
{
	// struct array define and init
	static ST edu[3] = {
		{"alex",21},
		{"bom",22},
		{"coly",23}
	};
	return edu;
}

void about_struct_array_rela(ST* _Struct_Array)
{
	// _Struct_Array: struct array address
	printf("struct_array_address=%p\n",_Struct_Array);			// array	ST []
	printf("struct_array[0]_address=%p\n",&_Struct_Array[0]);	// struct	ST *
	printf("&struct_array[0].name=%p\n",&_Struct_Array[0].name);// struct	char **
}


void struct_pointer_array()
{
	/*
		结构体数组变量与结构体指针数组（定义，初始化，函数传参，
		函数返回，成员访问，结构体数组与结构体与结构体成员之间的类型与关系）
	*/
	ST* struct_array_address = get_struct_pointer_array_address();
	printf("struct_array_address:%p\n",struct_array_address);
	
	for (int i = 0; i < 3; i++)
	{
		printf("store[%d]=%s\n", i, struct_array_address[i].name);
		printf("store[%d]=%d\n", i, struct_array_address[i].age);
	}

	about_struct_array_rela(struct_array_address);
}


int main70()
{
	single_struct_pointer();
	struct_pointer_array();
	return 0;
}
