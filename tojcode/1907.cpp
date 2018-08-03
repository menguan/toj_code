#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double dep[105];

int main()
{
	int month, n, temp, i;
	double downpay, monthpay, owe, r, car, nowdep;
	while (scanf("%d%lf%lf%d", &month, &downpay, &owe, &n), month > 0)
	{
		memset(dep, 0, sizeof(dep));
		while (n--)
		{
			scanf("%d%lf", &temp, &r);
			dep[temp] = r;
		}
		car = owe + downpay;
		nowdep = 0;
		monthpay = owe / month;
		for (i = 0;; ++i)
		{
			nowdep = (dep[i] ? dep[i] : nowdep);
			car *= 1 - nowdep;
			if (owe < car) break;
			owe -= monthpay;
		}
		if (i == 1) puts("1 month");
		else printf("%d months\n", i);
	}
	return 0;
}
