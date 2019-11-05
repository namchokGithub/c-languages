/*Program name : Puzzle.c
Student name : Namchok Singhachai 
Student No. 60160169 Section 02
The projects of Software Engineering #7 BUU60*/

#include<stdio.h> //declare header
#include<string.h>
#include<time.h>
#include<stdlib.h>
//#include <unistd.h> //search form Internet
//#include <termios.h> //search form Internet

// Defind Struct of Player
typedef struct{
	char name[10];
	char level[5];
	float time;
	int slide;
	int size;
}PLAYER;

void clear_data(); //declare function
void cls();
void credit();
void enter_name(char name[]);
void high_score();
void how2play();
void main_menu();
void mickey();
void play();
void puzzle();
void rd_puzzle(int size,int a[][size]);
void rd_check(int size,int a[][size],int b[][size]);
void show_easy(int s[][3]);
void show_normal(int s[][4]);
void show_hard(int s[][5]);
void slideright(int size,int data[][size]);
void slideleft(int size,int data[][size]);
void slideunder(int size,int data[][size]);
void slideUp(int size,int data[][size]);
int check( int size,int a[][size], int b[][size]);
float process_time(double a);
char playgame(int size,int arr1[][size],int arr2[][size],int slide,char name[],char level[],float time_show);
char getch();
char ready();

// Main of programs
int main(int argc, char *argv[])
{
	char choice; 										// declare variable
	do{ 												// condition (do_while) for menu
		cls();  										// clear screen 
		puzzle(); 										// calling function load logo
		main_menu();									// calling function load menu

		time_t rawtime;					 				// function timer
    	time (&rawtime);
        printf("\t\t       %s\n",ctime(&rawtime));		// show time

		choice = getch(); 								// function getch(); //choose choice
		switch(choice){ 								// condition (switch case) for choose choice
			case '1': cls(); play(); break;   			// calling function menu play
			case '2': cls(); how2play(); break;			// calling function menu how to play
			case '3': cls(); high_score(); break;		// calling function menu show score
			case '4': cls(); credit(); break;			// calling function menu show credit
			default : printf("Please again...\n"); 		// another case
		}

	}while(choice != '5' ); 							// end loop do while when 'choice' not equal '5' (charactor)
	cls(); 
	mickey(); 											// calling function show mickey for TK
	return 0;
} // End of main

/*
 * Function main_menu()
 * is a function for show main menu
 */
void main_menu()
{
	FILE *in; 											//declare for open file
	int result; 										//declare for check EOF!
	char text; 											//declare for keep charactor form file
	in = fopen("main_menu.txt","r"); 					//open file "read"
	result = fscanf(in,"%c",&text); 					//check EOF! and keep charactor 

	while (result != EOF){  							//condition (while) for check EOF!
		printf("%c",text);  							//output data in file
		result = fscanf(in,"%c",&text); 				//check EOF! and keep charactor 
	}
	// load file menu
	printf("\n");
	fclose(in); 										//close file
} 
// ENd of main_menu 


/*
 * Function play()
 * is a function for show level of game and let player choose level for playing
 */
