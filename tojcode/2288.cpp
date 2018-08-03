#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
int id[1000];
int sz[1000];
int n,m;
struct node
{
       int x,y;
}city[1000];
struct Edge
{
      int x,y;
      long long len;
}edge[1000000]; 
void init()
{
     for(int i=1;i<=n;i++)
     {
         id[i]=i;
         sz[i]=1;
     }
}
int find(int p)
{
    while(p!=id[p])
    {
        id[p]=id[id[p]];
        p=id[p];
    }
    return p;
}
void uni(int p,int q)
{
     if(sz[p]>sz[q])
     {
         sz[p]+=sz[q];
         id[q]=p;
     }
     else
     {
         sz[q]+=sz[p];
         id[p]=q;
     }
}
int dis(node mm,node nn)
{
    return (mm.x-nn.x)*(mm.x-nn.x)+(mm.y-nn.y)*(mm.y-nn.y);
}
bool cmp(Edge mm,Edge nn)
{
     return mm.len<nn.len;
}
int main()
{
    int xx,yy;
    scanf("%d",&n);  
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&city[i].x,&city[i].y);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
       edge[cnt].x=i;
       edge[cnt].y=j;
       edge[cnt].len=dis(city[i],city[j]);
       cnt++;
    }   
    scanf("%d",&m);
    while(m--)
    {
          scanf("%d%d",&edge[cnt].x,&edge[cnt].y);
          edge[cnt].len=0;
          cnt++;
    }
    sort(edge,edge+cnt,cmp);
    long long ans=0;
    for(int i=0;i<cnt;i++)
    {
       //cout<<edge[i].x<<" "<<edge[i].y<<endl;
       xx=find(edge[i].x);
       yy=find(edge[i].y);
       //cout<<xx<<" "<<yy<<endl;
       if(xx==yy)
         continue;
       uni(xx,yy);
       //cout<<edge[i].len<<endl;
       if(edge[i].len==0)
         continue;
       printf("%d %d\n",edge[i].x,edge[i].y);
    }
    
   // while(1);
}         
                                             
