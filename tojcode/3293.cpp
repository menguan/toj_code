#include<stdio.h>
#include<iostream>

#define MOD 200907
using namespace std;
long long f(long long a,long long b,int n){ 
    long long ret=1;
    for (;b;b>>=1,a=(long long)(((long long)a)*a%n))
        if (b&1)
            ret=(long long)(((long long)ret)*a%n);
    return ret;
}


int main()
{
    double a,b,c;
    int T;
    int k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%d",&a,&b,&c,&k);
        if(a+c==2*b)
        {
            long long a1=(long long )a;
            long long d=(long long )(b-a);
            int ans=(a1%MOD+((k-1)%MOD)*(d%MOD))%MOD;
            printf("%d\n",ans);
        }
        else
        {
            long long a1=(long long )a;
            long long t1=(long long )(a1%MOD);
            double q1=(b/a);
            long long q2=(long long)q1;
            long long q=(long long)(q2%MOD);//变个类型还这么多步 
            long long tmp=f(q,k-1,MOD);
            int ans=(t1*tmp)%MOD;
            
            
            printf("%d\n",ans);
        }
    }
    return 0;
}