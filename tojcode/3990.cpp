#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;
const int m=1000010;
int prime[m];
bool is[m];
int num;
void init()
{
     num=0;
     memset(is,0,sizeof(0));
     for(int i=2;i<m;i++)
     {
        if(!is[i])
        {
            prime[num++]=i;
            for(int j=i+i;j<m;j+=i)
            {
                is[j]=1;
            }
        }
     }
}
int main()
{
    init();long long b;
    long long ans;
    while(scanf("%lld",&b),b)
    {
        ans=b;
        for(int i=0;i<num;i++)
        {
           if(b%prime[i]==0)
           {
              ans=ans/prime[i]*(prime[i]-1);
              while(b%prime[i]==0)
                b/=prime[i];
           }
        }
        if(b!=1)
          ans=ans/b*(b-1);
        printf("%lld\n",ans);
    }
}                                           
                                   
     
