#include<iostream>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
int main()
{
    PlaySound(TEXT("Draw.wav"),NULL,SND_SYNC);
    return 0;
}
