#include<stdio.h>

int arr1[10000];
int arr2[10000];

int find1(int n,int x)
{
	int i;
	for(i=0;i<n;i++)
		if(arr1[i]==x)
			return i;
	return -1;
}
int find2(int n,int x)
{
	int i;
	for(i=0;i<n;i++)
		if(arr2[i]==x)
			return i;
	return -1;
}
int main()
{
	int i,n1=0,n2=0,x=2,temp;
	while((temp=find1(n1,x))==-1)
	{
		arr1[n1++]=x;
		x=(x*4-5)%10007;
		if(x<0)
			x+=10007;
	}
	x=2;
	while((temp=find2(n2,x))==-1)
	{
		arr2[n2++]=x;
		x=(x*4-4)%10007;
		if(x<0)
			x+=10007;
	}
	int cases,r=1;
	scanf("%d",&cases);
	while(cases--)
	{
		int n;
		scanf("%d",&n);
		if(n%2==1)
			printf("Case #%d: %d\n",r++,arr1[((n-1)/2)%n1]);
		else
			printf("Case #%d: %d\n",r++,arr2[((n-1)/2)%n2]);
	}
	return 0;
}