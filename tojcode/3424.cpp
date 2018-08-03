#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long mod=1000003;
long long a[40010];
void exgcd(long long a,long long b,long long &d,long long &x,long long &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
        return ;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=a/b*x;
    }
}
int main()
{
    a[0]=1;
    for(int i=1;i<=40000;i++)
        a[i]=a[i-1]*2%mod;
    long long x,y,d;
    int t;
    cin>>t;
    int cas=1;
    int n;
    while(t--)
    {
        cin>>n;
        long long ans=0;

        long long  p;
        for(int i=0;i<n;i++)
        {
            cin>>p;
            ans=ans+a[p];
            ans%=mod;
        }

        exgcd(n,mod,d,x,y);
        ans=(ans*x%mod)+mod;
        ans%=mod;
        cout<<"Case "<<cas++<<":"<<ans<<endl;
    }
}
