#include<stdio.h>
#pragma warning(disable:4996)		// x86 unsafe warning

/*
sccanf�߼��÷�
	3.֧�ּ��ϲ���: ֻ֧�ֻ�ȡ�ַ��� ��̰��ƥ�䣩
		%[a-z]	�����ܶ��ƥ��
		%[aBc]  ƥ��a��B��c��һԱ��̰����

		%[^aFc] ƥ���a Fc�������ַ���̰����
		%[^a-z] ��ʾ��ȡ��a-z ����������ַ�		
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



