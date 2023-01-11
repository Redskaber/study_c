#include<stdio.h>
/*
   数组指针：
        类似python中的step（跨步尺度）
        定义：
            类型 (*名称)[数组之间跨度][...];
            int (*p)[3];
        概念：
            本身是个指针，指向一个数组，加1跳一个数组，即指向下个数组。
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

    // 定义一个一维数组指针。类似python中的step（跨步大小）。
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