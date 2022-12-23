#include<stdio.h>
#include<stdarg.h>


int main13() 
{
	/*
		1.判断输入是否是闰年
		2.求输入年份天数
		3.求输入年份月份日天数
	*/

	// case_for_leap_year();
	// case_get_year_days();
	case_get_cuuracy_days();
}



int case_for_leap_year()
{	
	//1.判断输入是否是闰年

	int flag, year;
	int* year_p = &year;		// year_p 指向的是year的地址。

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
	// 2.求输入年份天数
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
	// 3.求输入年份月份日天数
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

int scanf_s_to_address(int num,int* address, ...)	// ...：表示可选参数，结合stdarg头文件
{
	int flag;
	char* format = "%d";

	if (num > 1) 
	{	
		format = "%d %d %d";

		// 声明一个可变参数序列
		va_list args;
		// 指针指向 可变参数并确定size。
		va_start(args, num);
		// 访问可变参数地址，每次访问指针自动后移。
		int* year_p = va_arg(args, int*);				//int* year_p指针指向year的指针
		int* month_p = va_arg(args, int*);
		int* day_p = va_arg(args, int*);
		
		flag = scanf_s(format, year_p, month_p, day_p);	// 控制台以 "%d"的形式输入地址 &address地址块中
		printf(
			"*year_p:%d,year_p:%d, \n*month_p:%d,month_p:%d, \n*days_p:%d,days_p:%d\n",
			*year_p,(int)year_p, *month_p,(int)month_p, *day_p,(int)day_p
		);				// address 数据，&address数据的存储地址

		va_end(args);	// 清除可变参数序列
	}
	else
	{
		flag = scanf_s(format, address);	// 控制台以 "%d"的形式输入地址 &address地址块中
		printf("*address:%d, address:%d\n", *address, (int)address);		// address 数据，&address数据的存储地址
	}

	return flag;
}
