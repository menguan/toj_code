#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
double ans[40];
double t;
int n;
double bp;
int main()
{
    while(scanf("%d%lf",&n,&t)!=EOF&&(n+t))
    {
        ans[n]=pow(2.0,n*1.0);
        for(int i=n-1;i>=0;i--)
        {
            bp=pow(2.0,i*1.0)/ans[i+1];
            if(bp<=t)
            {
                ans[i]=(1+t)/2 * ans[i+1];
            }
            else
            {
                ans[i]=(bp-t)/(1-t) * pow(2.0,i*1.0) + (1-bp)/(1-t) * (1+bp)/2 * ans[i+1];
            }
        }
        printf("%.3lf\n",ans[0]);
    }
}
