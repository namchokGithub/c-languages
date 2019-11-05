#include<stdio.h>
#include<string.h>
void show(int s[4][4]);
void slideright(int data[4][4]);
void slideleft(int data[4][4]);
void slideunder(int data[4][4]);
void slideup(int data[4][4]);
int main()
{
    int Arry[4][4]= { {15,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12},
                      {13,14,1,16} };
    char choice;
    do{
	    show(Arry);
	    printf("\n\n\n");
	    printf("\t\t        / \\ \n");
	    printf("\t\t         |  \n");
	    printf("\t\t         8 \n");
	    printf("\t\t <-- 4       6  -->\n");
	    printf("\t\t         2  \n");
	    printf("\t\t         |  \n");
	    printf("\t\t         v \n");
	    printf("\n\n\tEnter '0' to exit\n");

	    choice = getch();
	   	system("cls");
	    switch(choice){
	    	case '8': slideup(Arry);		
	    	break;
	    	case '6': slideright(Arry);
	    	break;	
	    	case '2': slideunder(Arry);
	    	break;
	    	case '4': slideleft(Arry);
	    	break;
		}
	}while(choice!='0');
  	
    return 0;
}
void show(int s[4][4])
{
    int i,j;
	for(i=0;i<4;i++)
	{
				//printf("|---------------------------|\n");
				printf("\t _______ _______ _______ _______ \n");
				printf("\t|       |       |       |       |\n");
            for(j=0;j<4;j++){
                if(s[i][j]!=16){
                	printf("\t|");
                	printf("%4d",s[i][j]);
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
void slideright(int data[4][4])
{
    int i,j,temp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(data[i][j]==16){
            	if(j>0){
                    temp=data[i][j];
                    data[i][j]=data[i][j-1];
                    data[i][j-1]=temp;
                }
                else{
                	printf("\n\t\t\t\t\a*Can't do it\n\n");
				}
			break;
            }
        }
    }
}
void slideleft(int data[4][4])
{
    int i,j,temp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(data[i][j]==16){
            	if(j<3){
                    temp=data[i][j];
                    data[i][j]=data[i][j+1];
                    data[i][j+1]=temp;
                }
                else{
                	printf("\n\t\t\t\t\a*Can't do it\n\n");
				}
			break;
            }
        }
    }
}
void slideunder(int data[4][4])
{
    int i,j,temp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(data[i][j]==16){
            	if(i>0){
                    temp=data[i][j];
                    data[i][j]=data[i-1][j];
                    data[i-1][j]=temp;       
                }
                else{
                	printf("\n\t\t\t\t\a*Can't do it\n\n");
				}
			break;
            }
        }
    }
}
void slideup(int data[4][4])
{
    int i,j,temp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(data[i][j]==16){
            	if(i<3){
                    temp=data[i][j];
                    data[i][j]=data[i+1][j];
                    data[i+1][j]=temp;       
                }
                else{
                	printf("\n\t\t\t\t\a*Can't do it\n\n");
				}
			return;
            }
        }
    }
}
