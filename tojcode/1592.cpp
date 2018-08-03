#include <stdio.h>
#include <cmath>
#include <iostream>
#include <cstring>
int main()
{
	int j=1;
	int t,w,d;
	while(scanf("%d%d",&w,&d)!=EOF&&(w+d))
	{
		t=(int)(log(810.0*w/d)/log(2)*5730);
		if (t<10000)
		{
			t=(t+50)/100*100;
		}
		else 
		{
			t=(t+500)/1000*1000;
		}
		printf("Sample #%d\n",j++);
		printf("The approximate age is %d years.\n\n",t);
	}
}
