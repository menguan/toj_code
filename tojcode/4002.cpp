#include<iostream>//主要是求树的直径
#include<cstdio>
#include<cstring>
#include<cstdio>
using namespace std;
struct Edge{
    int v,nxt;
}edge[200010];

int n,m,cnt,head[100010];
int dis[100010];

void addedge(int cu,int cv){
    edge[cnt].v=cv;    edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
}

void dfs(int u){
    for(int i=head[u];i!=-1;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(dis[v]==-1)
        {
            dis[v]=dis[u]+1;
            dfs(v);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        cnt=0;
        memset(head,-1,sizeof(head));
        int u,v;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        memset(dis,-1,sizeof(dis));
        dis[1]=0;
        dfs(1);
        int len=0;
        for(int i=1;i<=n;i++)
            if(dis[i]>len)
            {
                len=dis[i];
                u=i;
            }
        memset(dis,-1,sizeof(dis));
        dis[u]=0;
        dfs(u);
        len=0;
        for(int i=1;i<=n;i++)
            if(dis[i]>len)
                len=dis[i];
        len++;
        int k;
        while(m--)
        {
            scanf("%d",&k);
            if(len>=k)
                printf("%d\n",k-1);
            else
                printf("%d\n",(len-1)+(k-len)*2);
        }
    }
}
