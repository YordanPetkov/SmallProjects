#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
    string ans="1321.txt",ID="0003";
    int i=1;
    string massive[100][100],prom;
    ifstream reg1 (ans.c_str(),ios::in);
    while(! reg1.eof())
    {
        for(int j=1;j<=4;j++){
        reg1>>prom;
        massive[i][j]=prom;
        }
        i++;
    }
    int n=i;
    reg1.close();
    for(int i=1;i<=n;i++)
        {
            if(massive[i][1]==ID)
                {

            for(int j=1;j<=4;j++)
            {
                    cout<<massive[i][j]<<endl;

            }
            break;
                }
        }
    return 0;
}

