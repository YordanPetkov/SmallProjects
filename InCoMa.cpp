///  1.สฮฯศะภุ เไ๐ๅ๑เ ํเ ฯภฯสภาภ
///  2.ัหภรภุ ฯฮ 2 ๗ๅ๐๒่ ํเ โ๑ÿ๊๚ไๅ ๊๚ไๅ๒๎ ๅ 1 - > \ -> \\ /*
///  3.ฯศุลุ ํเ๊๐เÿ ่์ๅ ํเ ๔เ้๋เ.txt
///  4.slaga6 go dolu vmesto moq adres ->"D:\\dani\\PROGRAMMING\\MY PROJECTS\\READY PROJECTS\\InCoMa\\DATA\\TheCodingText.txt"


#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <ctime>
#include<cmath>
#include<fstream>
#include<string>

#define ESCAPE 27
#define LOCATION "D:\\dani\\PROGRAMMING\\MY PROJECTS\\READY PROJECTS\\InCoMa\\DATA\\TheCodingText.txt"

using namespace std;
string MyText="";
void TextReader();
void InCoMa();
void title();
bool Coding,FakeProfil;
int Date,BrGetchs=0,BrSpaces=7;
void CodingMashine();
void UnCodingMashine();
void FakeCodingMashine(bool random);
void MakeNewSpace();
void SetColor(int color)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}

void SaveTheText()
{
    string ans=LOCATION;
    ofstream reg (ans.c_str(),ios::app);
    if(reg.is_open())
    {
        reg<<endl;
        reg<<MyText;
        reg.close();

    }

}


COORD coord={0,0};
void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 int main()
{
    title();

    return 0;
}

void title()
{
    SetColor(137);
    cout<<"\t\t\t  Incredible Coding Mashine                             \n";
    SetColor(11);
    cout<<"             ******              ******              ***     ***\n";
    cout<<"            ///**/              **////              /** *   */**\n";
    cout<<"              /**    *******   /**         ******   /**/ * * /**    ******\n";
    cout<<"              /**   //**///**  /**        **////**  /** / *  /**   **////**\n";
    cout<<"              /**    /**  /**  /**       /**   /**  /**  /   /**  /**   /**\n";
    cout<<"              /**    /**  /**  /**       /**   /**  /**      /**  /**   /***\n";
    cout<<"             ******  ***  /**  //******  //******   /**      /**  //******/**\n";
    cout<<"            //////  ///   //    //////    //////    //       //    /////////\n";
    SetColor(143);
    cout<<"\n\n\t\t  Program by: Yordan Petkov and Kaloqn Botev                    ";
    SetColor(95);
    cout<<"\n\t\t\tPress Any Key to Continue...                            ";
    SetColor(15);
    char x;
    x = getch();
    if(x==ESCAPE) return;

/***************************LOADING DATABASE DESIGN**********************/
    SetColor(7);
    system("cls");
    cout<<"\n\n\n\n\n\t\t\t\tLoading Database...";
    cout<<"\t\t\t";

    gotoxy(3,9);
    printf("\t\t\tษอออออออออออออออออออออออออออออออออป");
    gotoxy(3,10);

    printf("\t\t\tบ                                 บ");

    gotoxy(3,11);
    printf("\t\t\tศอออออออออออออออออออออออออออออออออผ");
    SetColor(153);
    for(int k=25;k<58;k++)
    {

    Sleep(40);
    gotoxy(k,10);
    cout<<" ";
    }
    Sleep(30);
    SetColor(15);
    cout<<endl;
    system("cls");

    ///START InCoMa
    InCoMa();

    ///Loading Coding
    system("cls");
    SetColor(137);
    cout<<"\t\t\t  Incredible Coding Mashine                             \n";
    gotoxy(31,5);
    cout<<"Loading Coding Text...";
    SetColor(11);

    for(int i=1;i<=100;i++)
    {
        gotoxy(40,6);
        cout<<i<<"%";
        if(i==50)SaveTheText();
        Sleep(20);
    }



    Sleep(30);
    system("CLS");
    SetColor(137);
    cout<<"\t\t\t  Incredible Coding Mashine                             \n";
    SetColor(95);
    cout<<"\n\t\t\tThe Coding Text is :                                    \n\n";
    SetColor(121);
    cout<<"  ->  "<<MyText<<endl;

    SetColor(95);
    cout<<"\n\t\t\tPress Any Key to Continue...                            ";
    SetColor(15);
    char x1;
    x1 = getch();
    if(x1==ESCAPE) return;

    //LOADING END
    SetColor(7);
    system("cls");
    cout<<"\n\n\n\n\n\t\t\t\tLoading Deconstruction...";
    cout<<"\t\t\t";

    gotoxy(3,9);
    printf("\t\t\tษอออออออออออออออออออออออออออออออออป");
    gotoxy(3,10);

    printf("\t\t\tบ                                 บ");

    gotoxy(3,11);
    printf("\t\t\tศอออออออออออออออออออออออออออออออออผ");
    SetColor(153);
    for(int k=25;k<58;k++)
    {

    Sleep(40);
    gotoxy(k,10);
    cout<<" ";
    }
    Sleep(30);
    SetColor(15);
    cout<<endl;
    system("cls");

    //LOGO END
    SetColor(137);
    cout<<"\t\t\t  Incredible Coding Mashine                             \n";
    SetColor(11);
    cout<<"             ******              ******              ***     ***\n";
    cout<<"            ///**/              **////              /** *   */**\n";
    cout<<"              /**    *******   /**         ******   /**/ * * /**    ******\n";
    cout<<"              /**   //**///**  /**        **////**  /** / *  /**   **////**\n";
    cout<<"              /**    /**  /**  /**       /**   /**  /**  /   /**  /**   /**\n";
    cout<<"              /**    /**  /**  /**       /**   /**  /**      /**  /**   /***\n";
    cout<<"             ******  ***  /**  //******  //******   /**      /**  //******/**\n";
    cout<<"            //////  ///   //    //////    //////    //       //    /////////\n";
    SetColor(143);
    cout<<"\n\n\t\t  Program by: Yordan Petkov and Kaloqn Botev                    ";
    SetColor(95);
    cout<<"\n\t\t\tPress Any Key to Continue...                            ";
    SetColor(15);
    char x2;
    x2 = getch();
    if(x2==ESCAPE) return;


    return;




}








