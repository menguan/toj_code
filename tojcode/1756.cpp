#include <cstdio>//线性规划 网上看得和自己的式子差不多 不过自己用小数应该不靠谱
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int a[10000000];
#define N 110
int n,w,e,result;
int main()
{
 int i,j,x,y,t1,t2,t3,t4;
 while (scanf("%d%d%d",&n,&w,&e) != EOF && n > 0)
 {
  if (w == e)
  {
   if (w == 0 || w == 100 * N)
    printf("%d\n",n);
   else if (w % 100 == 0)
    printf("%d\n",2 * n);
   else
    printf("%d\n",n);
   break;
  }
  result = 0;
  for (i = 1;i <= n;i ++)
  for (j = 1;j <= n;j ++)
  {
   x = 100 * i - 100;
   y = 100 * j - 100;
   t1 = (e-w)*x - 100 * n * y + 100 * n * w;
   x = 100 * i;
   y = 100 * j - 100;
   t2 = (e-w)*x - 100 * n * y + 100 * n * w;
   x = 100 * i - 100;
   y = 100 * j;
   t3 = (e-w)*x - 100 * n * y + 100 * n * w;
   x = 100 * i;
   y = 100 * j;
   t4 = (e-w)*x - 100 * n * y + 100 * n * w;
   if (!((t1>0 && t2>0 && t3>0 && t4>0) || (t1<0 && t2<0 && t3<0 && t4<0)))
    result ++;
  }
  printf("%d\n",result);
 }
}
