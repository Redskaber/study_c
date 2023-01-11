#include<stdio.h>
#include<conio.h>	// _getch
#include<time.h>	// time_t 类型 time

/*
	打字游戏：
		1.随机字符 
			1.srand(种子) 设置随机种子
			2.rand()	  获取随机数
		2.时间
			1.time		time(NULL)
			2.time_t	类型
		3.获取键盘键值字符(无需按enter键：getchar)
			_getch()		conio.h
			getchar()		等待
*/


void help()
{
	printf("\n***************************************************"); 
	printf("\n*输入过程中无法退出!                              *");	
	printf("\n*请按所给字母敲击键盘!                            *");
	printf("\n*按任意键开始测试,按下首字母时开始计时!           *"); 
	printf("\n*输入出错则以_表示!                               *");
	printf("\n***************************************************\n\n");

}


int main14() 
{
	char ch;
	char random_string[51] = "";		// 注意：这里的长度需要在原始长度上加1，原因是：末尾\0占用一个，并表示字符组结束符。
	long late_time=NULL;
	while(1)
	{	
		system("cls"); // 每次重新进入都清空控制台
		
		help();
		ch = _getch();		// 获取键盘按下的键的值。
		srand(time(NULL));	// 设置随机种子
		get_random_string(&random_string);	// 将产生的随机字符组存放到random_string地址中 &random_string。
		printf("random_string: %s\n",random_string);

		int count = 0;

		printf("random_string: ");
		compare_random_string_and_input(&random_string,&count,&late_time);	// 监听键盘输入，并对比正确个数

		float percent = ((count * 100.0) / 50);
		printf("\n正确率：%f%c", percent, '%');
		printf("\n正确个数：%d", count);
		printf("\n总时长：%ld秒", late_time);
		
		while (1)
		{
			ch = _getch();
			if (ch == 32)	// space
			{
				break;
			}
			else if (ch == 27)	// ESC == 27
			{
				return;
			}
		}
	}
	return 0;
}

int compare_random_string_and_input(char* random_string, int* count, long* late_time)
{
	// 监听键盘输入，并对比正确个数
	char ch, random;
	time_t start_time, end_time;		// 定义及时时间

	for (int i = 0; i < 50; i++)
	{	
		if (i == 0)
		{
			start_time = time(NULL);
		}
		else if (i == 49)
		{
			end_time = time(NULL);
		}

		ch = _getch();
		random = random_string[i];
		if (ch == random) {
			printf("%c", random);
			(*count)++;
		}
		else
		{
			printf("%c", '_');
		}
	}
	*late_time = (long)end_time - start_time;

	return 0;
}


int get_random_string(char* random_string)
{
	for (int i = 0; i < 50; i++)
	{
		random_string[i] = rand() % 26 + 'a';
	}
	random_string[50] = '\0';
	
	return 0;
}
