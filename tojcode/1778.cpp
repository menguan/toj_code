#include <iostream>//记忆化搜索 
#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int INF = 123456789;
const int N = 1005;

vector<int> road[N];   
int map[N][N], dist[N], s[N];
bool visit[N];
int n, t, sum;

void init()
{
    int i, j;
    sum = 0;
    memset(s, 0, sizeof(s));
    for(i = 0; i <= n; i++) road[i].clear();
    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            if(i == j) map[i][j] = 0;
            else map[i][j] = INF;
}

inline void input()
{
    int a, b, d;
    while(t--)
    {
        scanf("%d %d %d", &a, &b, &d);
        if(d < map[a][b])//竟然有重边 
        {
            map[a][b] = map[b][a] = d;  
            road[a].push_back(b);
            road[b].push_back(a);
        }
    }
}

void spfa()     
{
    int i, now;
    memset(visit, 0, sizeof(visit));
    for(i = 1; i <= n; i++) dist[i] = INF;
    dist[2] = 0;
    queue<int> Q;
    Q.push(2);
    visit[2] = 0;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        visit[now] = 0;
        for(i = 1; i <= n; i++)
        {
            if(dist[i] > dist[now] + map[now][i])
            {
                dist[i] = dist[now] + map[now][i];
                if(visit[i] == 0)
                {
                    Q.push(i);
                    visit[i] = 1;
                }
            }
        }
    }
}

int dfs(int now)    
{
    int i;
    if(now == 2) return 1;  
    if(s[now]) return s[now];   
    for(i = 0; i < road[now].size(); i++)
    {
        if(dist[now] > dist[ road[now][i] ])
        {
            s[now] += dfs(road[now][i]);
        }
    }
    return s[now];  
}

int main()
{
    while(scanf("%d", &n), n)
    {
        scanf("%d", &t);
        init();
        input();
        spfa();
        sum = dfs(1);   
        printf("%d\n", sum);
    }

    return 0;
}
