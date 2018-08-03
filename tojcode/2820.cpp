#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int dp[2010][2010];
int main()
{
  memset(dp,0,sizeof(dp));
  for(int i=0;i<2010;i++)
  {
    dp[i][1]=dp[i][i]=1;
  }
  for(int i=1;i<2010;i++)
  {
    for(int j=1;j<i;j++)
    {
      dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%10000;
    }
  }
  int n;
  while(cin>>n,n)
  {
    int sum=0;
    for(int i=0;i<=n;i++)
      sum=(sum+dp[n][i])%10000;  
    printf("%.4d\n",sum);
  }
}                    