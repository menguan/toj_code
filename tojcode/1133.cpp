#include<iostream>

using namespace std;
bool go(int n,int m,int target)
{
	int now,next,b;
	now=b=0;
	while(true)
	{
		next=(now+m-1)%(n-b)+1;
		b++;
		if(next==target)
		{
			if(b<n)
				return false;
			else
				return true;
		}
		now=next-1;
	}
}
int main()
{
	int i,j,n,m;
	
	while(cin>>n,n)
	{
		
		for(m=1;;m++)
		{
			if(go(n-1,m,1))
			{
				cout<<m<<endl;
				break;
			}
		}
		
	}
	return 0;
}