#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[600][600];
long long dp[600][600];
bool vis[600][600];
int m,n;
const long long inf=-10101010101010101010;
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m+n==0)  return 0;
        //memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
                dp[i][j]=inf;
        }
    for(int i=0;i<=n;i++)  vis[0][i]=1;
        long long ans=-2*inf;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%lld",&a[i][j]);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=n-m+i;j++)
            {
                for(int k=0;k<j;k++)
                {
                    if(vis[i-1][k])
                    {


                    if(vis[i][j]==0)
                    {
                        //cout<<"Kk"<<endl;
                        vis[i][j]=1;
                        dp[i][j]=dp[i-1][k]+a[i][j];

                    }else
                      dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                    //cout<<dp[i][j]-inf<<" "<<i<<" "<<j<<endl;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[m][i])  continue;
            ans=max(dp[m][i],ans);
        }
        printf("%lld\n",ans-inf);
    }
}
