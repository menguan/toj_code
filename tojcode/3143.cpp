#include<iostream>
#include<cstring>
using namespace std;
int dp[100010];
int w[110];
int c[110];
int n,h;
int main()
{
    cin>>n>>h;
    int maxn=-1;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>c[i];
        maxn=max(w[i],maxn);
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int k=1;k*w[i]<=h+maxn;k*=2)
        {
            for(int j=k*w[i];j<=h+maxn;j++)
            {
                if((dp[j]==-1||dp[j-k*w[i]]+k*c[i]<dp[j])&&dp[j-k*w[i]]!=-1)
                    dp[j]=dp[j-k*w[i]]+k*c[i];
            }
        }
    }
    int ans=1010101010;
    for(int i=h;i<h+maxn;i++)
    {
        if(dp[i]==-1)continue;
        ans=min(ans,dp[i]);
    }
    cout<<ans<<endl;
}
