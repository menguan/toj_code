#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;int ans;
vector<int> e[10010];
int ma[10010];
bool vis[10010];
int dfs(int u)
{
    int v;
    for(int i=0;i<e[u].size();i++)
    {
        v=e[u][i];
        dfs(v);
        ma[u]+=ma[v];
        ans+=abs(ma[v]);
    }
    ma[u]--;
}
int main()
{
     while(cin>>n,n)
     {

         memset(ma,0,sizeof(ma));
         memset(vis,0,sizeof(vis));
         for(int i=0;i<=n;i++)e[i].clear();
         int a,b,c;
         for(int i=1;i<=n;i++)
         {
             cin>>a>>b>>c;
             ma[i]=b;
             while(c--)
             {

                 cin>>b;
                 vis[b]=1;
                 e[i].push_back(b);
             }

         }
         for(int i=1;i<=n;i++)
         {
             if(!vis[i])
             {
                 ans=0;
                 dfs(i);
                 break;
             }
         }
         cout<<ans<<endl;
     }
}
