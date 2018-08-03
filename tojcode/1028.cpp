#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int y[22],a[22],b[22],de[22];
int gcd(int x,int y)
{
 if(!y) return x;
 return gcd(y,x%y);
}
int main()
{
 //cout<<2141%136<<endl;
 //cout<<100/gcd(100,136)*136<<endl;
 int n,tc=1,i,my,gg,sy;
 while(scanf("%d",&n)!=EOF,n)
 {
  my=0;
  for(i=0;i<n;i++)
  {
   scanf("%d%d%d",&y[i],&a[i],&b[i]);
   de[i]=b[i]-a[i];
   if(a[i]>my) my=a[i];
   y[i]=y[i]%de[i];
  }
  gg=de[0];
  sy=y[0];
  for(i=1;i<n;i++)
  {
   while(sy%de[i]!=y[i]&&sy<10002)
    sy+=gg;
   //cout<<sy<<endl; 
   if(sy>10002) break;
   gg=gg/gcd(gg,de[i])*de[i];
  }
  while(sy<my)
   sy+=gg;
  printf("Case #%d:\n",tc++);
  if(sy>=10000)
   printf("Unknown bugs detected.\n\n");
  else
   printf("The actual year is %d.\n\n",sy);
 }
}

