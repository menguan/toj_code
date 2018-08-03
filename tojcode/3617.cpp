#include<iostream>
#include<queue>
#include<deque>
#include<cstdio>
#include<cstring>
using namespace std;
long long dp[500010];
long long sum[500010];
long long q[500010];
int n,m;
long long gety(int j)
{
    return dp[j]+sum[j]*sum[j];
}
long long getx(int j)
{
    return 2*sum[j];
}
long long getdp(int i,int j)
{
    return dp[j]+m+(sum[i]-sum[j])*(sum[i]-sum[j]);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld",&sum[i]);
        sum[0]=dp[0]=0;
        for(int i=1;i<=n;i++)
            sum[i]+=sum[i-1];
        //deque<int> q;
        //q.push_back(0);
        int head=0,tail=0;
        q[tail++]=0;
        for(int i=1;i<=n;i++)
        {
            while(head+1<tail&&(gety(q[head+1])-gety(q[head]))<=sum[i]*(getx(q[head+1])-getx(q[head])))
                head++;
            dp[i]=getdp(i,q[head]);
            while(head+1<tail&&((gety(i)-gety(q[tail-1]))*(getx(q[tail-1])-getx(q[tail-2]))<=(getx(i)-getx(q[tail-1]))*(gety(q[tail-1])-gety(q[tail-2]))))
                tail--;
                q[tail++]=i;
        }
        printf("%lld\n",dp[n]);
    }
}

