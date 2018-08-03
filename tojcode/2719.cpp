#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,e;int temp;
	cin>>n>>e;
	double a=0,b=0;
	for(int i=0;i<n-1;i++)
	{
		cin>>temp;
		a+=temp;
    }
    for(int i=0;i<e-1;i++)
    {
		cin>>temp;
		b+=temp;
	}
	cout<<(int)ceil(sqrt(a*a+b*b))<<endl;
	//while(1);
}
	
