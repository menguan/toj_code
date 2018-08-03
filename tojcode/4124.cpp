#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int xx,yy,kk;
long long mod;
long long dp[210][110][210];
long long DP(int x,int y,int k)
{

    if(dp[x][y][k]!=-1)return dp[x][y][k];
    if(k==0)
    {

        if(x==y) dp[x][y][k]=1;
        else dp[x][y][k]=0;
    }
    else
    {
       if(x>0)
        dp[x][y][k]=(DP(x+1,y,k-1)+DP(x-1,y,k-1) )%mod;
        else if(x==0)
        dp[x][y][k]=(DP(x+1,y,k-1) )%mod;
    }
    return dp[x][y][k];

}
int main()
{
    memset(dp,-1,sizeof(dp));
    mod=1;
    for(int i=1;i<=32;i++)mod=mod*2LL;
    while(~scanf("%d%d%d",&xx,&yy,&kk))
    {
        printf("%lld\n",DP(xx,yy,kk));
    }
}
