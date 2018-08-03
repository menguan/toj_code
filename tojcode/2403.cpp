#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int head[100010],enu,inf=1010101010;
int vis[100010],dis[100010];
struct Edge
{
       int v,next;
}edge[10000010];
void addedge(int u,int v)
{
     edge[enu].v=v;
     edge[enu].next=head[u];
     head[u]=enu++;
}
int n;
int spfa(int st)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)
      dis[i]=inf;
    dis[st]=0;
    vis[st]=1;
    queue<int> q;
    q.push(st);
    int now;
    int v;
    int temp;
    while(!q.empty())
    {
      now=q.front();
      q.pop();
      vis[now]=0;
      for(int i=head[now];i!=-1;i=edge[i].next)
      {
            temp=dis[now]+1;
            v=edge[i].v;
            if(temp<dis[v])
            {
                 dis[v]=temp;
                 if(!vis[v])
                 {
                      vis[v]=1;
                      q.push(v);
                 }
            }
      }
    }
}                                   
int main()
{
    while(cin>>n)
    {
          memset(head,-1,sizeof(head));
          enu=0;
          for(int i=0;i<n;i++)
          {
               int u,m,v;
               cin>>u>>m;
               while(m--)
               {
                    cin>>v;
                    addedge(u,v);
               }
          }
          int s,e;
          cin>>s>>e;
          spfa(s);
          cout<<s<<" "<<e<<" "<<dis[e]-1<<endl;
    }
}               
