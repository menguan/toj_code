#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5010;
int n,m,cnt,ans;
int s,t,k;
int dp[N][510],vis[N][510],head[N];
struct Edge{
       int u,v,w;
       int next;
}edge[200010];
void init()
{
     cnt=0;
     memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
     edge[cnt].u=u;
     edge[cnt].v=v;
     edge[cnt].w=w;
     edge[cnt].next=head[u];
     head[u]=cnt++;
}
struct node{
       int a,b;
       node(){}
       node(int x,int y):a(x),b(y){}
};
void spfa()
{
     queue<node> q;
     memset(vis,0,sizeof(vis));
     int i,j;
     for(int i=0;i<=n;i++)
     for(int j=0;j<=k;j++)
       dp[i][j]=inf;
    dp[s][0]=0;
    vis[s][0]=1;
    q.push(node(s,0));
    while(!q.empty())
    {
       node u=q.front();
       q.pop();
       vis[u.a][u.b]=0;//前面被修改过 表示后面有可能再被修改 
       if(u.a==t&&u.b==k)
          ans=min(ans,dp[t][k]);
       for(i=head[u.a];i!=-1;i=edge[i].next)
       {
           node cur;
           cur.a=edge[i].v;
           cur.b=u.b+10;
           if(cur.b>=k)
             cur.b=k;
           //int temp=dp[cur.a][cur.b];  
           if(dp[cur.a][cur.b]>dp[u.a][u.b]+edge[i].w)
           {
              dp[cur.a][cur.b]=dp[u.a][u.b]+edge[i].w;
              
                 if(!vis[cur.a][cur.b])//只是为了防止队列中有重复 
                 {
                     vis[cur.a][cur.b]=1;
                     q.push(cur);
                 }
           }
       }
    }
}                                                                                                                                    

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
      init();
      int u,v,w;
      for(int i=0;i<m;i++)
      {
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
      }
      scanf("%d%d%d",&s,&t,&k);
      ans=inf;
      spfa();
      printf("%d\n",ans==inf?-1:ans);
    }
}                               
