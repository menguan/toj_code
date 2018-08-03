/*#include<stdio.h>//有点乱 
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	char a[5];
	int n,x,i,j,t,w;
	int p=1,q=9,b[10000],sum=0,flag=0;
	for(i=1;i<=9;i++)
	{
		for(j=p;j<=q;j++)
		{
			sum+=i*j;
		    b[j]=sum;
			if(sum>=199000001)
			{flag=1; break;}	
		}
		if(flag==1)
			break;
		p=j;
		q=p*10-1;

	}
	while(cin>>n)
	{
		for(i=1;i<=9999;i++)
		{
			if(n<=b[i])
			{
				break;
			}
		}
			sprintf(a,"%d",i);
			w=strlen(a);
 			printf("%c\n",a[(n-b[i-1]-1)%w]);
	}

	return 0;

}
*/
#include<stdio.h>//有点乱 
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	char a[5];
	int n,x,i,j,t,w;
	int p=1,q=9,b[10000],sum=0,flag=0;
	for(i=1;i<=9;i++)
	{
		for(j=p;j<=q;j++)
		{
			sum+=i*j;
		    b[j]=sum;
			if(sum>=199000001)
			{flag=1; break;}	
		}
		if(flag==1)
			break;
		p=j;
		q=p*10-1;

	}
	while(cin>>n)
	{
		for(i=1;i<10000;i++)
		{
			if(n<=b[i])
			{
				break;
			}
		}
			sprintf(a,"%d",i);
			w=strlen(a);
 			printf("%c\n",a[(n-b[i-1]-1)%w]);
	}

	return 0;

}
