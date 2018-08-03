#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//vector<int> e[200010];
bool vis[50010];
int dis[50010];
int n,m,qq;
struct ee
{
  int next,v,w;
}edge[200020];
int head[50010];
int enu;
void addedge(int u,int v,int w)
{
  edge[enu].v=v;
  edge[enu].next=head[u];
  edge[enu].w=w;
  head[u]=enu++;
}
int main()
{
  cin>>n>>m>>qq;
  int u,v;
  int w;
  enu=0;
  memset(head,-1,sizeof(head));
  for(int i=0;i<m;i++)
  {
    cin>>u>>v>>w;
    addedge(u,v,w);
    addedge(v,u,w);
  }
  memset(vis,0,sizeof(vis));
  queue<int> q;
  for(int i=1;i<=n;i++)  dis[i]=1010101010;
  
  vis[1]=1;
  dis[1]=0;
  q.push(1);
  int tmp;
  while(!q.empty())
  {
    u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
      v=edge[i].v;
      w=edge[i].w;
      if(dis[v]>dis[u]+w)
      {
        dis[v]=dis[u]+w;
        if(!vis[v])
        {
          q.push(v);
        }
      }
    }
  }
  while(qq--)
  {
    cin>>u>>v;
      cout<<dis[u]+dis[v]<<endl;
  }
  //while(1);
}
  
    
    