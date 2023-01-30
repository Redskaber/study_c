#include<stdio.h>


/*
	枚举类型的定义与枚举变量的定义
	枚举类型变量赋值本质是int数值，最好使用枚举定义的成员
*/

typedef enum enum_name{
	m1,m2,m3,m4,m5,m6,m7		// defaults 0
} enum_nick_name;

typedef enum enum_name2 {
	_m1=10, _m2, _m3, _m4=10, _m5, _m6, _m7
} enum_nick_name2;

int main79()
{
	enum_nick_name _case;

	printf("%d\n",sizeof(_case));	// 4
	_case = m1;
	printf("%d\n", _case);
	_case = m2;
	printf("%d\n", _case);
	_case = m3;
	printf("%d\n", _case);
	_case = m4;
	printf("%d\n", _case);
	_case = m5;
	printf("%d\n", _case);
	_case = m6;
	printf("%d\n", _case);
	_case = m7;
	printf("%d\n", _case);

	enum_nick_name2 _case2;

	printf("%d\n", sizeof(_case2));	// 4
	_case2 = _m1;
	printf("%d\n", _case2);
	_case2 = _m2;
	printf("%d\n", _case2);
	_case2 = _m3;
	printf("%d\n", _case2);
	_case2 = _m4;
	printf("%d\n", _case2);
	_case2 = _m5;
	printf("%d\n", _case2);
	_case2 = _m6;
	printf("%d\n", _case2);
	_case2 = _m7;
	printf("%d\n", _case2);




	return 0;

}
