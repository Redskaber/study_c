#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/*
	sccanf�ĸ߼��÷���ϰ
		���ԣ���ȡָ���ַ�֮���ֵ
		1.ʵ��strlen
		2.ʵ��strcpy
		3.ʵ��atoi
	��ϰ4:ʹ��sscanf��ȡ"[ti:�򵥰�]""����"]"֮�������.
	��ϰ5:ʹ��sscanf ��ȡ"[02:06.85]" 02��������ӣ�06�������룩�����ͱ���min��sec��.
	��ϰ6:ʹ��strchr ���������ַ���ͳ��"helloworldhelloworldhellowvorld���ַ������ַ�w�ĸ�����λ�á�
*/

void get_define_bewteen_value(char* store,const char src[], char* s, char* f)
{
	/*
		�ַ�ƥ��
	*/
	char* format = "%*[^#]#%[^@]";
	int get_number = sscanf(src,format,store);
	printf("get_number:%d,store:%s\n", get_number, store);
}

char* init_momery(int count)
{
	char* store;
	store = (char*)calloc(count, sizeof(char));
	return store;
}

int free_momery_and_pointer_null(char* p)
{
	free(p);
	p = NULL;
	return p == NULL ? 1 : 0;
}

unsigned int my_strlen(const char* _Str) 
{
	const char* temp;
	temp = _Str;
	while (*temp != '\0')
	{
		temp++;
	}
	return temp -_Str;
}

char* my_strcpy(char* dest, const char* srouce)
{
	char* _dest = dest;
	char* _temp = srouce;
	while (*_temp != '\0')
	{
		*_dest = *_temp;
		_dest++;
		_temp++;
	}
	*_dest = '\0';
	return _dest;
}

int my_atoi(const char* _Str)
{
	int resp = 0;
	char* temp;
	temp = _Str;
	while (*temp != '\0')
	{
		resp = resp * 10 + (*temp - '0');
		temp++;
	}
	return resp;
}


char* use_set_and_match(const char* _Str, const char* format)
{
	char* result;
	result = (char*)calloc(100, sizeof(char));
	char* temp = _Str;
	sscanf(_Str,format,result);
	return result;
}

void use_set_and_matchs(const char* _Str, const char* format, char* min, char* sec)
{
	char* temp = _Str;
	sscanf(_Str, format, &min, &sec);
}


int* get_world_and_index(const char* _Str, const char* world)
{
	char* temp = _Str;
	char* get_world;
	int count = 0;
	int world_index[100];
	while ((get_world=strstr(temp,world)) != NULL)
	{
		world_index[count] = (int)(get_world - _Str);
		temp = get_world + 1;
		count++;
	}
	world_index[count] = count;

	for (size_t i = 0; i <=count; i++)
	{
		printf("world_index:%d\n", world_index[i]);
	}
}


int main67()
{	
	char str[] = "123#helloworld@321";
	char* store = init_momery(100);

	get_define_bewteen_value(store,str,"#","@");
	int flag = free_momery_and_pointer_null(store);
	printf("free:%d\n",flag);

	int length = my_strlen(str);
	printf("str length:%d\n", length);

	char* dest = init_momery(100);
	my_strcpy(dest,"redskaber");
	printf("dest:%s\n",dest);

	int d = my_atoi("1234");
	printf("d:%d\n",d);

	char* get_chr = use_set_and_match("[ti:�򵥰�]", "%*[^:]%*c%[^]]");
	printf("get_chr:%s\n",get_chr);
	free_momery_and_pointer_null(get_chr);

	int min, sec;
	sscanf("[02:06.85]", "[%2d:%2d",&min,&sec);
	printf("min=%02d,sec=%02d\n",min,sec);
	
	get_world_and_index("helloworldhelloworldhelloworld","w");
	return 0;
}






