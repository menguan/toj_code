#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
int id[100010];int belong[100010];int deg[100010];
bool vis[100010];
int n,m;
int find(int p)
{
    int t=p;
    while(p!=id[p])
    {
        id[p]=id[id[p]];
        p=id[p];
    }
    return p;           
}           
int main()
{
    int u,v;
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m))
    {
        //memset(deg,0,sizeof(deg));
        //memset(belong,0,sizeof(belong));
        //memset(vis,0,sizeof(vis));
        for(int i=0;i<=n;i++)
        {
          id[i]=i;
          deg[i]=belong[i]=vis[i]=0;
          }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            //cin>>u>>v;
            deg[u]++;deg[v]++;
            u=find(u);
            v=find(v);
            if(u==v)  continue;
              id[u]=v;
        }
        for(int i=0;i<n;i++)
        {
            if(deg[i]!=2)
            {
               belong[find(i)]=-1;
            }
        }
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
           int tt=find(i);
           if(!vis[tt])
           {
               //cout<<i<<endl;
               //cout<<belong[i]<<endl;
               //cout<<id[i]<<endl;
               vis[tt]=1;
               ans1++;
               if(belong[tt]!=-1)
               {
                     ans2++;
               }           
           }   
        }
        printf("%d %d\n",ans1,ans2);
        //cout<<ans1<<" "<<ans2<<endl;
    }
}       