///~~~~~~~~~~~~~~~~~~~~INCOMA
void InCoMa()
{
        SetColor(137);
    cout<<"\t\t\t  Incredible Coding Mashine                             \n";
    SetColor(95);
    cout<<"\n\t\t\tWrite your text here :                                  \n\n";
    SetColor(15);
    printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
    printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
    gotoxy(1,7);
    TextReader();
    //UNCODING
    ///BACKSPACE
}
void TextReader()
{

    //first date symbol
    srand(time(NULL));
    char FDSC;
    int RANDOM,FDS;
    FDSC=getch();BrGetchs++;
    if(FDSC==13)return;
    FDS=FDSC-48;
    RANDOM = rand()%6+1;
    FDSC=FDS+1+((RANDOM-1)*4)+64;
    if(FDS<0||FDS>3){FakeProfil=1;}
    cout<<FDSC;MyText+=FDSC;
    //second date symbol
    char SDSC;
    int SDS,RANDOM2;
    SDSC=getch();BrGetchs++;
    if(SDSC==13)return;
    SDS=SDSC-48;
    RANDOM2 = rand()%2+1;
    SDSC=SDS+1+((RANDOM2-1)*10)+96;
    if(SDS<0||SDS>9 ){FakeProfil=2;}
    cout<<SDSC;MyText+=SDSC;
    if(FDS==3 && SDS > 1){FakeProfil=3;}

    //DATE
    Date=FDS*10+SDS;
    //codingOrNoCoding
    char BinCodeC;
    int BinCodeI,RANDOM3;
    BinCodeI=getch()-48;BrGetchs++;
    if(BinCodeI+48==13)return;
    Coding=BinCodeI;
    RANDOM3 = rand()%26+1;
    BinCodeC=RANDOM3+96;
    if(BinCodeI!=1 && BinCodeI!=0){FakeProfil=4;}
    cout<<BinCodeC;MyText+=BinCodeC;
// Fake word
    if(FakeProfil!=0){FakeCodingMashine(0);return;}
    char FakeWordC;
    int FakeWordI,RANDOM4,BrChars;
    FakeWordI=getch()-48;BrGetchs++;
    if(FakeWordI==13)return;
    Coding=FakeWordI;
    RANDOM4 = rand()%26+1;
    FakeWordC=RANDOM4+96;
    BrChars=FakeWordI;
    if(FakeWordI<0||FakeWordI>9){FakeProfil=6;}
    cout<<FakeWordC;

    for(int i=1;i<=BrChars;i++)
    {
        int RANDOM5,FWI;
        char FWC;
        FWC=getch();BrGetchs++;
        RANDOM5 = rand()%26+1;
        FakeWordC=RANDOM5+96;
        cout<<FakeWordC;MyText+=FakeWordC;
    }
    int FAKEprofilOrNot;

    FAKEprofilOrNot=getch();BrGetchs++;
    if(FAKEprofilOrNot!=32 && FAKEprofilOrNot!=13){FakeProfil=8;FakeCodingMashine(1);}
    if(FAKEprofilOrNot==32){cout<<" ";MyText+=" ";}
    //if(FakeProfil)cout<<"\nYOU ARE A HACKERRRRRR"<<endl;
    //else cout<<"\nHELLO WORLD"<<endl;
    if(FakeProfil!=0){FakeCodingMashine(0);}
    else {
          if(BinCodeI==1)CodingMashine();
          if(BinCodeI==0)UnCodingMashine();
    }


}


