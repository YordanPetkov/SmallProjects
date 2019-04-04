#include <windows.h>
#include <iostream>
using namespace std;
int main(){
    cout<<"HELLO WORLD who LOVE c++"<<endl;
    cout<<"The standart colour is 7"<<endl;
    cout<<endl;
    for(int i = 0 ; i < 256; i++){
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
        cout <<i<<"\t ";
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
        cout<<" HELLO WORLD who LOVE c++"<<endl;
    }
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 9 );


    return 0;
}

