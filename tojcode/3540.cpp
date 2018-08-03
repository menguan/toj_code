#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[60][100010];
int now[100010];
int main()
{
    int n,w;int p,m,c,v;
    while(cin>>n>>w)
    {
      memset(dp,0,sizeof(dp));
      for(int i=1;i<=n;i++)
      {
          memset(now,-1,sizeof(now));
          cin>>p>>m;
          for(int j=p;j<=w;j++)
          {
            now[j]=dp[i-1][j-p];
          }
          for(int j=1;j<=m;j++)
          {
              cin>>c>>v;
              for(int k=w;k>=c;k--)
              {
                 if(now[k-c]!=-1)
                 now[k]=max(now[k],now[k-c]+v);
              }
          }
          for(int j=0;j<=w;j++)
            dp[i][j]=max(now[j],dp[i-1][j]);
      }
      cout<<dp[n][w]<<endl;
    }           
} 
