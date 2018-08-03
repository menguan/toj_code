#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){	
  int i,j,n,sam,ella;	
  int a[31];	
  while(cin>>n,n)	
  {		
    memset(a,0,sizeof(a));		
    for(i=1;i<=n;i++)			
      cin>>a[i];		
    for(i=1;i<=n;i++)		
    {		
    	sam=ella=0;			
        for(j=1;j<=i;j++) 
          sam+=a[j];			
        for(j=n;j>i;j--) 
          ella+=a[j];			
        if(sam==ella)			{				
        printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);				
        break;			}
        		}		
          if(sam!=ella)			
            puts("No equal partitioning.");	}	
          return 0;}