void play()
{				  	
	PLAYER easy,normal,hard;							// declare struct of player
	easy.size = 3;
	strcpy(easy.level,"Easy");							// set level is 'Easy'

	normal.size = 4;
	strcpy(normal.level,"Normal");						// set level is 'Normal'

	hard.size = 5;   
	strcpy(hard.level,"Hard");							// set level is 'Hard'

	int	arr_easy[3][3]	=  {{ 1 , 2 , 3 }, 				//declare arr for numbering of a game
							{ 4 , 5 , 6 },
							{ 7 , 8 , 9 }};
    int arr_normal[4][4] = {{ 1 , 2 , 3 , 4 },				 
							{ 5 , 6 , 7 , 8 },
							{ 9 ,10 ,11 ,12 },
							{13 ,14 ,15 ,16 }}; 
    int arr_hard[5][5] = {{ 1 , 2 , 3 , 4 , 5}, 
							{ 6 , 7 , 8 , 9 ,10},
							{11 ,12 ,13 ,14 ,15},
							{16 ,17 ,18 ,19 ,20},
							{21 ,22 ,23 ,24 ,25}};
    char choice,ck_exit; 								// declare for choose choice
    do{ 												// condition (do_while) for menu
    	cls(); 											// clear screen
    	FILE *in;										// declare for open file
		int result; 
		char text;										// declare for keep charector
		
		in = fopen("level.txt","r");
		result = fscanf(in,"%c",&text);
		while (result != EOF){
			printf("%c",text);
			result = fscanf(in,"%c",&text);
		}												// Banner of Level
		fclose(in);										// close file

    	printf("\n\t\t__________________\n"); 			// show menu level
    	printf("\t\t|   Choose Level  |\n");
    	printf("\t\t|                 |\n");
    	printf("\t\t| 1.Easy          |\n");
    	printf("\t\t|                 |\n");
    	printf("\t\t| 2.Normal        |\n");
    	printf("\t\t|                 |\n");
    	printf("\t\t| 3.Hard          |\n");
    	printf("\t\t|_________________|\n");
    	printf("\n\tPress X to exit\n");
    	choice = getch(); 								//	choose choice
		switch(choice){ 								//	condition (switch case) for choose choice
			case '1': 									//	calling function
					do{	
						ck_exit = playgame(easy.size,arr_easy,arr_easy,easy.slide,easy.name,easy.level,easy.time);
					}while(ck_exit != 'e');	break; 		
			case '2': 
					do{	
						ck_exit = playgame(normal.size,arr_normal,arr_normal,normal.slide,normal.name,normal.level,normal.time);
					}while(ck_exit != 'e');	break;
			case '3': 
					do{	
						ck_exit = playgame(hard.size,arr_hard,arr_hard,hard.slide,hard.name,hard.level,hard.time);
					}while(ck_exit != 'e');	break;
			default : printf("Please again...\n"); 		// another case
		}
	}while(choice != 'x' && choice != 'X');
} 
// End of function play

/*
 * Function 
 */
void how2play()
{
	char ch,text; 				//declare "ch" for choice exit //declare "text" for keep charactor form file
	FILE *in;											//declare for open file
	int result; 										//declare for check EOF!
	in = fopen("how2play.txt","r"); 					//openfile "read"
	result = fscanf(in,"%c",&text); 					//check EOF! and keep charector
	while (result != EOF){ 								//condition (while) for check EOF!
		printf("%c",text); 								//output data in file
		result = fscanf(in,"%c",&text); 				//condition (while) for check EOF!
	}
	printf("\n"); 
	fclose(in);											//close file
	printf("\n\nPress X to menu: "); 
	while(ch != 'x' && ch != 'X'){ 						//condition (while) for exit
	 ch = getch();
    }
} //how2play

/*
 * Function 
 */
void high_score()
{
	char ch,text; 			  //declare "ch" for choice exit //declare "text" for keep charactor form file
	int result; 										//declare for check EOF!
	FILE * in; 											//declare for open file
	cls(); 											//clear screen
    	FILE *in2;										//declare for open file
		int result2;
		char text2;										//declare for keep charector
		in2 = fopen("scoretable.txt","r");
		result = fscanf(in2,"%c",&text2);
		while (result2 != EOF){
		printf("%c",text2);
		result2 = fscanf(in2,"%c",&text2);
		}
		fclose(in2);										//close file
	in = fopen("Score_data.txt","r"); 					//open file "read"
	result = fscanf(in,"%c",&text); 					//check EOF! and keep charector
	if(result != EOF){  								//condition (if) for check data
		while (result != EOF){							//if have data will show
		printf("%c",text); 
		result = fscanf(in,"%c",&text);
		}
		clear_data();
	}else { 											//else show "No data..."
		printf("No data...\n");	
		printf("\n\nPress X to menu: ");
		while(ch != 'x' && ch != 'X'){ 					//condition (while) for exit
			ch = getch();
		}	
	}
	fclose(in); //close file
} //high_score

