#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
using namespace std;
const double g=9.8;
int main()
{
	int t;
	double x,y,v;
	double a,b,c,temp;
	double jie1,jie2;
	double sanjiao; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&x,&y,&v);
   		if(x==0 && y==0)	{printf("0.000000\n");continue;}
		temp=v/g;
		temp=1/2*g*temp*temp;
		if(x==0 && temp<y)	{printf("-1\n");continue;}
		if(x==0 && temp>=y)	{printf("90.000000\n");continue;}
        a=g*x*x;
		b=-2*x*v*v;
		c=g*x*x+2*y*v*v;
		sanjiao=b*b-4*a*c;
		if(sanjiao<0)	{printf("-1\n");continue;}
        jie1=(-b+sqrt(sanjiao))/2/a;
		jie2=(-b-sqrt(sanjiao))/2/a;
		if(jie1>jie2)
		{
			temp=jie1;
			jie1=jie2;
			jie2=temp;
		}
		if(jie2<0)	{printf("-1\n");continue;}
        double ans;
		if(jie1<0)	ans=atan(jie2);
		else		ans=atan(jie1);//输出小的那个 
		printf("%.6lf\n",ans);
	}
}
