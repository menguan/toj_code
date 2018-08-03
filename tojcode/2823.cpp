#include<stdio.h>//把牛拆点  限制牛和牛流量为一 保证一只牛只有一份食物 这种类型题搞通
#include<string.h>
#include<algorithm>
#define inf 1010101010
using namespace std;
struct E
{
    int v,w,next;
}edg[1000000];
int dis[5000],gap[5000],head[5000],nodes;
int sourse,sink,nn;
void addedge(int u,int v,int w)
{
    edg[nodes].v=v;
    edg[nodes].w=w;
    edg[nodes].next=head[u];
    head[u]=nodes++;
    edg[nodes].v=u;
    edg[nodes].w=0;
    edg[nodes].next=head[v];
    head[v]=nodes++;
}
int dfs(int src,int aug)
{
    if(src==sink)return aug;
    int left=aug,mindis=nn;
    for(int j=head[src];j!=-1;j=edg[j].next)
    {
    	int v=edg[j].v;
    	if(edg[j].w)
        {
           if(dis[v]+1==dis[src])
           {
               int minn=min(left,edg[j].w);
               minn=dfs(v,minn);
               edg[j].w-=minn;
               edg[j^1].w+=minn;
               left-=minn;
               if(dis[sourse]>=nn)return aug-left;
               if(left==0)break;
           }
           if(dis[v]<mindis)
           mindis=dis[v];
        }
    }

        if(left==aug)
        {
            if(!(--gap[dis[src]]))dis[sourse]=nn;
            dis[src]=mindis+1;
            gap[dis[src]]++;
        }
        return aug-left;
}
int sap(int s,int e)
{
    int ans=0;
    nn=e+1;
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    gap[0]=nn;
    sourse=s;
    sink=e;
    while(dis[sourse]<nn)
    ans+=dfs(sourse,inf);
    return ans;
}
int main()
{
    int n,f,d;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        int s=0,t=n+n+f+d+1;
        nodes=0;
        int food,drink,a,b;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&food,&drink);
            for(int j=1;j<=food;j++)
            {
                scanf("%d",&a);
                addedge(a,f+i,1);
            }
            for(int j=1;j<=drink;j++)
            {
                scanf("%d",&b);
                addedge(f+n+i,f+n+n+b,1);
            }
        }
        for(int i=1;i<=f;i++)addedge(s,i,1);
        for(int i=1;i<=d;i++)addedge(f+n+n+i,t,1);
        for(int i=1;i<=n;i++)addedge(f+i,f+n+i,1);
        printf("%d\n",sap(s,t));
    }
}
