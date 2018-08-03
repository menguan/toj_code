#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char s[300];
int dp[300][300];
int wei[300];
bool jud(int l,int r,int op)
{
    for(int i=l;i<l+op;i++)
    {
        for(int j=i+op;j<=r;j+=op)
            if(s[i]!=s[j])
              return 0;
    }
    return 1;
}
int DP(int l,int r)
{
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r) return dp[l][r]=1;
    dp[l][r]=101010;
    for(int i=l;i<r;i++)
    {
        dp[l][r]=min(dp[l][r],DP(l,i)+DP(i+1,r));
    }
    for(int i=1;i<=r-l+1;i++)
    {
        if((r-l+1)%i==0&&jud(l,r,i))
            dp[l][r]=min(dp[l][r],DP(l,l+i-1)+wei[(r-l+1)/i]+2);
    }
    return dp[l][r];
}
int main()
{
    int t;
    for(int i=0;i<10;i++)wei[i]=1;
    for(int i=10;i<100;i++)wei[i]=2;
    for(int i=100;i<300;i++)wei[i]=3;
    cin>>t;
    while(t--)
    {
       cin>>s;
       int len=strlen(s);
       memset(dp,-1,sizeof(dp));
       cout<<DP(0,len-1)<<endl;
    }
}
