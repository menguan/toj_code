#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 10000
#define MAXM 200000
#define INF 200000000000000LL
using namespace std;
struct EDGE
{
    int v, next;
    long long w;
    int id;
} edge[MAXM];
struct P
{
    int id, u;
    P(){}
    P(int a, int b) {u = a; id = b;}
};
int head[MAXN], e, n, m;
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
void add(int x, int y, long long w, char c)
{
    edge[e].v = y;
    edge[e].w = w;
    edge[e].next = head[x];
    if(c == 'L') edge[e].id = 0;
    if(c == 'O') edge[e].id = 1;
    if(c == 'V') edge[e].id = 2;
    if(c == 'E') edge[e].id = 3;
    head[x] = e++;
}
long long d[MAXN][4];
int vis[MAXN][4], num[MAXN][4];
void spfa(int src)
{
    int h = 0, t = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 4; j++)
            d[i][j] = INF, vis[i][j] = 0, num[i][j] = 0;
    queue<P> q;
    vis[src][3] = 1;
    d[src][3] = 0;
    P tmp = P(src, 3);
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        int u = tmp.u;
        int id = tmp.id;
        vis[u][id] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int x = edge[i].id;
            long long w = edge[i].w;
            if((d[u][id] + w < d[v][x] || d[v][x] == 0) && (id + 1) % 4 == x)
            {
                d[v][x] = d[u][id] + w;
                num[v][x] = num[u][id];
                if(x == 3) num[v][x]++;
                if(!vis[v][x])
                {
                    q.push(P(v, x));
                    vis[v][x] = 1;
                }
            }
            else if((d[u][id] + w == d[v][x] || d[v][x] == 0) && (id + 1) % 4 == x && num[v][x] <= num[u][id])
            {
                num[v][x] = num[u][id];
                if(x == 3) num[v][x]++;
                if(!vis[v][x])
                {
                    q.push(P(v, x));
                    vis[v][x] = 1;
                }
            }
        }
    }
}
int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &n, &m);
        int u, v, w;
        char s[5];
        while(m--)
        {
            scanf("%d%d%d%s", &u, &v, &w, s);
            add(u, v, w, s[0]);
            add(v, u, w, s[0]);
        }
        spfa(1);
        if(num[n][3] == 0 || d[n][3] == INF)
            printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n", ++cas);
        else
            printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %lld meters and finding %d LOVE strings at last.\n", ++cas, d[n][3], num[n][3]);
    }
}
