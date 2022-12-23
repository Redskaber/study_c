#include<stdio.h>
/*
	选择性编译
		1.如果有
			#ifdef Macro
		2.如果没有
			#ifndef Macro
	两者之间时互补的，其中更多的是#ifndef
	用于避免头文件的多次展开，
	从而可能导致的各种错误。
	（
	#ifdef || #ifndef 都是可以相互嵌套的，
	其作用：
		类似与判断语句中if | if not,
		都是具备选择条件判断功能。
	区别于：
		#ifdef || #ifndef 是选择编译部分
		if || if not 是选择执行部分
	）
	注：h文件是在预编译时被展开替换的。

	格式:
		#ifndef __文件名_H__
			#define __文件名_H__
			#ifndef _变_量_名_
			#else
			#endif
		#else
			{
			}
		#endif

	复合性多条件：
		#if defined (A) && defined (B)
			#define START
		#elif defined (C)
			#define STEP
		#else
			{
				return _vfprintf_l(_Stream, _Format, NULL, _ArgList);
			}
		#endif

*/
#include"28_case_fun.h"
#include"28_case_fun.h"

#define Macro 1
#define case_w 0
int main()
{
	#if (Macro) && (case_w)
		printf("if");
	#elif Macro
		printf("elif");
	#else
		printf("else");
	#endif
	return 0;
}
