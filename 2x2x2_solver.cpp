 #include<iostream>
#include<windows.h>
using namespace std;

void InputCube();
    int ColourToNum(char Colour);
bool IsCube();
    bool Different(int a,int b,int c);
bool ReadyCube();
string WhereBuffer();
    string AlgBlS(char buffer);
void SolveCube(string alg);
string FinalAlg(string alg);
int st[25];
string Y_Permutation="RuruRUrfRUrurFR",SolveAlg="";
bool iscube=1;
int main()
{
    START:
        string SolveAlg;
    system("cls");
    InputCube();
    if(IsCube())
    {
        while(!ReadyCube())
        {
            SolveAlg+=WhereBuffer();
            if(!IsCube()){cout<<"\tThis cube does not exist\n"; goto START;}
            SolveCube(SolveAlg);
        }
        cout<<FinalAlg(SolveAlg)<<endl;
    }
    else
    {
        cout<<"\tThis cube does not exist\n";
        goto START;
    }
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
    if(!iscube)return 0;
    for(int i=1;i<=24;i++)
        brC[st[i]]++;
    for(int i=1;i<=6;i++)
        if(brC[i]!=4)return 0;
    if(!Different(st[4],st[5],st[8]))return 0;
    if(!Different(st[3],st[6],st[9]))return 0;
    if(!Different(st[19],st[8],st[21]))return 0;
    if(!Different(st[7],st[12],st[22]))return 0;
    if(!Different(st[1],st[14],st[17]))return 0;
    if(!Different(st[15],st[20],st[24]))return 0;
    if(!Different(st[2],st[10],st[13]))return 0;
    if(!Different(st[11],st[16],st[23]))return 0;
    return 1;
}

    bool Different(int a,int b,int c)
    {
        if(a!=b && a!=c && b!=c)return 1;
        return 0;
    }

bool ReadyCube()
{
    for(int i=0;i<24;i=i+4)
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
        if();
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
            return '0';
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

void SolveAlg(string alg)
{
    int n=alg.size();
    char Help;
    for(int i=0;i<n;i++)
    {
        if(alg[i]=='')
    }
}

string FinalAlg(string alg)
{
    int n=alg.size();
    string FinalAlgorith="";
    for(int i=0;i<n;i++)
    {
        char d1,d2;
        d1=alg[i];
        d2=alg[i+1];
        if(abs(d1-d2)!= 32)
        {
            if(d1>96)
                {
                    FinalAlgorith+=d1-32;
                    FinalAlgorith+="\'";
                }
            else FinalAlgorith+=d1;
        }
        return FinalAlgorith;
    }
}
