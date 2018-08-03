#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int belong [6000];
bool instack[6000];
int stack[6000];
int in[6000];//写完之后发现其实没有必要计算入度 
int out[6000];
int head[6000];
int dfn[6000];
int low[6000];
int cnt;
int enu;
int depth;
int top;
vector<int> ans;
struct Edge
{
       int v,next;
}edge[100000];
void init()
{
     top=0;
     cnt=0;
     enu=0;
     depth=1;
     ans.clear();
     memset(head,-1,sizeof(head));
     memset(in,0,sizeof(in));
     memset(out,0,sizeof(out));
     memset(stack,0,sizeof(stack));
     memset(instack,0,sizeof(instack));
     memset(edge,0,sizeof(edge));
     memset(belong,0,sizeof(belong));
     memset(dfn,0,sizeof(dfn));
     memset(low,0,sizeof(low));
}
void addedge(int u,int v)
{
     edge[enu].v=v;
     edge[enu].next=head[u];
     head[u]=enu++;
}
void tarjan(int v)
{
     int u;
     dfn[v]=low[v]=depth++;
     stack[top++]=v;
     instack[v]=1;
     for(int i=head[v];i!=-1;i=edge[i].next)
     {
        u=edge[i].v;
        if(!dfn[u])
        {
           tarjan(u);
           low[v]=min(low[v],low[u]);
        }
        else if(instack[u])
        {
           low[v]=min(low[v],low[u]);
        }
     }
     if(dfn[v]==low[v])
     {
        do{
          u=stack[--top];
          instack[u]=0;
          belong[u]=cnt;
        }while(u!=v);
        cnt++;
     }
}    
int n,m;int u,v;
int main()
{
    while(~scanf("%d",&n)&&n)
    {
       scanf("%d",&m);
       init();
       while(m--)
       {
          scanf("%d%d",&u,&v);
          addedge(u,v);
       }
       for(int i=1;i<=n;i++)
         if(!dfn[i])
           tarjan(i);
       for(int i=1;i<=n;i++)
       {
          for(int j=head[i];j!=-1;j=edge[j].next)
          {
              if(belong[i]!=belong[edge[j].v])
              {
                  in[belong[edge[j].v]]++;
                  out[belong[i]]++;
              }
          }
       }
       for(int i=1;i<=n;i++)
       {
          if(out[belong[i]]==0)
            ans.push_back(i);
       }
       for(int i=0;i<ans.size();i++)
       {
          if(i)
            printf(" ");
          printf("%d",ans[i]);
       }
       puts("");
    }
}                                                                                                                                  

 
