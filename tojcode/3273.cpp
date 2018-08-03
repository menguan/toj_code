#include<iostream>//f[i][j][k]=f[i-j][j][k-1]+f[i][j-1][k]ï¼Œ
#include<cstring>
using namespace std;
const int mod=10009;
long long dp[1010][1010];
void init()
{
     memset(dp,0,sizeof(dp));
     
     dp[1][1]=1;dp[0][0]=1;
     for(int i=1;i<=1000;i++)
     {
         for(int j=1;j<=i;j++)
         {
            dp[i][j]=(dp[i-1][j-1]+dp[i-j][j])%mod;
         }
     }
     //cout<<dp[2][1]<<" "<<dp[2][2]<<endl;
     //cout<<dp[3][1]<<" "<<dp[3][2]<<" "<<dp[3][3]<<endl;
     //cout<<dp[4][1]<<" "<<dp[4][2]<<" "<<dp[4][3]<<" "<<dp[4][4]<<endl;
}         
int main()
{
    int t;int a,b;
    init();
    cin>>t;
    while(t--)
    {
         cin>>a>>b;
         cout<<dp[a][b]<<endl;
    }
}     
    
    

