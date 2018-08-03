#include<iostream>
#include<cstring>
using namespace std;
long long dp[310][310];
int main()
{
    int i,j,n;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=300;i++)
           for(j=i;j>=0;j--)
               dp[i][j]=1;
    for(i=0;i<=300;i++)
         dp[0][i]=1;
    for(i=2;i<=300;i++)
         for(j=i/2;j>=1;j--)
               dp[i][j]=dp[i-2*j][j]+dp[i][j+1];
    while(cin>>n,n)
      cout<<n<<" "<<dp[n][1]<<endl;
}
