#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int N,M;
struct node
{
    int x,y;
} p1[1010],p2[1010];
int match[1010];
bool vis[1010];
int cnt;
vector<int> g[1010];
bool dfs(int u)
{
    int i,j;
    for(i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungry()
{
    memset(match, -1, sizeof(match));
    int ans = 0;
    int u;
    for(u = 1; u <= N; u++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(u))
        {
            ans++;
        }
    }
    return ans;
}

bool judge(int a,int b)
{
    if(p1[a].x==p2[b].x&&p1[a].y==p2[b].y)
    {
        return true;
    }
    if(p1[a].x==p2[b].x&&p1[a].y==p2[b].y+1)
    {
        return true;
    }
    if(p1[a].x+1==p2[b].x&&p1[a].y==p2[b].y)
    {
        return true;
    }
    if(p1[a].x+1==p2[b].x&&p1[a].y==p2[b].y+1)
    {
        return true;
    }
    return false;
}

void build()
{
    int i,j;
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++)
        {
            if(judge(i,j))
            {
                g[i].push_back(j);
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d %d",&N,&M)==2&&N+M)
    {
        for(i=1; i<=N; i++)
        {
            scanf("%d %d",&p1[i].x,&p1[i].y);
            g[i].clear();
        }
        for(i=1; i<=M; i++)
        {
            scanf("%d %d",&p2[i].x,&p2[i].y);
        }
        build();
        int temp=hungry();
        printf("%d\n",N+M-temp);
    }
}
