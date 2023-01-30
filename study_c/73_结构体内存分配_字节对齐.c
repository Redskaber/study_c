#include<stdio.h>

/*
	�ṹ���ڴ����
		1.�洢��λ
		2.�ֽڶ���
	�ֽڶ���
	X64
	type  size alignment
	char	1	1
	short	2	2	
	int		4	4
	long	4	4
	float	4	4
	double	8	8
	long long	8	8
	long double	8	8
	pointer	8	8

	X86
	type  size alignment
	char	1	1
	short	2	2
	int		4	4
	long	4	4
	float	4	4
	double	8	8
	long long	8	8
	long double	8	8
	pointer	4	4

	ps: ע�� ����ȷ���洢��λ������ݳ�Ա˳�򣬷����ڴ��С��
		1.�ṹ������ڴ��Ǹ��ݳ�Ա�������µ�˳�򡣴洢��λֻ�᲻�ϵ����󣬲�����С��
		2.���ṹ���Ա��һ��������ʽʱ�����俴��ͬһ���͵�һ�����ϡ� char [10] = sizeof(char) * 10;
*/

typedef struct same_type_struct_member{
	int card;		// 4		4*n
	int number;		// 4		4*n
	int score;		// 4		4*n
} CASE;

typedef struct dsame_type_struct_member_same_order {
	char sex;			// 1		1*n
	double card;		// 8		8*n
} DSTSM_SO;

typedef struct dsame_type_struct_member_dsame_order{
	double card;		// 8		8*n
	char sex;			// 1		1*n
} DSTSM_DO;

typedef struct use_array_member_same_order {
	char number;			// 1		1*n
	int child[10];			// 4*10		4*n
}UAM_SO;

typedef struct use_array_member_dsame_order {
	int child[10];			// 4*10		4*n
	char number;			// 1		1*n
}UAM_DO;


void same_type_struct_member()
{
	/*
		�ṹ���ڴ����:
		1.��Ա˳���� int int int
		2.�洢��λ   4	 4   4		û�б仯 4*3
	*/
	CASE same_member;
	printf("sizeof(same_member)=%d\n", sizeof(same_member));
	printf("same_member.card=%p\n",&same_member.card);
	printf("same_member.number=%p\n",&same_member.number);
	printf("same_member.score=%p\n",&same_member.score);

	printf("2-1=%d\n", (int)(& same_member.number) - (int)(& same_member.card));	//4
	printf("3-2=%d\n", (int)(& same_member.score) - (int)(& same_member.number));	//4
	printf("\n\n");
}

void dsame_type_struct_member()
{
	/*
		�ṹ���ڴ����:
		1.��ȷ���洢��λ    1		 8			 
		2.���Ա˳����		char  double
	*/
	// char + double ����double��gcc��������4�ı���������char+double ��gcc������ռ�� 4+(4+4)=12���ֽ�
	// char + double ����double��vc��vs��������8�ı���������char+double ��vc��vs������ռ�� 8+8=16���ֽ�
	DSTSM_SO dsame_member;
	printf("sizeof(dsame_member)=%d\n",sizeof(dsame_member));					// 16
	printf("dsame_member.sex=%p\n", &dsame_member.sex);
	printf("dsame_member.card=%p\n", &dsame_member.card);
	printf("2-1=%d\n", (int)(&dsame_member.card) -(int)(&dsame_member.sex));					// 8

	printf("\n");

	DSTSM_DO dsame_dorder_member;
	printf("sizeof(dsame_dorder_member)=%d\n", sizeof(dsame_dorder_member));	// 16 
	printf("dsame_dorder_member.card=%p\n", &dsame_dorder_member.card);
	printf("dsame_dorder_member.sex=%p\n", &dsame_dorder_member.sex);
	printf("2-1=%d\n", (int)(&dsame_dorder_member.sex) - (int)(& dsame_dorder_member.card));	// 8

	printf("\n\n");
}

void use_array_member()
{
	UAM_SO array_member;
	printf("sizeof(array_member)=%d\n", sizeof(array_member));			// 44
	printf("array_member.number=%p\n", &array_member.number);
	printf("array_member.child=%p\n", &array_member.child);
	printf("2-1=%d\n", (int)(&array_member.child) - (int)(&array_member.number));		// 4
	
	printf("\n");


	UAM_DO darray_member;
	printf("sizeof(darray_member)=%d\n", sizeof(darray_member));		// 44
	printf("array_member.child=%p\n", &darray_member.child);
	printf("array_member.number=%p\n", &darray_member.number);
	printf("2-1=%d\n", (int)(&darray_member.number) - (int)(&darray_member.child));		// 40
	
	printf("\n\n");
}

int main73(int argc, char* argv[])
{
	// �ֽڶ���
	same_type_struct_member();
	dsame_type_struct_member();
	use_array_member();
	return 0;
}
