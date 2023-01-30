#include<stdio.h>
#pragma warning(disable:4996)		// x86 unsafe warning

/*
sccanf高级用法
	3.支持集合操作: 只支持获取字符串 （贪婪匹配）
		%[a-z]	尽可能多的匹配
		%[aBc]  匹配a、B、c中一员，贪婪性

		%[^aFc] 匹配非a Fc的任意字符，贪婪性
		%[^a-z] 表示读取除a-z 以外的所有字符		
*/

void use_include_Reget()
{
	char string[100];
	int get_number1 = sscanf("aabbAAccddCCeeaacFFcddeeyyzz", "%[a-eA-Z]", string);
	printf("string:%s\n", string);

	int get_number2 = sscanf("aabbcc ddeeaaccddeeyyzz", "%[a-eA-Z]", string);
	printf("string:%s\n", string);

	int get_number3 = sscanf("aabbccdd\0eeaaccddeeyyzz", "%[a-eA-Z]", string);
	printf("string:%s\n", string);

	int get_number4 = sscanf("aabbccACCSDddeeaaccddeeyyzz", "%[acbedA-C]", string);
	printf("string:%s\n", string);

}

void use_include_not_Reget()
{
	char string[100];
	int no_number1 = sscanf("aabbAAccddCCeeaacFFcddeeyyzz", "%[^f-zBD-Z]", string);
	printf("string:%s\n", string);

	int no_number2 = sscanf("aabbcc ddeeaaccddeeyyzz", "%[^f-zBD-Z]", string);
	printf("string:%s\n", string);

	int no_number3 = sscanf("aabbccdd\0eeaaccddeeyyzz", "%[^f-zBD-Z]", string);
	printf("string:%s\n", string);

	int no_number4 = sscanf("aabbccACCSDddeeaaccddeeyyzz", "%[^f-zBD-Z]", string);
	printf("string:%s\n", string);

}

int main64()
{
	use_include_Reget();
	use_include_not_Reget();

	return 0;
}



