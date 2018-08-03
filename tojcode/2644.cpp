#include<iostream>
#include<cmath>
#include<stdio.h>
#include<algorithm>
using namespace std;
double pi=acos(-1.0);
double pie[10010];
double sum,maxn;
int main()
{
    int i,n,f,t,c,cnt;
    double l,r,m;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d%d",&n,&f);
      f++;
      maxn=sum=0;
      for(i=0;i<n;i++)
      {
         scanf("%d",&c);
         pie[i]=pi*c*c;
         maxn=max(pie[i],maxn);
         sum+=pie[i];
      }
      l=maxn/f;
      r=sum/f;
      while(l+0.00001<r)//???????????????????
      {
        m=(l+r)/2;
        cnt=0;
        for(i=0;i<n;i++)
          cnt+=(int)floor(pie[i]/m);
        if(cnt<f) r=m;
        else l=m;
      }
      printf("%.4lf\n",l);
    }
    return 0;
}
