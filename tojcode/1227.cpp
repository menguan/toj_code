#include<algorithm>

#include<stdio.h>

#include<cstring>

#define N 105

using namespace std;
int dp[N][N], a[N], b[N];

int cas, n, m, i, j, k, l;

int main()

{

    scanf("%d", &cas);

    while (cas--)

    {

        memset(dp, 0, sizeof(dp));

        scanf("%d%d", &n, &m);

        for (i = 1; i <= n; i++)

            scanf("%d", &a[i]);

        for (i = 1; i <= m; i++)

            scanf("%d", &b[i]);

        for (i = 1; i <= n; i++)

            for (j = 1; j <= m; j++)

            {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                if (a[i] != b[j])

                {

                    for (k = i - 1; k > 0; k--)

                        if (a[k] == b[j])

                            break;

                    for (l = j - 1; l > 0; l--)

                        if (b[l] == a[i])

                            break;

                    if (k>0&&l>0)

                        dp[i][j] = max(dp[i][j], dp[k - 1][l - 1] + 2);

                }

            }

        printf("%d\n", dp[n][m]);

    }

    return 0;

}
