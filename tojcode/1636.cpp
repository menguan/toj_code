#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
const int emax=100110;
const int nmax=3000;
struct minflow
{
    int ans,s,e;
    struct Ed
    {
        int v,cap,cost,next,re;
    }edge[emax];
    int k,head[nmax];
    int pre[nmax],dis[nmax];
    bool vis[nmax];
    void adde(int u,int v,int ca,int co)
    {
        edge[k].v=v;
        edge[k].cap=ca;
        edge[k].cost=co;
        edge[k].next=head[u];
        edge[k].re=k+1;
        head[u]=k++;

        edge[k].v=u;
        edge[k].cap=0;
        edge[k].cost=-co;
        edge[k].next=head[v];
        edge[k].re=k-1;
        head[v]=k++;
    }
    bool spfa()
    {
        int i;
        queue<int> q;
        memset(dis,-1,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[s]=0;
        q.push(s);
        vis[s]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                int v=edge[i].v;
                if(edge[i].cap&&(dis[v]==-1||dis[v]>dis[u]+edge[i].cost))
                {
                    dis[v]=dis[u]+edge[i].cost;
                    pre[v]=i;
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
            vis[u]=0;
        }
        if(dis[e]==-1)return 0;
        return 1;
    }
    int find()
    {
       int u,p,sum=1010101010;
       for(u=e;u!=s;u=edge[edge[p].re].v)
       {
           p=pre[u];
           sum=min(sum,edge[p].cap);
       }
       for(u=e;u!=s;u=edge[edge[p].re].v)
       {
           p=pre[u];
           edge[p].cap-=sum;
           edge[edge[p].re].cap+=sum;
           ans+=sum*edge[p].cost;
       }
    }
    int solve()
    {
        while(spfa())
        {
            find();
        }
        return ans;
    }
    void init()
    {
        memset(head,-1,sizeof(head));
        ans=k=0;
    }
};

int n,m;
int h[101010][2];
int hh[101010][2];
char s[200][200];
minflow mm;
int main()
{
    while(cin>>n>>m&&(n+m))
    {
        mm.init();
        mm.s=1;
        mm.e=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>s[i][j];
            }
        }
        int hcnt=0,mcnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='H')
                {
                        h[hcnt][0]=i;
                        h[hcnt][1]=j;
                        hcnt++;
                }
                if(s[i][j]=='m')
                {
                        hh[mcnt][0]=i;
                        hh[mcnt][1]=j;
                        mcnt++;
                }
            }
        }
        for(int i=0;i<hcnt;i++)
        {
            mm.adde(1,3+i,1,0);
        }
        for(int i=0;i<mcnt;i++)
        {
            mm.adde(3+hcnt+i,2,1,0);
        }
        for(int i=0;i<hcnt;i++)
        {
            for(int j=0;j<mcnt;j++)
            {
                int dd=abs(h[i][0]-hh[j][0])+abs(h[i][1]-hh[j][1]);
                mm.adde(3+i,3+hcnt+j,1,dd);
            }
        }
        cout<<mm.solve()<<endl;
    }
}
