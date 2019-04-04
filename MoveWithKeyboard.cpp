#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<windows.h>
using namespace std;
int x1=2,y1=2,x2=2,y2=2;
void game(int x,int y)
{
    system("CLS");
    cout<<"TO QUIT PRESS ESCAPE"<<endl;
    if(x<1 || y<2 || y>81 || x>24){x=x2;y=y2;}
    for(int i=1;i<x;i++)
        cout<<endl;
    for(int j=2;j<y;j++)
        cout<<" ";
        cout<<"X";
        x1=x;
        y1=y;
        x2=x;
        y2=y;

}
int main()
{
    cout<<"TO QUIT PRESS ESCAPE"<<endl;
    cout<<"X"<<endl;
    START:
        char a;
        int k;
        a=getch();
        k=a;
        if(k==77 || k==72 || k==80 || k==75)
        {
            if(k==77)game(x1,y1+1);
            if(k==80)game(x1+1,y1);
            if(k==72)game(x1-1,y1);
            if(k==75)game(x1,y1-1);
            goto START;
        }
        else {

                if(k!=27)goto START;
                else {
                    return 0;
                }
             }
}
