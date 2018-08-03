#include<iostream>
#include<cstring>
using namespace std;


int main()
{
    int i,j,k;
    int go[101][101];
    int n;int m;
    int a[101];
    int maxnum;
    int f;
    int ans=0;
   int t;
   cin>>t;
    while (t--)
    {cin>>n>>m;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            cin>>go[i][j];
    maxnum=0;
    for (k=0;k<n;k++)
    {
        memset(a,0,sizeof(a));
        for (j=k;j<n;j++)
        {
            for (i=0;i<m;i++)
                a[i]+=go[j][i];
            f=0;
            for (i=0;i<m;i++)
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

