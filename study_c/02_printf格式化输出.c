#include<stdio.h>;

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

	printf("int int_a = 100; > %05d\n", int_a);				// %����d
	printf("int int_a = 100; > %-5d\n", int_a);				// %�Ҳ���(��)d
	printf("int int_a = 100; > %.2f", float_a);				// %.С�����f

	return 0;
}

