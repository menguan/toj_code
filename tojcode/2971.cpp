#include<stdio.h>
#include<math.h>
int main()
{        
int a[10000],i,j,k,n,m,l,ks,t;        
while(scanf("%d%d",&a[0],&n)!=EOF)        
{               
l=0;               
for(i=1;i<=1000;i++)               
{                       
k=log10(a[i-1]);                       
a[i]=a[i-1]/10+a[i-1]%10*pow(10,k);                          
for(j=0;j<i;j++)                               
if(a[j]==a[i])                               
{                                      
ks=j;                                      
t=i-j;                                      
l=1;                                      
break;                               
}                               
if(l)
break;               
}               
if(n<=ks)               
{                       
printf("%d\n",a[n]);                       
continue;               
}               
n=ks+(n-ks)%t;               
printf("%d\n",a[n]);        
}        
return 0;
}