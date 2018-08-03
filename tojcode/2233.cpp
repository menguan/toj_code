#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ze[200010];
vector<int> fe[200010];
int cost[200010];
int res[210010];
int belong[210010];
int dep[210010];
int vis[210010];
int n,m;
int depth;
int cnt;
int in[210010];
int dfs(int u)
{
   vis[u]=1;
   for(int i=0;i<ze[u].size();i++)
   {
     int v=ze[u][i];
     if(!vis[v])
       dfs(v);
   }
   dep[depth--]=u;
}
int dfs2(int u)
{
  vis[u]=1;
  belong[u]=cnt;
  for(int i=0;i<fe[u].size();i++)
   {
     int v=fe[u][i];
     if(!vis[v])
       dfs2(v);
  }
}
int main()
{
   while(scanf("%d%d",&n,&m)!=EOF)
   {
     if(n==0&&m==0)
       break;
     int ans=0;
     memset(res,-1,sizeof(res));
     cnt=1;
     for(int i=1;i<=n;i++)
     {
       scanf("%d",&cost[i]);
       ze[i].clear();
       fe[i].clear();
     }
     int u,v;
     for(int i=0;i<m;i++)
     {
       scanf("%d%d",&u,&v);
       ze[u].push_back(v);
       fe[v].push_back(u);
     }
     memset(vis,0,sizeof(vis));
     depth=n;
     for(int i=1;i<=n;i++)
     {
       if(!vis[i])
         dfs(i);
     }
     memset(vis,0,sizeof(vis));
     cnt=1;
     for(int i=1;i<=n;i++)
     {
        //cout<<dep[i]<<endl;
        if(!vis[dep[i]])
        {
         // cout<<dep[i]<<endl;
          dfs2(dep[i]);
          cnt++;
        }
     }
     memset(in,0,sizeof(in));
     for(int i=1;i<=n;i++)
     {
       for(int j=0;j<ze[i].size();j++)
       {
         if(belong[i]!=belong[ze[i][j]])
         {
           in[belong[ze[i][j]]]++;
         }
       }
     }
     for(int i=1;i<=n;i++)
     {
       //cout<<belong[i]<<endl;
       if(in[belong[i]])  res[belong[i]]=0;
       else if(res[belong[i]]==-1||res[belong[i]]>cost[i])
       {
         res[belong[i]]=cost[i];
       }
     }
     for(int i=1;i<cnt;i++)
     {
       //cout<<res[i]<<endl;
       ans+=res[i];
     }
     printf("%d\n",ans);
   }
}
              
         
       