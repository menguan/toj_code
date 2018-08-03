#include <stdio.h>
int main()
{    
  long long n,m,i,r;    
  while (scanf("%lld%lld",&n,&m)!=EOF)    
  {        
    if (m==0&&n==0) 
      break;        
    long long t=m+n;        
    if (n>m) n=m;        
    for (r=1,i=t-n+1;i<=t;i++) 
    r=(r*i)/(i-t+n);        
    printf("%lld\n",r);    
  }    
    return 0;
}