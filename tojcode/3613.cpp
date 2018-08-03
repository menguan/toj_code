#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const long long mod=100000007;
long long fun(long long a,long long b)
{
    long long d,t;

    d=1;
    t=a;
    while (b>0)
    {
        if (b%2==1)
            d=(d*t)%mod;
        b/=2;
        t=(t*t)%mod;
    }

    return d;
}
long long solve (long long n,long long m)
{
long long ans=1;

for (long long i=m*n+2-n;i<m*n+1;i++)
{
   ans=((((ans*i)%mod)*fun(i-m*n+n-1,mod-2)))%mod;
}

ans=(ans*fun(n,mod-2))%mod;

return ans;
}

int main ()
{
long long n,m;

while (scanf ("%lld%lld",&n,&m)!=EOF)
{
   printf ("%lld\n",solve(n,m));
}

return 0;
}
