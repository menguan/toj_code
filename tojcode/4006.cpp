#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL get(LL n,LL a,LL b)
{
    LL now=0,ret=0,tmp,x=0,y=0;
    while(now<n)
    {
        tmp=min(a-x,b-y);
        if (now+tmp>n) tmp=n-now;
        ret+=tmp*abs(x-y);//cout<<x<<"  "<<y<<"  "<<tmp<<endl;
        x=(x+tmp)%a;
        y=(y+tmp)%b;

        now+=tmp;
    }
    return ret;
}

int main()
{
    int i,j,T;
    LL a,b,n,l,ans;
    scanf("%d",&T);
    while(T--)
    {
        cin>>n>>a>>b;
        l=a*b/gcd(a,b);
        if (l>=n) ans=get(n,a,b);
        else ans=get(l,a,b)*(n/l)+get(n%l,a,b);
        cout<<ans<<endl;
    }
}
