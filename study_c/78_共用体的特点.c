#include<stdio.h>

/*
	��������ص�:
	1��ͬһ�ڴ�ο���������ż��ֲ�ͬ���͵ĳ�Ա����ÿһ˲ʱֻ��һ��������
	2������������������õĳ�Ա�����һ�δ�ŵĳ�Ա���ڴ���һ���µĳ�Ա��ԭ�еĳ�Ա��ֵ�ᱻ����
	3������������ĵ�ַ�����ĸ���Ա�ĵ�ַ����ͬһ��ַ4������������ĳ�ʼ��
	union data a={123}; ��ʼ��������ֻ��Ϊ��һ����Ա��ֵ�����ܸ����г�Ա������ֵ
*/

typedef union 
{
	char a;
	int b;
}
Un_Case;

int main78()
{
	/*
		Un_Case _Case;
		_Case.b = 100;
	*/
	Un_Case _Case = {
		.b = 0xffffffff
	};
	printf("Un_Case _Case.b=%x\n",_Case.b);		// Un_Case _Case.b=ffffffff
	
	_Case.a = 0x00;
	printf("Un_Case _Case.a=%x\n",_Case.a);		// Un_Case _Case.a=0
	printf("Un_Case _Case.b=%x\n",_Case.b);		// Un_Case _Case.b=ffffff00

	return 0;
}

