#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
       int to,next;
}edge[100010];
int n,enu,head[100010],f[100010],ans[100010];
void add(int u,int v)
{
     edge[enu].to=v;
     edge[enu].next=head[u];
     head[u]=enu++;
}
void dfs1(int v,int u)
{
     int to;
     for(int i=head[v];i!=-1;i=edge[i].next)
     {
         to=edge[i].to;
         if(to!=u)
         {
            dfs1(to,v);
            f[v]+=f[to];
         }
     }
}
void dfs2(int v,int u)
{
     int to,a,b;
     for(int i=head[v];i!=-1;i=edge[i].next)
     {
         to=edge[i].to;
         ans[v]=max(f[to],ans[v]);
         if(to!=u)
         {
            // cout<<to<<endl;
              a=f[v];
              b=f[to];
              f[v]=a-b;
              f[to]=a;
              dfs2(to,v);
              f[v]=a;
              f[to]=b;
         }
     }
}   
int main()
{
    cin>>n;
    enu=0;
    memset(head,-1,sizeof(head));
    memset(ans,0,sizeof(ans));
    int u,v;
    for(int i=1;i<n;i++)
    {
       cin>>u>>v;
       add(u,v);
       add(v,u);
       f[i]=1;
    }
    f[n]=1;
    dfs1(1,-1);
    dfs2(1,-1);
    /*
    for(int i=1;i<=n;i++)
    {
      ans[i]=-1;
      ans[i]=max(ans[i],n-f[i]);
      for(int j=head[i];j!=-1;j=edge[j].next)
      {
         ans[i]=max(ans[i],f[edge[j].to]);
      }     
      cout<<i<<" "<<ans[i]<<endl;
    }*/
    int minn=1010101010,first=0;
    for(int i=1;i<=n;i++)
      minn=min(minn,ans[i]);
    for(int i=1;i<=n;i++)
    {
      if(ans[i]==minn)
      {
         if(first)  cout<<" ";
         cout<<i; first=1;
      }
    }
    cout<<endl;
    //while(1);
}             
            
      
          

+)
    {
      if(ans[i]==minn)
      {
         if(first)  cout<<" ";
         cout<<i; first=1;
      }
    }
    cout<<endl;
    //while(1);
}             
            
      
          

