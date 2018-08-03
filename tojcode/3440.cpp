#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>

using namespace std;
int mod=1000000007;
const int maxn=50020;
  int n,op,x,y;

long long sum[maxn*4];
void build(int t, int l, int r) {
    int m = (l + r) >> 1;
    if (l == r) scanf("%lld", &sum[t]);
    else {
        build(t << 1, l , m);
        build(t << 1|1, m + 1, r);
        sum[t] = sum[t << 1] * sum[t << 1|1] % mod;
    }
}
long long query(int t, int l, int r) {
    int m = (l + r) >> 1;
    long long res = 1;
    if (x <= l && r <= y) return sum[t];
    else {
        if (x <= m) res = res * query(t << 1, l, m) % mod;
        if (y > m) res = res * query(t << 1|1, m + 1, r) % mod;
        return res;
    }
}
void update(int t, int l, int r) {
    int m = (l + r) >> 1;
    if(l == r) sum[t] = y % mod;
    else {
        if(x <= m) update(t << 1, l, m);
        else update(t << 1|1, m + 1, r);
        sum[t] = sum[t << 1] * sum[t << 1|1] % mod;
    }
}
int main()
{
    int t;int fl;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       build(1,1,n);
       
       
       scanf("%d",&op);
       for(int i=0;i<op;i++)
       {    
            scanf("%d%d%d",&fl,&x,&y);
            if(fl==0)
            {
                 long long ans=query(1,1,n);
                 printf("%lld\n",ans);
            }
            else
            {
                update(1,1,n);
            }
       }
    }
}                    
                                         
    
