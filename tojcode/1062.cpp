#include<iostream>
#include<cstring>
int a[110][110];
using namespace std;

int main()
{
    int s,c;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s>>c;
        for(int i=0;i<s;i++)
            cin>>a[0][i];
        for(int i=1;i<s;i++)
            for(int j=0;j<s-i;j++)
        {
            a[i][j]=a[i-1][j+1]-a[i-1][j];
        }
        for(int i=1;i<=c;i++)
          a[s-1][i]=a[s-1][0];
        for(int i=s-2;i>=0;i--)
            for(int j=0;j<=c;j++)
        {
            a[i][s-i+j]=a[i][s-i-1+j]+a[i+1][s-i-1+j];
        }
        cout<<a[0][s];
        for(int i=1;i<c;i++)
                cout<<" "<<a[0][s+i];
        cout<<endl;
    }
}
