
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(void)
{
int i;
struct tm *TimeStruc;
time_t nowtime;

time(&nowtime);
TimeStruc = localtime(&nowtime);
srand(TimeStruc->tm_sec);

for(i=0;i {};

printf("rand()=%d\n",rand()%100+1);
}

