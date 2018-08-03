#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
struct node
{
    int u;
    double dis;
    bool friend operator <(node aa,node bb)
    {
        return aa.dis<bb.dis;
    }
}tmp,nxt;
priority_queue<node> q;
double dis[60000];
struct Edge
{
    int v,next,c;
}edge[4000000];
int head[60000],cnt;
void addedge(int u,int v,int c)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    edge[cnt].c=c;
    head[u]=cnt++;
}
int n,m,v,c;
bool vis[60000];
int main()
{
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof(head));cnt=0;
        //memset(vis,,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d%d",&v,&c);
                addedge(i,v,c);
            }
        }
        int S,T,f;
        scanf("%d%d%d",&S,&T,&f);
        for(int i=0;i<50010;i++)dis[i]=-1;
        while(!q.empty())q.pop();
        dis[S]=f*1.0;
        tmp.u=S;
        tmp.dis=f*1.0;
        double ans=0;
        q.push(tmp);
        while(!q.empty())
        {
           tmp=q.top();
           q.pop();
           //cout<<tmp.u<<" "<<tmp.dis<<endl;
           //system("pause");
           if(fabs(tmp.dis)<0.0001) continue;
           if(tmp.u==T)
           {
               ans=tmp.dis;
               break;
           }
           for(int i=head[tmp.u];i!=-1;i=edge[i].next)
           {
               int v=edge[i].v;
               if(dis[v]<0)
               {
                   dis[v]=dis[tmp.u]*(1-edge[i].c/100.0);
                   nxt.u=v;
                   nxt.dis=dis[v];
                   q.push(nxt);
               }
               else if(dis[v]<dis[tmp.u]*(1-edge[i].c/100.0))
               {
                   dis[v]=dis[tmp.u]*(1-edge[i].c/100.0);
                   nxt.u=v;
                   nxt.dis=dis[v];
                   q.push(nxt);
               }
           }
        }
        if(dis[T]<0) puts("IMPOSSIBLE!");
        else printf("%.2f\n",f-ans);
    }
}
