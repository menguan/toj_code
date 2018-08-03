#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
struct Edge
{
       int v,next;
}edge[10010];
int p=1,head[1010];
int cowcnt[1010];
int cowsum[1010];
bool flag[1010];
void dfs(int u,int cnt)
{
     int i,v;
     for(i=head[u];i!=0;i=edge[i].next)
     {
        v=edge[i].v;
        if(flag[v])
          continue;
        flag[v]=1;
        cowsum[v]+=cnt;
        dfs(v,cnt);
     }
}                                 
int main()
{
    int k,n,m,i,pas,u,v;
    scanf("%d%d%d",&k,&n,&m);
    for(i=0;i<k;i++)
    {
       scanf("%d",&pas);
       cowcnt[pas]++;
    }
    for(i=0;i<m;i++)
    {
       scanf("%d%d",&u,&v);
       edge[p].v=v;
       edge[p].next=head[u];
       head[u]=p++;
    }
    for(i=1;i<=n;i++)
    {
       memset(flag,0,sizeof(flag));
       cowsum[i]+=cowcnt[i];
       flag[i]=1;
       dfs(i,cowcnt[i]);
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
       if(cowsum[i]==k)
       {
           ans++;
       }
    }
    printf("%d\n",ans);
    //while(1);
}                                                                       
