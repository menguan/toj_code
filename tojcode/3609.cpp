#include<iostream>//这道题就是求起点和终点到各点的距离  然后枚举权值减半的边a-b  然后加上起点到a 终点 到 b
#include<map>           //////////////////网上找一个思路一样的用了 不想自己打了
#include<string>
#include<cstring>
#include<stdio.h>
#include<algorithm>
//#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int NMAX = 100005;
const int MMAX = 500005;
const long long INF = 101010101010100101010;

struct Node{
    int v, w, nxt;
}edge[MMAX], reEdge[MMAX];
int n, m;
int k, edgeHead[NMAX];
int reK, reEdgeHead[NMAX];
string s, t;
map<string, int>pla;
int que[NMAX];
bool vis[NMAX];
long long sDis[NMAX], tDis[NMAX];

void addEdge(int u, int v, int w){
    edge[k].v = v;
    edge[k].w = w;
    edge[k].nxt = edgeHead[u];
    edgeHead[u] = k ++;

    reEdge[reK].v = u;
    reEdge[reK].w = w;
    reEdge[reK].nxt = reEdgeHead[v];
    reEdgeHead[v] = reK ++;
}

void spfa(long long *dis, int s, Node *edge, int *edgeHead){
    int i, he = 0, ta = 1;
    for(i = 0; i < n; i ++){
        dis[i] = INF;
        vis[i] = false;
    }
    dis[s] = 0;
    que[0] = s;
    vis[s] = true;
    while(ta != he){
        int u = que[he];
        for(i = edgeHead[u]; i; i = edge[i].nxt){
            int v = edge[i].v;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]){
                    vis[v] = true;
                    que[ta ++] = v;
                    if(ta == NMAX) ta = 0;
                }
            }
        }
        vis[u] = false;
        he ++;
        if(he == NMAX) he = 0;
    }
}

int main(){
    int i, j, u, v, w, ver;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(edgeHead, 0, sizeof(edgeHead));
        memset(reEdgeHead, 0, sizeof(reEdgeHead));
        pla.clear();
        ver = 0;
        k = reK = 1;
        for(i = 1; i <= m; i ++){
            cin >> s >> t >> w;
            if(pla.find(s) == pla.end())
                pla[s] = ver ++;
            if(pla.find(t) == pla.end())
                pla[t] = ver ++;
            addEdge(pla[s], pla[t], w);
        }
        cin >> s >> t;
        if(pla.find(s) == pla.end() || pla.find(t) == pla.end()){
            printf("-1\n"); continue;
        }else if(s == t){
            printf("0\n"); continue;
        }
        spfa(sDis, pla[s], edge, edgeHead);
        if(sDis[pla[t]] == INF){
            printf("-1\n"); continue;
        }
        spfa(tDis, pla[t], reEdge, reEdgeHead);
        long long ans = INF;
        for(u = 0; u < n; u ++){
            for(i = edgeHead[u]; i; i = edge[i].nxt){
                v = edge[i].v;
                ans = min(ans, sDis[u] + tDis[v] + edge[i].w / 2);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
