#include<stdio.h>
#include<algorithm>
#include<cstring>
int n,kk;
long long dp[70000][20],ans;
int s[17];
int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&kk);
    for (int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for (int i=1;i<=n;i++)
        dp[1<<(i-1)][i]=1;
    for (int i=0;i<=(1<<n);i++)
        for (int j=1;j<=n;j++)
            if ((1<<(j-1))&i)
                for (int k=1;k<=n;k++)
                    if (((1<<(k-1))&i)==0&&abs(s[j]-s[k])>kk)
                        dp[i|(1<<(k-1))][k]+=dp[i][j];
    for (int i=1;i<=n;i++)
        ans=ans+dp[(1<<n)-1][i];
    printf("%lld\n",ans);
}
