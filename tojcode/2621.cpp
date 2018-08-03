#include<iostream>
using namespace std;

int main()
{
  int n;
  while(cin>>n,n)
  {
     int i=9;
     int j=1;
     while(n-2*i>0)
     {
       n-=2*i;
       i*=10;
       j*=10;
     }
     //cout<<j<<endl;
     j--;
     if(n%i)
       j+=(n%i);
     else
       j+=i;
     //cout<<j<<endl;    
     cout<<j;
     if(n-i<=0)
       j/=10;
     while(j)
     {
       cout<<j%10;
       j/=10;
     }
     cout<<endl;
   }
   }
   /*
  int main()
{
  int n;
  while(cin>>n)
  {
     int i=9;
     int j=1;
     while(n-2*i>0)
     {
       n-=2*i;
       i*=10;
       j*=10;
     }
     j--;
     if(n%i)
       j+=(n%i);
     else
       j+=i;
         
     //cout<<j;
     if(n-i<=0)
       j/=10;
     while(j)
     {
       cout<<j;
       j/=10;
     }
     cout<<endl;
   }
   */          
               
    