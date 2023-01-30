#include<stdio.h>

/*
	结构体内存分配
		1.存储单位
		2.字节对齐
	字节对齐
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

	ps: 注意 （先确定存储单位，后根据成员顺序，分析内存大小）
		1.结构体分配内存是根据成员从上至下的顺序。存储单位只会不断的增大，不会缩小。
		2.当结构体成员是一个数组形式时，将其看作同一类型的一个集合。 char [10] = sizeof(char) * 10;
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
		结构体内存分析:
		1.成员顺序性 int int int
		2.存储单位   4	 4   4		没有变化 4*3
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
		结构体内存分析:
		1.先确定存储单位    1		 8			 
		2.后成员顺序性		char  double
	*/
	// char + double 由于double在gcc环境下是4的倍数，所以char+double 在gcc环境下占用 4+(4+4)=12个字节
	// char + double 由于double在vc或vs环境下是8的倍数，所以char+double 在vc或vs环境下占用 8+8=16个字节
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
	// 字节对齐
	same_type_struct_member();
	dsame_type_struct_member();
	use_array_member();
	return 0;
}
