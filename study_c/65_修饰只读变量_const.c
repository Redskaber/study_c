#include<stdio.h>

/*
	const :修饰普通变量，代表只读的意思,定义时，初始化后只能读不能改。
*/


int main65(int argc, char* argv[])
{
	const int onlyread = 100;
	printf("onltyread:%d\n",onlyread);
	// onlyread = 1000;		// error
	printf("onltyread:%d\n",onlyread);
	return 0;
}

