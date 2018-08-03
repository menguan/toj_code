#include<iostream>
using namespace std;
int gcd(int a,int b)
{
  if(a<b)
  {
    int temp=a;
    a=b;
    b=temp;
  }
  int r=a%b;
  while(r)
  {
    a=b;
    b=r;
    r=a%b;
  }
  return b;
}      
int main()
{
   int m,n,first,d;
   while(cin>>m>>n&&(m+n))
   {
     bool flag1=0;
     cin>>first;
     if(first>=n)
       flag1=1;
     if(m==1&&first!=n)
     {
       cout<<"NO"<<endl;
       continue;
     }
     else if(m==1&&first==n)
     {
       cout<<"YES"<<endl;
       continue;
     }
     else
     {
             
       m--;
       while(m--)
       {
         cin>>d;
         if(d>=n)
           flag1==1;
         first=gcd(first,d);
       }  
       if(flag1==1&&n%first==0)
       {
         cout<<"YES"<<endl;
         continue;
       }
       else
        {
       cout<<"NO"<<endl;
       continue;
     }
   }
 }
}      