#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 11111
#define INF 1010101010
using namespace std;
typedef pair<int, int> P;
vector<P>g[MAXN];
long long dis[MAXN][22];
int n, m, k;
struct node
{
    int v, num;
    long long w;
    node(){}
    node(int a, int b, long long c){v = a; num = b; w = c;}
    friend bool operator >(const node &t1,const node &t2) 
    {
        return t1.w > t2.w;
    }
};
priority_queue<node, vector<node>, greater<node> > q;
void dij()
{
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dis[i][j] = INF;
    dis[1][0] = 0;
    q.push(node(1, 0, 0));
    while(!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int u = tmp.v;
        int num = tmp.num;
        long long w = tmp.w;
        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].first;
            long long tw = g[u][i].second;
            if(num < k && w < dis[v][num + 1])
            {
                dis[v][num + 1] = w;
                q.push(node(v, num + 1, w));
            }
            if(w + tw < dis[v][num])
            {
                dis[v][num] = w + tw;
                q.push(node(v, num, w + tw));
            }
        }
    }
    long long ans = dis[n][0];
    for(int i = 1; i <= k; i++)
        ans = min(ans, dis[n][i]);
    cout<<ans<<endl;
}
int main()
{
    int u, v, w;
    while(cin>>n>>m>>k)
    {
        while(!q.empty()) q.pop();
        for(int i = 0; i <= n; i++) g[i].clear();
        for(int i = 0; i < m; i++)
        {
            cin>>u>>v>>w;
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
        dij();
    }
}
