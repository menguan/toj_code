#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct ston
{
    int x,y;
}a[210000];
int cmprow(ston a,ston b)
{
    if(a.x==b.x)
      return a.y<b.y;
    return a.x<b.x; 
}
int cmpcolumn(ston a,ston b)
{
    if(a.y==b.y)
      return a.x<b.x;
    return a.y<b.y;  
}
int main()
{
    int t,m,n,k,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d%d",&m,&n,&k);
        for(int i=1;i<=k;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        a[0].x=1,a[0].y=0;
        a[k+1].x=m,a[k+1].y=n+1;
        sort(a+1,a+k+1,cmprow);
        for(int i=1;i<=k+1;i++)
        {
                 if(a[i-1].x==a[i].x)
                {
                    if(a[i].y-a[i-1].y-1>=2)
                    sum+=1;
                }
                else
                {
                    sum+=a[i].x-a[i-1].x-1;
                    if(n-a[i-1].y>=2)
                        sum+=1;
                    if(a[i].y-1>=2)
                    sum+=1;
                }
        }
        a[0].x=0;a[0].y=1;a[k+1].x=m+1;a[k+1].y=n;
        sort(a+1,a+k+1,cmpcolumn);
        for(int i=1;i<=k+1;i++)
        {
                 if(a[i-1].y==a[i].y)
                {
                    if(a[i].x-a[i-1].x-1>=2)
                    sum+=1;
                }
                else
                {
                    sum+=a[i].y-a[i-1].y-1;
                    if(m-a[i-1].x>=2)
                    sum+=1;
                    if(a[i].x-1>=2)
                    sum+=1;
                }
        }
        printf("%d\n",sum);
    }
}
