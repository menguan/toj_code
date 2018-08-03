#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
using namespace std;
int col[100010];
vector<int> edge[100010];
int n,m,st;
bool ok;

void dfs(int u,int fa,int c)
{
   if(ok) return ;
   col[u]=c;
   int vv;
   for(int i=0;i<edge[u].size();i++)
   {
      vv=edge[u][i];
      if(vv==fa) continue;
      if(col[vv]==c){ok=1;return;}
      if(col[vv]==0)
      {
        dfs(vv,u,(int)((-1)*c));
      }
   } 
}
int main()
{
  int t;
  int u,v; 
  scanf("%d",&t);
  for(int cas=1;cas<=t;cas++)
  {
      scanf("%d%d%d",&n,&m,&st);
      for(int i=0;i<n;i++)
      {
        edge[i].clear();
        col[i]=0;
      }
      while(m--)
      {
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
      }
      ok=0;
      dfs((int)st,(int)-1,(int)1);
      printf("Case %d: ",cas);
      if(ok)
        puts("YES");
      else
        puts("NO");
  }
}  
        
        