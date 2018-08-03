#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
using namespace std;
const double pi=acos(-1.0);
int main()
{
    double a,b,c,l;int cas=1;
    while(cin>>a>>b>>c>>l&&(a+b+c+l))
    {
       double p=(a+b+c)/2;
       double s=sqrt(p*(p-a)*(p-b)*(p-c));
       printf("Case %d: ",cas++);
       if(p*2<=l)
       {
          printf("%.2f\n",s);
          continue;
       }
       double r=s/p;
       if(2*pi*r-l>=0)
       {
          printf("%.2f\n",(l/(2*pi))*(l/(2*pi))*pi);
          continue;
       }
       double _r=(p*2-l)*r/(p*2-2*pi*r);
       printf("%.2f\n",s-_r*_r/r/r*s+pi*_r*_r);
    }
} 
                                                        
                          

