#include <conio.h>
#include <iostream>
#include <windows.h>
 #include <stdio.h>

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

cout<<"\n\n\n\n\n\t\t\t\tLoading Database...";
cout<<"\t\t\t";
gotoxy(3,9);
printf("\t\t\t浜様様様様様様様様様様様様様様様様�");
gotoxy(3,10);
printf("\t\t\t紺旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�");
gotoxy(3,11);
printf("\t\t\t藩様様様様様様様様様様様様様様様様�");

for(int k=25;k<58;k++)
{
Sleep(30);
gotoxy(k,10);
printf("�");
}
Sleep(10);
cout<<endl;
return 0;
}
