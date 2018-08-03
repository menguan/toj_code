#include<stdio.h>
#include<string.h>
#include<math.h> 
using namespace std; 
int main()
{
    int T;
    long long n, i, j;  
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &n);
        n=(n+4)/5;
        long long minnum=101010101010101010, minl, minw; 
        for(i=1; i<=(long long)sqrt(1.0*n)+1; i++)
        {
            if(n%i==0) 
                 j=n/i;
            else
                j=n/i+1; 
            long long mid=(40*i+4*(i+1))*(8*j+2*(j+1));
            if(mid<minnum)
            {
                minnum=mid, minl=40*i+4*(i+1), minw=8*j+2*(j+1);
            }
        }
        if(minl<minw)
        {
            long long t=minl; minl=minw; minw=t;
        } 
        printf("%lld X %lld = %lld\n", minl, minw, minnum);
    }
}