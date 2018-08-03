#include<iostream>
#include<cstring>
using namespace std;
int dp[1000][20];
const int mod=200000007;
int main()
{
    int t;
    int n,m;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
       cin>>n>>m;
       long long ans=0;
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=n;i++)
         dp[i][1]=m;
       for(int i=2;i<=n;i++)
       {
        for(int j=1;j<=m;j++)
        {
           dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*(m-j+1))%mod;
        }
       }
       for(int i=1;i<m;i++)
         ans=(ans+dp[n][i])%mod;
       cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}                    
