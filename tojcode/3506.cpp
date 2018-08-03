#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int mm=10000010;
const long long mod=201004;
int prime[1000000];
bool vis[mm];
int cnt;long long n,m;int con;
void init()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<mm;i++)
    {
        if(vis[i]==0)
        {
            prime[cnt++]=i;
            for(int j=i+i;j<mm;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}
long long result(long long a,long long b)
{
    long long d,t;

    d=1;
    t=a;
    while (b>0)
    {
        if (b%2==1)
            d=(d*t)%mod;
        b/=2;
        t=(t*t)%mod;
    }

    return d;
}
int main()
{
    init();
    while(cin>>n>>m&&(n+m))
    {
        long long ans=1;
        for(int i=0;i<cnt&&n>=prime[i]&&n!=1;i++)
        {
            if(n%prime[i]==0)
            {
                con=0;
                while(n%prime[i]==0)
                {
                    con++;
                    n/=prime[i];
                }
                ans=(ans*(prime[i]-1)%mod)*result(prime[i],con*m-1)%mod;
            }

        }
        cout<<ans<<endl;
    }

}
