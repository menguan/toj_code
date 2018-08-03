#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],n,k;
bool check(int p)
{
    int ret=0;
    for (int i=0;i<n-2;i++)
        if (a[i+2]-a[i]<=p)
            ret++,i+=2;
    return ret>=k;
}
int main()
{
    while(scanf("%d%d",&n,&k),n+k) 
	{
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int l=0,r=1000001,mid;
        while(l<=r) 
	    {
             mid=(l+r)/2;
             if(check(mid))
                r=mid-1;
             else
                l=mid+1;
        } 
        printf("%d\n",r+1);
    }
}
