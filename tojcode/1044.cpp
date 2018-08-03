#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
struct Edge
{
       int v,next;
}edge[6000000];
int enu;
int head[16000];
bool vis[16000];
int match[16000];
void addedge(int u,int v)
{
     edge[enu].v=v;
     edge[enu].next=head[u];
     head[u]=enu++;
}
bool dfs(int p)
{
     int v;
     for(int i=head[p];i!=-1;i=edge[i].next)
     {
          v=edge[i].v;
          if(!vis[i])
          {
            vis[i]=1;
            if(match[v]==-1||dfs(match[v]))
            {
                 match[v]=p;
                 return 1;
            }
          }
     }
     return 0;
}                                        
int main()
{
    int n;int u,num,v;
    while(scanf("%d",&n)!=EOF)
    {
        enu=0;
        memset(head,-1,sizeof(head));
        memset(match,-1,sizeof(match));
        for(int i=1;i<=n;i++)
        {
            scanf("%d:(%d)",&u,&num);
            while(num--)
            {
               scanf("%d",&v);
               addedge(u,v);
               addedge(v,u);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
             memset(vis,0,sizeof(vis));
             if(dfs(i))                                      
                ans++;
        }
        printf("%d\n",ans/2);
    }
}        

