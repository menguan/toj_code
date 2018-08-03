#include <cstdio>//竟然是只需要选一个 
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

int rh0, rv0, sh0, sv0; 

int main()
{
	int rh, rv, sh, sv, n, price, ans, tmp, l, m;
	cin>>rh0>>rv0>>sh0>>sv0;
    cin>>n; 
	//scanf("%d%d%d%d", &rh0, &rv0, &sh0, &sv0);
	//scanf("%d", &n);
	priority_queue<int> Q;
	for (int i = 0; i < n; i++)
	{
		//scanf("%d%d%d%d%d", &rh, &rv, &sh, &sv, &price);
		cin>>rh>>rv>>sh>>sv>>price;
		tmp = -1 * price * max((rh0 + rh - 1) / rh, (sh0 + sh - 1) / sh) * max((rv0 + rv - 1) / rv, (sv0 + sv - 1) / sv);
		//cout<<tmp<<endl;
        Q.push(tmp);
		tmp = -1 * price * max((rh0 + rv - 1) / rv, (sh0 + sv - 1) / sv) * max((rv0 + rh - 1) / rh, (sv0 + sh - 1) / sh);
		Q.push(tmp);
	}
	ans = -1 * Q.top();
	cout<<ans<<endl;
    //printf("%d\n", ans);
	//while(1);
}
