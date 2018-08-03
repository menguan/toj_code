#include<cstdio>
#include<list>
#include<iostream>
using namespace std;
#define sf scanf
#define pf printf
const int maxn = 20;

int card[maxn], x;
list<int> li;
list<int>::iterator iter;

void solve()
{
	int i, j;
	for (i = 0; i < maxn; ++i)
	{
		for (iter = li.begin(), j = 1; iter != li.end(); ++j)
		{
			if (j == card[i])
			{
			    //cout<<j<<" "<<card[i]<<" "<<i<<endl;
                if (li.size() == x) return;
				iter = li.erase(iter);
				j = 0;
			}
			else ++iter;
		}
	}
}

int main()
{
	int n, i, cas = 0;
	while (~sf("%d%d", &n, &x))
	{
		li.clear();
		for (i = 1; i <= n; ++i) li.push_back(i);
		for (i = 0; i < maxn; ++i) sf("%d", &card[i]);
		solve();
		pf("Selection #%d\n", ++cas);
		for (iter = li.begin(), i = 0; i < li.size() - 1; ++i)
			pf("%d ", *iter++);
		pf("%d\n\n", *iter);
	}
	return 0;
}
