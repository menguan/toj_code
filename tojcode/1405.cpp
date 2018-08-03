#include <stdio.h>
#include <math.h>
typedef struct Point 
{
double x,y;
}Point;
Point p[1001],Q[1001];
int main()
{
int n,i;
double s;
while(scanf("%d",&n)!=EOF)
{
   for(i = 1;i <= n; i ++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
   s = 0;
   for(i = 1; i < n; i ++)
   {
    if(i % 2) s += 2 * p[i].x;
    else s -= 2 * p[i].x;
   }
   Q[1].x = (2 * p[n].x + s) / 2;
   for(i = 2; i <= n ;i ++)
    Q[i].x = 2 * p[i - 1].x - Q[i-1].x;
   s = 0;
   for(i = 1;i < n; i ++)
   {
    if(i % 2) s += 2 * p[i].y;
    else s -= 2 * p[i].y;
   }
   Q[1].y = (2 * p[n].y + s) / 2;
   for(i = 2; i <= n; i ++)
    Q[i].y = 2 * p[i-1].y - Q[i-1].y;
   printf("%d",n);
   for(i = 1; i <= n; i ++)
    printf(" %f %f",Q[i].x,Q[i].y);
   printf("\n");
}
return 0;
}
