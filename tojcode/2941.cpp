#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
double p[100010];
double v[100010];
int main()
{
    int n;
    while(cin>>n,n)
    {
         double ans=0;
         for(int i=1;i<=n;i++)
         {
              cin>>p[i]>>v[i];
              
         }
         for(int i=n;i>=1;i--)
         {
           ans=max(ans,(1.0-p[i]/100.0)*ans+v[i]/100*p[i]);
         }
         printf("%.2lf\n",ans);
    }
}       
                   
