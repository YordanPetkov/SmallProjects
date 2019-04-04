 #include<iostream>
#include<stdlib.h> /// exit();
#include<conio.h>
#include<windows.h>
#define K_UP 72
#define K_DOWN 80
#define K_ENTER 13
#define K_ESC 27
using namespace std;



int sizeArray;
int a[50];
int Move_pos,Move_count;



///COLOR FUNCTION

void COLOR(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}







///Main_Menu CLASS

class Main_Menu
{
public :
    void Menu_Choose();
    int Human_Choose;
    void Open_Menu();
    void Print_Menu();
private :
    int choose=1;
    int Difficulty=1;
    void Game_Options();
    void Show_Rules();
    void Start_Game();

    void ShowTable();
    //Choosing();

};







///Main_Menu:: Print_Menu() FUNCTION

void Main_Menu:: Print_Menu()
{
    system("cls");
    COLOR(9);
    cout<<"\n\n\n\t\t\t\t   Main Menu\n\n\n\n\n\n";
    COLOR(7);
    switch(choose)
    {

        case 1:
            COLOR(12);cout<<"\t\t\t\t";COLOR(9);cout<<"->";COLOR(12);cout<<"Start game\n";COLOR(7);
            cout<<"\t\t\t\t     Rules\n";
            cout<<"\t\t\t\t    Options\n";
            cout<<"\t\t\t\t   Quit game\n";
            break;
        case 2:
            cout<<"\t\t\t\t  Start game\n";
            COLOR(12);cout<<"\t\t\t\t   ";COLOR(9);cout<<"->";COLOR(12);cout<<"Rules\n";COLOR(7);
            cout<<"\t\t\t\t    Options\n";
            cout<<"\t\t\t\t   Quit game\n";
            break;
        case 3:
            cout<<"\t\t\t\t  Start game\n";
            cout<<"\t\t\t\t     Rules\n";
            COLOR(12);cout<<"\t\t\t\t  ";COLOR(9);cout<<"->";COLOR(12);cout<<"Options\n";COLOR(7);
            cout<<"\t\t\t\t   Quit game\n";
            break;
        case 4:
            cout<<"\t\t\t\t  Start game\n";
            cout<<"\t\t\t\t     Rules\n";
            cout<<"\t\t\t\t    Options\n";
            COLOR(12);cout<<"\t\t\t\t ";COLOR(9);cout<<"->";COLOR(12);cout<<"Quit game\n";COLOR(7);
            break;
    }
}







///Main_Menu::Menu_Choose() FUNCTION

void Main_Menu::Menu_Choose()
{
    while(choose!=0)
    {
        Print_Menu();
        char Ch;
        Ch=getch();
        if(Ch==K_ENTER){Human_Choose = choose ; choose=0;}
        if(Ch==K_UP)
        {
            if(choose==1)choose=4;
            else choose--;
        }
        else if(Ch==K_DOWN)
        {
            if(choose==4)choose=1;
            else choose++;
        }

    }


}







///Main_Menu::Open_Menu() FUNCTION

void Main_Menu::Open_Menu()
{
    switch(Human_Choose)
    {
    case 1:
        //start game
        Start_Game();
        break;
    case 2:
        //rules
        Show_Rules();
        choose=1;

        break;
    case 3:
        //options
        Game_Options();
        choose=1;
        break;
    case 4:
        //quit
        exit(1);
        break;
    }
}

///Main_Menu::ShowTable() FUNCTION

