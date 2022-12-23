#include<stdio.h>

/*
	选择性编译
		格式：
			#define Macro [...]		// 在本c文件中定义宏

			#ifdef Marco	// 如果在执行此命令前，本c文件定义了：宏(Marco)，则执行 handle one。
				handle one
			#else			// 没有定义
				handle two
			#endif			// 结束此次的选择性编译
		
		使用情景:
			当某种需要通过判断某种条件，决定需要某种功能时。（软件的裁剪）
*/

#define Marco // #define Marco [...]

int main27()
{	
	#ifdef Marco
		printf("hello world!\n");
	#else
		printf("hello china!\n");
	#endif
	
	return 0;
}
