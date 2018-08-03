#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int ar[8][8],sum[8],minn,n;

int judge()
{
    int i,maxn=0;
    for (i=0;i<n;i++)
        if(maxn<sum[i])maxn=sum[i];
    if(maxn>minn)return 0;
    return 1;
}

void dfs(int i)
{
    int j,k,l,maxn=0;
    if(i==n)
    {
        for (j=0;j<n;j++)
            if(maxn<sum[j])maxn=sum[j];
        if(maxn<minn)minn=maxn;
        return;
    }
    for (l=0;l<n;l++)
    {
        for (k=0,j=(n-l)%n;k<n;k++,j++)
            sum[k]+=ar[i][j%n];
        if(judge())dfs(i+1);
        for (k=0,j=(n-l)%n;k<n;k++,j++)
            sum[k]-=ar[i][j%n];
    }
}

int main()
{
    int i,j;
    while (cin>>n&&~n)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                cin>>ar[i][j];
        }
        minn=0x3f3f3f3f;
        for(i=0;i<n;i++)sum[i]=ar[0][i];
        dfs(1);
        cout<<minn<<endl;
    }
}
