#include <iostream>
#include <cmath> 
#include <cstring>
using namespace std;

bool prime[1000000];
int p[1000000];

int main()
{
	int i,j;
	memset(prime,0,sizeof(prime));
	for(i=2;i<=sqrt(1000000.0);i++)
	{
		if(!prime[i])
		{
			for(j=i*i;j<1000000;j+=i) prime[j]=1;
		}
	}
	j=0;
	for(i=2;i<=1000000;i++)
	{
		if(!prime[i]) 
		{
			p[j]=i;
			j++;
		}
	}
	int l,u;
	while(cin>>l>>u)
	{
		int psum=0;
		int nsum=0;
		if(l==-1&&u==-1) break;
		for(int k=0;k<j&&p[k]<=u;k++)
		{
			if(p[k]>=l&&p[k]<=u)
			{
				psum++;
				if(p[k]==2) nsum++;
				else if((p[k]-1)%4==0) nsum++;
			}
		}
		cout<<l<<" "<<u<<" "<<psum<<" "<<nsum<<endl;
	}
		return 0;
}
