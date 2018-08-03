#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int g[300][300];
int main()
{
  while(cin>>n>>m)
  {
      //memset(g,-1,sizeof(g));
      for(int i=0;i<300;i++)
      for(int j=0;j<300;j++)
        g[i][j]=-1010101010;
      int u,v;
      while(m--)
      {
          cin>>u>>v;
          g[u][v]=1;
      }
      for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      for(int k=1;k<=n;k++)
      {
        g[j][k]=max(g[j][k],g[j][i]+g[i][k]);
      }
      int ans=n*(n-1)/2;
      for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
        if(g[i][j]>1||g[j][i]>1)
        {
          //cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
          ans--;
        }
      cout<<ans<<endl;
  }
}    
                              
