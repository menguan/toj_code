#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	double r,a,b,c,t;
	double x1,x2;
	while(scanf("%lf%lf",&r,&a)!=EOF)
	{
		t=-1.0;
		b=r-a;
		c=r*r*r/a/2-2*r*r+a*r;
		if(b*b-4*c<0)
		{
			puts("Oh, my god!");
			continue;
		}
		x1=(-b+sqrt(b*b-4*c))/2;
		x2=(-b-sqrt(b*b-4*c))/2;
		if(x1>=0&&x1<=r)
			t=x1;
		else if(x2>=0&&x2<=r)
			t=x2;
		if(t>=0&&t<=r)
		        printf("%.2lf\n",t);
		else
			puts("Oh, my god!");
	}
	return 0;
}
