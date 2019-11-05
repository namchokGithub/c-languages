#include<stdio.h>
#include<time.h>
#include <stdlib.h>
void random(int size,int a[][size]);
int main()
{
	int i,j;
	int arry[4][4] = {{ 1 , 2 , 3 , 4 },
                      { 5 , 6 , 7 , 8 },
                      { 9 ,10 ,11 ,12 },
                      {13 ,14 ,15 ,16 }}; 
	random(4,arry);
	for(i=0;i<4;i++)
	{
				printf("\t _______ _______ _______ _______ \n");
				printf("\t|       |       |       |       |\n");
            for(j=0;j<4;j++){
                if(arry[i][j]!=16){
                	printf("\t|");
                	printf("%4d",arry[i][j]);
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
void random(int size,int a[][size])
{
		srand(time(NULL));
	int index1,index2,index3,index4,i,temp;
		for(i=0;i<20;i++){
			index1 = rand() % size;
			index2 = rand() % size;
			index3 = rand() % size;
 			index4 = rand() % size;
			temp = a[index1][index2];
			a[index1][index2] = a[index3][index4];
			a[index3][index4] = temp;	
	}	
}
