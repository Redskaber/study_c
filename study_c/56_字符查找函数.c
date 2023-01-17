#include<stdio.h>
#include<string.h>

/*
	�ַ����Һ���
		�״�ƥ��
			char* strchr(s1,c)			(str chr)
		ĩ��ƥ��		
			char* strrchr(s1,c)		��str reverse chr��
	���ؽ��
		�ҵ� �׵�ַ
		δ�ҵ�	NULL

*/

void* use_strchr_to_firstget(const char* s, int c)
{
	return strchr(s,c);
}

void* use_strrchr_endget(const char* s, int c)
{
	return strrchr(s, c);
}

void handle_printf(char* s, char* p)
{
	printf("s:%p\n", s);
	if (p) {
		printf("p:%p,\t%d\n", p, *p);
		printf("s-p:%d\n", (int)(s - p));
	}
}

int main56()
{
	char* s = "helloworldhelloworld";
	char* p1 =(char *)use_strchr_to_firstget(s,'w');
	char* p2 = (char*)use_strrchr_endget(s, 'w');
	char* p3 = (char*)use_strrchr_endget(s, 'word');	// �����һ���ַ���λ��
	char* p4 = (char*)use_strrchr_endget(s, 'z');		// NULL
	char* p5 = (char*)use_strrchr_endget(s, "hello");   // strchr && strrchr �ҵ���	"�ַ�"��-> NULL
	handle_printf(s, p1);
	handle_printf(s, p2);
	handle_printf(s, p3);
	handle_printf(s, p4);
	handle_printf(s, p5);
	/*
		s:00007FF6B09E2C10
		p:00007FF6B09E2C15,     119
		s-p:-5
		s:00007FF6B09E2C10
		p:00007FF6B09E2C1F,     119
		s-p:-15
		s:00007FF6B09E2C10
		p:00007FF6B09E2C23,     100
		s-p:-19
		s:00007FF6B09E2C10
		s:00007FF6B09E2C10
	*/
	return 0;
}