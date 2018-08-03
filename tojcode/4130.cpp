#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long mod=1000000007;
int main()
{
   long long h,n,t;
   //cin>>t;
   scanf("%lld",&t);
   while(t--)
   {
         //cin>>n;
         scanf("%lld",&n);
         long long sum=(n+1)*n;
         long long must=1;
         for(long long i=1;i<=n;i++)
            {must=must*i%mod;must=must*i%mod;}
         long long kk=1;
         for(int i=3;i<=2*n;i++)
         {
             //cin>>h;
             scanf("%lld",&h);
             sum-=h;
             kk=kk*h%mod;
         }
         long long tmp;

         for(long long i=1;i<=n;i++)
         {
             tmp=kk*(sum-i)%mod;
             tmp=tmp*i%mod;
             if( tmp==must

                )
                {

                    printf("%lld %lld\n",i,sum-i);
                    break;
                }

         }

   }

}
