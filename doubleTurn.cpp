 #include <iostream>
#include <windows.h>
#include <conio.h>
#include<ctime>
using namespace std;
int brzv,brmin;

int main()
{
//double t=clock();
if (kbhit())
       {
           char ch = getch();
           switch (ch)
           {
               case 27:               // press ESC to exit
                   system("cls");
                   brzv=0;
                   brmin=0;
                   break;
               case 32:               // press SPACE to clear screen
                   system("cls");
                   for(int j=0;j<brmin;j++)
                   cout<<'-';
                   cout<<'-';
                   brmin++;
                          cout<<endl;
                   for(int i=0;i<brzv;i++)
                   cout<< '*';
                   break;
           }
           cout << '*';
       brzv++;
       }
else
    {
       cout << '*';
       brzv++;

    }
       Sleep(800);
main();
   return 0;
}
