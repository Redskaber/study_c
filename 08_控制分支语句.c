#include<stdio.h>


void if_control()
{
	int score = 90;

	if (score >= 90)
	{
		printf("sccore>=90, %d\n", score);
	}
	else if (score >= 60)
	{
		printf("sccore>=60, %d\n", score);
	}
	else
	{
		printf("sccore<60, %d\n", score);
	}
}


void switch_control()
{
	/*
		scanf_s:��ȫ��׼���루�ڴ�й¶��
		scanf����׼����
	
	*/
	 int input;
	scanf_s("%d", &input);		//&input ȡ��ַ

	printf("&input: %p, input: %d\n", &input, input); // %p ��ַ

	switch (input) 
	{
	case 1:
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
	case 3:
	case 4:	
	case 5:
		printf("������-��\n");		// ��͸��
		break;
	default:
		printf("��������\n");
		break;
	}
}


int main08(int args, char * argv[]) {

	/*
		if 
		switch
	*/

	if_control();
	switch_control();

	return 0;
}



