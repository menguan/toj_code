#include <iostream>
#include <cstdio>
using namespace std;
long long result( int start , int i)
{
 int times = 1;
 int s;
 if(start == 1) times = 15;
 else if(start == 2) times = 150; 
 else
 {
  times = 750;
  start = start - 3;
  while(start--)
  {
   times *= 10;
  }
 }
 if(start == 2)
 {
  if( i % 4 == 0)
   s = (i + i/4 - 1)*times;
  else
   s = (i + i/4)*times;
  

 }
 else
 {
  if( i % 9 == 0)
   s = (i + i/9 - 1)*times;
  else
   s = (i + i/9)*times;
  
 }
 return s;
}

int main()
{
 int T;
 int zeroSum;
 int To;

 cin>>T;
    while(T--)
    {
  scanf("%d%d",&zeroSum,&To);
  printf("%d\n",result(zeroSum,To));
    }
 return 0;
}

