#include<stdio.h>

/*
	int argc		params count
	char* argv[]	second pointer
*/


int main49(int argc, char* argv[])
{
	printf("argc:%d\n",argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d]=%s\n",i,argv[i]);
	}
	return 0;
}
