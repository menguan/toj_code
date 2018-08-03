#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 50010
using namespace std;
struct node
{
	int t, x;
} cows[maxn];

int sum[maxn], pos[maxn * 2];

bool cmp(node a, node b)
{
	return a.x < b.x;
}

int main()
{
	int n, len = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &cows[i].t, &cows[i].x);
		if (cows[i].t == 0) cows[i].t = -1;
	}
	sort(cows + 1, cows + n + 1, cmp);
	sum[0] = 0;
	memset(pos, 0, sizeof(pos));
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + cows[i].t;
		if (pos[sum[i]] == 0) pos[sum[i]] = i;
		else
		{
			int tt = cows[i].x - cows[pos[sum[i]]+1].x;
			if (len < tt) len = tt;
		}
	}
	printf("%d\n", len);
	//while(1);
}
/*
7
0 11
1 10
0 25
1 12
1 4
0 13
1 22

*/
