#include<stdio.h>
/*
   ����ָ�룺
        ����python�е�step���粽�߶ȣ�
        ���壺
            ���� (*����)[����֮����][...];
            int (*p)[3];
        ���
            �����Ǹ�ָ�룬ָ��һ�����飬��1��һ�����飬��ָ���¸����顣
*/

void modify_more_array(int(*p)[3], int x, int y)
{
    p[x][y] = 100;
}
void more_arrays_case();

int main38()
{
    int array[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    // ����һ��һά����ָ�롣����python�е�step���粽��С����
    int(*p)[3];
    p = array;
    printf("array:%p\n", array);
    printf("array+1:%p\n", array + 1);
    printf("p:%p\n", p);
    printf("p+1:%p\n", p + 1);

    printf("array:%p\t", &array[1][1]);
    printf("array:%d\n", array[1][1]);
    modify_more_array(array, 1,1);
    printf("array:%p\t", &array[1][1]);
    printf("array:%d\n", array[1][1]);

    /*

        printf("array:%p\t", (* (array + 1) + 1));
        printf("array:%d\n", *(* (array + 1) + 1));
        modify_more_array(array,1,1);
        printf("array:%p\t", ( * (array + 1) + 1));
        printf("array:%d\n", *( * (array + 1) + 1));
    */
    more_arrays_case();

    return 0;
}

void more_arrays_case()
{
    int a[2][3][2] = {
        {
            {1,2},{3,4},{5,6}
        },
        {
            {7,8},{9,10},{11,12}
        }
    };
    int(*p)[3][2];
    p = a;
    printf("a:%p\n",a);
    printf("a+1:%p\n",a+1);
    printf("p:%p\n",p);
    printf("p+1:%p\n",p+1);
}