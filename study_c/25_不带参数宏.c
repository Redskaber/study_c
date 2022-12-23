#include<stdio.h>

#define PI 3.1415926	// 无界宏（单文件可使用） 这样存放在h文件中，只要使用h文件，此文件范围内即可使用。(推荐使用大写)
#define RANGE 10000	   // 有界宏（文件部分范围）

int main25()
{
	printf("#define PI %f\n",PI);
	printf("#undef %d\n",RANGE);
	#undef RANGE
	// printf("#undef %d\n", RANGE); // error

	return 0;
}

