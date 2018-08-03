#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
bool a[1050];
int main()
{ 
	int m=0,n=0,count=0,t; 
	while (scanf("%d%d",&m,&n)!=EOF) 
	{  
		if(m==0&&n==0) 
			break;  
		else         
			count++; 
		register int i=0; 
		int win=0,temp=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++) 
		{   
			scanf("%d",&t);  
			a[t]=1; 
		}  
		for(i=n*m;i>0;i--)
		{   
			if (a[i])
			{             
				if (temp==0)  
					++win;          
				else             
					--temp;    
			} 
			else  
				++temp;
		}  
		printf("Case %d: %d\n",count,win); 
	} 
	return 0;
}
