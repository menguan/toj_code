#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[1000010];
int main()
{
    long long t;long long n;
    
    scanf("%lld",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
          scanf("%lld",&a[i]);
        long long dif1=0;long long dif2=0;
        for(int i=1;i<n;i++)
        {
           if(a[i]>a[i-1])
           dif1+=(a[i]-a[i-1]);
           else
           dif2+=(a[i-1]-a[i]);  
        }
        long long ans=(dif1>dif2?dif1:dif2);
        long long tt=abs(a[n-1]-a[0])+1;
        printf("Case %d: %lld %lld\n",cas,ans,tt);

        //cout<<"Case "<<cas<<": "<<<<" "<<<<endl;
    }
}           

