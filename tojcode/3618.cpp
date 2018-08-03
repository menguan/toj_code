#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 500000
#define ll long long
ll prime[maxn];
ll mark[maxn];
ll top;
void MakePrime()
{
    int i,j,k;
    memset(mark,0,sizeof(mark));
    k=-1;
    for(i=2; i<=maxn; i++)
    {
        if(mark[i]==0)prime[++k]=i;
        for(j=0; j<=k; j++)
        {
            if(i*prime[j]>maxn)break;
            int tmp=i*prime[j];
            mark[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    top=k;
}
bool isprim(ll n)
{
    ll i;
    for(i=2; i*i<=n; i++)
        if(n%i==0)
            return false;
    return true;
}
int main()
{
    ll i,j,n;
    MakePrime();
    while(cin>>n)
    {
        if(n<=7)
        {
            if(n==0)
                printf("0\n");
            else cout<<n-1<<endl;
            continue;
        }
        if(isprim(n)||(n%2==0&&isprim(n/2)))
        {
            cout<<n-1<<endl;
        }
        else
        {
            ll tmp=n;
            for(i=0; i<top; i++)
            {
                if(prime[i]==2)continue;
                if(prime[i]>n)break;
                if(n%prime[i]==0)
                {
                    while(n%prime[i]==0)
                    {
                        n=n/prime[i];
                    }
                    break;
                }
            }
            if(n==1||n==2)cout<<tmp-1<<endl;
            else cout<<1<<endl;
        }


    }
    return 0;
}
            
