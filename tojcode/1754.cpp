#include<stdio.h>
#include<cmath>
const double P=acos(-1.0);
int main()

{

    double x1,y1,r1,x2,y2,r2,a1,a2,d,r,s;

    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)!=EOF)

    {

        d=sqrt(pow((x1-x2),2.)+pow((y1-y2),2.));

        if(d>=(r1+r2)) printf("0.000\n");

        else  if(d<=fabs(r1-r2))

        {

            r=r1>r2?r2:r1;

            printf("%.3f\n",P*r*r);

        }

        else

        {

            a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));

               a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));

                  s=a1*r1*r1+a2*r2*r2-r1*d*sin(a1);

                    printf("%.3f\n",s);

        }

    }

    return 0;

}