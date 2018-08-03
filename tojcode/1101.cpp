#include<iostream>//一开始的平地是跟平地后的数走的 之后的平地是跟平地前的数走的 
#include<stdio.h>
#include<cstring>
using namespace std;
const int EVEN=0,UP=1,DOWN=-1;
int main()
{
 int pre,cur,cnt=0,n;
 while(cin>>n)
 {
  if(n==0)break;
  int pre=n,cur,cnt=1,sta=EVEN;
  int uplen=0,downlen=0,evenlen=0,upcnt=0,downcnt=0;
  while(cin>>cur)
  {
   if(cur==0)break;
   cnt++;
   if(cur>pre)
   {
    if(sta==UP)uplen++;
    else if(sta==DOWN)
    {
     downcnt++;
     uplen++;
     sta=UP;
    }
    else
    {
     uplen+=evenlen+1;
     sta=UP;
    }
   }
   else if(cur<pre)
   {
    if(sta==DOWN)downlen++;
    else if(sta==UP)
    {
     upcnt++;
     downlen++;
     sta=DOWN;
    }
    else
    {
     downlen+=evenlen+1;
     sta=DOWN;
    }
   }
   else
   {
    if(sta==DOWN)downlen++;
    else if(sta==UP)uplen++;
    else evenlen++;
   }
   pre=cur;
  }
  if(sta==UP)upcnt++;
  else if(sta==DOWN)downcnt++;
  double upavg=0,downavg=0;
  if(upcnt!=0)upavg=1.0*uplen/upcnt;
  if(downcnt!=0)downavg=1.0*downlen/downcnt;
  printf("Nr values = %d: %.6f %.6f\n",cnt,upavg,downavg);
 }  
 return 0; 
}

