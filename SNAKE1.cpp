 #include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include <time.h>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
#define MIN_snake_size 5
#define MAX_snake_size 20
#define MAXlevels 10
#define MAXtN 13
#define MAXtM 16
int MAXN=MAXtN;//13
int MAXM=MAXtM;//16
#define MAXApple 15

unsigned int score=0,level=1,apple=0;
int snake_size=MAX_snake_size,speed=100,delS=5;
bool level_completed = 0 , gameover = 0 , quit = 0 , sound = 0;
//unsigned int Up=72,Down=80,Right=77,Left=75;
unsigned int Up=119,Down=115,Right=100,Left=97;
//char Upc='^',Downc='v',Rightc='>',Leftc='<',turn=77;
char Upc='w',Downc='s',Rightc='d',Leftc='a',turn=100;
char Video='c';
int table[MAXtN][MAXtM];
void firstMenu();

void startgame();
void SnakeLogo();
void viewstartgame();
void applegame();
string ExePath();
void resume_quit();
void options();
void CControls();
void Video_Set_Change(char Video1);
char controlsGEN();
void CLevel();
void CGameOptions();
void colour(int i);
void Gameover();
void levels(int level);

void saveGame();
void loadGame();

COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

class Snake
{
    public:
    int x;
    int y;
    int type;
};
Snake snake[26];
void cleargame()
{
    for(int i=0;i<=MAXN;i++)
        for(int j=0;j<=MAXM;j++)
        table[i][j]=0;
    turn=77;
    snake_size=MIN_snake_size;
    snake[0].x=0;
    snake[0].y=4;
    snake[0].type=2;
    snake[1].x=0;
    snake[1].y=3;
    snake[1].type=1;
    snake[2].x=0;
    snake[2].y=2;
    snake[2].type=1;
    snake[3].x=0;
    snake[3].y=1;
    snake[3].type=1;
    snake[4].x=0;
    snake[4].y=0;
    snake[4].type=1;
    table[0][0]=1;
    table[0][1]=1;
    table[0][2]=1;
    table[0][3]=1;
    table[0][4]=2;
    apple=0;
    level_completed = 0;
}
int main()
{

    system("cls");
    srand(time(NULL));
    if(level_completed==1)
    {
        LC:

        apple=0;
        cout<<"\tSnake Game Shadow"<<endl;
        cout<<"\tLEVEL COMPLETE"<<endl;
        cout<<"\n\tTo continue press enter"<<endl;
        level++;
        if(getch()!=13)goto LC;
        saveGame();
    }
    cleargame();
    if(gameover==1){level=1;score=0;saveGame();}



    firstMenu();
    saveGame();
    return 0;
}

