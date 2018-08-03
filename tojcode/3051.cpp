#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
double dp[1010][1010];
int main()
{
    int w,d,l;
    double ww,dd,ll;
    int n,p;
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        if(n+p==0) break;
        scanf("%d%d%d",&w,&d,&l);
        ww=w*1.0/(w+d+l);
        dd=d*1.0/(w+d+l);
        ll=l*1.0/(w+d+l);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i*3;j++)
        {
            dp[i][j+3]+=dp[i-1][j]*ww;
            dp[i][j+1]+=dp[i-1][j]*dd;
            dp[i][j]+=dp[i-1][j]*ll;
        }

    }
    double ans=0;
    for(int i=p;i<=n*3;i++)
        ans+=dp[n][i];
    printf("%.1f\n",ans*100);
    }

}
