#include<set>
#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int main()
{
    LL a,b,mod,n,l,minn,maxn,ll,k;
    LL i,j,sum;
    while(~scanf("%lld%lld%lld%lld%lld",&n,&l,&a,&b,&mod))
    {
        maxn=0;
        minn=l;
        sum=0;
        ll=l/2;
        for(i=1;i<=n;i++)
        {
            k=(a*i+b)%mod;
            if(k<=ll)
            {
                sum++;
                if(k>maxn)
                    maxn=k;
            }
            else if(k<minn)
                minn=k;
        }
        if(minn+maxn<=l)
            sum++;
        printf("%lld\n",sum);
    }
    return 0;
}                                                 
    
