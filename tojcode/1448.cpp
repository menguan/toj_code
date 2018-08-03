#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, t;
int a[110], h[110], maxh[110], minh[110];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
void dfs(int now, int cnt, int cur)
{
	if (cnt == 4)
	{
		for (int i = 0; i < t; i++)
		{
			int temp = h[i] / now * now;
			if (temp == h[i])
				maxh[i] = minh[i] = h[i];
			else
			{
				if (maxh[i] == -1 || temp > maxh[i])
					maxh[i] = temp;
				temp += now;
				if (minh[i] == -1 || temp < minh[i])
					minh[i] = temp;
			}
		}
		return;
	}
	if (cur == n) return;
	dfs(now, cnt, cur + 1);
	int temp = now/gcd(now,a[cur])*a[cur];
	dfs(temp, cnt + 1, cur + 1);
}

int main()
{
	int i;
	while (cin>>n>>t&&(n+t))
	{
		memset(maxh, -1, sizeof(maxh));
		memset(minh, -1, sizeof(minh));
		for (i = 0; i < n; ++i) cin>>a[i];
		for (i = 0; i < t; ++i) cin>>h[i];
		for (i = 0; i < n; ++i) dfs(a[i], 1, i + 1);
		for (i = 0; i < t; ++i) cout<<maxh[i]<<" "<<minh[i]<<endl;
	}
}
