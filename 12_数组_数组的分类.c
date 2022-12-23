#include<stdio.h>


int main12()
{
	/*
	����Ķ��壺
		������һ���������ڴ档��ά���߼��ϵĶ�ά�������������ĵ�ַ�顣
	
	������ࣺ
		 Ԫ�����ͷ���
		 ά�ȷ���
	�����ʼ����
		��ȫ��ʼ��
		���ֳ�ʼ����ֻ����ĩ��δ��ʼ������Ĭ��0��䣩
	*/

	element_classifaction();
	dimension_classifaction();
	initial_case();

	int a[5] = { 1,2,3 };
	int size = (int)sizeof(a);
	int step = size / sizeof(int);

	printf("sizeof(a[5]={1,2,3}) %d\n", size);
	part_initial_case(a, step);

	return 0;

}

int element_classifaction()
{
	// Ԫ�ط���
	/*
		char
		short int long
		float double
		
		*point		// ָ������ 8�ֽ� 64λ
		struct

		char c[10];  // ����
		char c2[] = { 1,2,3,4,5 };	// δinit����size��С�ģ�Ĭ�Ͻ����θ�ֵ��size��Ϊzise��
	*/

	char c[10];  // ����
	char c2[] = { 1,2,3,4,5 };	// δinit����size��С�ģ�Ĭ�Ͻ����θ�ֵ��size��Ϊzise��	
	short s[10];
	int i[10];
	float f[10];

	printf("char c[10] sizeof: %d\n", (int)sizeof(c)); //10	
	printf("char c2[] sizeof: %d\n", (int)sizeof(c2)); //5
	printf("short s[10] sizeof: %d\n", (int)sizeof(s)); //20
	printf("int i[10] sizeof: %d\n", (int)sizeof(i));	//40
	printf("float f[10] sizeof: %d\n", (int)sizeof(f)); //40

	char* p = &c;	// point 
	char* cp[10];
	char* cp2[] = {p};

	printf("char* cp[10] sizeof: %d\n", (int)sizeof(cp)); //80
	printf("char* cp2[] sizeof: %d\n", (int)sizeof(cp2)); //8
	
	// struct

	return 0;
}

int dimension_classifaction()
{
	/*
		һά	char a[A];
		��ά	char a[A][B];
		��ά	char a[A]...[...];
	*/

	char a[100];		//һά
	char b[10][10];		//��ά
	char c[2][5][10];	//��ά...

	return 0;
}

int initial_case()
{
	/*
		��ȫ��ʼ��
		���ֳ�ʼ����ĩβ���0��
	*/

	int a[5] = { 1,2,3,4,5 };	// all
	int c[5] = { 1,2,3 };		// part

	return 0;
}

int part_initial_case(int a[], int step)
{
	// 8,ע��: ԭ���������a��a[]��ָ�룬���������a[]ָ��Ĵ�С��������a[]��size��
	printf("sizeof(a[5]={1,2,3}) %d\n", (int)sizeof(a));	

	for (int i = 0; i < step; i++)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}
	return 0;
}








