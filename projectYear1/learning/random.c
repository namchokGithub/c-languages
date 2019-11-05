#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int main()
{
	int f,g,h,i,j,k,l,num;
	srand(time(NULL));
	
	int arry[4][4] = {{ 1 , 2 , 3 , 4 },
                      { 5 , 6 , 7 , 8 },
                      { 9 ,10 ,11 ,12 },
                      {13 ,14 ,15 ,16 }}; 
	for(h=0;h<20;h++){
			i = rand() % 4;
			j = rand() % 4;
			k = rand() % 4;
 			l = rand() % 4;
		//	printf("%d %d %d %d",i,j,k,l);
			num = arry[i][j];
			arry[i][j] = arry[k][l];
			arry[k][l] = num;	
	}	
	
	for(f=0;f<4;f++)
	{
				printf("\t _______ _______ _______ _______ \n");
				printf("\t|       |       |       |       |\n");
            for(g=0;g<4;g++){
                if(arry[f][g]!=16){
                	printf("\t|");
                	printf("%4d",arry[f][g]);
                }
                else{
                	printf("\t|");
                	printf("    ");
                }
            }
        printf("\t|\n");
        }
        printf("\t|_______|_______|_______|_______|\n");						
}	
