#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

int sizeArray;
int a[50];
int Move_pos,Move_count;
void InputN()
{
    int n;
    cout<<"\tVuvedete broq na kolonite\n";
    cin>>n;
    sizeArray=n;

}



void InputArray()
{

    cout<<"Vuvedete broq kutii v kolona s nomer :\n";
    for(int i=0;i<sizeArray;i++)
    {
        cout<<i<<" : ";cin>>a[i];cout<<"\n";
}
}

int NimSum_a()
{
      //cout<<"1111111"<<endl;
    int NimSum=0;
    for(int i=0;i<sizeArray;i++)
    {
        NimSum=NimSum^a[i];
      //  cout<<"11111112222222222"<<endl;
    }
     //cout<<"11111113333333333333"<<endl;
    if(NimSum==0)return 0;
    //cout<<"1111111444444444444"<<endl;
    return NimSum;
}

int PosOfLeftOne(int a, int b)
{
    if(a==0)return -2;
    string aa="",bb="";
    int asize,bsize;
    int k;
    while(a!=0)
    {
        if(a%2==0)aa+='0';
        else aa+='1';
        a/=2;
    }
    //cout<<"aa"<<aa<<endl;
    while(b!=0)
    {
        if(b%2==0)bb+='0';
        else bb+='1';
        b/=2;
    }
    //cout<<"bb"<<bb<<endl;
    asize=aa.size();
    bsize=bb.size();
    for(int i=asize-1;i>=0;i--)
    {
        if(aa[i]=='1'){k=i;break;}
        if(i==0)return -1;
    }
    if(bb[k]=='1')return k;
    return -1;
}

int SearchNimbit()
{
    //cout<<"2222222222"<<endl;
    int prom=NimSum_a(),k=0;
    for(int i=0;i<sizeArray;i++){
             //cout<<"22222222222322222222323"<<endl;
            k=PosOfLeftOne(prom,a[i]);
            if(k==-2)return -2;
    if(k!=-1)return i;
    }
    return 0;
    /*
    //
    int prom=NimSum_a(),k=0;
    //cout<<"2222222222333333333333"<<endl;
    if(prom==0)return 0;
    //cout<<"2222222222444444444444"<<endl;
    while(prom!=0)
    {
        prom/=2;
        k++;

       // cout<<"22222222225555555555555"<<endl;
    } cout<<"k=="<<k<<endl;
    for(int i=0;i<sizeArray;i++)
    {
       // cout<<"2222222222666666666666"<<endl;
        int k2=0,prom2=a[i];
        while(prom2!=0)
        {

            prom2/=2;
            k2++;
            //cout<<"22222222227777777777777"<<endl;
        }cout<<"k2=="<<k2<<endl;
       // cout<<"2222222222888888888888"<<endl;
        if(k2==k)
        {
           // cout<<"222222222299999999999"<<endl;
            Move_pos=i;
            cout<<"MOVEpos = i = "<<i<<endl;
            return i;
        }
    }*/
}


bool Move()
{
    //cout<<"3333333333"<<endl;
    int pos=SearchNimbit();
    //cout<<"POS = "<<pos<<endl;
    Move_pos=pos;
    if(pos==-2)return 0;
    int NimSum=NimSum_a()^a[pos];
    //cout<<"NimSum_a()^a[pos] = " <<NimSum<<endl;
    Move_count=a[pos]-NimSum;
    return 1;
}

bool ComputerMove()
{
    //cout<<"44444444"<<endl;
    if(!Move()){cout<<"NumSum=0 TI pe4eli6"<<endl;return 0;}
    cout<<"Vzemi "<<Move_count<<" ot kolona s nomer "<<Move_pos<<endl;
    getch();
    return 1;
}

int main()
{

    InputN();
    game:
    InputArray();

    if(!ComputerMove())return 0;
    for(int i=0;i<sizeArray;i++)
    {
        if(a[i]!=0){system("cls");goto game;}
    }



}
