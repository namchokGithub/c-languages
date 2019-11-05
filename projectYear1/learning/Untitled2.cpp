/*Program name : Puzzle.c
Student name : Namchok Singhachai 
Student No. 60160169 Section 02
The projects of Software Engineering #7 BUU60*/
#include<stdio.h>
#include<string.h>
#include<time.h>
void cls();
void main_menu();
void enter_name(char *name);
void micky();
void pluzzle();
float process_time(double a);
void play_case1();
void choose_game();
void how2play();
void high_score();
void about();
void show_easy(int s[][3]);
void show_normal(int s[][4]);
void show_hard(int s[][5]);
void easy();
void normal();
void hard();
void slideright_easy(int data[][3]);
void slideleft_easy(int data[][3]);
void slideunder_easy(int data[][3]);
void slideup_easy(int data[][3]);
void slideright_normal(int data[][4]);
void slideleft_normal(int data[][4]);
void slideunder_normal(int data[][4]);
void slideup_normal(int data[][4]);
void slideright_hard(int data[][5]);
void slideleft_hard(int data[][5]);
void slideunder_hard(int data[][5]);
void slideup_hard(int data[][5]);
int main(int argc, char *argv[])
{
	char choice;
	do{
		cls();
		pluzzle();
		main_menu();
	time_t rawtime;
    time (&rawtime);
        printf("\t       %s\n",ctime(&rawtime));
	choice = getch();
	if (choice < '0' && choice > '5'){
    		printf("Please again\n");
			choice = getch();
		}
	 switch(choice){
		case '1': 
				cls();
				play_case1();
				break;
		case '2': 	
				cls();
				how2play();
				break;
		case '3': 
				cls();
				high_score();
				break;
		case '4': 
				cls();
				about();
				break;
	 }
	}while(choice != '5' );
	cls();
	micky();
	return 0;
}
void play_case1()
{				  					   
    char choice;
    do{
    	cls();
    	printf("\n\t\t__________________\n");
    	printf("\t\t|   Choose Level  |\n");
    	printf("\t\t|                 |\n");
    	printf("\t\t| 1.Easy          |\n");
    	printf("\t\t|                 |\n");
    	printf("\t\t| 2.Normal        |\n");
    	printf("\t\t|                 |\n");
    	printf("\t\t| 3.Hard          |\n");
    	printf("\t\t|_________________|\n");
    	printf("\n\tPress X to exit\n");
    	choice = getch();
    	if (choice != '1' && choice != '2' && choice != '3' && choice != '4'){
    		choice = getch();
		}
		switch(choice){
			case '1': easy();
					break;
			case '2': normal();
					break;
			case '3': hard();
					break;
		}
	}while(choice != 'x' && choice != 'X');
}
void show_easy(int s[][3])
{
    int i,j;
	for(i=0;i<3;i++)
	{
				printf("\t _______ _______ _______ \n");
				printf("\t|       |       |       |\n");
            for(j=0;j<3;j++){
                if(s[i][j]!=9){
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
        printf("\t|_______|_______|_______|\n");
}
void show_normal(int s[][4])
{
    int i,j;
	for(i=0;i<4;i++)
	{
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
void show_hard(int s[][5])
{
    int i,j;
	for(i=0;i<5;i++)
	{
				printf("\t _______ _______ _______ _______ _______\n");
				printf("\t|       |       |       |       |       |\n");
            for(j=0;j<5;j++){
                if(s[i][j]!=25){
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
        printf("\t|_______|_______|_______|_______|_______|\n");
}
void slideright_easy(int data[][3])
{
    int i,j,temp;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(data[i][j] == 9){
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
void slideleft_easy(int data[][3])
{
    int i,j,temp;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(data[i][j]==9 ){
            	if(j<2){
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
void slideunder_easy(int data[][3])
{
    int i,j,temp;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(data[i][j]==9 ){
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
void slideup_easy(int data[][3])
{
    int i,j,temp;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(data[i][j]==9 ){
            	if(i<2){
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
void slideright_normal(int data[][4])
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
void slideleft_normal(int data[][4])
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
void slideunder_normal(int data[][4])
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
void slideup_normal(int data[][4])
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
void slideright_hard(int data[][5])
{
    int i,j,temp;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(data[i][j]==25){
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
void slideleft_hard(int data[][5])
{
    int i,j,temp;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(data[i][j] == 25){
            	if(j<4){
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
void slideunder_hard(int data[][5])
{
    int i,j,temp;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(data[i][j]==25){
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
void slideup_hard(int data[][5])
{
    int i,j,temp;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(data[i][j]==25){
            	if(i<4){
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
void about()
{
	cls();
	char ch;
	 printf("\n");
	 printf("                  MR.NAMCHOK SINGHACHAI\n\n");
	 printf("         179/1 Banna Kleang Rayong 21110 Thailand\n\n");	
	 printf("             Tel: 098-3534-191, 090-9847-751\n\n");
	 printf("               Email: 60160169@go.buu.ac.th\n\n");
	 printf("                 Email: pech4751@gmail.com\n\n");
	 printf("                Facebook: Namchok Singhachai\n\n");
	 printf("                    Line: Pech_namchok\n");
    printf("\n\nPress X to menu: ");
	while(ch != 'x' && ch != 'X'){
	 scanf("%c",&ch);
    }
}
void easy()
{
	time_t rawtime;
    time (&rawtime);
	FILE * In;
	float write_time;
	char choice;
    double time_end;
    time_t start,end;
    time (&start);
    char *player;
    enter_name(&player);
	int i,Arry[3][3] = {{ 6 , 1 , 3 },
                      { 8 , 7 , 5 },
                      { 4 , 2 , 9 }};
    do{
		show_easy(Arry);
		printf("\n");
		printf("\t\t_______________________\n");
		printf("\t\t|                     |\n");
		printf("\t\t|        Easy         |\n");
		printf("\t\t|_____________________|\n\n");
	/*    printf("\t\t|        / \\          |\n");
	    printf("\t\t|         |           |\n");
	    printf("\t\t|         w           |\n");
	    printf("\t\t| <-- a       d  -->  |\n");
	    printf("\t\t|         s           |\n");
	    printf("\t\t|         |           |\n");
	    printf("\t\t|         v           |\n");
	    printf("\t\t|_____________________|\n"); */
	    printf("\t      *** Please full screen ***");
	    printf("\n\tFinished !! (Press F)\n");
	    printf("\tPress X to exit\n");
	    choice = getch();
	   	cls();
	    switch(choice){
	    	case 'w': slideup_easy(Arry);		
	    	break;
	    	case 'd': slideright_easy(Arry);
	    	break;	
	    	case 's': slideunder_easy(Arry);
	    	break;
	    	case 'a': slideleft_easy(Arry);
	    	break;
	    	case 'f': cls();
						time (&end);
       					time_end = difftime (end,start);
       					In = fopen("Score_data.txt","a");
       					write_time = process_time(time_end);
       		if(time_end < 60 && time_end > 0){
       			printf("\t_______________________________\n");
      			printf("\t|                              |\n");
				printf("\t|Your time is %5.2f     seconds|\n",time_end);
				printf("\t|______________________________|\n");
				fprintf(In,"%s | %5.2f seconds | %s\n",*player,write_time,ctime(&rawtime));	
			}else {
			printf("\t_______________________________\n");
      		printf("\t|                              |\n");
			printf("\t|Your time is %5.2f     minutes|\n",time_end/60);
			printf("\t|______________________________|\n");
			fprintf(In,"%s | %5.2f minutes | %s\n",*player,write_time,ctime(&rawtime));	
			}
					fclose(In);
					choice = getch();
	    	break;
		}	
	}while(choice != 'x' && choice != 'X');
	time (&end);
}
void normal()
{
	time_t rawtime;
    time (&rawtime);
	FILE * In;
	float write_time;
	char choice;
    double time_end;
    time_t start,end;
    time (&start);
    char *player;
    enter_name(&player);
	int i,Arry[4][4] = {{11 , 2 , 4 , 3 },
                      { 8 , 6 , 5 , 7 },
                      { 9 ,13 ,15 ,12 },
                      {10 ,14 , 1 ,16 }};
	do{
		show_normal(Arry);
		printf("\n");
		printf("\t\t_______________________\n");
		printf("\t\t|                     |\n");
		printf("\t\t|        Normal       |\n");
		printf("\t\t|_____________________|\n\n");
	/*    printf("\t\t|        / \\          |\n");
	    printf("\t\t|         |           |\n");
	    printf("\t\t|         w           |\n");
	    printf("\t\t| <-- a       d  -->  |\n");
	    printf("\t\t|         s           |\n");
	    printf("\t\t|         |           |\n");
	    printf("\t\t|         v           |\n");
	    printf("\t\t|_____________________|\n"); */
	    printf("\t      *** Please full screen ***");
	    printf("\n\tFinished !! (Press F)\n");
	    printf("\tPress X to exit\n");
	    choice = getch();
	   	cls();
	    switch(choice){
	    	case 'w': slideup_normal(Arry);		
	    	break;
	    	case 'd': slideright_normal(Arry);
	    	break;	
	    	case 's': slideunder_normal(Arry);
	    	break;
	    	case 'a': slideleft_normal(Arry);
	    	break;
	    	case 'f': cls();
						time (&end);
       					time_end = difftime (end,start);
       					In = fopen("Score_data.txt","a");
       					write_time = process_time(time_end);
       		if(time_end < 60 && time_end > 0){
       			printf("\t_______________________________\n");
      			printf("\t|                              |\n");
				printf("\t|Your time is %5.2f     seconds|\n",time_end);
				printf("\t|______________________________|\n");
				fprintf(In,"%s | %5.2f seconds | %s\n",*player,write_time,ctime(&rawtime));	
			}else {
			printf("\t_______________________________\n");
      		printf("\t|                              |\n");
			printf("\t|Your time is %5.2f     minutes|\n",time_end/60);
			printf("\t|______________________________|\n");
			fprintf(In,"%s | %5.2f minutes | %s\n",*player,write_time,ctime(&rawtime));	
			}
					fclose(In);
					choice = getch();
	    	break;
		}	
		
	}while(choice != 'x' && choice != 'X');
	time (&end);
}
void hard()
{
	time_t rawtime;
    time (&rawtime);
	FILE * In;
	float write_time;
    double time_end;
    time_t start,end;
    time (&start);
    char choice, *player;
    enter_name(&player);
	int i,Arry[5][5] = {{ 6 , 2 ,13 ,25 ,20},
                      { 5 ,19 ,24 , 3 , 7},
                      {15 ,12 , 4 ,11 ,21},
                      { 1 ,14 , 8 , 9 ,22},
					  {17 ,16 ,18 ,10 ,23}};
    do{
		show_hard(Arry);
		printf("\n");
	 	printf("\t\t_______________________\n");
		printf("\t\t|                     |\n");
		printf("\t\t|        Hard         |\n");
		printf("\t\t|_____________________|\n\n");
	/*    printf("\t\t|        / \\          |\n");
	    printf("\t\t|         |           |\n");
	    printf("\t\t|         w           |\n");
	    printf("\t\t| <-- a       d  -->  |\n");
	    printf("\t\t|         s           |\n");
	    printf("\t\t|         |           |\n");
	    printf("\t\t|         v           |\n");
	    printf("\t\t|_____________________|\n"); */
	    printf("\t      *** Please full screen ***");
	    printf("\n\tFinished !! (Press F)\n");
	    printf("\tPress X to exit\n");
	    choice = getch();
	   	cls();
	    switch(choice){
	    	case 'w': slideup_hard(Arry);		
	    	break;
	    	case 'd': slideright_hard(Arry);
	    	break;	
	    	case 's': slideunder_hard(Arry);
	    	break;
	    	case 'a': slideleft_hard(Arry);
	    	break;
	    	case 'f': cls();
						time (&end);
       					time_end = difftime (end,start);
       					In = fopen("Score_data.txt","a");
       					write_time = process_time(time_end);
       		if(time_end < 60 && time_end > 0){
       			printf("\t_______________________________\n");
      			printf("\t|                              |\n");
				printf("\t|Your time is %5.2f     seconds|\n",time_end);
				printf("\t|______________________________|\n");
				fprintf(In,"%s | %5.2f seconds | %s\n",*player,write_time,ctime(&rawtime));	
			}else {
			printf("\t_______________________________\n");
      		printf("\t|                              |\n");
			printf("\t|Your time is %5.2f     minutes|\n",time_end/60);
			printf("\t|______________________________|\n");
			fprintf(In,"%s | %5.2f minutes | %s\n",*player,write_time,ctime(&rawtime));	
			}
					fclose(In);
					choice = getch();
	    	break;
		}	
	}while(choice != 'x' && choice != 'X');
	time (&end);
}
float process_time(double a)
{
		float min;
		if (a > 60 || a == 60){
			min = a / 60;
			return min;	
		} else {
			return a;
		}
}
void pluzzle()
{
	printf(" _______  ___      __   __  _______  _______  ___      _______ \n");  
	printf("|       ||   |    |  | |  ||       ||       ||   |    |       |\n");  
	printf("|    _  ||   |    |  | |  ||____   ||____   ||   |    |    ___|\n");  
	printf("|   |_| ||   |    |  |_|  | ____|  | ____|  ||   |    |   |___ \n");  
	printf("|    ___||   |___ |       || ______|| ______||   |___ |    ___|\n");  
	printf("|   |    |       ||       || |_____ | |_____ |       ||   |___ \n");  
	printf("|___|    |_______||_______||_______||_______||_______||_______|\n\n"); 

	printf("\t __    _  __   __  __   __  _______  _______  ______    \n");  
	printf("\t|  |  | ||  | |  ||  |_|  ||  _    ||       ||    _ |\n");  
	printf("\t|   |_| ||  | |  ||       || |_|   ||    ___||   | ||\n");  
	printf("\t|       ||  |_|  ||       ||       ||   |___ |   |_||_ \n");  
	printf("\t|  _    ||       ||       ||  _   | |    ___||    __  | \n");  
	printf("\t| | |   ||       || ||_|| || |_|   ||   |___ |   |  | |\n");  
	printf("\t|_|  |__||_______||_|   |_||_______||_______||___|  |_| \n\n"); 
}
void micky()
{
 printf("              $$$$$$$\n");
 printf("             $$$$$$$$$\n");
 printf("            $$$$$$$$$$$\n");
 printf("            $$$$$$$$$$$\n");
 printf("            $$$$$$$$$$$                $$$$$$$$       $$$$$$$$\n");
 printf("             $$$$$$$$$               $$$$$$$$$$$     $$$$$$$$$$$\n");
 printf("     $$$$$$     $$$$$$$$$$          $$$$$$$$$$$$$   $$$$$$$$$$$$$\n");
 printf("    $$$$$$$$  $$$$$$     $$$       $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
 printf("   $$$$$$$$$$$$$$$$         $      $$$$$$$$     $$$$$     $$$$$$$$\n");
 printf("   $$$$$$$$$$$$$$$$      $  $       $$$$$$$ Thank you for $$$$$$$\n");
 printf("   $$$$$$$$$$$$$$$$     $$$ $        $$$$$$$$$$ playing $$$$$$$$\n");
 printf("   $$$$$$$$$$$          $$$ $     $$  $$$$$$$$$$$    $$$$$$$$$$\n");
 printf("    $$$$$$$$$            $$ $$$$ $$$$   $$$$$$$$$$  $$$$$$$$$\n");
 printf("      $$$  $$  $$$              $$$$      $$$$$$$$$$$$$$$$$$\n");
 printf("           $$    $               $          $$$$$$$$$$$$$$\n");
 printf("           $$    $$$            $$            $$$$$$$$$$\n");
 printf("               $$$ $$$$$$ $$$$$                  $$$\n");
 printf("                $$    $$ $$$$$\n");
 printf("               $$$$$   $$$$$$$$$$\n");
 printf("               $$$$$$$$$$$$$$$$$$$$\n");
 printf("               $$ $$$$$$$$$$$$$$  $$\n");
 printf("               $$  $$$$$$$$$$$   $ $\n");
 printf("              $$$  $   $$$      $$$$\n");
 printf("              $$$ $          $$ $$$$\n");

}
void main_menu()
{
		printf("\t_______________________________________\n");
		printf("\t|               | Menu |              |\n");
		printf("\t|_______________|______|______________|\n");
		printf("\t|                                     |\n");
		printf("\t| 1.Play                              |\n");
		printf("\t|                                     |\n");
		printf("\t| 2.How to play                       |\n");
		printf("\t|                                     |\n");
		printf("\t| 3.Hight score                       |\n");
		printf("\t|                                     |\n");
		printf("\t| 4.Credits                           |\n");
		printf("\t|                                     |\n");
		printf("\t| 5.Exit                              |\n");
		printf("\t|_____________________________________|\n\n");
}
void how2play()
{
	cls();
	char ch;
	printf("\t___________________________________________________________\n");
	printf("\t|                      How to Play                         |\n");
	printf("\t|__________________________________________________________|\n");
	printf("\t|                                             /!\\          |\n");
	printf("\t|                                              |           |\n");
	printf("\t| 1. Press 'w' and enter for up                w           |\n");
	printf("\t| 2. Press 's' and enter for down      <-- a       d  -->  |\n");
	printf("\t| 3. Press 'd' and enter for right             s           |\n");
	printf("\t| 4. Press 'a' and enter for left              |           |\n");
	printf("\t|                                              v           |\n");
	printf("\t|__________________________________________________________|\n");
	printf("\n\nPress X to menu: ");
	while(ch != 'x' && ch != 'X'){
	 ch = getch();
    }
}
void high_score()
{
	cls();
	char ch,text;
	int result;
	FILE * in;
	printf("\t LEADERBOARD \n\n");
	in = fopen("Score_data.txt","r");
	result = fscanf(in,"%c",&text);
	while (result != EOF){
		printf("%c",text);
		result = fscanf(in,"%c",&text);
	}
	printf("\n\nPress X to menu: ");
	while(ch != 'x' && ch != 'X'){
	 ch = getch();
	}
	fclose(in);
}
void enter_name(char *name)
{
	printf("\t++ Please enter your name(10 char): ");
	scanf("%s",*name);
}
void cls(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
