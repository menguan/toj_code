#include<iostream>
#include<cmath>
#include<stdio.h> 
using namespace std;
int main()
{
int count;
double m,n,ratio1,ratio2,b,w,c,t;
while(scanf("%lf%lf%lf",&b,&w,&c)!=EOF)
{
   if(b==0&&w==0&&c==0)
    break;
   else
   {
    m=1.0;
    n=0.0;
    t=b/w;
    count=0; 
    do
    {
    n=(w*n+c*m/16)/(w+c/16);
    m=(m*b-c*m/16+n*c/16)/b;  
    ratio1=m*b/(b-m*b);      
    ratio2=n*w/(w-n*w);      
    count++;                     
    }
    while(fabs(ratio1-t)>0.00001||fabs(ratio2-t)>0.00001);
    printf("%d\n",count);
   }
}
return 0;
} 