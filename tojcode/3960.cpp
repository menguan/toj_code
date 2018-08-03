#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int cas,t=1;
	cin>>cas;
	while(cas--)
	{
		double a,b,c,d;
		{
			cin>>a>>b>>c>>d;
			bool f=1;
			double s=(a+b+c+d)/2;
			double ans=sqrt((s-a)*(s-b)*(s-c)*(s-d));
			if(a>=b+c+d || b>=a+c+d || c>=a+b+d || d>=a+b+c)
				printf("Case %d: -1\n",t++);
			else
				printf("Case %d: %.6lf\n",t++,ans);

		}
	}
	return 0;
}
