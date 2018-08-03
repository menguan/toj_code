#include<iostream>
#include<algorithm>
using namespace std;
int a[110][110];
int dp[110][110];
int main()
{
  int n;
  while(cin>>n,n)
  {
    for(int i=0;i<110;i++)
    for(int j=0;j<110;j++)
      a[i][j]=dp[i][j]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>a[i][j];
      
    for(int i=1;i<=n;i++)
      dp[1][i]=a[1][i];
      
    for(int i=2;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      dp[i][j]=a[i][j]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
      if(maxn<dp[n][i])
        maxn=dp[n][i];
    }
    cout<<maxn<<endl;
  }
}       