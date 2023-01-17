#include<stdio.h>
/*
	sccanf的高级用法
	2.读指定宽度的数据 %[width]s
*/

int main63(int argc, char* argv[])
{
	char buf[100];
	sscanf("12345678","%s",buf);		// char* char* char* []
	printf("buf:%s\n",buf);

	int bufa;
	sscanf("12345678","%d",&bufa);		// int	&int
	printf("bufa:%d\n", bufa);	// int

	int bufb;
	sscanf("12345678", "%4d", &bufb);		// int	&int
	printf("bufb:%d\n", bufb);	// int

	return 0;
}
