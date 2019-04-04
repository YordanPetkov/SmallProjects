#include<iostream>
#include<windows.h> //  header file for gotoxy
 //#include <stdio.h>     //header file for standard input output
 #include <cstdlib>
using namespace std;
  COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 int main()
 {
     gotoxy(10,0);
     cout<<"Employee System";
     gotoxy(5,4);
     cout<<"Write your name: ";
     gotoxy(13,6);
     cout<<"Made by";
     gotoxy(10,7);
     cout<<"Yordan Petkov";
     string s;
     gotoxy(22,4);
     cin>>s;
     system("cls");
     gotoxy(10,0);
     cout<<"Employee System";
     gotoxy(5,4);
     cout<<"Write your name: "<<s;
     gotoxy(13,6);
     cout<<"Made by";
     gotoxy(10,7);
     cout<<"Yordan Petkov";
     return 0;
 }
