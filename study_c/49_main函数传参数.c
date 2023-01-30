#include<stdio.h>

/*
	int argc		params count
	char* argv[]	second pointer
*/


int main49(int argc, char* argv[])
{
	/*
		argv[0] .exe path,
		other_argv [1-...]
	*/
	printf("argc:%d\n",argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d]=%s\n",i,argv[i]);
	}
	return 0;
}
