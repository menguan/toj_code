#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[11000];
int f()
{
	int i=0,j=1,k=0;
	int len=strlen(a);
	while(i<len&&j<len&&k<len)
	{
		int x=(i+k)%len;
		int y=(j+k)%len;
		if(a[x]>a[y])
		{
			i=i+k+1;k=0;
		}
		else if(a[x]<a[y])
		{
			j=j+k+1;k=0;
		}
		else
		  k++;
		if(i==j)
		  j++;
	}
	return min(i,j);
}
			
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cout<<f()+1<<endl;
	}
}
