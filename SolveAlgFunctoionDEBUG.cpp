#include<iostream>
using namespace std;
int st[26];
bool iscube=1;
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
/*void SolveCube(string alg)
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
*/
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

int main()
{
    InputCube();
    string alg;
    cout<<"Vuvedi algorithuma : "<<endl;
    cin>>alg;
    SolveCube(alg);
    if(!iscube){cout<<"NQMA TAKOVA KUBCHE"<<endl;return 0;}
    for(int i=1;i<=24;i++)
    cout<<i <<" : "<<NumToColour(st[i])<<endl;
    return 0;
}
//y y y y r r r r g g g g o o o o b b b b w w w w
