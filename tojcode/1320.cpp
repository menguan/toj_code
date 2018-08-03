#include <stdio.h>
#include <cmath>
const double PI=acos(-1.0);
int main()
{
    double a,b,s,m,n;
    while(scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n)==5)
    {
        if(a+b+s+m+n==0) break;
        double tan=(b*n)/(a*m);
        double d=atan(tan);
        double sum=a*m/cos(d);
        double v=sum/s;
        printf("%.2lf %.2lf\n",double(d*180.0/PI),v);
    }
    return 0;
}