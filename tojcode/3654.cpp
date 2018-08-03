#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define mod 1000000009
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-10
typedef long long ll;
using namespace std;
int n, s, p;
struct node {
    int id, val;
    int num;
} a[1005];
bool comp(node a, node b) {
    if (a.val == b.val)  {
        if (a.num == b.num) return a.id < b.id;
        return a.num > b.num;
    }
    return a.val > b.val;
}
int vis[1005];
vector<int> g[1005];
int main() {
    while (~scanf("%d%d%d", &n, &s, &p)) {
        int t;
        //memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= s; i++) g[i].clear();
        for (int i = 1; i <= n; i++) {
            int tot = 0;
            for (int j = 1; j <= s; j++) {
                scanf("%d", &t);
                tot += t;
                if (t) g[j].push_back(i);
            }
            vis[i] = s - tot;
        }
        for (int i = 1; i <= s; i++) {
            a[i].id = i; a[i].val = 0;
            a[i].num = g[i].size();
            for (int j = 0; j < g[i].size(); j++)
                a[i].val += vis[g[i][j]];
        }
        sort(a + 1, a + s + 1, comp);
        int ans = 0, the = 0;
        for (int i = 1; i <= s; i++) {
            if (a[i].id == p) {
                the = i;
                ans = a[i].val;
                break;
            }
        }
        printf("%d %d\n", ans, the);
    }
}