/*
 * Function 
 */
void credit()
{
	char ch,text; 				//declare "ch" for choice exit //declare "text" for keep charactor form file
	FILE *in; 											//declare for open file
	int result; 										//declare for check EOF!
	in = fopen("credit.txt","r"); 						//open file "read"
	result = fscanf(in,"%c",&text); 					//check file and keep charector
	while (result != EOF){ 								//condition (while) for check EOF!
		printf("%c",text); 								//output data in file
		result = fscanf(in,"%c",&text); 				//condition (while) for check EOF!
	}
	printf("\n");
	fclose(in); 										//close file
    printf("\n\nPress X to menu: ");
	while(ch != 'x' && ch != 'X'){ 						//condition (while) for exit
	 ch = getch();
    }
} //credit

/*
 * Function 
 */
void show_easy(int s[][3])
{
    int i,j; 											//declare for condition (for loop)
	for(i=0;i<3;i++) 									//condition (for) for show table of game easy EZ!
	{
		printf("\t _______ _______ _______ \n");
		printf("\t|       |       |       |\n");
        for(j=0;j<3;j++){ 
            if(s[i][j]!=9){ 							//condition (if) for check blank
               	printf("\t|"); 
               	printf("%4d",s[i][j]); 					//if != 9 show number
            }else{ 		
                	printf("\t|");
                	printf("    "); 					//else show blank
            }
        }
        printf("\t|\n");
    }
        printf("\t|_______|_______|_______|\n");
} //show_easy

/*
 * Function 
 */
void show_normal(int s[][4])
{
    int i,j; 											//declare for condition (for loop)
	for(i=0;i<4;i++) 									//condition (for) for show table of game normal
	{
		printf("\t _______ _______ _______ _______ \n");
		printf("\t|       |       |       |       |\n");
        for(j=0;j<4;j++){
            if(s[i][j]!=16){ 							//condition (if) for check blank
               	printf("\t|"); 
               	printf("%4d",s[i][j]); 					//if != 16 show number
            }else{ 
            	printf("\t|");
                printf("    "); 						//else show blank
            }
        }
        printf("\t|\n");
    }
    	printf("\t|_______|_______|_______|_______|\n");
} //show_normal

/*
 * Function 
 */
void show_hard(int s[][5])
{
    int i,j;											//declare for condition (for loop)
	for(i=0;i<5;i++)									//condition (for) for show table of game hard
	{
		printf("\t _______ _______ _______ _______ _______\n");
		printf("\t|       |       |       |       |       |\n");
        for(j=0;j<5;j++){							
            if(s[i][j]!=25){							//condition (if) for check blank
                printf("\t|");
                printf("%4d",s[i][j]); 					//if != 25 show number
            }else{
                printf("\t|");
                printf("    ");   						//else show blank
            }
        }
        printf("\t|\n");
        }
        printf("\t|_______|_______|_______|_______|_______|\n");
} //show_hard

/*
 * Function 
 */
void slideright(int size,int data[][size])
{
    int i,j,temp;										//declare for function slide
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(data[i][j] == (size * size) ){			//condition (if) for this number is blank (9-16-25)
            	if(j>0){								//if col > 0 
                    temp=data[i][j];					//blank --> temp
                    data[i][j]=data[i][j-1]; 			//replace blank with col -1 
                    data[i][j-1]=temp;					//blank --> col -1
                }else{ 									//when can't slide  
                	printf("\n\t  \a*Can't do it   \n\n");
				}
			break;
            }
        }
    }
} //slideright

/*
 * Function 
 */
void slideleft(int size,int data[][size])
{
    int i,j,temp;										//delare for function slide
    for(i=0;i<size;i++){								
        for(j=0;j<size;j++){							
            if(data[i][j]==(size * size)  ){			//condition (if) for this number is blank (9-16-25)
            	if(j<(size-1)){							//if col < (column of table)
                    temp=data[i][j];					//blamk --> temp
                    data[i][j]=data[i][j+1];			//replace blank with col +1
                    data[i][j+1]=temp;					//blank --> col+1
                }else{									//when can't slide
                	printf("\n\t  \a*Can't do it   \n\n");
				}
			break;
            }
        }
    }
} //slideleft

