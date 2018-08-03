#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct f
{
   long long x,y;
   long long h;
}a[2000];
long long n,w;
int main()
{
    while(scanf("%lld%lld",&n,&w)!=EOF)
    {
        if(n==0&&w==0) return 0;
        memset(a,0,sizeof(a));
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].h);
            long long high=0;
            for(int j=1;j<i;j++)
            {
                if((a[i].x<=a[j].y&&a[i].x>=a[j].x)||(a[i].y<=a[j].y&&a[i].y>=a[j].x)||(a[i].x<=a[j].x&&a[i].y>=a[j].y))
                    high=max(high,a[j].h);
            }
            a[i].h+=high;
            ans=max(a[i].h,ans);
        }
        printf("%lld\n",ans);
    }

}
