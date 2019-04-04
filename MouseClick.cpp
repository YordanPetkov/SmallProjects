#include <windows.h>

void left_click(int x_pos , int y_pos)
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, x_pos, y_pos, 0, 0);
    mouse_event(MOUSEEVENTF_LEFLTUP, x_pos, y_pos, 0, 0);
}

void right_click(int x_pos , int y_pos)
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN, x_pos, y_pos, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, x_pos, y_pos, 0, 0);
}
int main()
{

}
