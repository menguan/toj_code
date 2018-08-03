#include<iostream>//网上找的用floyed建邻接表 第零项来记录相邻边的个数 
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1010;
int f[N][N];
int large[N][N];
int small[N][N];
int n, m;
int main()
{
	int i, j, k, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		f[a][b] = 1;
		large[a][++large[a][0]] = b;
		small[b][++small[b][0]] = a;
	}
	for (k = 1; k <= n; k++)
		for (i = 1; i <= small[k][0]; i++)
		{
			a = small[k][i];
			for (j = 1; j <= large[k][0]; j++)
			{
				b = large[k][j];
				if (!f[a][b])
				{
					f[a][b] = 1;
					large[a][++large[a][0]] = b;
					small[b][++small[b][0]] = a;
				}
			}
		}
	int ans = 0;
	for (i = 1; i <= n; i++)
		ans += large[i][0] + small[i][0];
	printf("%d\n", ((n - 1) * n - ans) / 2);
	//while(1); 
}
