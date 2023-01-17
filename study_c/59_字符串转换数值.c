#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:6387)
#pragma warning(disable:6328)
#pragma warning(disable:4996)
/*
	�ַ���ת����ֵ
		����	int atoi
		������	long atol
		������	double atof
	����ֵ��
		- ת������
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
	char*	str_store	=	(char*)calloc(length+1, sizeof(char));	// ��̬����
	memset( str_store, '\0', length);								// init
	char*	re_tostr	=	_itoa(to_int, str_store, decimal);		// ����תstring
	int		relength	=	strlen(re_tostr);

	free(str_store);		// �ͷ�
	str_store = NULL;		// ȥҰ

	return (
		(length == 1 && string == str_zreo) | (to_int && (length == relength))
		) ? 1 : 0;

}

void use_atoi_will_string_become_int(const char* string)
{
	/*
		int a = atoi(string);	// ����������"0"�������ǷǷ����ݣ�
	*/

	//Ԥ����
	int flag;
	flag = about_atoi_zreo_handle(string);
	if (flag == 0) printf("%s:������ǷǷ�����!\n",string);
	else printf("%s\n",string);
}

long use_atol(char* string)		// ����atol��Ҳһ���Ĵ���
{
	return atol(string);
}

double use_atof(char* string)	// ����atof��Ҳһ���Ĵ���
{
	return atof(string);
}

int main59()
{
	char* string1 = "1000";
	char* string2 = "1000q";
	char* string3 = "10q00";
	char* string4 = "q1000";	// 0	�Ƿ�
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
