#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long a[100010],n,k,m,maxn;
int jud(long long ans)
{
    long long cnt = 0;
    for(int i = 0; i < n; i++)
    if(a[i]>ans)
    {
        long long t = ceil(1.0*(a[i]-ans)/(k-1));
        if(t>ans) return 0;
        cnt+=t;
    }
    return cnt<=ans*m;
}
int main ()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        maxn = 0;
        scanf("%lld",&n);
        for(int i = 0; i < n; i++) {scanf("%d",&a[i]); maxn = max(a[i],maxn); }
        scanf("%lld%lld",&m,&k);
        long long l = 0, r = maxn, mid;
        long long ans=maxn;
        if(k!=1)
        while(l<=r)
        {
             mid = (l+r)/2;
             if(jud(mid)){ r = mid-1;ans=mid;}
             else l = mid+1;
        }
        printf("%lld\n",ans);
    }
}
