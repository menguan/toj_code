#include<stdio.h>
using namespace std;
int a[60000];
long long sum[60000];
int main()
{
  int n,q,beat;
  scanf("%d%d",&n,&q);
  int count=1;
  sum[0]=0;
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&beat);
      a[count++]=beat;
    sum[count-1]=a[count-1]+sum[count-2];  
  }
  sum[count]=sum[count-1]+100;
  int r;
  
  while(q--)
  {
    scanf("%d",&r);
    int high=count;
    int low=0;
    while(1)
    {
      int m=(high+low)/2;
      if(r>=sum[m-1]&&r<sum[m])
      {
        printf("%d\n",m);
          break;
      }
      else if(r<sum[m-1])
        high=m-1;
      else if(r>=sum[m])
        low=m+1;  
    }           
  }
  //while(1);
}  