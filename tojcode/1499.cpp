#include<iostream>//最长上升子序列 
#include<cstdlib>
#include<stdio.h>
#define N 40005
using namespace std;
int a[N];
int b[N];
int n;
void solve()
{
    b[1]=a[0];
    int maxn=1;
    for(int i=1;i<n;i++)
    {
        int l=1;
        int r=maxn;
        int mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(b[mid]<a[i]) l=mid+1;
            else r=mid-1;
        }
        b[l]=a[i];//l长度下右侧最小值 
        if(l>maxn) maxn=l;
    }
    printf("%d\n",maxn);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        solve();
    }
}
