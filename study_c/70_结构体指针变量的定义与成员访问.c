#include<stdio.h>
#include<string.h>

/*
	�ṹ��ָ������Ķ������Ա����ķ���

		�ṹ��ָ���������
		     �ṹ������	ָ�����η� ��;	ST * stu;	
		�ṹ��ָ�������Ա�ķ���
			1.�ṹ��.��Ա
			
			2.�ṹ��ָ��
				(*�ṹ��ָ��).��Ա
				�ṹ��ָ��->��Ա
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
	�ⲿ��Ҫ�ֲ����ݣ�����Ҫ���� static,�����ⲿ����
	*/

	// �ṹ������Ķ������ʼ��
	ST local_alex = { "alex",22 };					
	static ST global_alex = { "alex",11 };


	// �ṹ��ָ������Ķ������ʼ��
	ST* g_stu, *l_stu;
	l_stu = &local_alex;
	g_stu = &global_alex;

	// global
	printf("ST* student=%p\n", g_stu);
	printf("(*g_stu).name=%s\n", (*g_stu).name);
	printf("g_stu->age=%d\n", g_stu->age);
	return g_stu;		// �ṹ��ָ��
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
		�ṹ�������ṹ��ָ�루���壬��ʼ�����������Σ��������أ���Ա���ʣ�
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
		�ṹ�����������ṹ��ָ�����飨���壬��ʼ�����������Σ�
		�������أ���Ա���ʣ��ṹ��������ṹ����ṹ���Ա֮����������ϵ��
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
