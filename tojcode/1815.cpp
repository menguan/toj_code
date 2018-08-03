#include <stdio.h>
#include <math.h>
#define EPS 1e-2
double PI = acos(-1.0);
double distance(double a,double b,double c,double d)
{
double s;
s = (a - c) * (a - c) + (b - d) * (b - d);
s = sqrt(s);
return s;
}
double ACOS(double x,double y,double z)//,double y2,double x3,double y3)
{
double s;
s = (y * y + z * z - x * x) / (2 * y * z);
s = acos(s);
return s;
}
int main()
{
double x1,x2,x3,y1,y2,y3,d1,d2,d3,A,B,C;
int total;
while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
{
   d1 = distance(x1,y1,x2,y2);
   d2 = distance(x2,y2,x3,y3);
   d3 = distance(x1,y1,x3,y3);
   if(d1 - d2 - d3 >= 0||d2 - d3 - d1 >= 0||d3 - d1 - d2 >= 0) { printf("Not a Triangle\n"); continue; }
   total = 0;
   if(d1 - d2 < EPS && d2 - d1 < EPS)
    total ++;
   if(d1 - d3 < EPS && d3 - d1 < EPS) 
    total ++;
   if(d2 - d3 < EPS && d3 - d2 < EPS)
    total ++;
   if(total == 0)
    printf("Scalene ");
   else if(total == 1)
    printf("Isosceles ");
   else
    printf("Equilateral ");
   A = ACOS(d1,d2,d3) * 180 / PI;
   B = ACOS(d2,d1,d3) * 180 / PI;
   C = ACOS(d3,d1,d2) * 180 / PI;
   if(A >= 92||B >= 92||C >= 92) printf("Obtuse\n");
   else if(A < 88 &&B < 88 && C < 88) printf("Acute\n");
   else printf("Right\n");
     
}
    printf("End of Output\n");
return 0;
}
