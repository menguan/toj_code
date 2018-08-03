#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char isprime[50000];
int prime[10000];
int main()
{
    int n,i,j,p,testcase,mul,sq,t,s=1;
    memset(isprime,-1,sizeof(isprime));
    for(i=2;i<250;i++)
        for(j=i*2;j<50000;j+=i)
            isprime[j]=0;
    for(i=2,p=0;i<50000;i++)
        if(isprime[i]!=0)prime[(p)++]=i;
    scanf("%d",&testcase);
    while(testcase--)
    {
        scanf("%d",&n);
        mul=1,sq=(int)sqrt(n*1.00),t=0;
        for(i=0;i<p;i++)
    	{
    	    t=0;
            if(prime[i]>sq)break;
            while(n%prime[i]==0)
    		{
               n/=prime[i];t++;
    		}
            mul*=(t*2+1);
    	}
        if(n>1)mul*=3;
        printf("Scenario #%d:\n",s++);
        printf("%d\n\n",(mul+1)/2);
    }
    return 0;
}
