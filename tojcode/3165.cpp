#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<stdio.h>
using namespace std;
int n;
int v;
int dep;
int cnt;
stack<int>  st;
int go[100010];
bool vis[100010];
int dfn[100010];
int low[100010];
int belong[100010];
int siz[100010];
int ans[100010];
int head[100010];
int enu;
struct E{int v,next;}e[100010];
void adde(int u,int v)
{
    e[enu].v=v;
    e[enu].next=head[u];
    head[u]=enu++;
}

void dfs(int u)
{
   dfn[u]=low[u]=dep++;st.push(u);
   vis[u]=1;
   if(!vis[go[u]]){dfs(go[u]);low[u]=min(low[u],low[go[u]]);}
   else if(!belong[go[u]])low[u]=min(low[u],dfn[go[u]]);
   if(low[u]==dfn[u])
   {
       int tmp=0;
       while(tmp!=u)
       {
           tmp=st.top();
           st.pop();
           belong[tmp]=cnt;
           siz[cnt]++;
       }
       cnt++;
   }
}
int dfs2(int u)
{
    if(ans[u])  return ans[u];
    ans[u]=siz[u];
    if(siz[u]==1)  ans[u]+=dfs2(e[head[u]].v);
    return ans[u];
}
int main()
{
    dep=1;
    cnt=1;
    enu=0;
    memset(belong,0,sizeof(belong));
    memset(siz,0,sizeof(siz));
    memset(head,-1,sizeof(head));
    memset(ans,0,sizeof(ans));
    //cin>>n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        //cin>>v;
        scanf("%d",&v);
        go[i]=v;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {while(!st.empty()) st.pop();dfs(i);}
    }
    for(int i=1;i<=n;i++)
    {
        if(belong[i]!=belong[go[i]])
            adde(belong[i],belong[go[i]]);
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<dfs2(belong[i])<<endl;
        printf("%d\n",dfs2(belong[i]));
    }
}

