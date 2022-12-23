#include<stdio.h>;
#include<limits.h>;
#include<float.h>;

/*
	printf:
		%c  char
		%s  string		   short  int   long   float double
		%d  int				%hd   %d    %ld
		%f  float								%f	 %lf
		%e	��ѧ����											%e    %E
		%u  unsigned		%hu   %u    %lu
		%o  ox(�˽���)		%ho   %o    %lo
		%x	hex(ʮ������)	%hx   %x    %lx
		%g
		%p	address			 &a ȡַ

	����Ӧ��:
		%3d: Ҫ����Ϊ3λ���������3λ��ǰ��ո���;����㹻3λ���������Ч
		%03d��Ҫ����Ϊ3λ���������3λ��ǰ��0����;����㹻3λ���������Ч
		%-3d��Ҫ����Ϊ3λ���������3λ������ո���;����㹻3λ���������Ч
		%.2f: С�����ֻ����2λ
*/

int main01()
{
	/*	
		��������������صĹؼ���		(64λ)	(Ĭ�ϴ�����,����ռһλ)		��ֵ������ȡ��λ
		1.char		1    8	range(-2^7, 2^7-1)						  -128 -- 127
		2.short		2    16	range(-2^15, 2^15 -1)					-32768 -- 32767
		3.int       4    32 range(-2^31, 2^31 -1) 			-2,147,483,648 -- 2,147,483,647 
		4.long      4    32 range(-2^31, 2^31 -1) 			-2,147,483,648 -- 2,147,483,647 
		5.long long 8    64 range(-2^63, 2^63 -1) 	-9223372036854775807i64 -1 -- 9223372036854775807i64
		6.float     4	 1(����λ) 8(ָ��λ)  23(β��λ)		ָ�� -128 - 127			=> float  Range -2^(-128) - 2^(128) -1   ������ϣ�2^23��[6,7)λ
		7.double    8    1(����λ) 11(ָ��λ) 52(β��λ)		ָ�� -1024 - 1023		=> double Range -2^(-1024) - 2^(1024) -1 ������� (2^52) [15,16)λ
		8.long double 8  ���忴ϵͳ��64 window10��
	*/


	sizeofcase();

	int res1, res2;

	res1 = charcase();
	res2 = shortcase();

	intcase();
	floatcase();
	longcase();
	doublecase();
	longlongcase();
	longdoublecase();

	if (res1 == res2) {
		return 0;
	}
}


int sizeofcase()
{
	int char_size,short_size, int_size, long_size, long_long_size, float_size, double_size, long_double_size,
		charpoint_size, shortpoint_size, intpoint_size, longpoint_size,longlongpoint_size, floatpoint_size,doublepoint_size,longdoublepoint_size;
	
	char_size = sizeof(char);
	short_size = sizeof(short);
	int_size = sizeof(int);
	long_size = sizeof(long);
	long_long_size = sizeof(long long);
	float_size = sizeof(float);
	double_size = sizeof(double);
	long_double_size = sizeof(long double);

	charpoint_size = sizeof(char*);
	intpoint_size = sizeof(int*);
	shortpoint_size = sizeof(short*);
	longpoint_size = sizeof(long*);
	longlongpoint_size = sizeof(long long*);
	floatpoint_size = sizeof(float*);
	doublepoint_size = sizeof(double*);
	longdoublepoint_size = sizeof(long double*);

	printf(
		"char_size = sizeof(char)==%d;\n"				// 1		char range		 -2^7 - 2^7 -1
		"short_size = sizeof(short)==%d;\n"				// 2		short range		-2^15 - 2^15 -1
		"int_size = sizeof(int) == %d; \n"				// 4		int range		-2^31 - 2^31 -1
		"long_size = sizeof(long) == %d; \n"			// 4		long range		-2^31 - 2^31 -1
		"long_long_size = sizeof(long long) == %d;\n"		// 8	long long range -2^63 - 2^63 -1
		"float_size = sizeof(float) == %d; \n"				// 4	1(����λ) 8(ָ��λ)  23(β��λ)  float  ָ�� -128 - 127   => float  Range -2^(-128) - 2^(128) -1   ������ϣ�2^23��[6,7)λ
		"double_size = sizeof(double) == %d; \n"			// 8    1(����λ) 11(ָ��λ) 52(β��λ)  double ָ�� -1024 - 1023 => double Range -2^(-1024) - 2^(1024) -1 ������� (2^52) [15,16)λ
		"long_double_size = sizeof(long double) == %d;\n"	// >=8, ���ݲ�ͬ��ϵͳ�����仯�����ȱ�double�ߡ�

		"charpoint_size = sizeof(char*) == %d;\n"		// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"shortpoint_size = sizeof(short*) == %d;\n"		// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"intpoint_size = sizeof(int*) == %d;\n"			// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"longpoint_size = sizeof(long*) == %d;\n"		// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"longlongpoint_size = sizeof(long long*) == %d;\n"				// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"floatpoint_size = sizeof(float*) == %d;\n"						// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"doublepoint_size = sizeof(double*) == %d;\n"					// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��
		"longdoublepoint_size = sizeof(long double*) == %d;\n",			// ���ݲ�ͬ��ϵͳ�����仯��64λϵͳ��8�ֽ�=64λ,32λϵͳ��4�ֽ�=32λ��

		// base
		char_size,
		short_size,
		int_size,
		long_size,
		long_long_size,
		float_size,
		double_size,
		long_double_size,
		// point
		charpoint_size,
		shortpoint_size,
		intpoint_size,
		longpoint_size,
		longlongpoint_size,
		floatpoint_size,
		doublepoint_size,
		longdoublepoint_size
	);
}


