#include<iostream>

using namespace std;
int main()
{
  int t,n,k;
  cin>>t;
  while(t--)
  {
     cin>>n>>k;
     if(n==13&&k>13)
     {
       cout<<2<<endl;
     }  
     else if(k<=12||k>14)
     {
       if(n%k)
         cout<<n/k+1<<endl;
       else
         cout<<n/k<<endl;
     }
     else if(k==13)
     {
       if(n%12)
         cout<<n/12+1<<endl;
       else
         cout<<n/12<<endl;
     }
     else if(k==14)
     {
       if(n%14==13)
         cout<<n/14+2<<endl;
       else if(n%14)
         cout<<n/k+1<<endl;
       else
         cout<<n/k<<endl;   
     }
                  
  }
}     