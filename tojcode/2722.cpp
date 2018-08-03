#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
struct data
{
	int val,pos;
}num[100100];
bool cmp(data m,data n)
{
     return m.val<n.val;
}
int main()
{
	int n,m,i,a,b,t;
	 while (scanf("%d%d",&n,&m)!=EOF)
	 {
		 for(i=1;i<=n;i++)
		 {
			 scanf("%d",&num[i].val);
			 num[i].pos=i;					
		 }
		 sort(num+1,num+n+1,cmp);	
		 while (m--)
		 {
			 scanf("%d%d%d",&a,&b,&t);
			 int sum=b-a+1;
			 int mid=sum/2;
			 if(t>mid)					
			 {
				  t=sum-t+1;
				  for(i=n;i>=1;i--)
				  {
					   if(num[i].pos>=a&&num[i].pos<=b)
						   if(--t==0)
							break;
				  }
				  printf("%d\n",num[i].val);
			 }
			 else					   
			 {
				 for(i=1;i<=n;i++)
				 {
					 if(num[i].pos>=a&&num[i].pos<=b)
					 {
						 if(--t==0)
							 break;
					 }
				 }
				 printf("%d\n",num[i].val);
			 }
			 
		 }
	 }
}
