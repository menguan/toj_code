#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;



void toMinMax(int a[],int n,int b[],int c[])
{
	int i,j=0;int k=0;
	int min=1000;
	int max=0;
	int lengthA=n;
	for(i=0;i<lengthA;i++)
	{
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	for(i=0;i<lengthA;i++)
	{
		if(min==a[i])
		{
			b[j]=i+1;
			j++;
		}
		if(max==a[i])
		{
			c[k]=i+1;
			k++;
		}
	}
}
bool isValue(int a[][101],int n,int m,int p)
{
	int length=m;
	for(int i=0;i<length;i++)
		for(int j=0;j<p;j++)
		if(a[i][j]==n)
			return true;
	return false;
}
int howValue(int a[][101],int n,int m,int p)
{
	int length=m;
	int count=0;
	for(int i=0;i<length;i++)
		for(int j=0;j<p;j++)
		if(a[i][j]==n)
			count++;
	return count;
}
int main()
{
	int N,P,i,j,k=0;
	int a[101];
	int b[101];
	int min[101][101];
	int max[101][101];

	while(cin>>N>>P)
	{
		memset(a,0,sizeof(a)); 
		memset(b,0,sizeof(b)); 
		memset(min,0,sizeof(min)); 
		memset(max,0,sizeof(max));
		for(i=0;i<N;i++)
		{
			for(j=0;j<P;j++)
				cin>>a[j];
			toMinMax(a,P,min[i],max[i]);
		}
		for(i=0;i<N;i++)
			for(j=0;j<P;j++)
			{
				if(howValue(min,min[i][j],N,P)>N/2 && isValue(max,min[i][j],N,P)==false)
				{
					int flag=0;
					for(int m=0;m<k;m++)
					{
						if(b[m]==min[i][j])
						{
							flag=1;
							break;
						}								
					}
					if(flag==0)
					{
						b[k]=min[i][j];
						k++;
					}
				}
			}
		if(k!=0)
		{
			sort(b,b+k);
			cout<<b[0];			
			for(i=1;i<k;i++)
				cout<<" "<<b[i];
		}
		else
			cout<<0;
		cout<<endl;
		k=0;
	}
	return 0;
}
