/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int enu;int n,m,kk;int f;
struct Edge
{
   int u,v,w,next;
}edge[10000];
int head[600];
void addedge(int u,int v,int w)
{
     edge[enu].u=u;
     edge[enu].v=v;
     edge[enu].w=w;
     edge[enu].next=head[u];
     head[u]=enu;
     enu++;
}
int dis[600];
bool bf()
{
     dis[1]=0;
     for(int i=1;i<n;i++)
     for(int k=0;k<enu;k++)
     {
       
           if(dis[edge[k].v]>dis[edge[k].u]+edge[k].w)
             dis[edge[k].v]=dis[edge[k].u]+edge[k].w;
        
     }
     for(int k=0;k<enu;k++)
     {
       
           if(dis[edge[k].v]>dis[edge[k].u]+edge[k].w)
             return 1;
        
     }           
     return 0;
}
int main()    
{
    int u,v,w;
    scanf("%d",&f);
    while(f--)
    {
      memset(edge,0,sizeof(edge));
      memset(head,-1,sizeof(head));
      enu=0; 
      for(int i=0;i<600;i++)
      {
         dis[i]=10000000;
      }
      scanf("%d%d%d",&n,&m,&kk);
      for(int i=0;i<m;i++)
      {
          scanf("%d%d%d",&u,&v,&w);
          addedge(u,v,w);
          addedge(v,u,w);
      }
      for(int i=0;i<kk;i++)
      {
            scanf("%d%d%d",&u,&v,&w);
         addedge(u,v,-w);
      }
      if(bf())
        puts("YES");
      else
        puts("NO");
    }
}                 
      
