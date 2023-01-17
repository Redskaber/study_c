#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:6387)
#pragma warning(disable:6328)
#pragma warning(disable:4996)
/*
	字符串转换数值
		整型	int atoi
		长整形	long atol
		浮点型	double atof
	返回值：
		- 转化后结果
		- 0
*/

int about_atoi_zreo_handle(const char* string)
{
	/*
		strlen() && atoi && _itoa && strlen && calloc && free 
			- length = 1 && string == "0";
			- length != 1
				strlen(string) ? strlen( (string)(atoi(string)) )
	*/
	int		decimal		=	10;
	int		to_int		=	atoi(string);
	int		length		=	strlen(string);
	char*	str_zreo	=	"0";
	char*	str_store	=	(char*)calloc(length+1, sizeof(char));	// 动态申请
	memset( str_store, '\0', length);								// init
	char*	re_tostr	=	_itoa(to_int, str_store, decimal);		// 重新转string
	int		relength	=	strlen(re_tostr);

	free(str_store);		// 释放
	str_store = NULL;		// 去野

	return (
		(length == 1 && string == str_zreo) | (to_int && (length == relength))
		) ? 1 : 0;

}

void use_atoi_will_string_become_int(const char* string)
{
	/*
		int a = atoi(string);	// 如果传入的是"0"，而不是非法数据？
	*/

	//预处理
	int flag;
	flag = about_atoi_zreo_handle(string);
	if (flag == 0) printf("%s:传入的是非法数据!\n",string);
	else printf("%s\n",string);
}

long use_atol(char* string)		// 对于atol，也一样的处理
{
	return atol(string);
}

double use_atof(char* string)	// 对于atof，也一样的处理
{
	return atof(string);
}

int main59()
{
	char* string1 = "1000";
	char* string2 = "1000q";
	char* string3 = "10q00";
	char* string4 = "q1000";	// 0	非法
	char* string5 = "0";		// 0	0
	char* string6 = "-120";		// -120
	char* string7 = "-120.2";		// -120
	use_atoi_will_string_become_int(string1);
	use_atoi_will_string_become_int(string2);
	use_atoi_will_string_become_int(string3);
	use_atoi_will_string_become_int(string4);
	use_atoi_will_string_become_int(string5);
	use_atoi_will_string_become_int(string6);
	use_atoi_will_string_become_int(string7);

	printf("use_atol:%ld\n", use_atol(string1));
	printf("use_atof:%lf\n", use_atof(string1));
	return 0;
}
