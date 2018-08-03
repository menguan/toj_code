#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1010101010;
int n,m;
struct edge
{
    int v,c,w,next;
}e[150000];
int head[40000],cnt;
void addedge(int u,int v,int c,int w)
{
    e[cnt].v=v;
    e[cnt].c=c;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
    e[cnt].v=u;
    e[cnt].c=0;
    e[cnt].w=-w;
    e[cnt].next=head[v];
    head[v]=cnt++;
}
int a[40000],b[40000];
int S,T;
int dis[100010];
bool vis[100010];
int pre[100010];
int pos[100010];
int gao()
{
     int ans=0;
     while(1){
      for(int i=0;i<=T;i++) dis[i]=-1,vis[i]=0,pre[i]=i,pos[i]=0;
      queue<int> q;
      dis[S]=0;
      q.push(S);
      vis[S]=1;
      int u,v,w,c;

        while(!q.empty())
        {
            u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=head[u];i!=-1;i=e[i].next)
            {
                v=e[i].v;
                if(e[i].c>0&&dis[v]<dis[u]+e[i].w)
                {

                    pre[v]=u;
                    pos[v]=i;
                    dis[v]=dis[u]+e[i].w;
                    //cout<<u<<" "<<v<<dis[v]<<endl;
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }

                }
            }

         }
         //cout<<"kk"<<endl;
         if(dis[T]==-1) break;
         //cout<<dis[T]<<"jj"<<endl;
         int sum=inf;
         for(u=T;u!=S;u=pre[u])
         {
             c=e[pos[u]].c;
             sum=min(sum,c);
         }
         for(u=T;u!=S;u=pre[u])
         {
             e[pos[u]].c-=sum;
             e[pos[u]^1].c+=sum;
             ans+=sum*e[pos[u]].w;
         }
     }
     return ans;
}
int main()
{
    int t;
    //cin>>t;
    while(cin>>n,n)
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        S=0;T=366;
        for(int i=0;i<366;i++)
          addedge(i,i+1,2,0);
        int x,y,w;
        while(n--)
        {
            cin>>x>>y>>w;
            addedge(x,y+1,1,w);
        }

        cout<<gao()<<endl;
    }
}
