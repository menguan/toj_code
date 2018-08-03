#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int odd;
int dp[1010][1010];
int uu[1010];int vv[1010];
//int deg[10101010];
int main()
{
    int n;
    int u,v;
    while(scanf("%d",&n)!=EOF)
    {
       
       memset(dp,0,sizeof(dp));
       for(int i=4;i<=n;i++)
       {
           scanf("%d%d",&u,&v);
           uu[i]=u;
           vv[i]=v;
       }
       int ans=-1;
       for(int i=n;i>=4;i--)
       {
            u=uu[i];
            v=vv[i];
            ans=max(ans,dp[v][u]+dp[i][v]+dp[u][i]+3);
            dp[u][v]=dp[v][u]=max(dp[u][v],dp[u][i]+dp[i][v]+1);
      }
       ans=max(ans,dp[1][2]+dp[2][3]+dp[1][3]+3); 
       printf("%d\n",ans);
    }
} 