/*
 * Function 
 */
void slideunder(int size,int data[][size])
{
    int i,j,temp;										//declare for function slide
    for(i=0;i<size;i++){								
        for(j=0;j<size;j++){							
            if(data[i][j]==(size * size)  ){			//condition (if) for this number is blank (9-16-25)
            	if(i>0){								//if row > o
                    temp=data[i][j];					//blank --> temp
                    data[i][j]=data[i-1][j];			//replace blank with row -1
                    data[i-1][j]=temp;       			//blank --> row -1
                }else{									//when can't slide
              		printf("\n\t  \a*Can't do it   \n\n");
				}
			break;										
            }
        }
    }
} //slideunder

/*
 * Function 
 */
void slideUp(int size,int data[][size])
{
    int i,j,temp;										//declare for function slide
    for(i=0;i<size;i++){			
        for(j=0;j<size;j++){					
            if(data[i][j]==(size * size) ){				//condition (if) for this number is blank (9-16-25)
            	if(i<(size-1)){							//if row < (row of table)
                    temp=data[i][j];					//blank --> temp
                    data[i][j]=data[i+1][j];			//replace blank with row +1
                    data[i+1][j]=temp;       			//blank --> row+1
                }else{									//when can't slide
                	printf("\n\t  \a*Can't do it   \n\n");
				}
			return; 									//for else last row will go to first (error)
            }
        }
    }
} //slideUp

/*
 * Function 
 */
char playgame(int size,int arr1[][size],int arr2[][size],int slide,char name[],char level[],float time_show)
{
	time_t rawtime; 									//(time) search form Internet
    time (&rawtime);
    double time_end;
    time_t start,end;
	FILE * In; 											//declare for open file 
	slide = 0;											//set slide = o
	int count,ck_correct;									//declare for check amount of correct
	char choice,ck_ready;								//declare "choice" for play or exit  "ck_ready" for exit
	int i,j,ck_arr[size][size];
	for (i=0;i<size;i++){
		for(j=0;j<size;j++){
			ck_arr[i][j] = arr2[i][j];
		}
	}
    cls(); 												//clear screen
    enter_name(name); 									//function enter name
    cls();
	rd_check(size,arr1,ck_arr); 						//calling function for random table 
	cls();
	ck_ready = ready(); 								//calling function for ready!!
	count = 0;
	ck_correct = (size * size);
	if(ck_ready != 'a'){
	cls();										
	time (&start); 										//start timer
    do{ 												//condition (do_while) for play game
		if (size == 3){
			show_easy(arr1); 								//calling function for show table
		}else if (size == 4){
			show_normal(arr1); 
		}else if (size == 5){
			show_hard(arr1); 
		}
		printf("\n\tCorrect : %d/%d | silde: %d\n",count,ck_correct,slide); //show amount of channal correct and slide
		printf("\t_______________________\n");
		printf("\t                       \n");
		printf("\t        > %s           \n",level);
		printf("\t_______________________\n\n");
	    printf("\t*** Please full screen ***\n\n");
	    printf("\tGive up press X \n\n");
	    printf("\tFinished Press any key to continues...\n");
	    choice = getch();
	    count = check(size,arr1,ck_arr); 				//check amount of channal correct
	   	cls();
	    switch(choice){ 								//codition (switch case) for slide number and exit
	    	case 'w': slideUp(size,arr1); slide++; break;
	    	case 'd': slideright(size,arr1); slide++; break;	
	    	case 's': slideunder(size,arr1); slide++; break;
	    	case 'a': slideleft(size,arr1);	slide++; break;
	    	case 'W': slideUp(size,arr1); slide++; break;
	    	case 'D': slideright(size,arr1); slide++; break;	
	    	case 'S': slideunder(size,arr1); slide++; break;
	    	case 'A': slideleft(size,arr1);	slide++; break;
		}
		if(count == ck_correct){ 								//conditiom (if) for check if when you finish
			cls();
			time (&end);
       					time_end = difftime (end,start);
       					In = fopen("Score_data.txt","a"); //open file "write again"
       					time_show = process_time(time_end); //set easy.time form function process_time
       		if(time_end < 60 && time_end > 0){  		//condition (if) for check "second" and "minutes"
				printf("\n\n\t > Your time is %5.2f      seconds \n\n",time_end);
				printf("\t > Times of slide is %d      times \n",slide);
				fprintf(In," > Level %s \n",level);
				fprintf(In,"   %s | %d times | %5.2f seconds | %s\n",name,slide,time_show,ctime(&rawtime));	
			}else {
				printf("\n\n\t > Your time is %5.2f      minutes \n\n",time_end/60);
				printf("\t > Times of slide is %d      times \n",slide);
				fprintf(In," > Level %s \n",level);
				fprintf(In,"   %s | %d times | %5.2f minutes | %s\n",name,slide,time_show,ctime(&rawtime));
			}
				fclose(In);	 							//close file  
				printf("\n\tPress X to exit\n");
				while(choice != 'x' && choice != 'X'){	//condition (while) for exit
	 				choice = getch();}
			} 
	}while(choice != 'x' && choice != 'X');
	time (&end); 										//stop timer
	}
	return 'e';											//return for exit
} //playname

