 #include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
#include<cmath>
using namespace std;

void InputCube();
    int ColourToNum(char Colour);
bool IsCube();
    bool Different(int a,int b,int c);
void FirstLayer();
bool ReadyCube();
string WhereBuffer();
    string AlgBlS(char buffer);
    string AlgOrM();
void SolveCube(string alg);
string FinalAlg(string alg);
int st[7][5],YOG,YGR,YRB,YBO,WOB,WBR,WRG,WGO;
string Y_Permutation="RuruRUrfRUrurFR",SolveAlg="";
bool iscube=1;
int main()
{
    START:
        cout<<"Press any key to continue"<<endl;
        getch();
        string SolveAlg,hAlg;
    system("cls");
    InputCube();
    if(IsCube())
    {
        FirstLayer();
    }
    else
    {
        cout<<"\tThis cube does not exist!\n";
        goto START;
    }
    exit(0);
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
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=3;j++){
                char c='A'+i-1;
                cout<<"\t"<<c<<": ";cin>>co;st[i][j]=ColourToNum(co);//if(st[i][j]==0)iscube=0;
        }

    }
    SetCorners();

}


    int ColourToNum(char Colour)
    {
        if(Colour=='y')return 0;
        if(Colour=='r')return 1;
        if(Colour=='g')return 2;
        if(Colour=='o')return 3;
        if(Colour=='b')return 4;
        if(Colour=='w')return 5;
        return 0;
    }
/*
int brC[7];
bool IsCube()
{
    if(!iscube){cout<<"123213421ISCUBE"<<endl;return 0;}
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

    bool Different(int a,int b,int c)
    {
        if(a!=b && a!=c && b!=c)return 1;
        cout<<a<<" "<<b<<" "<<c<<endl;
        return 0;
    }
*/
bool wbr=0,wrg=0,wgo=0,wob=0;

void FirstLayer()
{
    if(wbr==0)
    {

    }
}

bool ReadyCube()
{
    for(int i=0;i<=5;i=i+4)
    {

        if(!(st[i][0]==st[i][1] && st[i][1]==st[i][2] && st[i][2]==st[i][3]))return 0;

    }
    return 1;
}



void SetCorners()
{
    if(st[0][0]==0 && st[4][0]==4 && st[3][2]==3)
}


int& Corner(int C1,int C2,int C3)
{

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


//y g o y o w o o b y b y r b r r r g g g w b w w
//b y y y r r r r g g g g o o o o w b b y w w w b
//y r g b w w r r o b y g w o o g b o y g b w r y
//o g o b r b r b y y g g r y b o g w o y w w w r

