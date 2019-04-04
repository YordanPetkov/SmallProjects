#include<iostream>
#include<string>
#include <algorithm>
#include<conio.h>
#define MAXN 30
using namespace std;

int minM=20,brM=0,st[25],copyst[25],NumberS,Counter;
string Nalg="";
bool iscube=1;
long long NumberD=-1;
string Alg;
int brC[7];

bool Different(int a,int b,int c)
    {
        if(a!=b && a!=c && b!=c)return 1;
        cout<<a<<" "<<b<<" "<<c<<endl;
        return 0;
    }

bool IsCube()
{
    if(!iscube){cout<<"123213421ISCUBE"<<"Nalg = "<<Nalg<<endl;return 0;}
    for(int i=1;i<=6;i++)
        brC[i]=0;
    for(int i=1;i<=24;i++)
        brC[st[i]]++;
    for(int i=1;i<=6;i++){
        if(brC[i]!=4){cout<<"0"<<endl;return 0;}cout<<"BR["<<i<<"] "<<brC[i]<<endl;}
    if(!Different(st[4],st[5],st[18])){cout<<"1"<<endl;return 0;}
    if(!Different(st[3],st[6],st[9])){cout<<"2"<<endl;return 0;}
    if(!Different(st[19],st[8],st[21])){cout<<"3"<<endl;return 0;}
    if(!Different(st[7],st[12],st[22])){cout<<"4"<<endl;return 0;}
    if(!Different(st[1],st[14],st[17])){cout<<"5"<<endl;return 0;}
    if(Different(st[15],st[20],st[24])==0){cout<<"6"<<endl;return 0;}
    if(!Different(st[2],st[10],st[13])){cout<<"7"<<endl;return 0;}
    if(!Different(st[11],st[16],st[23])){cout<<"8"<<endl;return 0;}
    return 1;
}


int ColourToNum(char Colour)
    {
        if(Colour=='y')return 1;
        if(Colour=='r')return 2;
        if(Colour=='g')return 3;
        if(Colour=='o')return 4;
        if(Colour=='b')return 5;
        if(Colour=='w')return 6;
        return 0;
    }
void InputCube()
{
    cout<<"\t                --- --- \n";
    cout<<"\t               | A | B |\n";
    cout<<"\t                --- ---\n";
    cout<<"\t               | D | C |\n";
    cout<<"\t                --- ---\n";
    cout<<"\t                 UPPER\n\n";
    cout<<"\t --- ---        --- ---        --- ---        --- --- \n";
    cout<<"\t| Q | R |      | E | F |      | I | J |      | M | N |\n";
    cout<<"\t --- ---        --- ---        --- ---        --- ---\n";
    cout<<"\t| T | S |      | H | G |      | L | K |      | P | O |\n";
    cout<<"\t --- ---        --- ---        --- ---        --- --- \n";
    cout<<"\t  RIGHT          FRONT           LEFT          BACK\n\n";
    cout<<"\t                --- --- \n";
    cout<<"\t               | U | V |\n";
    cout<<"\t                --- ---\n";
    cout<<"\t               | X | W |\n";
    cout<<"\t                --- ---\n";
    cout<<"\t                 DOWN\n\n";
    cout<<"\n";
    cout<<"Input the colours : y(yellow) , r(red) , g(green) , o(orange) , b(blue) , w(white).\n\n"<<endl;

    char co;
    for(int i=1;i<=24;i++)
    {
        char c='A'+i-1;
        cout<<"\t"<<c<<": ";cin>>co;st[i]=ColourToNum(co);if(st[i]==0)iscube=0;

    }
    for(int i=1;i<=24;i++)
        copyst[i]=st[i];


}


 char NumToColour(int Num)
    {
        if(Num==1)return 'y';
        if(Num==2)return 'r';
        if(Num==3)return 'g';
        if(Num==4)return 'o';
        if(Num==5)return 'b';
        if(Num==6)return 'w';
        return 0;
    }
