#include<stdio.h>
double dp[110][12];
int main()
{
    int k,n;
    while(scanf("%d%d",&k,&n)!=EOF)
    {
        if(k<=1)
        printf("100.00000\n");
        else
        {
            for(int i=0;i<=k;i++)
            dp[1][i]=100.0/(k+1);
            for(int i=2;i<=n;i++)
            {
                for(int j=0;j<=k;j++)
                {
                    if(j==0)
                    {
                        dp[i][j]=1.0/(k+1)*(dp[i-1][j]+dp[i-1][j+1]);
                    }
                    else if(j==k)
                    {
                        dp[i][j]=1.0/(k+1)*(dp[i-1][j-1]+dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j]=1.0/(k+1)*(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]);
                    }
                }
            }
            double ans=0;
            for(int i=0;i<=k;i++)
            {
                ans+=dp[n][i];
            }
            printf("%.5lf\n",ans);
        }
    }
    return 0;
}
