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
bool ReadyCube();
string WhereBuffer();
    string AlgBlS(char buffer);
    string AlgOrM();
void SolveCube(string alg);
string FinalAlg(string alg);
int st[25];
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
        while(!ReadyCube())
        {
            hAlg=WhereBuffer();
            if(hAlg=="")break;
            SolveAlg+=hAlg;
                for(int i=1;i<=24;i++)
        cout<<i<<" "<<st[i]<<endl;
            cout<<"SolveAlg="<<SolveAlg<<endl;
            if(!IsCube()){cout<<"\tThis cube does not exist\n"; goto START;}
            SolveCube(SolveAlg);
        }
        cout<<"~~~~~~"<<FinalAlg(SolveAlg)<<"~~~~~~~~"<<endl;
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
    for(int i=1;i<=24;i++)
    {
        char c='A'+i-1;
        cout<<"\t"<<c<<": ";cin>>co;st[i]=ColourToNum(co);if(st[i]==0)iscube=0;

    }
    cout<<st[15]<<" "<<st[20]<<" "<<st[24]<<endl;

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

bool ReadyCube()
{
    for(int i=1;i<=24;i=i+4)
    {
        if(!(st[i]==st[i+1] && st[i]==st[i+2] && st[i]==st[i+3]))return 0;

    }
    return 1;
}

string WhereBuffer()
{
    char buffer;
    int SumB=0;

    SumB=st[1]+st[17]+st[14];
    cout<<SumB<<"SUMB"<<endl;
    switch(SumB)
    {
    case 8:
        if(st[1]==4 or st[17]==4 or st[14]==4)
        {
            if(st[1]==1)buffer='B';
            if(st[1]==3)buffer='J';
            if(st[1]==4)buffer='M';

        }
        else {
            if(st[1]==1)buffer='D';
            if(st[1]==2)buffer='E';
            if(st[1]==5)buffer='R';
        }
        break;
    case 10:
        if(st[7]+st[12]+st[22]!=11)
        {
            string HELPER;
            SolveCube(Y_Permutation);
            SolveAlg+=Y_Permutation;
            HELPER=WhereBuffer();
            SolveCube(HELPER);
            //SolveAlg+=;
            return HELPER;
        }
         else {return AlgOrM();}

            break;
    case 13:
        if(st[1]==4 or st[17]==4 or st[14]==4)
        {
            if(st[1]==4)buffer='P';
            if(st[1]==3)buffer='K';
            if(st[1]==6)buffer='W';

        }
        else {
            if(st[1]==5)buffer='S';
            if(st[1]==2)buffer='H';
            if(st[1]==6)buffer='U';
        }
        break;
    case 6 :
            if(st[1]==1)buffer='C';
            if(st[1]==2)buffer='F';
            if(st[1]==3)buffer='I';
            break;
    case 11:
            if(st[1]==6)buffer='V';
            if(st[1]==2)buffer='G';
            if(st[1]==3)buffer='L';
            break;
    case 15:
            if(st[1]==5)buffer='T';
            if(st[1]==6)buffer='X';
            if(st[1]==4)buffer='O';
            break;
    default :
            iscube=false;
            return "o";
    }
    return AlgBlS(buffer);
}

        string AlgBlS(char buffer)
        {
            string SetHelpAlg="",UndoHelpAlg="";
            if(buffer=='B'){SetHelpAlg="Rd";UndoHelpAlg="Dr";}
            if(buffer=='C'){SetHelpAlg="F";UndoHelpAlg="f";}
            if(buffer=='D'){SetHelpAlg="Fr";UndoHelpAlg="Rf";}
            if(buffer=='E'){SetHelpAlg="fD";UndoHelpAlg="dF";}
            if(buffer=='F'){SetHelpAlg="FFD";UndoHelpAlg="dFF";}
            if(buffer=='G'){SetHelpAlg="FD";UndoHelpAlg="df";}
            if(buffer=='H'){SetHelpAlg="D";UndoHelpAlg="d";}
            if(buffer=='I'){SetHelpAlg="r";UndoHelpAlg="R";}
            if(buffer=='J'){SetHelpAlg="RR";UndoHelpAlg="RR";}
            if(buffer=='K'){SetHelpAlg="R";UndoHelpAlg="r";}
            if(buffer=='M'){SetHelpAlg="rF";UndoHelpAlg="fR";}
            if(buffer=='O'){SetHelpAlg="dR";UndoHelpAlg="rD";}
            if(buffer=='P'){SetHelpAlg="d";UndoHelpAlg="D";}
            if(buffer=='R'){SetHelpAlg="FF";UndoHelpAlg="FF";}
            if(buffer=='S'){SetHelpAlg="FFr";UndoHelpAlg="RFF";}
            if(buffer=='T'){SetHelpAlg="DD";UndoHelpAlg="DD";}
            if(buffer=='U'){SetHelpAlg="f";UndoHelpAlg="F";}
            if(buffer=='V'){SetHelpAlg="fr";UndoHelpAlg="RF";}
            if(buffer=='W'){SetHelpAlg="RRF";UndoHelpAlg="fRR";}
            if(buffer=='X'){SetHelpAlg="Df";UndoHelpAlg="Fd";}
            return SetHelpAlg+Y_Permutation+UndoHelpAlg;
        }

        string AlgOrM()
        {
            cout<<"ORIGINAL METHOD"<<endl;
            return "";
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
