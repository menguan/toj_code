#include<iostream>//最小割  直接找的 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2010;
const int M=550000;
const int inf=(1<<28);
int head[N];
struct Edge
{
    int v,next,w;
} edge[M];
int cnt,n,s,t;
void addedge(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].w=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
int sap()
{
    int pre[N],cur[N],dis[N],gap[N];
    int flow=0,aug=inf,u;
    bool flag;
    for(int i=0; i<n; i++)
    {
        cur[i]=head[i];
        gap[i]=dis[i]=0;
    }
    gap[s]=n;
    u=pre[s]=s;
    while(dis[s]<n)
    {
        flag=0;
        for(int &j=cur[u]; j!=-1; j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=1;
                if(edge[j].w<aug) aug=edge[j].w;
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    flow+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        edge[cur[u]].w-=aug;
                        edge[cur[u]^1].w+=aug;
                    }
                    aug=inf;
                }
                break;
            }
        }
        if(flag) continue;
        int mindis=n;
        for(int j=head[u]; j!=-1; j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=j;
            }
        }
        if((--gap[dis[u]])==0)
            break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return flow;
}


int main()
{
    int m,p;
    while(scanf("%d%d",&m,&p)!=-1)
    {
        cnt=0;
        memset(head,-1,sizeof(head));
        n=m+2;
        s=0,t=n-1;
        for(int i=1;i<=m;i++)
        {
            int x;scanf("%d",&x);
            addedge(s,i,x);
        }
        for(int i=1;i<=m;i++)
        {
            int x;scanf("%d",&x);
            addedge(i,t,x);
        }
        while(p--)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        int ans=sap();
        printf("%d\n",ans);
    }
    return 0;
}
 
