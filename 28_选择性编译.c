#include<stdio.h>
/*
	ѡ���Ա���
		1.�����
			#ifdef Macro
		2.���û��
			#ifndef Macro
	����֮��ʱ�����ģ����и������#ifndef
	���ڱ���ͷ�ļ��Ķ��չ����
	�Ӷ����ܵ��µĸ��ִ���
	��
	#ifdef || #ifndef ���ǿ����໥Ƕ�׵ģ�
	�����ã�
		�������ж������if | if not,
		���Ǿ߱�ѡ�������жϹ��ܡ�
	�����ڣ�
		#ifdef || #ifndef ��ѡ����벿��
		if || if not ��ѡ��ִ�в���
	��
	ע��h�ļ�����Ԥ����ʱ��չ���滻�ġ�

	��ʽ:
		#ifndef __�ļ���_H__
			#define __�ļ���_H__
			#ifndef _��_��_��_
			#else
			#endif
		#else
			{
			}
		#endif

	�����Զ�������
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
