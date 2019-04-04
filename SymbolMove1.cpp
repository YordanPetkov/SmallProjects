#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int x1=1,y1=1,x2=15,y2=50;
bool moves();
void visualGame(int x1,int y1,int x2,int y2);
int coutBG(string AEs);
void coutChar(int n,char c);
int main()
{

      system("cls");
      visualGame(x1,y1,x2,y2);
      int i=1;
      while(i==1)
      {
          if(!moves())i=2;

      }
      return 0;
}

bool moves()
{
    start:
    char turn;
    turn = getch();
    switch(turn)
    {
    case 27 :
        return false;
        break;
    case 72 :
        if(x1!=1)x1--;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 80 :
        if(x1!=15)x1++;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 75 :
        if(y1!=1)y1--;
         else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 77 :
        if(y1!=50)y1++;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 119 :
        if(x2!=1)x2--;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 115 :
        if(x2!=15)x2++;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 97 :
        if(y2!=1)y2--;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    case 100 :
        if(y2!=50)y2++;
        else
        {
            cout<<"\a";
            goto start;
        }
        break;
    default :
        goto start;
        break;
    }
    visualGame(x1,y1,x2,y2);
        return true;

}

void visualGame(int x1,int y1,int x2,int y2)
{
    system("cls");
    string con1="",con2="W S A D";
    char ch;
    ch=24;
    con1=con1+ch+" ";
    ch=25;
    con1=con1+ch+" ";
    ch=26;
    con1=con1+ch+" ";
    ch=27;
    con1=con1+ch;
    coutChar(35,' ');coutBG("ZDRAVEYTE");cout<<endl;
    coutChar(34,' ');coutBG("VIE IGRAETE");cout<<endl;
    coutChar(30,' ');coutBG("SIMVOLNO DVIJENIE 1");cout<<endl;
    cout<<endl;
    cout<<endl;
    coutChar(5,' ');coutChar(52,'*');cout<<endl;
    for(int i=1;i<=15;i++)
    {
        coutChar(5,' ');cout<<"*";
        for(int j=1;j<=50;j++)
        {
            if(x1 == x2 && y1==y2 && x1==i && y1==j)cout<<"#\a";
            else
            {
            if(i==x1 && j==y1)
            {
                cout<<"X";
            }
            else
                {
                    if(i==x2 && j==y2)
                    {
                        cout<<"Y";
                    }
                    else cout<<" ";
                }
            }
        }
        cout<<"*";
        if(i==1){coutChar(5,' ');coutBG("KONTROLITE SA :");}
        if(i==5){coutChar(4,' ');coutBG("IGRA4 1 X :");cout<<con1;}
        if(i==10){coutChar(4,' ');coutBG("IGRA4 2 ");cout<<"Y :"<<con2;}
        cout<<endl;
    }
    coutChar(5,' ');coutChar(52,'*');
    coutChar(23,' ');coutBG("AKO ISKA6 DA IZLEZE6 NATISNI escape");
}

void coutChar(int n,char c)
{
    for(int i=1;i<=n;i++)
        cout<<c;
}
int coutBG(string AEs)
{
    string BGs="";
    char c;
    int n=AEs.size();
    for(int i=0;i<n;i++)
    {
        if(AEs[i]==' '){c=' ';BGs=BGs+c;continue;}
        if(AEs[i]=='A'){c=128;BGs=BGs+c;continue;}//À
        if(AEs[i]=='B'){c=129;BGs=BGs+c;continue;}//Á
        if(AEs[i]=='V'){c=130;BGs=BGs+c;continue;}//Â
        if(AEs[i]=='G'){c=131;BGs=BGs+c;continue;}//Ã
        if(AEs[i]=='D'){c=132;BGs=BGs+c;continue;}//Ä
        if(AEs[i]=='E'){c=133;BGs=BGs+c;continue;}//Å
        if(AEs[i]=='J'){c=134;BGs=BGs+c;continue;}//Æ
        if(AEs[i]=='Z'){c=135;BGs=BGs+c;continue;}//Ç
        if(AEs[i]=='I'){c=136;BGs=BGs+c;continue;}//È
        if(AEs[i]=='Y'){c=137;BGs=BGs+c;continue;}//É
        if(AEs[i]=='K'){c=138;BGs=BGs+c;continue;}//Ê
        if(AEs[i]=='L'){c=139;BGs=BGs+c;continue;}//Ë
        if(AEs[i]=='M'){c=140;BGs=BGs+c;continue;}//Ì
        if(AEs[i]=='N'){c=141;BGs=BGs+c;continue;}//Í
        if(AEs[i]=='O'){c=142;BGs=BGs+c;continue;}//Î
        if(AEs[i]=='P'){c=143;BGs=BGs+c;continue;}//Ï
        if(AEs[i]=='R'){c=144;BGs=BGs+c;continue;}//Ð
        if(AEs[i]=='S'){c=145;BGs=BGs+c;continue;}//Ñ
        if(AEs[i]=='T'){c=146;BGs=BGs+c;continue;}//Ò
        if(AEs[i]=='U'){c=147;BGs=BGs+c;continue;}//Ó
        if(AEs[i]=='F'){c=148;BGs=BGs+c;continue;}//Ô
        if(AEs[i]=='H'){c=149;BGs=BGs+c;continue;}//Õ
        if(AEs[i]=='C'){c=150;BGs=BGs+c;continue;}//Ö
        if(AEs[i]=='4'){c=151;BGs=BGs+c;continue;}//×
        if(AEs[i]=='6'){c=152;BGs=BGs+c;continue;}//Ø
        if(AEs[i]=='^'){c=153;BGs=BGs+c;continue;}//Ù
        if(AEs[i]=='y'){c=154;BGs=BGs+c;continue;}//Ú
        if(AEs[i]=='!'){c=156;BGs=BGs+c;continue;}//Ü
        if(AEs[i]=='u'){c=158;BGs=BGs+c;continue;}//Þ
        if(AEs[i]=='Q'){c=159;BGs=BGs+c;continue;}//ß
        BGs=BGs+AEs[i];


    }
    cout<< BGs ;
    return BGs.size();
}
