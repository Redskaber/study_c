#include<stdio.h>

/*
	const :������ͨ����������ֻ������˼,����ʱ����ʼ����ֻ�ܶ����ܸġ�
*/


int main65(int argc, char* argv[])
{
	const int onlyread = 100;
	printf("onltyread:%d\n",onlyread);
	// onlyread = 1000;		// error
	printf("onltyread:%d\n",onlyread);
	return 0;
}

