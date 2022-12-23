#include<stdio.h>
#include<math.h>


int main11()
{
	/*
		(1-999)水仙花数： ABC = A^3+B^3+C^3
		
	*/

	for (int i = 1; i < 1000; i++)
	{
		// 获取百、十、 个
		int mono, deaci, hund;
		mono = i % 10;
		deaci = (i / 10) % 10;
		hund = i / 100;
		int flag = is_narcissistic_number(i, mono, deaci, hund);

		if (flag) {
			printf(
				"hund=%d, deaci=%d, mono=%d\t"
				"\t%.1f\t+%.1f\t+%.1f\t=%d\n", 
				hund, deaci, mono,
				pow(hund,3),pow(deaci,3),pow(mono,3),i
			);
		}
	}
	return 0;
}

int is_narcissistic_number(int origin, int mono, int deaci, int hund)
{
	return origin == pow(mono,3)+pow(deaci,3)+pow(hund,3);
}



