#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 110;
int grid[MAXN][MAXN];
int f[MAXN][MAXN];
int n, k;
int dp(int x, int y)
{
	if (f[x][y] != -1) return f[x][y];

	int tmp = grid[x][y];
	for (int i = 1; i <= k; i++) {
		if (x + i < n && grid[x + i][y] > grid[x][y]) {
			tmp = max(tmp, grid[x][y] + dp(x + i, y));
		}

		if (x - i >= 0 && grid[x - i][y] > grid[x][y]) {
			tmp = max(tmp, grid[x][y] + dp(x - i, y));
		}

		if (y + i < n && grid[x][y + i] > grid[x][y]) {
			tmp = max(tmp, grid[x][y] + dp(x, y + i));
		}

		if (y - i >= 0 && grid[x][y - i] > grid[x][y]) {
			tmp = max(tmp, grid[x][y] + dp(x, y - i));
		}
	}

	return f[x][y] = tmp;

}
int main()
{
	    scanf("%d%d", &n, &k);
	    for (int i = 0; i < n; i++)
		  for (int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
		memset(f, -1, sizeof(f));
	    dp(0, 0);
	    printf("%d\n", f[0][0]);
}
