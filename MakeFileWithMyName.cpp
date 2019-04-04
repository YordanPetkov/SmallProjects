#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
    string ans="lol11.txt";
    ofstream reg (ans.c_str(),ios::app);
    if(reg.is_open())
    {
        reg<<endl;
        reg<<"sadas111111";
        reg.close();

    }
    return 0;
}
