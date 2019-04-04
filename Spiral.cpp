#include <iostream>
using namespace std;
int main()
{
        int n,i,j,a1,br=0,br2=0;
        int a[100][100];
        do
        {
                cout<<"n=";cin>>n;
        }
        while (n<1||n>100);
        int br1=n-1;
        cout<<"Vavedete nachalno chislo:";cin>>a1;
        for (i=0;i<n;i++)
        {
                for (j=br2;j<br1+1;j++)
                {
                        a[i][j]=a1+br;
                        br++;
                }
                for (j=br2+1;j<br1+1;j++)
                {
                        a[j][br1]=a1+br;
                        br++;
                }
                for (j=br1-1;j>=br2;j--)
                {
                        a[br1][j]=a1+br;
                        br++;
                }
                for (j=br1-1;j>br2;j--)
                {
                        a[j][i]=a1+br;
                        br++;
                }
                br1--;
                br2++;
        }
        for (i=0;i<n;i++)
        {
                for (j=0;j<n;j++)
                {
                        cout<<a[i][j]<<" ";
                }
                cout<<endl;
        }
        return 0;
}
