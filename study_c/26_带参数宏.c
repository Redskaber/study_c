#include<stdio.h>

/*
	��������
		��ʽ�� #define ������(�β�,...) ���ʽ
		ps�� #define S(a,b) a*b	
	
	Ԥ����
		gcc -E hello.c -o hello.i		(ʹ�ú���βε�ʵ�Σ����滻�����ʽ�е��β�)
		ps��
			origin�� number = S(2,4);
			target�� number = 2 * 4 ;
	ע�⣺
		�������û�����͵ġ�
		�궨���β����Ҫ��;����
		��ֻ���滻�ββ�������������������
		ps��
			origin�� number = S(2+5,4);
			target�� number = 2+5 * 4 ;		// ��������ȼ� -> 22;
	
	�����Ŀӣ�
		ps�� #define S(a,b) (a)*(b)	
*/

#define S(a,b) (a)*(b)

int main26()
{
	int number = S(10+10, 20);
	printf("#define S(a,b) a*b: %d",number);
	return 0;
}