void Main_Menu::ShowTable()
{
    for(int i=0;i<sizeArray;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n Press any key"<<endl;
    getch();

}


///Main_Menu::Start_Game() FUNCTION

void InputN()
{
    INPUT:
    int n;
    cout<<"\tSet the size (n*n)\n";
    cin>>n;
    if(n>40 || n<1)goto INPUT;
    sizeArray=n;

}
void InputArray()
{

    cout<<"Enter the number in column number :\n";
    for(int i=0;i<sizeArray;i++)
    {
        InA:
        cout<<i<<" : ";cin>>a[i];cout<<"\n";
        if(a[i]>50)goto InA;
}
}

int NimSum_a()
{
      //cout<<"1111111"<<endl;
    int NimSum=0;
    for(int i=0;i<sizeArray;i++)
    {
        NimSum=NimSum^a[i];
      //  cout<<"11111112222222222"<<endl;
    }
     //cout<<"11111113333333333333"<<endl;
    if(NimSum==0)return 0;
    //cout<<"1111111444444444444"<<endl;
    return NimSum;
}

int PosOfLeftOne(int a, int b)
{
    if(a==0)return -2;
    string aa="",bb="";
    int asize,bsize;
    int k;
    while(a!=0)
    {
        if(a%2==0)aa+='0';
        else aa+='1';
        a/=2;
    }
    //cout<<"aa"<<aa<<endl;
    while(b!=0)
    {
        if(b%2==0)bb+='0';
        else bb+='1';
        b/=2;
    }
    //cout<<"bb"<<bb<<endl;
    asize=aa.size();
    bsize=bb.size();
    for(int i=asize-1;i>=0;i--)
    {
        if(aa[i]=='1'){k=i;break;}
        if(i==0)return -1;
    }
    if(bb[k]=='1')return k;
    return -1;
}

int SearchNimbit()
{
    //cout<<"2222222222"<<endl;
    int prom=NimSum_a(),k=0;
    for(int i=0;i<sizeArray;i++){
             //cout<<"22222222222322222222323"<<endl;
            k=PosOfLeftOne(prom,a[i]);
            if(k==-2)return -2;
    if(k!=-1)return i;
    }
    return 0;
}


bool Move()
{
    //cout<<"3333333333"<<endl;
    int pos=SearchNimbit();
    //cout<<"POS = "<<pos<<endl;
    Move_pos=pos;
    if(pos==-2)return 0;
    int NimSum=NimSum_a()^a[pos];
    //cout<<"NimSum_a()^a[pos] = " <<NimSum<<endl;
    Move_count=a[pos]-NimSum;
    return 1;
}


bool ComputerMove()
{
    //cout<<"44444444"<<endl;
    if(!Move())
    {
        for(int i=0;i<sizeArray;i++)
        if(a[i]!=0){a[i]--;Move_count=1;Move_pos=i;}
    }
    else
        {
            a[Move_pos]-=Move_count;
        }
    cout<<"\n\nI get "<<Move_count<<" from column number "<<Move_pos<<endl;
    getch();
    return 1;
}

bool PlayerMove()
{
    cout<<"\n\nI get "<<Move_count<<" from column number "<<Move_pos<<endl;
}
bool FLAG=1;
void Main_Menu::Start_Game()
{
    char ans;
    START_GAME:
    system("cls");
    cout<<"\n\n\n\n\t\t\t GAME \n";
    cout<<"\n\n\t\t\t            NIM\n\n";
    cout<<"\n\n\t\t You want to start first/second (F/S) : ";cin>>ans;
    if(ans=='F')
    {
        InputN();
        game:
    if(FLAG){InputArray();FLAG=0;}
    ShowTable();
    if(!PlayerMove())return;
    if(!ComputerMove())return;


    for(int i=0;i<sizeArray;i++)
    {
        if(a[i]!=0){system("cls");goto game;}
    }

    }
    else if(ans=='S')
    {

    }
    else goto START_GAME;


}


///Main_Menu::Show_Rules() FUNCTION

void Main_Menu::Show_Rules()
{
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t RULES \n";
    cout<<"\n\n\t\t\t Cows and Bulls\n\n";
    cout<<"\t On a sheet of paper, the players each write a 4-digit secret number.\n\t The digits must be all different. \n\tThen, in turn, the players try to guess their opponent's number \n\twho gives the number of matches. \n\tIf the matching digits are in their right positions,\n\tthey are 'bulls', if in different positions, they are 'cows'.\n\n";

        cout<<"\t\t\tPress ESCAPE to continue\n";
    ESC_R:
    int ESC=getch();
    if(ESC!=K_ESC)goto ESC_R;
}






///Game_Options() FUNCTION
void Main_Menu::Game_Options()
{
    Set_Difficulty:
    system("cls");
    cout<<"\n\n\n\n\t\t\t\tOPTIONS\n\n";
    COLOR(12);cout<<"\t\t\tSet difficulty (1-3) :";
    COLOR(7);

        int dif;
        cin>>dif;
        if(!cin || dif<1 || dif>3)goto Set_Difficulty;
        Difficulty=dif;

        cout<<"\t\t\tPress ESCAPE to continue\n";
        ESC_R:
        int ESC=getch();
        if(ESC!=K_ESC)goto ESC_R;



}







///Game_CandB FUNCTION

void Game_CandB ()
{
    START_GAME:
    Main_Menu Game_CB;
    Game_CB.Menu_Choose();
    Game_CB.Open_Menu();
    Game_CB.Print_Menu();
    goto START_GAME;
}

///MAIN FUNCTION

int main()
{
    Game_CandB ();

} 