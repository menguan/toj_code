#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int nn=110000;
const int mod=9901;
int c[nn];
int n,d;
int lowbit(int x)
{
    return x&(-x);
}
int setn(int i,int p)
{
    while(i<=nn)
    {
        c[i]=(c[i]+p)%mod;
        i+=lowbit(i);
    }
}
int getsum(int p)
{
    int ret=0;
    while(p)
    {
        ret=(ret+c[p])%mod;
        p-=lowbit(p);
    }
    return ret;
}
int dp[110000];
int a[110000],num[110000];
int x;
int main()
{
   while(cin>>n>>d)
   {
       memset(c,0,sizeof(c));
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
           num[i]=a[i];
       }
       sort(num+1,num+n+1);
       //int uu=unique(num+1,num+n+1)-num-1;
       int uu=n;
       for(int i=1;i<=n;i++)
       {
           int id=lower_bound(num+1,num+uu+1,a[i])-num;
           int l=lower_bound(num+1,num+uu+1,a[i]-d)-num;
           int r=upper_bound(num+1,num+uu+1,a[i]+d)-num-1;
           dp[i]=(getsum(r)-getsum(l-1)+mod)%mod;
           dp[i]++;
           //cout<<dp[i]<<" "<<getsum(r)<<" "<<getsum(l-1)<<endl;
           setn(id,dp[i]);
       }
       int ans=0;
       for(int i=1;i<=n;i++)
        ans=(ans+dp[i])%mod;
    cout<<((ans-n)%mod+mod)%mod<<endl;
   }
}
