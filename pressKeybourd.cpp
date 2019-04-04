#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
class Keyboard
{
public :

    BYTE name;
    BYTE code;

};
void Press(Keyboard key)
{
    /*if(key.name==NULL){
        keybd_event( NULL,
                      key.code,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( NULL,
                      key.code,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
                      return ;
    }*/
    //string a=key.name.c_str(),b=key.code.c_str();
    // Simulate a key press
         keybd_event( key.name,
                      key.code,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );


}

void Push(Keyboard key)
{
    // Simulate a key release
         keybd_event( key.name,
                      key.code,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
}

int main()
{
    Keyboard enter,browser_search,up,down,right,left,ctrl,shift,space,esc,backspace,tab,alt,capslock,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,q,w,e,r,t,y,u,i,o,p,a,s,d,f,g,h,j,k,l,z,x,c,v,b,n,m,LeftMouse,RightMouse;

    ///Keys options
    backspace.name=VK_BACK;
    backspace.code=0x08;

    tab.name=VK_TAB;
    tab.code=0x09;

    enter.name = VK_RETURN;
    enter.code = 0x0D;

    shift.name=VK_SHIFT;
    shift.code=0x10;

    ctrl.name=VK_CONTROL;
    ctrl.code=0x11;

    alt.name=VK_MENU;
    alt.code=0x12;

    capslock.name=VK_CAPITAL;
    capslock.code=0x14;

    esc.name=VK_ESCAPE;
    esc.code=0x1B;

    space.name=VK_SPACE;
    space.code=0x20;

    left.name=VK_LEFT;
    left.code=0x25;

    up.name=VK_UP;
    up.code=0x26;

    right.name=VK_RIGHT;
    right.code=0x27;

    down.name=VK_DOWN;
    down.code=0x28;

    LeftMouse.name=VK_LBUTTON;
    LeftMouse.code=0x01;

    RightMouse.name=VK_RBUTTON;
    RightMouse.code=0x02;

    _0.name=VkKeyScan('0');
    _0.code=0x30;

    _1.name=VkKeyScan('1');
    _1.code=0x31;

    _2.name=VkKeyScan('2');
    _2.code=0x32;

    _3.name=VkKeyScan('3');
    _3.code=0x33;

    _4.name=VkKeyScan('4');
    _4.code=0x34;

    _5.name=VkKeyScan('5');
    _5.code=0x35;

    _6.name=VkKeyScan('6');
    _6.code=0x36;

    _7.name=VkKeyScan('7');
    _7.code=0x37;

    _8.name=VkKeyScan('8');
    _8.code=0x38;

    _9.name=VkKeyScan('9');
    _9.code=0x39;

    a.name=VkKeyScan('A');
    a.code=0x41;

    b.name=VkKeyScan('B');
    b.code=0x42;

    c.name=VkKeyScan('C');
    c.code=0x43;

    d.name=VkKeyScan('D');
    d.code=0x44;

    e.name=VkKeyScan('E');
    e.code=0x45;

    f.name=VkKeyScan('F');
    f.code=0x46;

    g.name=VkKeyScan('G');
    g.code=0x47;

    h.name=VkKeyScan('H');
    h.code=0x48;

    i.name=VkKeyScan('I');
    i.code=0x49;

    j.name=VkKeyScan('J');
    j.code=0x4A;

    k.name=VkKeyScan('K');
    k.code=0x4B;

    l.name=VkKeyScan('L');
    l.code=0x4C;

    m.name=VkKeyScan('M');
    m.code=0x4D;

    n.name=VkKeyScan('N');
    n.code=0x4E;

    o.name=VkKeyScan('O');
    o.code=0x4F;

    p.name=VkKeyScan('P');
    p.code=0x50;

    q.name=VkKeyScan('Q');
    q.code=0x51;

    r.name=VkKeyScan('R');
    r.code=0x52;

    s.name=VkKeyScan('S');
    s.code=0x53;

    t.name=VkKeyScan('T');
    t.code=0x54;

    u.name=VkKeyScan('U');
    u.code=0x55;

    v.name=VkKeyScan('V');
    v.code=0x56;

    w.name=VkKeyScan('W');
    w.code=0x57;

    x.name=VkKeyScan('X');
    x.code=0x58;

    y.name=VkKeyScan('Y');
    y.code=0x59;

    z.name=VkKeyScan('Z');
    z.code=0x5A;

    getch();
    cout<<"PRESS Key AFTER : "<<endl;
    Sleep(500);
    cout<<"3"<<endl;
     Sleep(500);
    cout<<"2"<<endl;
     Sleep(500);
    cout<<"1"<<endl;
     Sleep(500);

     ///iF YOU OPEN mY computer this open a picture with imoticons :
     /*Press(right);
     Press(right);
     Press(enter);
     Press(right);
     Press(enter);
     Press(up);
     Press(enter);
     Press(right);
     Press(right);
     Press(enter);
     Press(right);
     Press(right);
     Press(right);
     Press(right);
     Press(enter);*/

     ///Write in text file
     /*Press(capslock);
     Press(d);
     Press(a);
     Press(n);
     Press(c);
     Press(h);
     Press(o);
     Press(capslock);
     Press(space);
     Press(k);
     Press(a);
     Press(k);
     Press(v);
     Press(o);
     Press(space);
     Press(p);
     Press(r);
     Press(a);
     Press(v);
     Press(i);
     Press(s);
     Press(h);*/

     ///MAKE A FOLDER
     //Press(LeftMouse);
     /*Press(up);
     Press(up);
     Press(enter);
     Press(enter);
     Press(d);
     Press(a);
     Press(n);
     Press(c);
     Press(h);
     Press(o);
     Press(enter);*/


     return 0;

}