void SnakeLogo()
{
    system("cls");
    ///LOADING PROCESS
        cout<<"\n\n\n\n\n\t\t\t\tLoading Database...";
        cout<<"\t\t\t";
        gotoxy(3,9);
        printf("\t\t\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
        gotoxy(3,10);
        printf("\t\t\tº°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°º");
        gotoxy(3,11);
        printf("\t\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");

        for(int k=25;k<58;k++)
        {
        Sleep(30);
        gotoxy(k,10);
        printf("±");
        }
        Sleep(10);
        cout<<endl;
        system("cls");


///LOGO
}

void firstMenu()
{
    loadGame();
    SnakeLogo();
    if(quit==1)return;
    int k,v=1;
    start_fMenu:
    if(Video=='f')ios_base::sync_with_stdio(false);
    if(Video=='c')ios_base::sync_with_stdio(true);
    system("cls");
    cout<<"\t\t\t\tSnake Game Shadow\n\n\n"<<endl;
    switch(v)
    {
    case 1 :
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   MINE MENU           |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t";colour(12);cout<<"-> CONTINUE GAME       ";colour(7);cout<<"|"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   START NEW GAME      |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   OPTIONS             |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   QUIT                |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        break;
    case 2 :
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   MINE MENU           |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   CONTINUE GAME       |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t";colour(12);cout<<"-> START NEW GAME      ";colour(7);cout<<"|"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   OPTIONS             |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   QUIT                |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        break;
    case 3 :
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   MINE MENU           |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   CONTINUE GAME       |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   START NEW GAME      |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t";colour(12);cout<<"-> OPTIONS             ";colour(7);cout<<"|"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   QUIT                |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        break;
    case 4 :
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   MINE MENU           |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   CONTINUE GAME       |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   START NEW GAME      |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t   OPTIONS             |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|\t";colour(12);cout<<"-> QUIT                ";colour(7);cout<<"|"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        break;
    }
    fMenu:
    k=getch();
    switch(k)
    {
    case 72 :
        if(v==1)v=4;
        else v--;
        break;
    case 80 :
        if(v==4)v=1;
        else v++;
        break;
    case 13 :
        switch(v)
        {
        case 1 :

            startgame();
            break;
        case 2 :
            cleargame();
            startgame();
            break;
        case 3 :
            options();
            break;
        case 4 :
            quit=1;
            exit(1);
            break;
        }
        break;

    }
   goto start_fMenu;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void startgame()
{
    levels(level);
    applegame();
    viewstartgame();
}

void applegame()
{
    int xA,yA;

    xA = rand()%MAXN;
    yA = rand()%MAXM;
    if(table[xA][yA]==0)table[xA][yA]=3;
    else {applegame();return;}
}


string CheatPoint="";
void viewstartgame()
{
    snake_size=MIN_snake_size+apple;
    int lx,ly;
    system("cls");
    cout<<"\t\t\t\tSnake Game Shadow"<<endl;
    cout<<"\n\n\n";
    cout<<"\tScore : "<<score<<"\tLevel : "<<level<<"\tApples : "<<apple<<"/"<<MAXApple<<endl;
    cout<<"\n\n\n";
    cout<<"\t";
    for(int i=0;i<=MAXM+1;i++)
        cout<<"*";
        cout<<endl;
    for(int i=0;i<MAXN;i++)
    {
        cout<<"\t*";
        for(int j=0;j<MAXM;j++)
        {
             if(table[i][j]==2){colour(10);cout<<"G";colour(7);}
             else
             {
                if(table[i][j]==1){colour(10);cout<<"o";colour(7);}
                else
                {
                    if(table[i][j]==3){colour(12);cout<<"@";colour(7);}
                    else
                    {
                        if(table[i][j]==4){colour(8);cout<<"#";colour(7);}
                       else if(table[i][j]==0)cout<<" ";
                    }
                }

             }
        }
        cout<<"*"<<endl;
    }
    cout<<"\t";
        for(int i=0;i<=MAXM+1;i++)
        cout<<"*";
    cout<<endl;
    cout<<"\n\n\t Press ESCAPE to quit"<<endl;
    if(kbhit())
    {////////////////////////////
        lx=snake[snake_size-1].x;
        ly=snake[snake_size-1].y;
        /////////////////////

        char button=getch();
        ///CHEATS
        if(button=='m'){CheatPoint="m";}
              else if(button=='o')
                {
                    if(CheatPoint=="m")CheatPoint="mo";
                    else CheatPoint="";
                }
               else if(button=='n')
                {
                    if(CheatPoint=="mo")CheatPoint="mon";
                    else CheatPoint="";
                }
                else if(button=='e')
                {
                    if(CheatPoint=="mon")CheatPoint="mone";
                    else CheatPoint="";
                }
                else if(button=='y')
                {
                    if(CheatPoint=="mone")CheatPoint="money";
                    else CheatPoint="";
                }


               else  if(button=='f'){CheatPoint="f";}
                else if(button=='r')
                {
                    if(CheatPoint=="f")CheatPoint="fr";
                    else CheatPoint="";
                }
                else if(button=='u')
                {
                    if(CheatPoint=="fr")CheatPoint="fru";
                    else CheatPoint="";
                }
               else  if(button=='i')
                {
                    if(CheatPoint=="fru")CheatPoint="frui";
                    else CheatPoint="";
                }
               else  if(button=='t')
                {
                    if(CheatPoint=="frui")CheatPoint="fruit";
                    else CheatPoint="";
                }
               else if(button=='h')
               {
                   CheatPoint="h";
               }
               else if(button=='a')
               {
                    if(CheatPoint=="h")CheatPoint="ha";
                    else CheatPoint="";
               }
               else if(button=='c')
               {
                   if(CheatPoint=="ha")CheatPoint="hac";
                   else CheatPoint="";
               }
               else if(button=='k')
               {
                   if(CheatPoint=="hac")CheatPoint="hack";
                   else CheatPoint="";
               }
               else{ CheatPoint="";}

                if(CheatPoint=="money")score+=100;
                if(CheatPoint=="fruit")
                    {
                        if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level_completed=1;level++;apple=0;saveGame();

                        main();
                        return;
                    }}
                    if(CheatPoint=="hack")
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }




        if((button==Down && turn ==Up)|| (button == Up && turn==Down)|| (button==Right && turn==Left) || (button==Left && turn == Right) )goto CPU;
        if(button!=Down && button!=Up && button!=Right && button!=Left && button!= 27)goto CPU;

        if(button==Up && turn != Down)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            //cout<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<endl;getch();
            //cout<<snake_size-1<<" "<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<" "<<snake[snake_size-1].type<<endl;
            //cout<<"TABLE : "<<table[snake[snake_size-1].x][snake[snake_size-1].y]<<endl;getch();
            for(int i=snake_size-1;i>0;i--)
            {

                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                //cout<<i<<" "<<snake[i].x<<" "<<snake[i].y<<" "<<snake[i].type<<endl;
                //cout<<"TABLE : "<<snake[i].x<<" "<<snake[i].y<<" "<<table[snake[i].x][snake[i].y]<<endl;getch();

            }



            if(snake[0].x==0)snake[0].x=MAXN-1;
                else snake[0].x-=1;

                ////////////////
                if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level_completed=1;level++;apple=0;saveGame();

                        main();
                        return;
                    }
                }
                  if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
                ///////////////

            table[snake[0].x][snake[0].y]=snake[0].type;
            turn=Up;
        }

        if(button==Down && turn!=Up)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Down;
            }
            if(snake[0].x==MAXN-1)snake[0].x=0;
            else snake[0].x+=1;
            if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();
                        return;
                    }
                }
            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
            turn=Down;
        }
        else if(button==Right && turn !=Left)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Right;
            }
            if(snake[0].y==MAXM-1)snake[0].y=0;
                else snake[0].y+=1;
                if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
               turn=Right;
        }
        if(button==Left && turn!=Right)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn = Left;
            }
            if(snake[0].y==0)snake[0].y=MAXM-1;
                else snake[0].y-=1;
                if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
            turn=Left;
        }
        if(button==27)
        {
            saveGame();
            resume_quit();
            return;
        }
                if(button==Right || button==Left)Sleep(speed-delS*level);
        else Sleep(speed-delS*level+20);
        viewstartgame();
    }
    else
    {
        CPU:
        lx=snake[snake_size-1].x;
        ly=snake[snake_size-1].y;
        char button=turn;
        if(button==Up)
        {


            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            //cout<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<endl;getch();
            //cout<<snake_size-1<<" "<<snake[snake_size-1].x<<" "<<snake[snake_size-1].y<<snake[snake_size-1].type<<endl;
            //cout<<"TABLE : "<<table[snake[snake_size-1].x][snake[snake_size-1].y]<<endl;getch();
            for(int i=snake_size-1;i>0;i--)
            {
                //cout<<table[snake[snake_size-1].x][snake[snake_size-1].y]<<endl;getch();
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                table[snake[i].x][snake[i].y]=snake[i].type;
                //cout<<i<<" "<<snake[i].x<<" "<<snake[i].y<<" "<<snake[i].type<<endl;
                //cout<<"TABLE : "<<snake[i].x<<" "<<snake[i].y<<" "<<table[snake[i].x][snake[i].y]<<endl;getch();
                turn=Up;
            }

            if(snake[0].x==0)snake[0].x=MAXN-1;
                else snake[0].x-=1;
                if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
        }
        if(button==Down)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Down;
            }
            if(snake[0].x==MAXN-1)snake[0].x=0;
            else snake[0].x+=1;
            if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
        }
        if(button==Right)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                //cout<<"snake["<<i<<"].x : "<<snake[i].x<<" snake ["<<i<<"].y "<<snake[i].y<<endl;getch();
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn=Right;
            }
            if(snake[0].y==MAXM-1)snake[0].y=0;
                else snake[0].y+=1;
                if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;

        }
        if(button==Left)
        {
            table[snake[snake_size-1].x][snake[snake_size-1].y]=0;
            for(int i=snake_size-1;i>0;i--)
            {
                snake[i].x=snake[i-1].x;
                snake[i].y=snake[i-1].y;
                table[snake[i].x][snake[i].y]=snake[i].type;
                turn = Left;
            }
            if(snake[0].y==0)snake[0].y=MAXM-1;
                else snake[0].y-=1;
                if(table[snake[0].x][snake[0].y]==3)
                {if(sound)cout<<"\a";
                    snake_size++;snake[snake_size-1].type=1;
                    apple++;applegame();
                    snake[snake_size-1].x=lx;
                    snake[snake_size-1].y=ly;
                    score+=level*10 + apple*10;
                    if(apple==MAXApple)
                    {
                        level++;
                        level_completed=1;apple=0;saveGame();main();
                        return;
                    }
                }
                            if(table[snake[0].x][snake[0].y]==1 || table[snake[0].x][snake[0].y]==4)
                {
                    gameover=1;
                    Gameover();
                    return ;
                }
            table[snake[0].x][snake[0].y]=snake[0].type;
        }
        if(button==27)
        {
            resume_quit();
            return;
        }
        if(button==Right || button==Left)Sleep(speed-delS*level);
        else Sleep(speed-delS*level+10);
        viewstartgame();
    }


}