int charcase()
{	
	char char1;
	char1 = 'a';
	char char2 = 'a';
	char char3 = 97;

	if (char1 == char2) {  // str == str2
		printf("char1==char2\n %c == %c\n", char1, char2);
		printf("char1='a', char3=97 => char1=%c, char3=%c\n", char1, char3);
	}

	printf("case_char1==%d, case_char2==%d\n", CHAR_MIN, CHAR_MAX);		// -128,127

	return 0;
}


int shortcase()
{	
	// ����д�� short int�� ��������д short
	short snumber;
	short snumber2 = 32767;			// max +(2^15)-1
	snumber = -32768;					// min -(2^15)

	printf("short min val is snumber=%d (-2^16), short max val is snumber2=%d (2^16-1)\n", SHRT_MIN, SHRT_MAX);  // -32768,32767

	return 0;
}


int intcase()
{
	int intnumber;
	int intnumber2 = 10;
	intnumber = 1;
	// -2147483648 => 2147483648 > 2147483647 => unsigned => ȡ�� => signed error

	printf("int min %d, int max %d\n", INT_MIN, INT_MAX);  //-2147483647-1, 2147483647

	return 0;
}


int longcase()
{	
	long longnumber;
	long longnumber2 = 10;
	longnumber = 20;

	printf("long min %d, long max %d\n", LONG_MIN, LONG_MAX); // //-2147483647L-1, 2147483647L
	return 0;
}


int longlongcase()
{
	long long longlongnumber;
	long long longlongnumber2 = 2;
	longlongnumber =1;

	printf("long long type min: %E, long long type max: %E", LLONG_MIN,LLONG_MAX); // -2^64 2^64 -1
	//#define LLONG_MAX     9223372036854775807i64
	//#define LLONG_MIN   (-9223372036854775807i64 - 1)
	
	return 0;
}


int floatcase()
{	
	/*
	float��
����	  1bit������λ�� 8bits��ָ��λ�� 23bits��β��λ��
	double��
����	  1bit������λ�� 11bits��ָ��λ�� 52bits��β��λ��

	���ǣ�float��ָ����ΧΪ-128~+127����double��ָ����ΧΪ-1024~+1023������ָ��λ�ǰ��������ʽ�����ֵġ�
����	  ���и�ָ�������˸��������ܱ��ľ���ֵ��С�ķ�����������ָ�������˸��������ܱ��ľ���ֵ��������Ҳ�������˸�������ȡֵ��Χ��
����	  float�ķ�ΧΪ-2^128 ~ +2^128��Ҳ��: -3.40E+38 ~ +3.40E+38��double�ķ�ΧΪ-2^1024 ~ +2^1024��Ҳ��: -1.79E+308 ~ +1.79E+308��
	*/
	printf("float min %f, float max %E\n", FLT_MIN, FLT_MAX);	// float min 0.000000, float max 3.402823E+38
	printf("val:%f\n", 3.1234567890f);			// float 6λ��ȷ 000 000

	return 0;
}


int doublecase()
{
	printf("double min %E, double max %E\n", DBL_MIN, DBL_MAX);	// double min 2.225074E-308, double max 1.797693E+308
	printf("val:%lf\n", 3.1234567890);			// double 6λ��ȷ 000 000

	return 0;
}


int longdoublecase()
{
	long double longdoublenumber;
	long double longdoublenumber2 = 3.12345678901234567890;
	longdoublenumber = 1.1234567890;
	printf("long double min: %E, long double max: %E\n",LDBL_MIN,LDBL_MAX); // 64 window10  ==> double
	printf("long double range:%lf", longdoublenumber2);   // 64 window10  ==> double

	return 0;
}