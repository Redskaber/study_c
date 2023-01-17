#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

/*
	×Ö·û´®Æ¥Åäº¯Êı
		char* strstr(const char* haystack, const char* needle)

		×Ö·û´®ÖĞÕÒ×Ó×Ö·û´®

	·µ»ØÖµ£º
		- Æ¥ÅäÊ×µØÖ·
		- NULL
*/

void* use_strstr_getchildstr(const char* haystack, const char* needle)
{
	return strstr(haystack, needle);
}

void handle_print(char* s, char* p)
{
	printf("s:%p\n", s);
	printf("p:%p\n", p);
	// char* result = (p) ? (int)(p - s) : NULL;
	if (p) printf("p-s:%d\n",(int)(p-s));
	else printf("p is point NULL\n");

}

int main57()
{
	char* stemp = "000*9*0000*9*000";
	char* sfind1 = "*9*";
	char* sfind2 = "**";
	char* sfind3 = "00";
	char* p1 = (char*)use_strstr_getchildstr(stemp, sfind1);
	char* p2 = (char*)use_strstr_getchildstr(stemp, sfind2);
	char* p3 = (char*)use_strstr_getchildstr(stemp, sfind3);
	handle_print(stemp, p1);
	handle_print(stemp, p2);
	handle_print(stemp, p3);
	return 0;
}
