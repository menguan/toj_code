#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
bool vis[100010];
int match[100010];
vector<int> g[80];
int dfs(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        if(!vis[g[u][i]])
        {
            vis[g[u][i]]=1;
            if(match[g[u][i]]==-1||dfs(match[g[u][i]]))
            {
                match[g[u][i]]=u;
                //cout<<g[u][i]<<" "<<u<<endl;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t;int a,b;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        memset(match,-1,sizeof(match));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            g[i].clear();
            for(int j=a;j<=b;j++)
            {
                g[i].push_back(j);
            }
        }
        stack<int> ans;
        for(int i=n;i>=1;i--)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
            {
                ans.push(i);
            }
       }
        printf("%d\n",ans.size());
        bool fir=0;int tmp;
        while(!ans.empty())
        {
            if(fir) printf(" ");
            tmp=ans.top();
            ans.pop();
            fir=1;
            printf("%d",tmp);
        }
        puts("");
    }

}
