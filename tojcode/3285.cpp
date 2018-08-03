#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100102];
int main()
{
    int t;
    int n,m,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&m);
        int ans=2000000010;
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        for(int i=0;i<m-1;i++)
        {
            ans=min(ans,n-(a[i+1]-a[i])+min(min(abs(a[i]-x),abs(a[i+1]-x)),min(n-abs(a[i]-x),n-abs(a[i+1]-x))));
        }
        ans=min(ans,(a[m-1]-a[0])+min(min(abs(a[m-1]-x),abs(a[0]-x)),min(n-abs(a[m-1]-x),n-abs(a[0]-x))));
        printf("%d\n",ans);
    }
}