//CODING MASHINE
void CodingMashine()
{
    StartWritingCM:
    int newChar,PosOfChar,TheCodingCode;
    char CodingChar;
    newChar=getch();BrGetchs++;

    if(BrGetchs==79)MakeNewSpace();
    if(newChar>='A' && newChar<='Z')
    {
            PosOfChar=newChar-64;
            //TheCodingCode=(PosOfChar+31+Date)%26+1;
            TheCodingCode=26-PosOfChar+Date/2+Date%10;
            if(TheCodingCode>26)TheCodingCode-=26;
            CodingChar=TheCodingCode+64;
    }
   else if(newChar>='a' && newChar<='z'){
            PosOfChar=newChar-96;
            //TheCodingCode=(PosOfChar+31+Date)%26+1;
            TheCodingCode=26-PosOfChar+Date/2+Date%10;
            if(TheCodingCode>26)TheCodingCode-=26;
            CodingChar=TheCodingCode+96;
    }
         else
         {
             if(newChar==13)return;

             else
             CodingChar=newChar;
         }
    cout<<CodingChar;MyText+=CodingChar;
    if(newChar==8 && BrGetchs>1)
         {
             MyText.erase(MyText.size()-2,1);
             cout<<" "<<CodingChar;
         }
    goto StartWritingCM;
}
//UNCODING MASHINE
void UnCodingMashine()
{
    StartWritingUCM:
    int newChar,PosOfChar,TheUnCodingCode;
    char UnCodingChar;
    newChar=getch();BrGetchs++;

    if(BrGetchs==79)MakeNewSpace();
    if(newChar>='A' && newChar<='Z')
    {
            PosOfChar=newChar-64;
            TheUnCodingCode=26-PosOfChar+Date/2+Date%10;
            if(TheUnCodingCode>26)TheUnCodingCode-=26;
            UnCodingChar=TheUnCodingCode+64;
    }
   else if(newChar>='a' && newChar<='z'){
            PosOfChar=newChar-96;
            TheUnCodingCode=26-PosOfChar+Date/2+Date%10;
            if(TheUnCodingCode>26)TheUnCodingCode-=26;
            UnCodingChar=TheUnCodingCode+96;
    }
         else
         {
             if(newChar==13)return;

             else
             UnCodingChar=newChar;
         }
    cout<<UnCodingChar;MyText+=UnCodingChar;
    if(newChar==8 && BrGetchs>1)
         {
             MyText.erase(MyText.size()-2,1);
             cout<<" "<<UnCodingChar;
         }
    goto StartWritingUCM;

}
//FAKE CODING MASHINE
void FakeCodingMashine(bool random)
{
    StartWritingFCM:
    int newChar,RANDOMFCN;
    char FCodingChar;
    newChar=getch();BrGetchs++;
    if(BrGetchs==79)MakeNewSpace();

    if(newChar>='A' && newChar<='Z')
    {
            RANDOMFCN = rand()%26+65;
            FCodingChar = RANDOMFCN;

    }
   else if(newChar>='a' && newChar<='z')
    {
            RANDOMFCN = rand()%26+97;
            FCodingChar = RANDOMFCN;
    }
         else
         {
             if(newChar==13)return;

             else
             {
                 FCodingChar=newChar;
             }

         }

         cout<<FCodingChar;MyText+=FCodingChar;
         if(newChar==8 && BrGetchs>1)
         {
             MyText.erase(MyText.size()-2,1);
             cout<<" "<<FCodingChar;
         }
         if(random==1)return;
    goto StartWritingFCM;
}


void MakeNewSpace()
{
    BrGetchs=1;
    BrSpaces++;
    gotoxy(0,BrSpaces);
    cout<<"\t\t\t\t\t\t\t\t\t\t";
    gotoxy(0,BrSpaces+1);
    printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
    gotoxy(1,BrSpaces);




}
