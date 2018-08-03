#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
using namespace std;
int n,m;
struct Edge
{
       int u,v;int w;
       int next;
}edge[310];
int head[310];int cnt;
int dis[210];
void addedge(int u,int v,int w)
{
     edge[cnt].v=v;
     edge[cnt].u=u;
     edge[cnt].w=w;
     edge[cnt].next=head[u];
     head[u]=cnt++;
}
bool bf()
{
     for(int i=0;i<=n;i++)
     {
        dis[i]=1010101010;
     }
     dis[0]=0;
     for(int i=1;i<=n;i++)
     {
       for(int j=0;j<cnt;j++)
       {
           if(dis[edge[j].u]+edge[j].w<dis[edge[j].v])
           {
                dis[edge[j].v]=dis[edge[j].u]+edge[j].w;
           }
       }
     }
     for(int j=0;j<cnt;j++)
     {
          if(dis[edge[j].u]+edge[j].w<dis[edge[j].v])
          {
                return 0;
          }   
     }
     return 1;
}                                                          
int main()
{
    int u,v,w;string s;
    while(cin>>n,n)
    {
       cnt=0;
       cin>>m;
       while(m--)
       {
         cin>>u>>v>>s>>w;
         if(s[0]=='g')
         {
             addedge(u+v,u-1,-w-1);
         }
         else 
             addedge(u-1,u+v,w-1);
       }
       if(bf())
         cout<<"lamentable kingdom"<<endl;
       else
         cout<<"successful conspiracy"<<endl;
    }
}                
                              

