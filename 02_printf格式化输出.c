#include<stdio.h>;

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

int main02()
{
	
	char char_a = 97;
	char* p = "hello world!";
	int int_a = 100;
	float float_a = 3.1234567890F;
	float float_b = 31415926;
	
	
	printf("char char_a = %c\n", char_a);					// %c
	printf("char* p = \"hello world!\"; > %s\n", p);		// %s
	printf("int int_a = 100; > %d\n", int_a);				// %d
	printf("float float_a = 3.1234567890; > %f\n", float_a);// %f
	printf("float float_b = 31415926; > %E\n", float_b);	// %E
	printf("int int_a = 100; > %o\n", int_a);				// %o
	printf("int int_a = 100; > %x\n", int_a);				// %x

	printf("int int_a = 100; > %05d\n", int_a);				// %左补数d
	printf("int int_a = 100; > %-5d\n", int_a);				// %右补数(空)d
	printf("int int_a = 100; > %.2f", float_a);				// %.小数点后f

	return 0;
}

