#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long m,long long n)
{
	long long p=max(m,n);
	long long q=min(m,n);
	long long r=p%q;
	while(r)
	{
		p=q;
		q=r;
		r=p%q;
	}
	return q;
}
int main()
{
	long long a,b;
	while(cin>>a>>b&&a&&b)
	{
		
		if(gcd(a,b)==1)
		{
			cout<<a*b-a-b<<endl;
	    }
	    else
	      cout<<"Inf"<<endl;

	}	 
}
