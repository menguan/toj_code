#include<iostream>
using namespace std;
int modexp(long long a,long long b,long long n)
{
    long long ret=1,tmp=a;
    while(b)
    {
        if(b&1)
            ret=ret*tmp%n;
        tmp=tmp*tmp%n;
        b>>=1;
    }
    return ret;
}
int main()
{
    int z,m,ans,h,a,b;
    cin>>z;
    while(z--)
    {
        ans=0;
        cin>>m;
        cin>>h;
        while(h--)
        {
            cin>>a>>b;
            ans+=modexp(a,b,m);
            ans%=m;
        }
        cout<<ans<<endl;
    }
    return 0;
}
