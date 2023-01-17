#include<stdio.h>

/*
	格式化字符串操作函数
		1.格式化存入
		sprintf(char* buf, const char* format, ...);
		2.格式化读取
		sscanf(char* buf, const char* format, ...);

*/

int use_sprintf_data_format_to_array(char* buf[], const char* format, void* data,...)
{
	/*
		return: length(data);
	*/
	int* temp;
	int resp;
	temp = (int*)data;
	resp = sprintf(buf, format, temp[0], temp[1],temp[2]);
	return resp;
}

int use_sscanf_array_format_to_val(char* buf[], char* format, void* address[])
{
	/*
		return: length(data);
	*/
	int** addr = (int**)address;
	int resp;
	resp = sscanf(buf, format, addr[0],addr[1],addr[2]);
	return resp;
}

int main61()
{
	char buf[100];
	char* format = "%d:%d:%d";
	int data[] = { 2001,10,24 };
	// sprintf(buf,"%d:%d:%d",2001,10,24);
	
	int sprintfflag = use_sprintf_data_format_to_array(buf, format, data);
	printf("buf=%s, sprintfflag=%d\n", buf,sprintfflag);

	int a, b, c;
	int* address[] = {&a, &b, &c};
	int sccanfflag = use_sscanf_array_format_to_val(buf,format,address);
	printf("a:%d\tb:%d\tc:%d\t\tsccanfflag=%d\n", a, b, c, sccanfflag);
	
	return 0;
}




