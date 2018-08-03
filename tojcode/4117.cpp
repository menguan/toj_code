#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int g[110][110];
struct e{
       int u,v,w;
}ed[1000000];int gg;
bool cmp(e aa,e bb)
{
     return aa.w<bb.w;
}
int dp[110];
int find(int p)
{
    while(dp[p]!=p)
     p=dp[p];
     return p;
}
int unio(int a,int b,int c)
{
    int aa=find(a);
    int bb=find(b);
    if(aa==bb) return 0;
    else {
           dp[aa]=bb;
           gg++;
           return c;
    }
}
int n,t;
int main()
{
     while(cin>>n)
     {
                  int cnt=0;
                  gg=0;
                  for(int i=1;i<=n;i++)
                  {
                          for(int j=1;j<=n;j++)
                          {
                               cin>>g[i][j];
                               if(i!=j)
                               {
                                   ed[cnt].u=i;
                                   ed[cnt].v=j;
                                   ed[cnt].w=g[i][j];
                                   cnt++;
                               }
                          }
                  }
                  for(int i=1;i<=n;i++) dp[i]=i;
                  int u,v;
                  int ans=0;
                  cin>>u>>v;
                  ans+=unio(u,v,g[u][v]);
                  sort(ed,ed+cnt,cmp);
                  for(int i=0;i<cnt;i++)
                  {
                      ans+=unio(ed[i].u,ed[i].v,ed[i].w);
                      if(gg==n-1) break;
                  }
                  cout<<ans<<endl;
     }
}
