/*Program name : Puzzle.h
Student name : Namchok Singhachai 
Student No. 60160169 Section 02
The projects of Software Engineering #7 BUU60*/
#include<stdio.h> //declare header
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h> //search form Internet
#include <termios.h> //search form Internet
typedef struct{
	char name[10];
	char level[5];
	float time;
	int slide;
	int size;
}PLAYER;
void clear_data(); //declare function
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
void slideup(int size,int data[][size]);
int check( int size,int a[][size], int b[][size]);
float process_time(double a);
char playgame(int size,int arr1[][size],int arr2[][size],int slide,char name[],char level[],float time_show);
char getch();
char ready();
