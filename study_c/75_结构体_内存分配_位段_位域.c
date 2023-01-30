#include<stdio.h>

/*
	结构体 内存分配 位段（位域）
		以位作为内存分配的单位，位只能在单一的存储单元中，不能跨存储单元
		
		ps: char a: 2;
		ps: char : 0;
		ps: char : 2;

		1.位 < len(char) | len([short | long] int)
		2.:位 = 0; 表示存储单元切换到下一个
		3.:位 = num; 表示后存储位空num个; 

*/

typedef struct {
	char a : 2;
	char b : 6;
	char c : 4;
	char d : 4;

} B_seg_1;


typedef struct {
	char a : 1;
	char b : 2;
	char c : 3;

} B_seg_2_1;

typedef struct {
	char a : 1;
	char b : 2;
	char : 0;
	char c : 3;

} B_seg_2_2;


typedef struct {
	char a : 1;
	char b : 2;
	char c : 3;

} B_seg_3_1;

typedef struct {
	char a : 1;
	char b : 2;
	char : 2;
	char c : 3;

} B_seg_3_2;

typedef struct {
	char a : 1;
	char b : 2;
	char : 3;
	char c : 3;

} B_seg_3_3;

typedef struct {
	//char a : 9;	// 不能超过类型位数
	char a : 8;	// 不能超过类型位数
	char b : 2;
	char c : 3;

} B_seg_1_2;

int main75(int argc, char* argv[])
{

	B_seg_1 test1;
	printf("%d\n", sizeof(test1));	
	B_seg_1_2 test1_2;
	printf("%d\n", sizeof(test1_2));

	B_seg_2_1 test2_1;
	printf("%d\n",sizeof(test2_1));
	B_seg_2_2 test2_2;
	printf("%d\n", sizeof(test2_2));

	B_seg_3_1 test3_1;
	printf("%d\n", sizeof(test3_1));
	B_seg_3_2 test3_2;
	printf("%d\n", sizeof(test3_2));
	B_seg_3_3 test3_3;
	printf("%d\n", sizeof(test3_3));

	return 0;
}
