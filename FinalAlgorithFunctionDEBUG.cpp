#include<iostream>
#include<windows.h>
#include<cmath>
using namespace std;

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
    string l;
    int k;
    cin>>l;
    cout<<FinalAlg(l)<<endl;
    cout<<"~~~~~~~~~~~~"<<endl;
    char a,b;
    cin>>a>>b;
    k=a;
    cout<<k<<endl;
    cout<<abs(a-b)<<endl;
    b=a-32;
    cout<<b<<endl;
}
