#include <cstdio>
#include <iostream>
#include <cstring> 
using namespace std;
const int maxn=1000010;
const double eps=0.0000001;
int p[maxn];
long long sum[maxn];
double pm[maxn], pn[maxn];
int main()
{
    int m, n, k, l, r;
    while(scanf("%d%d%d", &m, &n, &k) != EOF)
    {
        sum[0] = 0;
        for(int i = 1; i <= k; i++)
        {
            scanf("%d.%d", &l, &r);
            p[i] = l * 100 + r;
            sum[i] = sum[i-1] + p[i];
        }
        for(int i = m; i <= k; i++)
         pm[i] = (double)(sum[i] - sum[i-m]) / m;
        for(int i = n; i <= k; i++)
         pn[i] = (double)(sum[i] - sum[i-n]) / n;
        if(pm[n] - pn[n] > eps)
         printf("BUY ON DAY %d\n", n);
        else if(pn[n] - pm[n] > eps)
         printf("SELL ON DAY %d\n", n);
        for(int i = n+1; i <= k; i++)
         if(pm[i] - pn[i] > eps && pn[i-1] - pm[i-1] > eps)
          printf("BUY ON DAY %d\n", i);
        else if(pn[i] - pm[i] > eps && pm[i-1] - pn[i-1] > eps)
         printf("SELL ON DAY %d\n", i);
    }
}
