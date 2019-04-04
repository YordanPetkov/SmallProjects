#include <iostream>

using namespace std;



int main()

{

        int x;

        int y;



        cout<<"Vuvedi stoinist za x: ";

        do {

                cin>> x;

        } while (x==0);



        cout<<"Vuvedi stoinost za y: ";

        do {

                cin>> y;

        } while (y==0);



        if (x>0)

        {

                        if (y>0)

                        {

                                        cout<<"\n          I kvadrant     "<<endl<<endl;

                                        cout<<"-----------------------------------\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"|                 |      I        |\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"-----------------------------------\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"-----------------------------------\n"<<endl;


                                        cout<<"Pri vuvedeni stoinosti za x="<<x<<" i y="<<y<<endl;

                        }

                        else

                        {

                                        cout<<"\n         IV kvadrant     "<<endl<<endl;

                                        cout<<"-----------------------------------\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"-----------------------------------\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"|                 |          IV   |\n";

                                        cout<<"|                 |               |\n";

                                        cout<<"-----------------------------------\n"<<endl;


                                        cout<<"Pri vuvedeni stoinosti za x="<<x<<" i y="<<y<<endl;

                        }

        }



        else if (x<0)

        {

                 if (y<0)

                 {

                                 cout<<"\n       III kvadrant     "<<endl<<endl;

                                 cout<<"-----------------------------------\n";

                                 cout<<"|                |               |\n";

                                 cout<<"|                |               |\n";

                                 cout<<"|                |               |\n";

                                 cout<<"-----------------------------------\n";

                                 cout<<"|                |               |\n";

                                 cout<<"|   III          |              |\n";

                                 cout<<"|                |               |\n";

                                 cout<<"-----------------------------------\n"<<endl;


                                 cout<<"Pri vuvedeni stoinosti za x="<<x<<" i y="<<y<<endl;

                 }

                 else

                 {

                                 cout<<"\n        II kvadrant     "<<endl<<endl;

                                 cout<<"-----------------------------------\n";

                                 cout<<"|                |               |\n";

                                 cout<<"|   II           |                |\n";

                                 cout<<"|                |               |\n";

                                 cout<<"-----------------------------------\n";

                                 cout<<"|                |               |\n";

                                 cout<<"|                |               |\n";

                                 cout<<"|                |               |\n";

                                 cout<<"-----------------------------------\n"<<endl;


                                 cout<<"Pri vuvedeni stoinosti za x="<<x<<" i y="<<y<<endl;

                 }

        }





        return 0;

}
