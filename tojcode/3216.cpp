#include <iostream>//直接拷的 和我想法一样 
#include <cstdio>
#include <cstring>
using namespace std ;
typedef long long ll ;
ll c[1005][1005],n,m,dp[1005] ;
ll cal(int s)
{
    ll temp=s-1 ;
    ll cnt=2 ;
    ll ans=0 ;
    while(temp-cnt>0)
    {
        ans+=cnt/2 ;
        temp-=cnt ;
        cnt*=2 ;
    }
    if(temp>=cnt/2)ans+=cnt/2 ;
    else ans+=temp ;
    return ans ;
}
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(c,0,sizeof(c)) ;
        for(int i=1 ;i<1001 ;i++)
        {
            c[i][0]=c[i][i]=1 ;
            for(int j=1 ;j<i ;j++)
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%m ;
        }
        memset(dp,0,sizeof(dp)) ;
        dp[0]=dp[1]=1 ;
        for(int i=2 ;i<=n ;i++)
        {
            ll a=cal(i) ;
            ll b=i-1-a ;
            dp[i]=c[i-1][a]*dp[a]%m*dp[b]%m ;
        }
        cout<<dp[n]%m<<endl;
    }
    return 0 ;
}
