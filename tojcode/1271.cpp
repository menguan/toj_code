#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct point
{
       int x,y;
}p[110];
bool judge(int x1,int x2,int y2,int y1,point a)
{
     if((a.x-x1)*(a.x-x2)<=0&&(a.y-y1)*(a.y-y2)<=0)
       return 1;
     return 0;
}
int main()
{
    int t,n,r;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&r);
       for(int i=1;i<=n;i++)
         scanf("%d%d",&p[i].x,&p[i].y);
       int res=1;
       int temp;
       for(int i=1;i<=n;i++)
       {
          for(int j=i+1;j<=n;j++)
          {
              if(abs(p[i].x-p[j].x)>r||abs(p[i].y-p[j].y)>r) continue;
              int tx=min(p[i].x,p[j].x);
              int ty=max(p[i].y,p[j].y);
              temp=0;
              for(int k=1;k<=n;k++)
                 if(judge(tx,tx+r,ty,ty-r,p[k]))
                    temp++;
              res=max(res,temp);
          }
       }
       printf("%d\n",res);
    }
}      
                                    
