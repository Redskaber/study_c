#include<stdio.h>


void if_control()
{
	int score = 90;

	if (score >= 90)
	{
		printf("sccore>=90, %d\n", score);
	}
	else if (score >= 60)
	{
		printf("sccore>=60, %d\n", score);
	}
	else
	{
		printf("sccore<60, %d\n", score);
	}
}


void switch_control()
{
	/*
		scanf_s:安全标准输入（内存泄露）
		scanf：标准输入
	
	*/
	 int input;
	scanf_s("%d", &input);		//&input 取地址

	printf("&input: %p, input: %d\n", &input, input); // %p 地址

	switch (input) 
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
	case 3:
	case 4:	
	case 5:
		printf("星期三-五\n");		// 穿透！
		break;
	default:
		printf("其他星期\n");
		break;
	}
}


int main08(int args, char * argv[]) {

	/*
		if 
		switch
	*/

	if_control();
	switch_control();

	return 0;
}



