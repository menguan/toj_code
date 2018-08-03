#include<iostream>
#include<cstring>
using namespace std;
int a[500000];
int len;
void f(int t,int po)
{
	len=1;
	a[0]=1;
	for(int i=1;i<=po;i++)
	{
		for(int j=0;j<len;j++)
		{
			a[j]=a[j]*t;
	    }
		for(int j=0;j<len;j++)
		{
			if(a[j]>=10)
			{
				int d=j;int temp=a[j];
				a[d]=temp%10;
				d++;
				if(d>len)
					  len=d;
			    temp/=10;
			    
				while(temp)
				{//cout<<temp<<endl;
			    //system("pause");
					a[d++]+=temp%10;
					temp/=10;
					if(d>len)
					  len=d;
				}
			}
		}
}		
}	  
					
int main()
{
	int t,po;
	while(cin>>t>>po&&(t+po))
	{
		memset(a,0,sizeof(a));
		
		
		len=0;
		f(t,po);
		if(t==0||po==0)
	      cout<<1<<endl;
	    else  
		{
			for(int i=len-1;i>=0;i--)
		{
           cout<<a[i];
	    }
	    cout<<endl;
	}
	    
	}
}   
