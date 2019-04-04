#include<iostream>
#include<windows.h>
using namespace std;
int main(){
    DialogBoxParamW(NULL,NULL,"ADs",NULL,NULL);
   cout<<MessageBox(NULL,"Error with login","GameMenu",MB_YESNOCANCEL | MB_ICONSTOP  )<<endl;
   cout<<MessageBox(NULL,"Error with login","GameMenu",MB_OKCANCEL | MB_ICONSTOP  )<<endl;
   cout<<MessageBox(NULL,"Error with login","GameMenu",MB_RETRYCANCEL | MB_ICONSTOP  )<<endl;
   cout<<MessageBox(NULL,"Error with login","GameMenu",MB_ABORTRETRYIGNORE | MB_ICONSTOP  )<<endl;
   cout<<MessageBox(NULL,"Error with login","GameMenu",MB_COMPOSITE | MB_ICONSTOP  )<<endl;
   MessageBeep(NULL);

   //OK->1
   //cansel->2
   //abort->3
   //retry->4
   //ignore->5
   //yes->6
   //no->7

 return 0;
}
