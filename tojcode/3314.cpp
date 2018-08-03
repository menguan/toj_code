#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
int a[110000];
int n;
long long sum[110000];
int lb(int p)
{
    return p&(-p);
}
int up(int pos,int aa,long long ss)
{
    while(pos<=n)
    {
        a[pos]+=aa;
        sum[pos]+=ss;
        pos+=lb(pos);
    }
}
int ga(int pos)
{
    int ret=0;
    while(pos)
    {
        ret+=a[pos];
        pos-=lb(pos);
    }
    return ret;
}
long long gs(int pos)
{
    long long ret=0;
    while(pos)
    {
        ret+=sum[pos];
        pos-=lb(pos);
    }
    return ret;
}

int p;
int main()
{
    n=100010;
    int d;
    while(~scanf("%d",&d))
    {
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        long long ans=0;
        for(int i=1;i<=d;i++)
        {
            scanf("%d",&p);
            up(p,1,p);
            long long tmp=ga(n)-ga(p);
            ans+=tmp*p+gs(n)-gs(p);
        }
        printf("%lld\n",ans);
    }
}
