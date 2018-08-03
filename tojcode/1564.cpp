#include<iostream>
#include<cstring>
using namespace std;


int main()
{
    int i,j,k;
    int go[100][100];
    int n;
    int a[100];
    int maxnum;
    int f;
    int ans=0;

    while (cin>>n)
    {
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            cin>>go[i][j];
    maxnum=-10000000;
    for (k=0;k<n;k++)
    {
        memset(a,0,sizeof(a));
        for (j=k;j<n;j++)
        {
            for (i=0;i<n;i++)
                a[i]+=go[j][i];
            f=0;
            for (i=0;i<n;i++)
            {
                if (f+a[i]>=0)
                    f+=a[i];
                else
                    f=0;
                if (f>maxnum)
                    maxnum=f;
            }
        }
    }
    cout<<maxnum<<endl;
    }}
