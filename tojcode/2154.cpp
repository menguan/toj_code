#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXN=1005;
 
int main()
{
  int n;
  double x0[MAXN], x, y;
  int t;int cas=1;
  scanf("%d",&t);
  while(t--)
  {
   int i;scanf("%d", &n);
   for (i=0; i<n; i++)
   {
    scanf("%lf", &x0[i]);
   }
   sort(x0,x0+n);
   y=1.0;
   for (i=1; i<n; i++)
   {
    y+=sqrt(4-(x0[i]-x0[i-1])*(x0[i]-x0[i-1])/4);
   }
   printf("%d: %.4lf %.4lf\n", cas++, (x0[0]+x0[n-1])/2, y);
  }
  return 0;
}
