#include<stdio.h>
#include<stdarg.h>


int main13() 
{
	/*
		1.�ж������Ƿ�������
		2.�������������
		3.����������·�������
	*/

	// case_for_leap_year();
	// case_get_year_days();
	case_get_cuuracy_days();
}



int case_for_leap_year()
{	
	//1.�ж������Ƿ�������

	int flag, year;
	int* year_p = &year;		// year_p ָ�����year�ĵ�ַ��

	scanf_s_to_address(1, year_p);
	flag = is_leap_year(year);

	if (flag) 
	{
		printf("flag:%d, year:%d\n", flag, year);
	}
	else 
	{
		printf("this not's leap year! %d %d",flag,year);
	}
	return flag;
}


int case_get_year_days()
{	
	// 2.�������������
	int year,flag;
	int* year_p = &year;
	scanf_s_to_address(1, year_p);
	flag = is_leap_year(year);

	if (flag) 
	{
		printf("%d year is leap year, have 366 days.",year);
	}
	else
	{
		printf("%d year is not leap year, have 365 days.", year);
	}
	return 0;
}


int case_get_cuuracy_days()
{
	// 3.����������·�������
	int year, month, day, flag, sum;
	int* year_p = &year;
	int* month_p = &month;
	int* day_p = &day;
	char date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf_s_to_address(3, year_p, month_p, day_p);

	sum = day;
	for (int i = 0; i < month; i++)
	{
		sum += date[i];
	}

	flag = is_leap_year(year);
	if (flag)
	{
		sum += 1;
	}
	printf("%d %d %d -> %d", year, month, day, sum);

	return 0;
}


int is_leap_year(int year)
{
	return(year % 4 == 0)&&(year % 100 != 0) || (year % 400 == 0);	// return (0 false|1 true)
}

int scanf_s_to_address(int num,int* address, ...)	// ...����ʾ��ѡ���������stdargͷ�ļ�
{
	int flag;
	char* format = "%d";

	if (num > 1) 
	{	
		format = "%d %d %d";

		// ����һ���ɱ��������
		va_list args;
		// ָ��ָ�� �ɱ������ȷ��size��
		va_start(args, num);
		// ���ʿɱ������ַ��ÿ�η���ָ���Զ����ơ�
		int* year_p = va_arg(args, int*);				//int* year_pָ��ָ��year��ָ��
		int* month_p = va_arg(args, int*);
		int* day_p = va_arg(args, int*);
		
		flag = scanf_s(format, year_p, month_p, day_p);	// ����̨�� "%d"����ʽ�����ַ &address��ַ����
		printf(
			"*year_p:%d,year_p:%d, \n*month_p:%d,month_p:%d, \n*days_p:%d,days_p:%d\n",
			*year_p,(int)year_p, *month_p,(int)month_p, *day_p,(int)day_p
		);				// address ���ݣ�&address���ݵĴ洢��ַ

		va_end(args);	// ����ɱ��������
	}
	else
	{
		flag = scanf_s(format, address);	// ����̨�� "%d"����ʽ�����ַ &address��ַ����
		printf("*address:%d, address:%d\n", *address, (int)address);		// address ���ݣ�&address���ݵĴ洢��ַ
	}

	return flag;
}
