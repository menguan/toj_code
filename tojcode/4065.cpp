#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctype.h>
#include <assert.h>
#include <cstdlib>
#define maxn 10010
#define Max 14860
using namespace std;

const int key = 223092870;
int a[maxn], s[Max][2], f[300];
int n, q, l, r;long long ans;

int main()
{
	for (int i = 1, k = 0; i * i <= key; i++)
		if (key % i == 0) f[k++] = i;
	cin>>n;
	for (int i = 0; i < n; i++)
		cin>>a[i];
	cin>>q;
	while (q--)
	{
		memset(s, 0, sizeof(s));
		cin>>l>>r;
		ans=0;
		for (int i = l; i <= r; i++)
		{
            if (!a[i]) continue;
			if (key % a[i] == 0)
			{
                if (a[i] < Max) s[a[i]][0]++;
                if (a[i] >= Max) s[key / a[i]][1]++;
            }	
		}
		for (int i = 0; i < 256; i++)
		{
            int temp = f[i];
            ans+= s[temp][0] * s[temp][1];
        }
		cout<<ans<<endl;
	}
		
}
