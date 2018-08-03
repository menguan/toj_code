#include<iostream>
#include<cstring>
#include<algorithm>
int dp[1200]; int wi,vi;
int w[120];
int v[120];
using namespace std;
int main()
{
  int n,V;int ans;
  
  while(cin>>n>>V)
  {
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
     cin>>w[i];
    for(int i=0;i<n;i++)
     cin>>v[i];
    for(int i=0;i<n;i++)
    {
      for(int j=w[i];j<=V;j++)
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }      
    ans=0;
    for(int i=0;i<=V;i++)
      if(dp[i]>ans)
        ans=dp[i];
    cout<<ans<<endl;
  }
}            