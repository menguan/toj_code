#include<stdio.h>//网上模板 
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
#define eps 1e-8
using namespace std;
const int N=25;
struct point
{
       double x,y;
}pt[N],pd[N];
int n;
double tmp,maxx;
int dblcmp(double a){return fabs(a)<eps?0:a>0?1:-1;}
double cross(point a,point b,point c)
{
       return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool segcross(point a,point b,point c,point d)
{
     int d1,d2;
     double s1,s2;
     d1=dblcmp(s1=cross(c,a,b));
     d2=dblcmp(s2=cross(d,a,b));
     if(d1*d2<0)
     {
        tmp=(s2*c.x-s1*d.x)/(s2-s1);
        return 1;
     }
     if(d1*d2==0)
     {
        if(d1==0)
          tmp=c.x;
        else
          tmp=d.x;
        return 1;
     }
     return 0;
}                        
                
int main()
{
    while(scanf("%d",&n),n)
    {
      int i,j,k;
      bool flag=0;
      for(i=1;i<=n;i++)
      {
        scanf("%lf%lf",&pt[i].x,&pt[i].y);
        pd[i]=pt[i];pd[i].y-=1;
      }
      for(i=1,maxx=pt[1].x;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          for(k=1;k<=n;k++)
          {
             if(!segcross(pt[i],pd[j],pt[k],pd[k]))  break;
          }   
             if(k>n){  flag=1;break;}
             if(k<max(i,j))  continue;
             segcross(pt[i],pd[j],pt[k-1],pt[k]);
             if(tmp>maxx)  maxx=tmp;
             segcross(pt[i],pd[j],pd[k-1],pd[k]);    
             if(tmp>maxx) maxx=tmp;
        }
           if(flag)
            break;
       }
       if(flag) puts("Through all the pipe.");
       else printf("%.2lf\n",maxx);
    }
}                                                                /**/           
                                                     
