#include<iostream>//照着别人的代码打了一遍 
#include<cstring>
#include<stdio.h>
#define MAXN 10010
using namespace std;
int first[MAXN],second[MAXN],head[MAXN];
int n,depth,size;
bool flag[MAXN];
struct Edge
{
   int v,next;
   Edge(){};
   Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXN];
inline void initial()
{
   size=0;
   memset(head,-1,sizeof(head));
}
inline void add_edge(int u,int v)
{
   edge[size]=Edge(v,head[u]);
   head[u]=size++;
}
inline void dfs(int t)
{
   int i;
   flag[t]=1;
   first[t]=depth++;
   for(i=head[t];i!=-1;i=edge[i].next)
   {
      int u=edge[i].v;
      if(!flag[u])
        dfs(u);
   }
   second[t]=depth++;
}
int main()
{
    int i,j,k,T,u,v,Q;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d",&n);
       memset(first,0,sizeof(first));
       memset(second,0,sizeof(second));
       memset(flag,0,sizeof(flag));
       initial();
       for(i=1;i<n;i++)
       {
          scanf("%d%d",&u,&v);
          add_edge(v,u);
       }
       depth=0;
       dfs(0);
       scanf("%d",&Q);
       while(Q--)
       {
          scanf("%d%d",&u,&v);
          if(first[u]<first[v]&&second[u]>first[v])
              puts("Yes");
          else
              puts("No");
       }
       puts("");
    }
}                                                                                                                                                                             
