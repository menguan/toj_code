#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct f
{
   int x;
   int y;
   int len;
}edge[120000];
int n,k;
int is[120000];
int id[120000];
bool cmp(f mm, f nn)
{
     return mm.len>nn.len;
}
void init()
{
     for(int i=0;i<=n;i++)
       id[i]=i;
     memset(edge,0,sizeof(edge));
     memset(is,0,sizeof(is));
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
int uni(int p,int q)
{
    if(is[p])
    {
       id[q]=p;
    }
    else
      id[p]=q;
}                  
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      
      scanf("%d%d",&n,&k);init();
      for(int i=0;i<n-1;i++)
      {
         scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].len);
      }
      int g;
      while(k--)
      {
         scanf("%d",&g);
         is[g]=1;
      }       
      long long ans=0;int pp,qq;
      sort(edge,edge+n-1,cmp);
      for(int i=0;i<n-1;i++)
      {
          pp=find(edge[i].x);
          qq=find(edge[i].y);
          if(is[pp]&&is[qq])
          {
             ans+=edge[i].len;
          }
          else
            uni(pp,qq);
      }
      cout<<ans<<endl;
    }
}                  
                              
