#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstdio>
using namespace std;
int dis[3000];
int x[60],y[60];
int g[60][60];
int d[60][60];
int que[60],dp[60];
//bool use[60];
int n,k;
int cnt,maxn;
void build(int p)
{
    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(d[i][j]>=p) g[i][j]=g[j][i]=1;
        }
    }
}
bool dfs(int u,int pos)
{
    int j;
    for(int i=u+1;i<n;i++)
    {
        if(dp[i]+pos<=maxn) return 0;
        if(g[u][i])
        {
            for(j=0;j<pos;j++)if(!g[i][que[j]]) break;
            if(j==pos)
            {
                que[pos]=i;
                if(dfs(i,pos+1)) return 1;
            }
        }
    }
    if(pos>maxn)
    {
        maxn=pos;
        return 1;
    }
    return 0;
}
int fun()
{
    maxn=-1;
    //memset(use,0,sizeof(use));
    for(int i=n-1;i>=0;i--)
    {
       que[0]=i;
       dfs(i,1);
       dp[i]=maxn;
    }
    return maxn;
}
int main()
{
   while(~scanf("%d%d",&n,&k))
   {
       cnt=0;
       for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
        //cin>>x[i]>>y[i];
       for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
       {
           d[i][j]=d[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
           dis[cnt++]=d[i][j];
       }
       sort(dis,dis+cnt);
       int l=0,r=cnt,mid;
       while(l+1!=r)
       {
           mid=(l+r)/2;
           build(dis[mid]);
           if(fun()>=k)
           {
               l=mid;
           }
           else
           {
               r=mid;
           }
       }
       printf("%.2f\n",sqrt(1.0*dis[l]));
   }
}
