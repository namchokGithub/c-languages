/*
@Author: Mr.Suppakit Thongdee
@Website: www.sourcecode.in.th
*/

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>

//using namespace std;

//For Dev C++
void gotoxy(short x, short y){
     COORD pos = {x, y};
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main(int argc, char *argv[])
{
    time_t timer;
    struct tm * ptm;
    char ch;
    bool blExit=false;
    bool blStart=true;
    short time_hh=0;
    short time_mm=0;
    short time_ss=0;
    short sec=0;
    
    system("cls");
    printf("Program Timer (press's':Start/Stop, 'r':Reset, 'q':Exit)\n");
    
    while(!blExit){
                   
                   if(_kbhit()){
                                ch = getch();
                                if(ch=='q' || ch=='Q'){
                                           blExit = true;
                                }else if(ch=='r' || ch=='R'){
                                      time_hh=0;
                                      time_mm=0;
                                      time_ss=0;      
                                }else if(ch=='s' || ch=='S'){
                                      blStart = !blStart;
                                                 
                                }
                   }else{
                   time(&timer);
                   ptm = gmtime(&timer);
                   
                   if(sec != ptm->tm_sec && blStart){
                          sec = ptm->tm_sec;
                          time_ss = time_ss+1;
                          if(time_ss==60){
                                        time_ss=0;
                                        time_mm=time_mm+1;
                          }
                          if(time_mm==60){
                                        time_mm=0;
                                        time_hh=time_hh+1;
                          }
                          if(time_hh==24){
                                          time_hh=0;
                          }
                   }
                   
    
                   gotoxy(0,1);
                   printf("%02d:%02d:%02d", time_hh,time_mm,time_ss);
                    
                   Sleep(500);
                   }
                    
    }
    
    return 0;
    
}





