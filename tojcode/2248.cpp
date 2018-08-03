//新学的  还需要练
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 150;
const int TOOBIG = (1<<30);

double g[maxn][maxn], mincost[maxn];
int pre[maxn], n;
bool vis[maxn], exist[maxn];
double  ans;


void combine(int *list, int h, int r) {
    // 环中的点依序保存在 list[h..r] 中，将这个环缩成一个点
    memset(vis, 0, sizeof(vis));
    for (int i = h; i <= r; i++) {
        vis[list[i]] = true;
        exist[list[i]] = false;
    }
    int now = list[h];
    // 首先处理边权问题
    double newg[maxn];
    for (int j = 1; j <= n; j++) newg[j] = TOOBIG;
    for (int i = h; i <= r; i++) {
        int x = list[i];
        ans += mincost[x];
        for (int j = 1; j <= n; j++) if (!vis[j] && exist[j]) {
            if (g[j][x] != -1) {
                double tmp = g[j][x] - mincost[x];
                newg[j] = min(newg[j], tmp);
            }
            if ((g[x][j] != -1 && g[x][j] < g[now][j]) || g[now][j] == -1) g[now][j] = g[x][j];
        }
    }
    exist[now] = true;
    for (int j = 1; j <= n; j++) g[j][now] = newg[j];
    // 然后处理缩成的点引出的最小边
    for (int i = 2; i <= n; i++) if (exist[i] && !vis[i] && vis[pre[i]]) pre[i] = now;
    // 最后处理缩成的点自己的最小边
    mincost[now] = TOOBIG;
    for (int i = 1; i <= n; i++)
        if (exist[i] && i != now && g[i][now] != -1 && g[i][now] < mincost[now]) {
            mincost[now] = g[i][now];
            pre[now] = i;
        }
}


bool find_circle(int *list, int &h, int &r) {
    // 由于每个点的 vis 只会被标记一次，所以这个过程是 O(n) 的
    // 如果找到了环那么将环中的点依序保存在 list[h..r] 中
    int mark[maxn];
    memset(vis, 0, sizeof(vis));
    for (int k = 2; k <= n; k++) if (!vis[k] && exist[k]) {
        memset(mark, 0, sizeof(mark));
        r = 0;
        int i = k;
        for (; i != 1 && !mark[i] && !vis[i]; i = pre[i]) {
            vis[i] = true;
            r++;
            list[r] = i;
            mark[i] = r;
        }
        if (mark[i]) {
            h = mark[i];
            return true;
        }
    }
    return false;
}


void dfs(int v){
    vis[v] = true;
    for (int i = 1; i <= n; i++) if (!vis[i] && g[v][i] != -1) dfs(i);
}


bool min_shuxingtu() {
    // 求以 1 为根的最小树形图，原图以邻接矩阵保存于 g[1..n][1..n] 中，求解将破坏 g 矩阵
    // 如果存在返回 true，并且将最小树形图的边权和放在 ans 中，否则返回 false
    memset(vis, 0, sizeof(vis));
    dfs(1);
    for (int i = 1; i <= n; i++) if (!vis[i]) return false;
    // 初始化 mincost 和 pre 和 id
    for (int i = 1; i <= n; i++) exist[i] = true;
    for (int i = 2; i <= n; i++) {
        mincost[i] = TOOBIG;
        for (int j = 1; j <= n; j++)
            if (j != i && g[j][i] != -1 && g[j][i] < mincost[i]) {
                mincost[i] = g[j][i];
                pre[i] = j;
            }
    }
    ans = 0;
    int list[maxn], h, r;
    while (find_circle(list, h, r)) combine(list, h, r);
    for (int i = 2; i <= n; i++) if (exist[i]) ans += mincost[i];
    return true;
}


int main(){
    int i,j,u,v,m;
    while(scanf("%d %d",&n,&m)!=EOF&&n){
        for(i=0;i<=n;i++) for(j=0;j<=n;j++) g[i][j]=-1;
        for(i=1;i<=m;i++)
        {
            double t;
            scanf("%d%d%lf",&u,&v,&t);
            g[u][v]=t;
        }
        if(!min_shuxingtu()) puts("impossible");
        else{
            printf("%.0lf\n",ans);
        }
    }
    return 0;
}
