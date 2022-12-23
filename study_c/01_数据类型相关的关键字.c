#include<stdio.h>;
#include<limits.h>;
#include<float.h>;

/*
	printf:
		%c  char
		%s  string		   short  int   long   float double
		%d  int				%hd   %d    %ld
		%f  float								%f	 %lf
		%e	科学计数											%e    %E
		%u  unsigned		%hu   %u    %lu
		%o  ox(八进制)		%ho   %o    %lo
		%x	hex(十六进制)	%hx   %x    %lx
		%g
		%p	address			 &a 取址

	特殊应用:
		%3d: 要求宽度为3位，如果不足3位，前面空格补齐;如果足够3位，此语句无效
		%03d：要求宽度为3位，如果不足3位，前面0补齐;如果足够3位，此语句无效
		%-3d：要求宽度为3位，如果不足3位，后面空格补齐;如果足够3位，此语句无效
		%.2f: 小数点后只保留2位
*/

int main01()
{
	/*	
		测试数据类型相关的关键字		(64位)	(默认带符号,符号占一位)		数值溢出会截取高位
		1.char		1    8	range(-2^7, 2^7-1)						  -128 -- 127
		2.short		2    16	range(-2^15, 2^15 -1)					-32768 -- 32767
		3.int       4    32 range(-2^31, 2^31 -1) 			-2,147,483,648 -- 2,147,483,647 
		4.long      4    32 range(-2^31, 2^31 -1) 			-2,147,483,648 -- 2,147,483,647 
		5.long long 8    64 range(-2^63, 2^63 -1) 	-9223372036854775807i64 -1 -- 9223372036854775807i64
		6.float     4	 1(符号位) 8(指数位)  23(尾数位)		指数 -128 - 127			=> float  Range -2^(-128) - 2^(128) -1   精度组合（2^23）[6,7)位
		7.double    8    1(符号位) 11(指数位) 52(尾数位)		指数 -1024 - 1023		=> double Range -2^(-1024) - 2^(1024) -1 精度组合 (2^52) [15,16)位
		8.long double 8  具体看系统（64 window10）
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
		"float_size = sizeof(float) == %d; \n"				// 4	1(符号位) 8(指数位)  23(尾数位)  float  指数 -128 - 127   => float  Range -2^(-128) - 2^(128) -1   精度组合（2^23）[6,7)位
		"double_size = sizeof(double) == %d; \n"			// 8    1(符号位) 11(指数位) 52(尾数位)  double 指数 -1024 - 1023 => double Range -2^(-1024) - 2^(1024) -1 精度组合 (2^52) [15,16)位
		"long_double_size = sizeof(long double) == %d;\n"	// >=8, 根据不同的系统环境变化，精度比double高。

		"charpoint_size = sizeof(char*) == %d;\n"		// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"shortpoint_size = sizeof(short*) == %d;\n"		// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"intpoint_size = sizeof(int*) == %d;\n"			// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"longpoint_size = sizeof(long*) == %d;\n"		// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"longlongpoint_size = sizeof(long long*) == %d;\n"				// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"floatpoint_size = sizeof(float*) == %d;\n"						// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"doublepoint_size = sizeof(double*) == %d;\n"					// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。
		"longdoublepoint_size = sizeof(long double*) == %d;\n",			// 根据不同的系统环境变化，64位系统：8字节=64位,32位系统：4字节=32位。

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
	// 可以写作 short int， 但可以略写 short
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
	// -2147483648 => 2147483648 > 2147483647 => unsigned => 取反 => signed error

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
	float：
　　	  1bit（符号位） 8bits（指数位） 23bits（尾数位）
	double：
　　	  1bit（符号位） 11bits（指数位） 52bits（尾数位）

	于是，float的指数范围为-128~+127，而double的指数范围为-1024~+1023，并且指数位是按补码的形式来划分的。
　　	  其中负指数决定了浮点数所能表达的绝对值最小的非零数；而正指数决定了浮点数所能表达的绝对值最大的数，也即决定了浮点数的取值范围。
　　	  float的范围为-2^128 ~ +2^128，也即: -3.40E+38 ~ +3.40E+38；double的范围为-2^1024 ~ +2^1024，也即: -1.79E+308 ~ +1.79E+308。
	*/
	printf("float min %f, float max %E\n", FLT_MIN, FLT_MAX);	// float min 0.000000, float max 3.402823E+38
	printf("val:%f\n", 3.1234567890f);			// float 6位精确 000 000

	return 0;
}


int doublecase()
{
	printf("double min %E, double max %E\n", DBL_MIN, DBL_MAX);	// double min 2.225074E-308, double max 1.797693E+308
	printf("val:%lf\n", 3.1234567890);			// double 6位精确 000 000

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