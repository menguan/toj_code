#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define MAXN 100010

using namespace std;

struct point{long long x,y,id;}a[MAXN];
long long sumx[MAXN],sumy[MAXN];
long long now[MAXN];
bool cmp1(point A,point B)
{
    if(A.x<B.x) return true;
    if(A.x==B.x&&A.y<B.y) return true;
    return false;
}

bool cmp2(point A,point B)
{
    if(A.y<B.y) return true;
    if(A.y==B.y&&A.y<B.y) return true;
    return false;
}

int main()
{
    long long test,i,j,n;
    cin>>test;
    while(test--)
    {
        memset(sumx,0,sizeof(sumx));
        memset(sumy,0,sizeof(sumy));
        memset(now,0,sizeof(now));
        cin>>n;
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].x,&a[i].y);
        }
        long long ans=1;ans<<=60;
        sort(a+1,a+n+1,cmp1);
        sumx[1]=a[1].x;
        for(i=2;i<=n;i++) sumx[i]=sumx[i-1]+a[i].x;
        for(i=1;i<=n;i++)
            {now[i]=i*a[i].x-sumx[i]+(sumx[n]-sumx[i]-(n-i)*a[i].x);a[i].id=i;}
        sort(a+1,a+n+1,cmp2);
        sumy[1]=a[1].y;
        for(i=2;i<=n;i++) sumy[i]=sumy[i-1]+a[i].y;
        for(i=1;i<=n;i++)
        {
            ans=min(ans,now[a[i].id]+=i*a[i].y-sumy[i]+(sumy[n]-sumy[i]-(n-i)*a[i].y));
        }
        cout<<ans<<endl;
    }
}
