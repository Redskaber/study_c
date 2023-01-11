#include<stdio.h>
#include<conio.h>	// _getch
#include<time.h>	// time_t ���� time

/*
	������Ϸ��
		1.����ַ� 
			1.srand(����) �����������
			2.rand()	  ��ȡ�����
		2.ʱ��
			1.time		time(NULL)
			2.time_t	����
		3.��ȡ���̼�ֵ�ַ�(���谴enter����getchar)
			_getch()		conio.h
			getchar()		�ȴ�
*/


void help()
{
	printf("\n***************************************************"); 
	printf("\n*����������޷��˳�!                              *");	
	printf("\n*�밴������ĸ�û�����!                            *");
	printf("\n*���������ʼ����,��������ĸʱ��ʼ��ʱ!           *"); 
	printf("\n*�����������_��ʾ!                               *");
	printf("\n***************************************************\n\n");

}


int main14() 
{
	char ch;
	char random_string[51] = "";		// ע�⣺����ĳ�����Ҫ��ԭʼ�����ϼ�1��ԭ���ǣ�ĩβ\0ռ��һ��������ʾ�ַ����������
	long late_time=NULL;
	while(1)
	{	
		system("cls"); // ÿ�����½��붼��տ���̨
		
		help();
		ch = _getch();		// ��ȡ���̰��µļ���ֵ��
		srand(time(NULL));	// �����������
		get_random_string(&random_string);	// ������������ַ����ŵ�random_string��ַ�� &random_string��
		printf("random_string: %s\n",random_string);

		int count = 0;

		printf("random_string: ");
		compare_random_string_and_input(&random_string,&count,&late_time);	// �����������룬���Ա���ȷ����

		float percent = ((count * 100.0) / 50);
		printf("\n��ȷ�ʣ�%f%c", percent, '%');
		printf("\n��ȷ������%d", count);
		printf("\n��ʱ����%ld��", late_time);
		
		while (1)
		{
			ch = _getch();
			if (ch == 32)	// space
			{
				break;
			}
			else if (ch == 27)	// ESC == 27
			{
				return;
			}
		}
	}
	return 0;
}

int compare_random_string_and_input(char* random_string, int* count, long* late_time)
{
	// �����������룬���Ա���ȷ����
	char ch, random;
	time_t start_time, end_time;		// ���弰ʱʱ��

	for (int i = 0; i < 50; i++)
	{	
		if (i == 0)
		{
			start_time = time(NULL);
		}
		else if (i == 49)
		{
			end_time = time(NULL);
		}

		ch = _getch();
		random = random_string[i];
		if (ch == random) {
			printf("%c", random);
			(*count)++;
		}
		else
		{
			printf("%c", '_');
		}
	}
	*late_time = (long)end_time - start_time;

	return 0;
}


int get_random_string(char* random_string)
{
	for (int i = 0; i < 50; i++)
	{
		random_string[i] = rand() % 26 + 'a';
	}
	random_string[50] = '\0';
	
	return 0;
}
