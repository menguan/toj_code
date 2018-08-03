#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
  int a,b;
}m[20010],dp[20010];
bool vis[20010];
bool cmp(node mm,node nn)
{
  if(mm.a==nn.a)
    return mm.b<nn.b;
  return mm.a>nn.a;
}  
int in[20010];
vector<int> edge[20010];
int main()
{
  int t;
 // cin>>t;
  scanf("%d",&t);
  int n;
  while(t--)
  {
    //cin>>n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       //cin>>m[i].a>>m[i].b;
       scanf("%d%d",&m[i].a,&m[i].b);
     //  vis[i]=0;
      dp[i].a=dp[i].b=1001010;
    }
    sort(m,m+n,cmp);
    int prea=0;
    int preb=0;
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
      int j=0;
      while(dp[j].a<=m[i].a||dp[j].b<=m[i].b)
      {
        j++;
      }
      dp[j].a=m[i].a;
      dp[j].b=m[i].b;
    }
    for(int i=0;i<n;i++)
      if(dp[i].a!=1001010)
        ans++;
    /*
    while(cnt<n)
    {
      for(int i=0;i<n;i++)
      {
        if(!vis[i])
        {
          vis[i]=1;
          prea=m[i].a;
          preb=m[i].b;
          cnt++;
          ans++;
          for(int j=i+1;j<n;j++)
          {
             if(!vis[j])
             if(m[j].a>prea&&m[j].b>preb)
             {
               vis[j]=1;
               cnt++;
               prea=m[j].a;
               preb=m[j].b;
             }
          }
        }
      }
    }
    */
    printf("%d\n",ans);
    //cout<<ans<<endl;
  }
}
   