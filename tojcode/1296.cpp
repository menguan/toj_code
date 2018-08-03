#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long prime[1010000];
long long pp[1010000];
bool vis[1010000];
void init()
{
    memset(vis,0,sizeof(vis));
    int cnt=0;
    for(int i=2;i<=1000000;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(int j=i+i;j<=1000000;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}
int main()
{
    init();
    long long l,r;
    while(cin>>l>>r)
    {
        int cnt=0;
        memset(vis,0,sizeof(vis));
        if(l<2) l=2;
        for(int i=0;prime[i]*prime[i]<=r;i++)
        {
            long long tmp=l/prime[i];
            for(;tmp*prime[i]<=r;tmp++)
            {
                if(tmp*prime[i]<l) continue;
                if(tmp<=1) continue;
                vis[tmp*prime[i]-l]=1;
            }
        }
        for(int i=0;i<=r-l;i++)
        {
            if(!vis[i])
            {
                pp[cnt++]=i+l;
            }
        }
        if(cnt<2) cout<<"There are no adjacent primes."<<endl;
        else
        {
            long long ma=-1010101010;long long mi=2147483647;
            int a,b;
            for(int i=0;i<cnt-1;i++)
            {
                if(pp[i+1]-pp[i]>ma)
                {
                    a=i;
                    ma=pp[i+1]-pp[i];
                }
                if(pp[i+1]-pp[i]<mi)
                {
                    b=i;
                    mi=pp[i+1]-pp[i];
                }
            }
            cout<<pp[b]<<","<<pp[b+1]<<" are closest, "<<pp[a]<<","<<pp[a+1]<<" are most distant."<<endl;
        }
    }
}
