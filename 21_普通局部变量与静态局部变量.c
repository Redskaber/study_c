#include<stdio.h>
/*
	��ͨ�ľֲ�����
		���÷�Χ ����ĺ����򸴺������
			int a =1;
			for(int i =1;;)
		�������ڣ�һ�ε�����ȫ�����򸴺����
	��̬�ֲ�����
		���÷�Χ ����ĺ����򸴺������
		�������ڣ���һ��������ֱ�����������
*/

void case_for_part_val(void)
{
	int number=1; // ÿһ�κ�������������
	printf("part val: number=%d\n",number);
	number++;
}

void case_for_part_static_val()
{
	static int number = 5;	// �ӱ�ע�ᵽ�������
	printf("part val: number=%d\n", number);
	number++;
}

int main21()
{
	for (short i = 0; i < 3; i++)
	{
		case_for_part_val();
	}
	for (short i = 0; i < 3; i++)
	{
		case_for_part_static_val();
	}
	return 0;
}