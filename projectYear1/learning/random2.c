#include <stdio.h> /* printf() */  
#include <time.h> /* time() */  
#include <stdlib.h> /* srand(), rand() */  
  
int main()  
{  
    int i, t, pool[16], result[16];  
      
    /* Intializes random number generator */  
    srand(time(NULL));  
      
    /* Fill pool with 0..9 */  
    for(i=0;i<16;i++)  
        pool[i]=i;  
  
    /* Loop for result[0]..result[3] */  
    i=0;  
    while(i<16)  
    {  
        t=rand()%16+1;  
        if(pool[t])  
        {  
            result[i++]=pool[t];  
            pool[t]=0;  
        }  
    }  
      
    /* print result */  
    for(i=0;i<16;i++)  
        printf(" %d", result[i]);  
    printf("\n");  
  
    /* Calm down compiler */  
    return 0;  
}  