/*
 * Function 
 */
float process_time(double a)  								//receviev time form game ("a" = second)
{
		float min; 											//declare for convert second to minutes
		if (a > 60 || a == 60){								//condition (if) for check second or mintutes
			min = a / 60;									//if "a" > 60 or "a" = 60 set min = a / 60
			return min;										//return min (minutes)
		} else {
			return a;										//return a (second)
		}
} //process_time

/*
 * Function 
 */
void enter_name(char name[])								//receviev array from game (name == player[] in game)
{
	FILE *in;												//declare for open file
	int result;
	char text;												//declare for keep charector
	in = fopen("entername.txt","r");
	result = fscanf(in,"%c",&text);
	while (result != EOF){
		printf("%c",text);
		result = fscanf(in,"%c",&text);
	}
	fclose(in);												//close file
	printf("\n\t++ Please enter your name(10 char):  ");
	scanf("%s",name);
} //enter_name

/*
 * Function 
 */
void cls(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
} //cls

/*
 * Function 
 */
int check(int size,int a[][size], int b[][size])			
{
	int i,j,count=0;										//declare "count" for check table
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if (a[i][j] == b[i][j]){						//condition (if) for check table
				count++;									//if it match count +1
			}
		}
	}
	    return count;										//return count to game
} //check

/*
 * Function 
 */
char ready()												//use this for wait function random and return for exit loop
{
	FILE *in;												//declare for open file 
	int result;												//declare for check EOF!
	char text,ans[3] = "111";								//declare "text" for show text art "ans" for check exit
	in = fopen("ready.txt","r");							//open file "read"
	result = fscanf(in,"%c",&text);							//check EOF! and keep charector
	while (result != EOF){									//condition (while) for check EOF!
		printf("%c",text);									//show charector
		result = fscanf(in,"%c",&text);						//check EOF! and keep charector
	}
	printf("\n");
	fclose(in);												//close file 
	while(strcmp(ans,"yes") != 0 && strcmp(ans,"no") != 0){
		printf("\t Are you ready? (yes/no) : ");
		scanf("%s",ans);
	}
	if(strcmp(ans,"yes") != 0){							//condition (if) for check "ans"
		return 'a';
	} else return 'b';
}

/*
 * Function 
 */
