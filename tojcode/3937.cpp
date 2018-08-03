#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 0xfffffff
struct point
{
    int mat;
    int dig;
} node[55][1005];
int dp[55][1005];
bool cmp(const point &a,const point &b)
{
    return a.mat<b.mat;
}
int main()
{
    int T,x,n,m;
    scanf("%d",&T);
    for(; T--;)
    {
        scanf("%d%d%d",&n,&m,&x);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                scanf("%d",&node[i][j].mat);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                scanf("%d",&node[i][j].dig);
                /*
        for(int i=1; i<=n; ++i)
            sort(node[i]+1,node[i]+m+1,cmp);
        */
        for(int i=2; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                dp[i][j]=inf;
        for(int i=1; i<=m; ++i)
            dp[1][i]=abs(x-node[1][i].mat)+node[1][i].dig;
        for(int i=2; i<=n; ++i)
        {
            int idx=1,minn=inf;
            for(int j=1; j<=m; ++j)
            {
                //for(;idx<=m&&node[i][j].mat>=node[i-1][idx].mat;++idx)
                for(idx=1;idx<=m;++idx)
                {
                    //minn=min(minn,dp[i-1][idx]-node[i-1][idx].mat);
                    dp[i][j]=min(dp[i][j],dp[i-1][idx]+abs(node[i][j].mat-node[i-1][idx].mat));
                }
                //dp[i][j]=min(dp[i][j],minn+node[i][j].mat);
            }
            /*
            idx=m,minn=inf;
            for(int j=m; j>=1; --j)
            {
                for(;idx>=1&&node[i][j].mat<=node[i-1][idx].mat;--idx)
                {
                    minn=min(minn,dp[i-1][idx]+node[i-1][idx].mat);
                }
                dp[i][j]=min(dp[i][j],minn-node[i][j].mat);
            }
            */
            for(int j=1; j<=m; ++j)
                dp[i][j]+=node[i][j].dig;
        }
        int ans=inf;
        for(int i=1; i<=m; ++i)
            ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
