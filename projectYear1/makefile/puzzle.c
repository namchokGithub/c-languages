/*Program name : Puzzle.c
Student name : Namchok Singhachai 
Student No. 60160169 Section 02
The projects of Software Engineering #7 BUU60*/
#include"puzzle.h"
int main(int argc, char *argv[])
{
	char choice; 										//declare variable
	do{ 												//condition (do_while) for menu
		system("clear");  										//clear screen 
		puzzle(); 										//calling function
		main_menu();
		time_t rawtime;					 				//search form Internet
    	time (&rawtime);
        printf("\t\t       %s\n",ctime(&rawtime));
		choice = getch(); 								//function getch(); //choose choice
		switch(choice){ 								//condition (switch case) for choose choice
			case '1': system("clear"); play(); break;   			//calling function
			case '2': system("clear"); how2play(); break;
			case '3': system("clear"); high_score(); break;
			case '4': system("clear"); credit(); break;
			default : printf("Please again...\n"); 		//another case
		}
	}while(choice != '5' ); 
	system("clear"); 
	mickey(); 											//calling function mickey
	return 0;
} //main
