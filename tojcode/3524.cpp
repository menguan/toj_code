#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y;
int a[100],b[100];
int dp[100][300];
bool jud(int tim)
{
    memset(dp,-1,sizeof(dp));
    for(int j=0;j<=x&&j*a[1]<=tim;j++)
    {
        dp[1][j]=(tim-j*a[1])/b[1];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            for(int k=0;k<=j&&k*a[i]<=tim;k++)
            {
                if(dp[i-1][j-k]<0) continue;
                dp[i][j]=max(dp[i][j],dp[i-1][j-k]+(tim-k*a[i])/b[i]);
            }
        }
    }
    return dp[n][x]>=y;
}
int main()
{
    int t,cas=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        for(int i=1;i<=n;i++) 
          scanf("%d%d",&a[i],&b[i]);
        int l=0,r=500000;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(jud(mid)) r=mid;
            else l=mid+1;
        }
        printf("Case %d: %d\n",cas++,r);
    }
}
