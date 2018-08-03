#include<iostream>
using namespace std;
int a[1000];
int main()
{
  int n,i,j=0,k;
  while(cin>>n)
  {
    i=2;
	j=0;
	while(n-i>=0)
	{
	  a[j]=i;
	  n-=i;
	  i++;
	  j++;
	}
	if(n>j)
	{
	k=n/j;
	for(i=0;i<j;i++)
	a[i]+=k;
	n%=j;

	}

	for(i=j-1;i>=0,n>0;i--,n--)
	a[i]++;
    cout<<a[0];
	for(i=1;i<j;i++)
	cout<<' '<<a[i];
	cout<<endl;
    }

}

