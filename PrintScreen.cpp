#include <iostream>
#include <windows.h>
using namespace std;



int main()
{
    keybd_event(VK_MENU, 0, 0, 0); //Alt Press
    keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press


    keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); //Alt Release

return 0;
}