void resume_quit()
{
    char ch;
    resumeORquit:
    system("cls");
    cout<<"\t\t\t\tSnake Game Shadow\n\n\n"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t ENTER-> QUIT         |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t ESCAPE-> Resume      |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    ch=getch();
    int k=ch;
    switch(k)
    {
    case 27 :
        viewstartgame();
        break;
    case 13:
        main();
        break;
    default:
        goto resumeORquit;
        break;

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void options()
{
    int k,v=1;

    start_options:
    system("cls");
    cout<<"\t\t\t\tSnake Game Shadow\n\n\n\n"<<endl;
    switch(v)
    {
    case 1 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t";colour(12);cout<<"-> OPTIONS            ";colour(7);cout<<"|"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Controls           |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Level              |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Game Options       |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Sound-";
    if(sound)cout<<"ON          |"<<endl;
    else cout<<"OFF          |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|    Video Settings - ";
    if(Video=='c')cout<<"CGP     |"<<endl;
    if(Video=='f')cout<<"NLGP    |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Back               |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;



    case 2 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   OPTIONS            |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t";colour(12);cout<<"-> Controls           ";colour(7);cout<<"|"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Level              |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Game Options       |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Sound-";
    if(sound)cout<<"ON          |"<<endl;
    else cout<<"OFF          |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|    Video Settings - ";
    if(Video=='c')cout<<"CGP     |"<<endl;
    if(Video=='f')cout<<"NLGP    |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Back               |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;



    case 3 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   OPTIONS            |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Controls           |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t";colour(12);cout<<"-> Level              ";colour(7);cout<<"|"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Game Options       |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Sound-";
    if(sound)cout<<"ON          |"<<endl;
    else cout<<"OFF          |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|    Video Settings - ";
    if(Video=='c')cout<<"CGP     |"<<endl;
    if(Video=='f')cout<<"NLGP    |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Back               |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;

    case 4 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   OPTIONS            |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Controls           |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Level              |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t";colour(12);cout<<"-> Game Options       ";colour(7);cout<<"|"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Sound-";
    if(sound)cout<<"ON          |"<<endl;
    else cout<<"OFF          |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|    Video Settings - ";
     if(Video=='c')cout<<"CGP     |"<<endl;
    if(Video=='f')cout<<"NLGP    |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Back               |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;
    case 5 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   OPTIONS            |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Controls           |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Level              |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Game Options       |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t";colour(12);cout<<"-> Sound-";
    if(sound){cout<<"ON          ";colour(7);cout<<"|"<<endl;}
    else cout<<"OFF          ";colour(7);cout<<"|"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|    Video Settings - ";
    if(Video=='c')cout<<"CGP     |"<<endl;
    if(Video=='f')cout<<"NLGP    |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Back               |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;
    case 6 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   OPTIONS            |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Controls           |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Level              |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Game Options       |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Sound-";
    if(sound)cout<<"ON          |"<<endl;
    else cout<<"OFF          |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|";colour(12);cout<<"  ->Video Settings - ";
    if(Video=='c'){cout<<"CGP     ";colour(7);cout<<"|"<<endl;}
    if(Video=='f'){cout<<"NLGP    ";colour(7);cout<<"|"<<endl;}
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Back               |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;
    case 7 :
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   OPTIONS            |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Controls           |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Level              |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Game Options       |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t   Sound-";
    if(sound)cout<<"ON          |"<<endl;
    else cout<<"OFF          |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|    Video Settings - ";
    if(Video=='c')cout<<"CGP     |"<<endl;
    if(Video=='f')cout<<"NLGP    |"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t|\t";colour(12);cout<<"-> Back               ";colour(7);cout<<"|"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
        break;
    }
    Options:
    k=getch();
    switch(k)
    {
    case 72 :
        if(v==1 || v==2)v=7;
        else v--;
        break;
    case 80 :
        if(v==7)v=2;
        else v++;
        break;
    case 13 :
        switch(v)
        {
        case 2 :
            CControls();
            break;
        case 3 :
            CLevel();
            break;
        case 4 :
            CGameOptions();
            break;
        case 5 :
            if(sound)sound=0;
            else sound=1;
            cout<<"\a";
            break;
        case 6 :

            if(Video=='c'){Video='f';}
            else if(Video='f'){Video='c';}Video_Set_Change(Video);
            break;
        case 7 :
            return;
        }
        break;
    default :
        goto Options;
        break;

    }
   goto start_options;
}


string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}



void Video_Set_Change(char Video1)
{
    Video=Video1;
    saveGame();
    string a="start "+ExePath()+"\\SNAKE1.exe";
    system(a.c_str());
    exit(0);

}


void CControls()
{
    int k,v=1;
    start_options:
        if(Up>200)Up=72;
        if(Down>200)Down=80;
        if(Right>200)Right=77;
        if(Left>200)Left=75;
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    if(Up!='H')Upc=Up;
    if(Down!='P')Downc=Down;
    if(Right!='M')Rightc=Right;
    if(Left!='K')Leftc=Left;
    switch(v)
    {
    case 1 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    cout<<"\tMove Down\t"<<Downc<<endl;
    cout<<"\tMove Right\t"<<Rightc<<endl;
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 2 :
    cout<<"\tAction\t\tKey"<<endl;
    colour(9);cout<<"\tMove Up\t\t"<<Upc<<endl;colour(7);
    cout<<"\tMove Down\t"<<Downc<<endl;
    cout<<"\tMove Right\t"<<Rightc<<endl;
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 3 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    colour(9);cout<<"\tMove Down\t"<<Downc<<endl;colour(7);
    cout<<"\tMove Right\t"<<Rightc<<endl;
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 4 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    cout<<"\tMove Down\t"<<Downc<<endl;
    colour(9);cout<<"\tMove Right\t"<<Rightc<<endl;colour(7);
    cout<<"\tMove Left\t"<<Leftc<<endl;
        break;
    case 5 :
    cout<<"\tAction\t\tKey"<<endl;
    cout<<"\tMove Up\t\t"<<Upc<<endl;
    cout<<"\tMove Down\t"<<Downc<<endl;
    cout<<"\tMove Right\t"<<Rightc<<endl;
    colour(9);cout<<"\tMove Left\t"<<Leftc<<endl;colour(7);
    }
    cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
    cout<<"\n\n\n\t To back press escape"<<endl;
    Options:
    k=getch();
    switch(k)
    {
    case 72 :
        if(v==1 || v==2)v=5;
        else v--;
        break;
    case 80 :
        if(v==5)v=2;
        else v++;
        break;

    char k2;
    int k2i;
    case 27 :
        return;
    case 13 :
        switch(v)
        {
        case 2 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            colour(12);cout<<"\tMove Up\t\t"<<Upc<<endl;colour(7);
            cout<<"\tMove Down\t"<<Downc<<endl;
            cout<<"\tMove Right\t"<<Rightc<<endl;
            cout<<"\tMove Left\t"<<Leftc<<endl;
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=72;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Up=k2i;
            if(k2i==27) return;
            if(k2i>200)Up=72;
            break;
        case 3 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            cout<<"\tMove Up\t\t"<<Upc<<endl;
            colour(12);cout<<"\tMove Down\t"<<Downc<<endl;colour(7);
            cout<<"\tMove Right\t"<<Rightc<<endl;
            cout<<"\tMove Left\t"<<Leftc<<endl;
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=80;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Down=k2i;
            if(k2i==27) return;
            if(k2i>200)Down=80;
            break;
        case 4 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            cout<<"\tMove Up\t\t"<<Upc<<endl;
            cout<<"\tMove Down\t"<<Downc<<endl;
            colour(12);cout<<"\tMove Right\t"<<Rightc<<endl;colour(7);
            cout<<"\tMove Left\t"<<Leftc<<endl;
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=77;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Right=k2i;
            if(k2i==27) return;
            if(k2i>200)Right=77;
            break;
        case 5 :
            system("cls");
            cout<<"\tSnake Game Shadow"<<endl;
            cout<<"\tAction\t\tKey"<<endl;
            cout<<"\tMove Up\t\t"<<Upc<<endl;
            cout<<"\tMove Down\t"<<Downc<<endl;
            cout<<"\tMove Right\t"<<Rightc<<endl;
            colour(12);cout<<"\tMove Left\t"<<Leftc<<endl;colour(7);
            cout<<"\t To use the defaut controls press 'SPACE'"<<endl;
            cout<<"\n\n\n\t To back press escape"<<endl;
            k2=75;
            k2=getch();
            k2i=k2;
            if(k2==' ')goto start_options;
            if(k2i!=27 || k2i<200)Left=k2i;
            if(k2i==27) return;
            if(k2i>200)Left=75;
            break;
        }
        break;
        case 32 :
            Up=72;
            Down=80;
            Right=77;
            Left=75;
            Upc='^';
            Downc='v';
            Rightc='>';
            Leftc='<';
            break;
    default :
        goto Options;
        break;

    }
   goto start_options;

}
void CLevel()
{
    start_Clevel:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    cout<<"\tLEVEL : "<<"<"<<level<<">"<<endl;
    cout<<"\tPress ENTER to continue"<<endl;
    int k=getch();
    switch (k)
    {
    case 72 :
        if(level==MAXlevels)level=1;
        else level++;
        break;
    case 77 :
        if(level==MAXlevels)level=1;
        else level++;
        break;
    case 75 :
        if(level==1)level=MAXlevels;
        else level--;
        break;
    case 80 :
        if(level==1)level=MAXlevels;
        else level--;
        break;
    case 13 :
        return;
    default :
        goto start_Clevel;
        break;
    }
    goto start_Clevel;
}
void CGameOptions()
{
    start_Clevel:
    system("cls");
    cout<<"\tSnake Game Shadow"<<endl;
    cout<<"\tGame Settings"<<endl;
    cout<<"\tTable width : "<<"<"<<MAXN<<">"<<endl;
    cout<<"\tTable hight : "<<"<"<<MAXM<<">"<<endl;
    cout<<"\tPress ENTER to continue"<<endl;
    int k=getch();
    switch (k)
    {
    case 72 :
        MAXM++;
        break;
    case 77 :
        MAXN++;
        break;
    case 75 :
        MAXN--;
        break;
    case 80 :
        MAXM--;
        break;
    case 13 :
        return;
    default :
        goto start_Clevel;
        break;
    }
    goto start_Clevel;
}

void Pixel(int color,int spaces)
{
    if(Video=='c'){


            colour(color);
            for(int i=1;i<=spaces;i++)
            cout<<" ";
                colour(7);
    }

    if(Video=='f')
    {
        if(color==0){
        for(int i=1;i<=spaces;i++)
            cout<<"-";
        }
        if(color==255)
        {
            for(int i=1;i<=spaces;i++)
            cout<<"@";
        }
    }
}

void Gameover()
{
    int B=0,W=255;
    gameOVER:
    system("cls");

      /*0*/  cout<<"\n\n\t\t";Pixel(W,37);cout<<"\n";
        /*1*/  cout<<"\t\t";Pixel(W,1);Pixel(W,4);Pixel(B,10);Pixel(W,7);Pixel(B,10);Pixel(W,4);Pixel(W,1);cout<<"\n";
        /*2*/  cout<<"\t\t";Pixel(W,1);Pixel(W,3);Pixel(B,2);Pixel(W,8);Pixel(B,3);Pixel(W,3);Pixel(B,3);Pixel(W,8);Pixel(B,2);Pixel(W,3);Pixel(W,1);cout<<"\n";
        /*3*/  cout<<"\t\t";Pixel(W,1);Pixel(W,2);Pixel(B,2);Pixel(W,2);Pixel(B,6);Pixel(W,3);Pixel(B,2);Pixel(W,1);Pixel(B,2);Pixel(W,3);Pixel(B,6);Pixel(W,2);Pixel(B,2);Pixel(W,2);Pixel(W,1);cout<<"\n";
        /*4*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,2);Pixel(W,2);Pixel(B,2);Pixel(W,4);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,9);Pixel(W,2);Pixel(B,2);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*5*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,2);Pixel(W,2);Pixel(B,7);Pixel(W,1);Pixel(B,3);Pixel(W,1);Pixel(B,11);Pixel(W,2);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*6*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,2);Pixel(W,2);Pixel(B,8);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,11);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*7*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,10);Pixel(W,3);Pixel(B,13);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*8*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,10);Pixel(W,2);Pixel(B,14);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*9*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,11);Pixel(W,2);Pixel(B,13);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*10*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,12);Pixel(W,2);Pixel(B,12);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*11*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,11);Pixel(W,2);Pixel(B,13);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*12*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(B,2);Pixel(W,1);Pixel(B,10);Pixel(W,2);Pixel(B,14);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*13*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,9);Pixel(W,2);Pixel(B,14);Pixel(W,1);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*14*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,2);Pixel(W,1);Pixel(B,2);Pixel(W,1);Pixel(B,10);Pixel(W,2);Pixel(B,12);Pixel(W,2);Pixel(B,1);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*15*/  cout<<"\t\t";Pixel(W,1);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,13);Pixel(W,2);Pixel(B,10);Pixel(W,2);Pixel(B,2);Pixel(W,1);Pixel(W,1);cout<<"\n";
        /*16*/  cout<<"\t\t";Pixel(W,1);Pixel(W,2);Pixel(B,2);Pixel(W,2);Pixel(B,11);Pixel(W,2);Pixel(B,10);Pixel(W,2);Pixel(B,2);Pixel(W,2);Pixel(W,1);cout<<"\n";
        /*17*/  cout<<"\t\t";Pixel(W,1);Pixel(W,3);Pixel(B,2);Pixel(W,3);Pixel(B,8);Pixel(W,2);Pixel(B,9);Pixel(W,3);Pixel(B,2);Pixel(W,3);Pixel(W,1);cout<<"\n";
        /*18*/  cout<<"\t\t";Pixel(W,1);Pixel(W,4);Pixel(B,3);Pixel(W,3);Pixel(B,6);Pixel(W,2);Pixel(B,7);Pixel(W,3);Pixel(B,3);Pixel(W,4);Pixel(W,1);cout<<"\n";
        /*19*/  cout<<"\t\t";Pixel(W,1);Pixel(W,6);Pixel(B,3);Pixel(W,2);Pixel(B,6);Pixel(W,2);Pixel(B,5);Pixel(W,2);Pixel(B,3);Pixel(W,6);Pixel(W,1);cout<<"\n";
        /*20*/  cout<<"\t\t";Pixel(W,1);Pixel(W,8);Pixel(B,2);Pixel(W,3);Pixel(B,5);Pixel(W,2);Pixel(B,2);Pixel(W,3);Pixel(B,2);Pixel(W,8);Pixel(W,1);cout<<"\n";
        /*21*/  cout<<"\t\t";Pixel(W,1);Pixel(W,9);Pixel(B,3);Pixel(W,3);Pixel(B,2);Pixel(W,2);Pixel(B,1);Pixel(W,3);Pixel(B,3);Pixel(W,9);Pixel(W,1);cout<<"\n";
        /*22*/  cout<<"\t\t";Pixel(W,1);Pixel(W,11);Pixel(B,3);Pixel(W,7);Pixel(B,3);Pixel(W,11);Pixel(W,1);cout<<"\n";
        /*23*/  cout<<"\t\t";Pixel(W,1);Pixel(W,13);Pixel(B,3);Pixel(W,3);Pixel(B,3);Pixel(W,13);Pixel(W,1);cout<<"\n";
        /*24*/  cout<<"\t\t";Pixel(W,1);Pixel(W,3);Pixel(B,8);Pixel(W,1);Pixel(B,5);Pixel(W,1);Pixel(B,4);Pixel(W,1);Pixel(B,12);Pixel(W,1);cout<<"\n";
        /*25*/  cout<<"\t\t";Pixel(W,1);Pixel(W,2);Pixel(B,2);Pixel(W,6);Pixel(B,3);Pixel(W,3);Pixel(B,3);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,7);Pixel(B,1);Pixel(W,1);cout<<"\n";
        /*26*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,2);Pixel(W,2);Pixel(B,7);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,2);Pixel(W,3);Pixel(B,1);Pixel(W,3);Pixel(B,1);Pixel(W,2);Pixel(B,6);Pixel(W,1);cout<<"\n";

        /*27*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,7);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,7);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(W,1);cout<<"\n";
        /*28*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,3);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,1);Pixel(W,5);Pixel(B,1);Pixel(W,2);Pixel(W,1);cout<<"\n";
        /*29*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,1);Pixel(W,7);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(W,1);cout<<"\n";
        /*30*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,2);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,6);Pixel(W,1);cout<<"\n";
        /*31*/  cout<<"\t\t";Pixel(W,1);Pixel(W,2);Pixel(B,2);Pixel(W,6);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,7);Pixel(B,1);Pixel(W,1);cout<<"\n";
        /*32*/  cout<<"\t\t";Pixel(W,1);Pixel(W,2);Pixel(B,33);Pixel(W,1);cout<<"\n";

        /*33*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,2);Pixel(W,6);Pixel(B,2);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,7);Pixel(B,1);Pixel(W,6);Pixel(B,2);Pixel(W,1);cout<<"\n";
        /*34*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,6);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,1);cout<<"\n";
        /*35*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,2);Pixel(B,6);Pixel(W,2);Pixel(B,3);Pixel(W,2);Pixel(B,1);Pixel(W,1);cout<<"\n";
        /*36*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,1);Pixel(W,3);Pixel(B,1);Pixel(W,3);Pixel(B,1);Pixel(W,5);Pixel(B,3);Pixel(W,2);Pixel(B,2);Pixel(W,3);Pixel(B,1);Pixel(W,1);cout<<"\n";
        /*37*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,2);Pixel(W,5);Pixel(B,2);Pixel(W,2);Pixel(B,6);Pixel(W,5);Pixel(B,3);Pixel(W,1);cout<<"\n";
        /*38*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,1);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,3);Pixel(W,3);Pixel(B,3);Pixel(W,2);Pixel(B,6);Pixel(W,2);Pixel(B,1);Pixel(W,3);Pixel(B,2);Pixel(W,1);cout<<"\n";
        /*39*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,2);Pixel(W,6);Pixel(B,2);Pixel(W,1);Pixel(B,2);Pixel(W,1);Pixel(B,2);Pixel(W,1);Pixel(B,1);Pixel(W,7);Pixel(B,1);Pixel(W,2);Pixel(B,2);Pixel(W,3);Pixel(B,1);Pixel(W,1);cout<<"\n";
        /*40*/  cout<<"\t\t";Pixel(W,1);Pixel(W,1);Pixel(B,9);Pixel(W,2);Pixel(B,4);Pixel(W,2);Pixel(B,17);Pixel(W,1);cout<<"\n";
        /*41*/  cout<<"\t\t";Pixel(W,37);cout<<"\n";

            cout<<"\n\n\t\tSnake Game Shadow"<<endl;
    cout<<"\t\tGAMEOVER"<<endl;
    cout<<"\t\tLevel : "<<level<<endl;
    cout<<"\t\tScore : "<<score<<endl;
    cout<<"\t\tTo continue press ENTER"<<endl;
    if(getch()!=13)goto gameOVER;
    main();
}


