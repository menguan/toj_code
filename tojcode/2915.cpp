#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int a[100000],mod[100000] ; 
int main()
{
 int c,n,i,j;
 long long sum;
 while(scanf("%d%d",&c,&n),c||n)
 {
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
   mod[i]=-2;
  }
  mod[0]=-1;
  sum=0;
  for(i=0;i<n;i++)        
  {
    sum+=a[i];      
   if (mod[sum%c]!=-2)
   {
    for (j=mod[sum%c]+1;j<=i;j++)
    {
     printf("%d",j+1);
     if (i!=j)
      printf(" ");
    }
    printf("\n");
    break;
   }
   mod[sum%c]=i;
        }
    }
 return 0;
}
