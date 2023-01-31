#include<stdio.h>
#include<stdarg.h>

/*
	变长参数的使用
		1.声明一个变长参数类型 va_list valist;
		va_start(valist)
		va_end(valist)


	#define va_start __crt_va_start
	#define va_arg   __crt_va_arg
	#define va_end   __crt_va_end
	#define va_copy(destination, source) ((destination) = (source))



	#elif defined _M_IX86 && !defined _M_HYBRID_X86_ARM64

	#define _INTSIZEOF(n)          ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

	#define __crt_va_start_a(ap, v) ((void)(ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)))
	#define __crt_va_arg(ap, t)     (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
	#define __crt_va_end(ap)        ((void)(ap = (va_list)0))
*/

double AverageNumber(int count,double number,...)
{
	va_list valist;		//typedef char* va_list;
	double _Sum=0.0;

	va_start(valist, count);	// start
	for(int i=0; i < count; i++ )
	{
		_Sum += va_arg(valist,double);
	}
	va_end(valist);			// end

	return (_Sum / count);
} 

int main88()
{
	double avg = AverageNumber(3,100.11,90.22,80.33);
	printf("%lf\n",avg);
	return 0;
}
