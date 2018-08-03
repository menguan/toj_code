#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[120];
int m[120][120];
int dp[120][120][120];
int n,k;
const int inf=1010101010;
int f(int s,int t,int d)
{
    if(dp[s][t][d]!=inf) return dp[s][t][d];
    if(d==1) return m[s][t];
    if(t-s+1<d||t<s) return dp[s][t][d];
    for(int i=s;i<t;i++)
    {
        dp[s][t][d]=min(dp[s][t][d],f(s,i,d-1)+m[i+1][t]);
        dp[s][t][d]=min(dp[s][t][d],f(i+1,t,d-1)+m[s][i]);
    }
    return dp[s][t][d];
}
int main()
{
    while(cin>>n>>k&&(n+k))
    {
        memset(m,0,sizeof(m));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            m[i][i]=a[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int l=1;l<=k;l++)
                    dp[i][j][l]=inf;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        for(int l=i;l<=j;l++)
            m[i][j]=max(m[i][j],a[l]);
        cout<<f(1,n,k)<<endl;
    }
}
