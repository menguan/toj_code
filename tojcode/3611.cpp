#include<iostream>
using namespace std;
long long eular(long long n)
{
    long long ret=1,i;
    for(i=2;i*i<=n;i++)
        if (n%i==0)
        {
            n/=i,ret*=i-1;
            while (n%i==0)
                n/=i,ret*=i;
        }
        if (n>1)
            ret*=n-1;
        return ret;    
}
int main()
{
    long long n;
    while(cin>>n,n)
    {
        long long sum=n*(n+1)/2-n;
        sum-=(eular(n)*n/2);
        cout<<sum%1000000007<<endl;
    }
    return 0;
}