void levels(int level)
{
    for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXM;j++)
                table[i][j]=0;
    switch(level)
    {
    case 1:
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;

    case 2:
        table[MAXN/4][MAXM/4]=4;
        table[MAXN/4*3][MAXM/4*3]=4;
        table[MAXN/4][MAXM/4*3]=4;
        table[MAXN/4*3][MAXM/4]=4;
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 3:
        for(int i=MAXN/4;i<=MAXN/4*3;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
        case 4:
        for(int i=0;i<MAXM;i++)
            table[0][i]=4;
        for(int i=0;i<MAXM;i++)
            table[MAXN-1][i]=4;
        for(int i=0;i<MAXN;i++)
        {
            table[i][0]=4;
            table[i][MAXM-1]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=1;
            snake[i].y=snake_size-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 5:
        for(int i=MAXN/4;i<=MAXN/4*3;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=MAXM/4;i<=MAXM/4*3;i++)
        {
            table[MAXN/4][i]=4;
            table[MAXN/4*3][i]=4;
        }
        table[MAXN/2][MAXM/4]=0;
        table[MAXN/2][MAXM/4*3]=0;
        table[MAXN/4][MAXM/2]=0;
        table[MAXN/4*3][MAXM/2]=0;
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 6:
        for(int i=1;i<=MAXM-2;i++)
        {
            table[MAXN/4][i]=4;
            table[MAXN/4*3][i]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 7:
        for(int i=0;i<MAXN/4;i++)
        {
            table[i][MAXM/4]=4;
        }
        for(int i=0;i<MAXM/4;i++)
        {
            table[MAXN/4*3][i]=4;
        }
        for(int i=MAXM/4*3;i<=MAXM-1;i++)
        {
            table[MAXN/4][i]=4;
        }
        for(int i=MAXN/4*3;i<=MAXN-1;i++)
        {
            table[i][MAXM/4*3]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=MAXN/2;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 8:
        for(int i=0;i<MAXN/4;i++)
        {
            table[i][MAXM/4]=4;
        }
        for(int i=0;i<MAXM/4;i++)
        {
            table[MAXN/4*3][i]=4;
        }
        for(int i=MAXM/4*3;i<=MAXM-1;i++)
        {
            table[MAXN/4][i]=4;
        }
        for(int i=MAXN/4*3;i<=MAXN-1;i++)
        {
            table[i][MAXM/4*3]=4;
        }
        for(int i=0;i<MAXM;i++)
        {
            table[MAXN/2][i]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=MAXN/2-1;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 9:
        for(int i=1;i<MAXN-1;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/2]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=MAXM/2;i<=MAXM/4*3;i++)
        {
            table[1][i]=4;
        }
        for(int i=MAXM/4;i<=MAXM/2;i++)
        {
            table[MAXN-2][i]=4;
        }
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    case 10:
        for(int i=1;i<MAXN-1;i++)
        {
            table[i][MAXM/4]=4;
            table[i][MAXM/2]=4;
            table[i][MAXM/4*3]=4;
        }
        for(int i=MAXM/2;i<=MAXM/4*3;i++)
        {
            table[1][i]=4;
            table[MAXN-2][i]=4;
        }
        table[MAXN/2][MAXM/4*3]=0;
        for(int i=0;i<snake_size;i++)
        {
            snake[i].x=0;
            snake[i].y=snake_size-1-i;
            if(i==0)snake[i].type=2;
            else snake[i].type=1;
            table[snake[i].x][snake[i].y]=snake[i].type;
        }
        break;
    }

}
void saveGame()
{
    string s="" ;
    char c;
    int sc=score,l=level,a=apple;
    while(sc!=0)
        {
            c=sc%10+48;
            s=c+s;
            sc/=10;
        }
        ofstream score_of_load_game("score.txt",ios::out);
        if(score_of_load_game.is_open()){
             score_of_load_game<<s;


        }
        score_of_load_game.close();
        s="";
            while(a!=0)
        {
            c=a%10+48;
            s=c+s;
            a/=10;
        }
        ofstream apple_of_load_game("apple.txt",ios::out);
        if(apple_of_load_game.is_open()){
             apple_of_load_game<<s;


        }
        score_of_load_game.close();

        ofstream Video_Set("video.txt",ios::out);
        if(Video_Set.is_open()){
             Video_Set<<Video;


        }
        Video_Set.close();

    if(l!=10)s=l+48;
    else s="10";
    ofstream level_of_load_game("level.txt",ios::out);
    if(level_of_load_game.is_open())
    {
    level_of_load_game<<s;

    }
    level_of_load_game.close();
}

void loadGame()
{
    string load_score,load_level,load_apple;
    ifstream score_of_load_game("score.txt",ios::in);
    score_of_load_game>>load_score;
    score=atoi( load_score.c_str() );
    score_of_load_game.close();

    ifstream level_of_load_game("level.txt",ios::in);
    level_of_load_game>>load_level;
    level=atoi( load_level.c_str() );
    level_of_load_game.close();

    ifstream apple_of_load_game("apple.txt",ios::in);
    apple_of_load_game>>load_apple;
    apple=atoi( load_apple.c_str() );
    apple_of_load_game.close();

    ifstream Video_Set("video.txt",ios::in);
    Video_Set>>Video;
    Video_Set.close();

    //if(level.size()>1)level=10;
    //else level=level-48;
}
void colour(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}
