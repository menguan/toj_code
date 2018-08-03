#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char a[200];
char f(char c,int t)
{
	bool flag=0;
	
	if(c>='a'&&c<='z')
	{  flag=1;
	c=c-32;}
	int num=c-'A';
	int ans;//cout<<num<<endl;
	if(num<=2)
	{
		t%=3;
		ans=(num-t+24)%3;
	}
	else if(num<=5)
	{
		t%=3;
		ans=3+(num-t+24)%3;
	}
	else if(num<=8)
	{
		t%=3;
		ans=6+(num-t+24)%3;
	}
	else if(num<=11)
	{
		t%=3;
		ans=9+(num-t+24)%3;
	}
	else if(num<=14)
	{
		t%=3;
		ans=12+(num-t+24)%3;
	}
	else if(num<=18)
	{
		t%=4;
		ans=15+(num-15-t+24)%4;
	}
	else if(num<=21)
	{
		t%=3;
		ans=19+(num-19-t+24)%3;
	}
	else if(num<=25)
	{
		t%=4;
		ans=22+(num-22-t+24)%4;
	}	
	
	//cout<<ans<<endl;
	if(flag)
	  return ans+32+'A';
	else
	  return ans+'A';
}  		  

int main()
{
	while(cin>>a)
	{
		if(strcmp(a,"#")==0)
		  return 0;
		
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			a[i]=f(a[i],i+1);
	    }
		cout<<a<<endl;
	}
}	
		  
