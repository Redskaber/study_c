#include<stdio.h>
#include<stdlib.h>

/*
	�ڴ�Ķ�̬�������ͷ�
		1.malloc ����
		2.free   �ͷ�
*/


void free_malloc(int * array)	// &
{
	if (array)printf("ָ��δ�ͷţ�\n");
	if (array) {
		free(array);	// �ͷ��ڴ�
		array = NULL;	// �����Ұָ�롱
	}
	if (array == NULL)printf("ָ���ͷţ�\n");
}

int main50()
{
	int count;
	printf("�����붯̬���ɵ�int�ռ��С��\n");
	scanf_s("%d",&count);

	int* array = (int*)malloc(sizeof(int) * count);
	if (array == NULL) {
		printf("��̬�����ַʧ�ܣ�");
		return 0;
	}

	for (int i = 0; i < count; i++) { array[i] = i; }
	for (int i = 0; i < count; i++){ printf("array[%d]=%d\n",i,array[i]); }

	free_malloc(array);		// &

	return 0;
}

