#include<stdio.h>

#define PI 3.1415926	// �޽�꣨���ļ���ʹ�ã� ���������h�ļ��У�ֻҪʹ��h�ļ������ļ���Χ�ڼ���ʹ�á�(�Ƽ�ʹ�ô�д)
#define RANGE 10000	   // �н�꣨�ļ����ַ�Χ��

int main25()
{
	printf("#define PI %f\n",PI);
	printf("#undef %d\n",RANGE);
	#undef RANGE
	// printf("#undef %d\n", RANGE); // error

	return 0;
}

