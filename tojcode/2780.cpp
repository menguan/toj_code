#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
struct f
{
       int x,y;
};

f a[1010];
bool cmp(f mm, f nn)
{
    return mm.y*nn.x>mm.x*nn.y;
} 
int main()
{
    int t;int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].x);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].y);
        }
        sort(a,a+n,cmp);
        long long ans=0;
        long long now=0;
        for(int i=0;i<n;i++)
        {
           now+=a[i].x;
           ans+=(now*a[i].y);
        }          
        printf("%lld\n",ans);
    } 
}                
