#include<stdio.h>

/*
	ѡ���Ա���
		��ʽ��
			#define Macro [...]		// �ڱ�c�ļ��ж����

			#ifdef Marco	// �����ִ�д�����ǰ����c�ļ������ˣ���(Marco)����ִ�� handle one��
				handle one
			#else			// û�ж���
				handle two
			#endif			// �����˴ε�ѡ���Ա���
		
		ʹ���龰:
			��ĳ����Ҫͨ���ж�ĳ��������������Ҫĳ�ֹ���ʱ��������Ĳü���
*/

#define Marco // #define Marco [...]

int main27()
{	
	#ifdef Marco
		printf("hello world!\n");
	#else
		printf("hello china!\n");
	#endif
	
	return 0;
}
