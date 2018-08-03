#include<iostream>
#include<cstring>
using namespace std;
long long dp[12][2010];
int main()
{
    int t;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=2000;i++)
        dp[1][i]=1;
    for(int i=2;i<=10;i++)
    {
        for(int j=1;j<=2000;j++)
        {

            for(int k=1;k<=j/2;k++)
            {
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {

        int n,m;
        cin>>n>>m;
        long long ans=0;
        for(int i=1;i<=m;i++)
            ans+=dp[n][i];
        cout <<"Case "<<cas<<": n = "<<n<<", m = "<<m<<", # lists = " <<ans<<endl;
    }
}