void rd_puzzle(int size,int a[][size])
{
	int random,i;											//declare "random" for random choice
	srand(time(NULL));										//function random
	for(i=0;i<50;i++){										//condition (for loop) for random
		random = rand() % 9;								//random 0 - 9
		switch(random){										//condition (switch case) for random
			case 0 : slideright(size,a);					//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 1 : slideleft(size,a);						//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 2 : slideUp(size,a);						//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 3 : slideunder(size,a);					//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 4 : slideright(size,a);					//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 5 : slideUp(size,a);						//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 6 : slideunder(size,a);					//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 7 : slideleft(size,a);						//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 8 : slideright(size,a);					//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
			case 9 : slideUp(size,a);						//switch case random slide
				slideleft(size,a);
				slideUp(size,a);
				slideright(size,a);
				slideunder(size,a); break;
	 	}													//why many case? because it will not match between two table
	}
} //rd_puzzle

/*
 * Function 
 */
void rd_check(int size,int a[][size],int b[][size])
{
	int i,j;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if (a[i][j] == b[i][j]){					//condition (if) for when  two table is match it will random
					rd_puzzle(size,a);  					//calling function random
				}
			}
		}
}

/*char getch(){												//this function  for Linux
    //#include <unistd.h>   //_getch
    //#include <termios.h>  //_getch
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
 }*/ 
 //getchlinux

/*
 * Function 
 */
void clear_data()
{
	FILE *in;												//declare for open file
	int i,check=0;											//declare "check" for check amount of login admin
	char ch,ans[3] = "11",use[10]="11",pass[10]="11";
	while(strcmp(ans,"exit")!=0 && strcmp(ans,"edit")!=0 ){	//condition (while) for check "edit" and "exit"
		printf("Do you want to exit or edit? (exit/edit): ");
		scanf("%s",ans);
	}
	if(strcmp(ans,"edit") == 0){							//condition (if) for check "edit"
			strcmp(ans,"11");
			while(strcmp(ans,"yes")!=0 && strcmp(ans,"no")!=0 ){
			printf("Do you want to clear data? (yes/no): ");	
			scanf("%s",ans);
			}
		if(strcmp(ans,"yes") == 0){							//condition (if) for check "ues"
			while(check < 3){
				while(strcmp(use,"admin")!=0){
					check++;								//check +1
					printf("\t\tUsername: ");
	    			scanf("%s",use);
	    			if (check > 3) break;					//if check > 3 --> break
				}
				if (check > 3) {
					break;
				}else check = 0;
				while(strcmp(pass,"manzaza")!=0){
						check++;							//check +1
						printf("\t\tPassword: ");
	    				scanf("%s",pass);
	    				if (check > 3) break;				//if check > 3 --> break
				}
				if (strcmp(use,"admin") == 0 && strcmp(pass,"manzaza") == 0) 
					check = 0;  break;
			}
			if(check < 3){
				in = fopen("Score_data.txt","w");
				printf("Clear data completely...\n");
				printf("\n\nPress X to menu: ");
				while(ch != 'x' && ch != 'X'){
	 				ch = getch();
   	 			}
			}else {											//else check > 3 show try again later
				printf("Please try again later...");
				printf("\n\nPress X to menu: ");
				while(ch != 'x' && ch != 'X'){
	 				ch = getch();
   	 			}
			}
		}else printf("Data not clear...\n");
	}
} //clear_data

/*
 * Function 
 */
void puzzle()
{
	FILE *in;												//declare for open file
	int result;
	char text;												//declare for keep charector
	in = fopen("puzzle.txt","r");
	result = fscanf(in,"%c",&text);
	while (result != EOF){
		printf("%c",text);
		result = fscanf(in,"%c",&text);
	}
	printf("\n\n");
	fclose(in);												//close file
} //pluzzle

/*
 * Function 
 */
void mickey()
{
	FILE *in;												//declare for open file
	int result;
	char text;												//declare for keep charector
	in = fopen("mickey.txt","r");
	result = fscanf(in,"%c",&text);
	while (result != EOF){
		printf("%c",text);
		result = fscanf(in,"%c",&text);
	}
	fclose(in);												//close file
} //mickey
