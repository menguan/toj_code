#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[100010];
long long b[100010];
long long dp[100010];
long long q[100010];
long long gety(int i,int j)
{
    return dp[j]-dp[i];
}
long long getx(int i,int j)
{
    return b[i]-b[j];
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%lld",&b[i]);
        int  head=0,tail=0;
        dp[1]=0;
        q[tail++]=1;
        for(int i=2;i<=n;i++)
        {
            while(head+1<tail&&(gety(q[head+1],q[head])>=a[i]*getx(q[head+1],q[head])))
                  head++;
            dp[i]=dp[q[head]]+a[i]*b[q[head]];
            //cout<<head<<" "<<i<<" "<<dp[i]<<endl;
            while(head+1<tail&&(double)(dp[i]-dp[q[tail-1]])/(b[i]-b[q[tail-1]])>=(double)(dp[q[tail-1]]-dp[q[tail-2]])/(b[q[tail-1]]-b[q[tail-2]]))
                  tail--;
            q[tail++]=i;
        }
        printf("%lld\n",dp[n]);
    }
}
