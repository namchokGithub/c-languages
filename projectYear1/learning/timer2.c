#include <stdio.h>

#include <time.h>



int main()

{

	int i, j;

	double total;



	clock_t cstart, cend;



	cstart = clock();



// ��ǹ���ͺ�Ѻ����



	for(i = 0; i < 10000; ++i)

	{

		for(j = 0; j < 10000; ++j)

			printf("");

	}



// ����ǹ���ͺ



	cend = clock();



	total = (cend - cstart) / CLK_TCK;



	printf("%lf second(s)\n", total);



	return 0;

}