void SolveCube(string alg)
{
    int n=alg.size();
    char Help;
    for(int i=0;i<n;i++)
    {
        if(alg[i]=='r'){
                        Help=st[7];st[7]=st[3];st[3]=st[13];st[13]=st[23];st[23]=Help;
                        Help=st[6];st[6]=st[2];st[2]=st[16];st[16]=st[22];st[22]=Help;
                        Help=st[9];st[9]=st[10];st[10]=st[11];st[11]=st[12];st[12]=Help;}
        if(alg[i]=='R'){Help=st[23];st[23]=st[13];st[13]=st[3];st[3]=st[7];st[7]=Help;
                        Help=st[22];st[22]=st[16];st[16]=st[2];st[2]=st[6];st[6]=Help;
                        Help=st[12];st[12]=st[11];st[11]=st[10];st[10]=st[9];st[9]=Help;}
        if(alg[i]=='l'){Help=st[5];st[5]=st[21];st[21]=st[15];st[15]=st[1];st[1]=Help;
                        Help=st[8];st[8]=st[24];st[24]=st[14];st[14]=st[4];st[4]=Help;
                        Help=st[17];st[17]=st[18];st[18]=st[19];st[19]=st[20];st[20]=Help;}
        if(alg[i]=='L'){Help=st[1];st[1]=st[15];st[15]=st[21];st[21]=st[5];st[5]=Help;
                        Help=st[4];st[4]=st[14];st[14]=st[24];st[24]=st[8];st[8]=Help;
                        Help=st[20];st[20]=st[19];st[19]=st[18];st[18]=st[17];st[17]=Help;}
        if(alg[i]=='f'){Help=st[4];st[4]=st[9];st[9]=st[22];st[22]=st[19];st[19]=Help;
                        Help=st[3];st[3]=st[12];st[12]=st[21];st[21]=st[18];st[18]=Help;
                        Help=st[5];st[5]=st[6];st[6]=st[7];st[7]=st[8];st[8]=Help;}
        if(alg[i]=='F'){Help=st[19];st[19]=st[22];st[22]=st[9];st[9]=st[4];st[4]=Help;
                        Help=st[18];st[18]=st[21];st[21]=st[12];st[12]=st[3];st[3]=Help;
                        Help=st[8];st[8]=st[7];st[7]=st[6];st[6]=st[5];st[5]=Help;}
        if(alg[i]=='b'){Help=st[2];st[2]=st[11];st[11]=st[24];st[24]=st[17];st[17]=Help;
                        Help=st[1];st[1]=st[10];st[10]=st[23];st[23]=st[20];st[20]=Help;
                        Help=st[13];st[13]=st[14];st[14]=st[15];st[15]=st[16];st[16]=Help;}
        if(alg[i]=='B'){Help=st[17];st[17]=st[24];st[24]=st[11];st[11]=st[2];st[2]=Help;
                        Help=st[20];st[20]=st[23];st[23]=st[10];st[10]=st[1];st[1]=Help;
                        Help=st[16];st[16]=st[15];st[15]=st[14];st[14]=st[13];st[13]=Help;}
        if(alg[i]=='u'){Help=st[5];st[5]=st[17];st[17]=st[13];st[13]=st[9];st[9]=Help;
                        Help=st[6];st[6]=st[18];st[18]=st[14];st[14]=st[10];st[10]=Help;
                        Help=st[1];st[1]=st[2];st[2]=st[3];st[3]=st[4];st[4]=Help;}
        if(alg[i]=='U'){Help=st[9];st[9]=st[13];st[13]=st[17];st[17]=st[5];st[5]=Help;
                        Help=st[10];st[10]=st[14];st[14]=st[18];st[18]=st[6];st[6]=Help;
                        Help=st[4];st[4]=st[3];st[3]=st[2];st[2]=st[1];st[1]=Help;}
        if(alg[i]=='d'){Help=st[8];st[8]=st[12];st[12]=st[16];st[16]=st[20];st[20]=Help;
                        Help=st[7];st[7]=st[11];st[11]=st[15];st[15]=st[19];st[19]=Help;
                        Help=st[21];st[21]=st[22];st[22]=st[23];st[23]=st[24];st[24]=Help;}
        if(alg[i]=='D'){Help=st[20];st[20]=st[16];st[16]=st[12];st[12]=st[8];st[8]=Help;
                        Help=st[19];st[19]=st[15];st[15]=st[11];st[11]=st[7];st[7]=Help;
                        Help=st[24];st[24]=st[23];st[23]=st[22];st[22]=st[21];st[21]=Help;}
    }
    /*for(int i=1;i<=24;i++){
    cout<<i <<" : "<<NumToColour(st[i])<<endl;
    cout<<i <<" : "<<NumToColour(copyst[i])<<endl;
    }
    getch();*/
}
bool ReadyCube()
{

    SolveCube(Nalg);
    for(int i=1;i<=21;i=i+4)
    {
        if(!(st[i]==st[i+1] && st[i]==st[i+2] && st[i]==st[i+3]))
        { for(int j=1;j<=24;j++)
        st[j]=copyst[j];return 0;}

    }
     for(int i=1;i<=24;i++)
        st[i]=copyst[i];
    return 1;
}

