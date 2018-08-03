#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double s,v,a,j,t1,t2,d;
double solve()
{
if (a*a>j*v)
{
   t1=sqrt(v/j);
   s=j*t1*t1*t1;
}
else
{
   t1=a/j;
   t2=v/j/t1-t1;
   s=j*t1*t1*t1+1.5*j*t1*t1*t2+0.5*j*t1*t2*t2;
}
// printf("%lf %lf\n",t1,s);
if (2*s>d)
{
   t1=pow(d/2/j,1.0/3.0);
// printf("%lf %lf\n",t1*j,a);
   if (j*t1<a) return 4*t1;
   else
   {
    t1=a/j;
    t2=(-3*t1+sqrt(t1*t1+4*d/a))/2;
    return 4*t1+2*t2;
   }
}
else
{
   if (a*a>j*v) 
    return 4*t1+(d-2*s)/v;
   else return 4*t1+2*t2+(d-2*s)/v;
}
return 0;
}
int main()
{
while(scanf("%lf%lf%lf%lf",&d,&v,&a,&j)!=EOF)
{
   printf("%0.1lf\n",solve());
}
return 0;
}
