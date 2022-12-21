#include<stdio.h>


int main07()
{
	int num;
	int i = 3;

	num = before_increment(i);
	printf("num = before_increment(3): %d\n", num); // 9
	i = 3;
	num = after_increment(i);
	printf("num = after_increment(3): %d\n", num); // 18

	return 0;
}

int before_increment(incre)
{
	return (incre++) + (incre++) + (incre++);
}

int after_increment(incre)
{
	return (++incre) + (++incre) + (++incre);
}