bool CubeIsSolved()
{
    Nalg="";
     int N=Alg.size();
    for(int i=0;i<N;i++)
    {
        if(Alg[i]=='0')Nalg+="R";
        if(Alg[i]=='1')Nalg+="L";
        if(Alg[i]=='2')Nalg+="F";
        if(Alg[i]=='3')Nalg+="B";
        if(Alg[i]=='4')Nalg+="U";
        if(Alg[i]=='5')Nalg+="D";

        if(Alg[i]=='6')Nalg+="r";
        if(Alg[i]=='7')Nalg+="l";
        if(Alg[i]=='8')Nalg+="f";
        if(Alg[i]=='9')Nalg+="b";
        if(Alg[i]=='A')Nalg+="u";
        if(Alg[i]=='B')Nalg+="d";

    }
    //reverse(Nalg.begin(),Nalg.end());
    if(ReadyCube())return 1;
    cout<<"Number = "<<NumberD<<" Alg = "<<Alg<<" Nalg = "<<Nalg<<endl;
    Alg="";
    return 0;
    //reverse(Nalg.begin(),Nalg.end());return 0;
}

void DecToSix(int Number)
{

    if(Number>11)DecToSix(Number/12);
    if(Number%12==10)Alg+='A';
    if(Number%12==11)Alg+='B';
    if(Number%12<10)Alg+=Number%6+'0';

}
bool Solving()

{
    //cout<<"Number = "<<NumberD<<" Alg = "<<Alg<<" Nalg = "<<Nalg<<endl;
    if(CubeIsSolved()){cout<<Nalg<<endl;exit(0);return 1;}


    return 0;
}
bool IsFailSix()
{

    string alg=Alg;
    int n=alg.size();
    for(int i=0;i<n-2;i++)
    {
        if(Alg[i]==Alg[i+1] && Alg[i]==Alg[i+2])return 1;
        if(abs(Alg[i]-Alg[i+1])==32)return 1;

    }

    for(int i=0;i<n-3;i++)
    if(Alg[i]==Alg[i+1] && abs(Alg[i+1]-Alg[i+2])==1 && Alg[i]==Alg[i+3])return 1;



    return 0;
}

string FinalAlg(string alg)
{
    int n=alg.size();
    string FinalAlgorith="";
    while(n>0)
    {
        //cout<<alg<<"   ALGLLAL"<<endl;
        //cout<<FinalAlgorith<<" FINALALG"<<endl;
        char d1,d2,d3,d4,help;
        d1=alg[0];
        if(1<n)d2=alg[1];
        if(2<n)d3=alg[2];
        if(3<n)d4=alg[3];
        //cout<<"N= "<<n<<endl;
        if(n==1)
        {
            if(d1>96)
                {
                    help=d1-32;
                    FinalAlgorith+=help;
                    FinalAlgorith+="\'";
                    alg.erase(0,1);n=n-1;continue;
                }
            else {alg.erase(0,1);n=n-1;FinalAlgorith+=d1;continue;}
        }
        if(abs(d1-d2)!= 32)
        {
            if(d1==d2 && d2==d3 && d3==d4)
            {
                alg.erase(0,4);n=n-4;
                continue;
            }
            else if(d1==d2 && d2==d3 )
            {
                alg.erase(0,3);n=n-3;
                if(d1>96)
                {
                    help=d1-32;
                    FinalAlgorith+=help;continue;
                }
                else
                {
                    FinalAlgorith+=d1;
                    FinalAlgorith+="\'";continue;
                }

            }
            else if(d1>96)
                {
                    help=d1-32;
                    FinalAlgorith+=help;
                    FinalAlgorith+="\'";
                    alg.erase(0,1);n=n-1;continue;
                }
            else {alg.erase(0,1);n=n-1;FinalAlgorith+=d1;continue;}
        }


if(abs(d1-d2)==32){alg.erase(0,2);n=n-2;continue;}


    }return FinalAlgorith;
}
int main()
{

    InputCube();cout<<endl;
    for(NumberD=0;NumberD<=10000000000000000;NumberD++)//
        {
            Nalg="";
            Alg="";
            DecToSix(NumberD);
            if(IsFailSix())continue;
            if(Solving())break;}

    cout<<FinalAlg(Nalg)<<endl;

    return 0;
}
//y y y y b b r r r r g g g g o o o o b b w w w w
