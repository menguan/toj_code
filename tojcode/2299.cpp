#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10010;
struct Edge
{
       int v,next;
}edge[N<<2];
int head[N],vis[N],dfn[N],low[N],cut[N];
int cnt,root,k;
void addedge(int u,int v)
{
     edge[cnt].v=v;
     edge[cnt].next=head[u];
     head[u]=cnt++;
}
void tarjan(int u,int fa)
{
     int son=0;
     vis[u]=1;
     dfn[u]=low[u]=++k;
     for(int i=head[u];i!=-1;i=edge[i].next)
     {
           int v=edge[i].v;
           if(vis[v]==1&&v!=fa)
           {
              low[u]=min(low[u],dfn[v]);
           }
           if(!vis[v])
           {
              tarjan(v,u);
              son++;
              low[u]=min(low[u],low[v]);
              if((u==root&&son>1)||(u!=root&&dfn[u]<=low[v]))
                cut[u]++;
           } 
     }
     vis[u]=2;
}               
                                 
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n)
    {
      if(m==0)
      {
        cout<<n-1<<endl;
        continue;
      }
      memset(head,-1,sizeof(head));
      memset(vis,0,sizeof(vis));
      memset(cut,0,sizeof(cut));
      memset(dfn,0,sizeof(dfn));
      cnt=0;
      int u,v;
      while(m--)
      {
           scanf("%d%d",&u,&v);
           addedge(u,v);
           addedge(v,u);
      }
      int ans=0;int MAX=0;
      for(int i=0;i<n;i++)
      {
         if(!dfn[i])
         {
             ans++;
             k=0;
             root=i;
             tarjan(i,-1);
         }
         MAX=max(MAX,cut[i]);
      }
      cout<<ans+MAX<<endl;
    }
}                     
                                  
