#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101
int main()
{
    int i, j;
    int t, n, m[N], k;
    int band[N][N], price[N][N], low, high, sump, minp;
    double ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        low = 0xffffff;
        high = 0;
        for(i=1; i<=n; i++)
        {
            scanf("%d", &m[i]);
            for(j=1; j<=m[i]; j++)
            {
                scanf("%d%d", &band[i][j], &price[i][j]);
                low = min(band[i][j],low);
                high = max(band[i][j],high);
            }
        }
        ans = 0.0;
        for(i=low; i<=high; i++)
        {
            sump = 0;
            for(j=1; j<=n; j++)
            {
                minp = 0xffffff;
                for(k=1; k<=m[j]; k++)
                    if(band[j][k] >= i && price[j][k] < minp)
                        minp = price[j][k];
                sump += minp;
            }
            if(i * 1.0 / sump - ans > 0)
                ans = i * 1.0 / sump;
        }
        printf("%.3f\n", ans);
    }
}
