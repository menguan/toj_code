#include<iostream>
#include<stdio.h>
using namespace std;
int chang(int n)
{
	int ret=0;
	while(n>0)
	{
		ret=ret*10+n%10;
		n/=10;
	}
	return ret;
}
int main()
{
    int x,y,N,i,j,n=0,b=0,c=0,d,a,m=0;
    //cin>>N;
	scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
                     //cin>>x>>y;
		scanf("%d%d",&x,&y);
                     x=chang(x);
					 y=chang(y);
					 d=x+y;
                     //cout<<d<<endl;
                     //cout<<endl;
					 printf("%d\n\n",d );
    }
    return 0;
}