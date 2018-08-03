#include<iostream>
using namespace std;
const int M=100010;
int s[M],prime[M],phi[M];
void init()
{
	int i,j;
	for(i=2;i<M;i++)
       if(!prime[i])
          for(j=i+i;j<M;j+=i)
            prime[j]=1;
	for(i=1;i<M;i++)
		phi[i]=i;
	for(i=2;i<M;i++)
		if(!prime[i])
			for(j=i;j<M;j+=i)
				phi[j]=phi[j]/i*(i-1);
	for(i=2;i<=10000;i++)
		s[i]=s[i-1]+(i-1-phi[i])*2 +1;
}
int main()
{
	int t,n;
	init();
	cin>>t;
	while(t--)
	{
		cin>>n;		
		cout<<n*n-s[n]<<endl;		
	}
}
