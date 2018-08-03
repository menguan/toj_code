#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
    int w,to,next;
}edge[50000];
int dis[1010];
int head[1010];int enu;
int cnt[1010];
bool used[1010];int n,x,y;int ans;
void addedge(int from,int to,int w)
{
     edge[enu].to=to;
     edge[enu].w=w;
     edge[enu].next=head[from];
     head[from]=enu++;
}   
int spfa(int s)
{
    int u,v;
    for(int i=1;i<=n;i++)
    {
      cnt[i]=0;
      used[i]=0;
      dis[i]=1010101001;
    }
    queue<int> q;
    q.push(s);
    dis[s]=0;
    used[s]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        used[u]=0;
        if(cnt[u]>n)
          return -1;
        cnt[u]++;  
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
             v=edge[i].to;
             int temp=dis[u]+edge[i].w;
             if(temp<dis[v])
             {
                dis[v]=temp;
                if(!used[v])
                {
                   used[v]=1;
                   q.push(v);
                }
             }
        }
    }
    if(dis[n]==1010101001)
       return -2;
    return dis[n];                                           
}           
                     
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
          cin>>n>>x>>y;
          memset(head,-1,sizeof(head));
          enu=0;
          int u,v,w;
          for(int i=1;i<=x;i++)
          {
               cin>>u>>v>>w;
               addedge(u,v,w);
          }
          for(int i=1;i<=y;i++)
          {
               cin>>u>>v>>w;
               addedge(v,u,-w);
          }
          for(int i=1;i<n;i++)
            addedge(i+1,i,0);
          ans=spfa(1);
          cout<<ans<<endl;
    }
}  
                         
        
