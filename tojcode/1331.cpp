#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int m1,n1,m2,n2,maxn,i;
	double re;
	while(cin>>m1>>n1>>m2>>n2)
	{
		n1=max(n1,m1-n1),n2=max(n2,m2-n2);
		maxn=max(n1,n2);
		re=1.0;
		for(i=1;i<=maxn;++i)
		{
			if(i<=n2)re=re/(m2-n2+i)*i;
            if(i<=n1)re=re/i*(m1-n1+i);
		}
		printf("%.5f\n",re);
	}
	return 0;
}
