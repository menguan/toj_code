#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long mod;
bool vis[1000010];
int pri[1000010];
int pcnt;
void init()
{
    pcnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<1000010;i++)
    {
        if(!vis[i]) {
                pri[pcnt++]=i;
               for(int j=i+i;j<1000010;j+=i)
                vis[j]=1;
        }
    }
}
long long fastmod(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b%2==1)ret=ret*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return ret;
}
long long count(long long n,long long prime)
{
    long long ret=0;
    while(n/prime)
    {
        ret+=n/prime;
        n/=prime;
    }

    return  ret;
}
long long f(long long n,long long m)
{
    long long ans=1,cnt;
    for(int i=0;i<pcnt&&pri[i]<=n;i++)
    {
        cnt=count(n,pri[i])-count(m,pri[i])-count(n-m,pri[i]);
        ans=ans*fastmod(pri[i],cnt)%mod;
        if(ans==0) break;
    }
    return ans;
}
int main()
{
    init();
    mod=1;
    for(int i=0;i<32;i++)
        mod*=2;
    int t;
    long long n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<f(n,m)<<endl;
    }

}
