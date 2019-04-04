#include <windows.h>
#include <iostream>
#include <conio.h>
#include<string>
#define start "start "
#define mozilla "D:\\PROGRAMS\\MozilaFirefox\\MozillaFirefox "
#define google "www.google.bg/search?q="
#define photos "&biw=1024&bih=635&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjWtZ3YgI_PAhULAcAKHc9mBm4Q_AUIBigB"
using namespace std;
int main()
{
  string n,ALLs;

  ALLs=google+n+photos;
  ALLs=mozilla+ALLs;
  ALLs=start+ALLs;
  //system ("start D:\\dani\\snimki\\ÄÐÓÃÈ\\images.jpg"); //for opening stackoverflow through google chrome , if chorme.exe is in that folder..
 system (ALLs.c_str());
// system("start D:\\PROGRAMS\\MozilaFirefox\\MozillaFirefox  https://www.google.bg/search?hl=bg&site=imghp&tbm=isch&source=hp&biw=1024&bih=635&q=car&oq=car&gs_l=img.3..0l3j0i10k1j0l6.241324.241556.0.241944.3.3.0.0.0.0.163.163.0j1.1.0....0...1ac.1.64.img..2.1.162.ousy-3RrMCo");
n=getch();
    cout<<n<<endl;
  return 0;
}
