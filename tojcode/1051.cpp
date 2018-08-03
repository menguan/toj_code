#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1010;
const int MAXQ=500010;
int F[MAXN];
int find(int x)
{
    if(F[x]==-1)  return x;
    return F[x]=find(F[x]);
}
void bing(int u,int v)
{
     int t1=find(u);
     int t2=find(v);
     if(t1!=t2)
       F[t1]=t2;
}
bool vis[MAXN];
int ancestor[MAXN];
struct Edge
{
       int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void addedge(int u,int v)
{
     edge[tot].to=v;
     edge[tot].next=head[u];
     head[u]=tot++;
}
struct Query
{
     int q,next;
     int index;
}query[MAXQ*2];
int answer[MAXQ];
int h[MAXQ];
int tt,Q;
void add_query(int u,int v,int index)
{
     query[tt].q=v;
     query[tt].next=h[u];
     query[tt].index=index;
     h[u]=tt++;
     query[tt].q=u;
     query[tt].next=h[v];
     query[tt].index=index;
     h[v]=tt++;
}
void init()
{
     tot=0;tt=0;
     memset(head,-1,sizeof(head));
     memset(h,-1,sizeof(h));
     memset(vis,0,sizeof(vis));
     memset(F,-1,sizeof(F));
     memset(ancestor,0,sizeof(ancestor));
}
void LCA(int u)
{
     ancestor[u]=u;
     vis[u]=1;
     for(int i=head[u];i!=-1;i=edge[i].next)
     {
         int v=edge[i].to;
         if(vis[v]) continue;
         LCA(v);
         bing(u,v);
         ancestor[find(u)]=u;
     }
     for(int i=h[u];i!=-1;i=query[i].next)
     {
        int v=query[i].q;
        if(vis[v])
        {
            answer[query[i].index]=ancestor[find(v)];
        }
     }
}               
bool flag[MAXN];
int countnum[MAXN];       
int main()
{
    int n;
    int u,v,k;
    while(~scanf("%d",&n))
    {
       init();
       memset(flag,0,sizeof(flag));
       for(int i=1;i<=n;i++)
       {
               scanf("%d:(%d)",&u,&k);
               while(k--)
               {
                   scanf("%d",&v);
                   flag[v]=1;
                   addedge(u,v);
                   addedge(v,u);
               }
       }
       scanf("%d",&Q);
       for(int i=0;i<Q;i++)
       {
            char ch;
            cin>>ch;
            scanf("%d,%d)",&u,&v);
            add_query(u,v,i);
       }
       int root;
       for(int i=1;i<=n;i++)
       {
          if(!flag[i])
          {  
            root=i;
            break;
          }
       }
       LCA(root);
       memset(countnum,0,sizeof(countnum));
       for(int i=0;i<Q;i++)
         countnum[answer[i]]++;
       for(int i=1;i<=n;i++)
         if(countnum[i]>0)
           printf("%d:%d\n",i,countnum[i]);
    }
}
                
                                          
