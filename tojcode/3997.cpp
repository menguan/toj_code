#include<cstdio>
#include <iostream>
using namespace std;
const int MOD=1000000007;
int n,k,t;

long long pow(long long x,long long p)
{
    
    long long ans=1;
    while(p>1)
    {
        if(p%2)ans=(ans*x)%MOD;
        x=(x*x)%MOD;
        p/=2;
    }

    ans=(ans*x)%MOD;
    return ans;
}
int a[5];
int main()
{
    cin>>t;
    while(t--)
    {
        a[1]=1;
        a[2]=2;
        a[3]=5;
        scanf("%d%d",&n,&k);
        int ord=n-k+1;
        if(ord<=0)
        printf("%d\n",0);
        else if(ord<=3)printf("%d\n",a[ord]);
        else
        {
            long long ans=(ord+2)%MOD;
            ans=ans*pow(2,ord-3)%MOD;
            printf("%d\n",ans);
        }

    }
    return 0;
}
