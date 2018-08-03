#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000010, INF = 0x3fffffff;

int f[N], g[N], a[N];

int max_sum(int m, int n)
{
    int i, j, t;
    for (i = 1; i <= n; i++)
    {
        t = min(i, m);
        for (j = 1; j <= t; j++)
        {
            f[j] = max(f[j], g[j-1]) + a[i];
            g[j-1] = max(f[j-1],g[j-1]);
        }
        g[j-1]=max(f[j-1],g[j-1]);
    }
    return g[m];
}

int main()
{
    int m, n;

    while (scanf("%d %d", &m, &n) == 2 && m && n)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i] = g[i] = -INF;
            scanf("%d", &a[i]);
        }
        printf("%d\n", max_sum(m, n));
    }

}
