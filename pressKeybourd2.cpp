#include <windows.h>
#include <winuser.h>

void    pressKey(WORD a_unicode)
{
        KEYBDINPUT kbinput;
        ZeroMemory(&kbinput, sizeof(kbinput));
        kbinput.wScan = a_unicode;
        kbinput.dwFlags = KEYEVENTF_UNICODE;
        kbinput.time = 0;

        INPUT input;
        ZeroMemory(&input, sizeof(input));
        input.type = INPUT_KEYBOARD;
        input.ki = kbinput;

        SendInput(1, &input, sizeof(input));
}
int main()
{}
