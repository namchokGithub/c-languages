#include <stdio.h>

#include <time.h>



int main()

{

	int i, j;

	double total;



	clock_t cstart, cend;



	cstart = clock();



// ส่วนทดสอบจับเวลา



	for(i = 0; i < 10000; ++i)

	{

		for(j = 0; j < 10000; ++j)

			printf("");

	}



// จบส่วนทดสอบ



	cend = clock();



	total = (cend - cstart) / CLK_TCK;



	printf("%lf second(s)\n", total);



	return 0;

}
