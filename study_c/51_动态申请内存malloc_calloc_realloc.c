#include<stdio.h>
#include<stdlib.h>

/*
*	stdlib.h
	动态申请内存
			fun			init		args
		1.malloc		未知		size
		2.calloc		0			nmemb,size
		3.realloc		
*/

void* use_malloc_start_space(size_t size)
{
	return malloc(size);
}

void* use_calloc_start_space(size_t nmemb, size_t size)
{
	return calloc(nmemb,size);
}

void* use_realloc_extend_or_shrink(int* p, size_t newsize)
{
	return realloc(p, newsize);
}

void use_free_release_memory(char** p)
{
	/*
		char**		char*	   char
		&	(*      &) (*      &) *
			 p		p   *p	   *p **p
	*/ 
	free(*p);
	*p = NULL;
}

case_realloc_explain() {
	char * array_calloc = (char*)use_calloc_start_space(25, 4);
	for (size_t i = 0; i < 25; i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%d\t", array_calloc[i]);	// 0
	}
	printf("\n");

	// extend
	use_realloc_extend_or_shrink(array_calloc, 120);
	for (size_t i = 0; i < 30; i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%d\t", array_calloc[i]);	// 0
	}
	printf("\n");

	//shrink
	use_realloc_extend_or_shrink(array_calloc, 80);
	for (size_t i = 0; i < 20; i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%d\t", array_calloc[i]);	// 0
	}
	printf("\n");

	printf("array_calloc:%p\n", array_calloc);
	use_free_release_memory(&array_calloc);
	printf("array_calloc:%p\n", array_calloc);
}

int main51()
{
	char* array_malloc;
	char* array_calloc;
	array_malloc = (char*)use_malloc_start_space(25 * 4);
	array_calloc = (char*)use_calloc_start_space(25, 4);

	for (size_t i = 0; i < 25; i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%d\t",array_malloc[i]);		// 未知
	}
	
	printf("\n");
	
	for (size_t i = 0; i < 25; i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%d\t", array_calloc[i]);	// 0
	}
	printf("\n");

	printf("array_malloc:%p\n", array_malloc);
	printf("array_calloc:%p\n", array_calloc);

	use_free_release_memory(&array_malloc);	// int* -> int**
	use_free_release_memory(&array_calloc);	// int* -> int**

	printf("array_malloc:%p\n", array_malloc);
	printf("array_calloc:%p\n", array_calloc);

	case_realloc_explain();

	return 0;
}
