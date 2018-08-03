#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[600][600];
int wei[600];
int dfs(int n,int k)
{
    if(dp[n][k]!=-1)
      return dp[n][k];
    if(n<=1)
      return dp[n][k]=0;
    dp[n][k]=10101010;
    for(int i=1;i<=n;i++)
      dp[n][k]=min(n*(k+i)+dfs(i-1,k)+dfs(n-i,k+i),dp[n][k]);
    return dp[n][k];
}         
int main()
{
    int t;
    int n,k;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&k);
        
        printf("Case %d: %d\n",cas,dfs(n,k));
    }
}      

][r];
    for(int i=l;i<=r;i++)
    {
        int u=i+k;
        if(i!=l)
          u+=solve(l,i-1,i+k);
        if(i!=r)
          u+=solve(i+1,r,i+k);
        ans=min(ans,u);
    }
    return ans+s;}    
    */                                    
int main()
{
    int t;
    /*
    ofstream outfile("1784.txt",ios::out);
    
    for(int i=0;i<=500;i++)
    {
       for(int j=0;j<=500;j++)
       {
          outfile<<dfs(i,j)<<",";
       }
    }
    outfile.close();          
    */memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&k);
        
        
        printf("Case %d: %d\n",cas,dfs(n,k));
    }
}      

