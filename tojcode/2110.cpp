#include <stdio.h>//最后看网上的才知道要用double型 
int main()
{
	int y[11],n,i,j,x;
	double m,l;
	while(scanf("%d",&n),n!=0)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&y[i]);
		scanf("%d",&x);
		for(i=2;i<=n;i++)
			if(y[i]!=y[1])
				break;
		if(i>n)//给的数字都一样 
		{
			printf("Term %d of the sequence is %d\n",x+n,y[1]);
			continue;
		}
		x+=n;
		m = 0;
		for(i=1;i<=n;i++)
		{
			l=1;
			for(j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				l=l*(x-j)/(i-j);
			}
			//printf("%f\n",l);
			l *= y[i];
			m+=l;
		}
		printf("Term %d of the sequence is %.0lf\n",x,m);
	}
}
