#include <iostream>
using namespace std;
int w[21][21][21];
void f()
{
    for (int i=0;i<21;i++)
    {
        for (int j=0;j<21;j++)
        {
            for (int k=0;k<21;k++)
            {
                if(i==0||j==0||k==0)
                    w[i][j][k]=1;
                else if(i<j&&j<k)
                    w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                else
                    w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
            }
        }
    }
}
int main()
{
    f();
    int a,b,c;
    while (cin>>a>>b>>c)
    {
        if (a==-1&&b==-1&&c==-1)
          return 0;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "; 
        if (a<=0||b<=0||c<=0)
          cout<<1<<endl;  
        else if (a>20||b>20||c>20)
        {
            cout<<w[20][20][20]<<endl;
        }
        else
        {
            cout<<w[a][b][c]<<endl;
        }
    }
}