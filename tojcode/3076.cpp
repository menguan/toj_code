#include<iostream>
using namespace std;
bool isprime(long long n)
{
  if(n==2||n==3||n==5||n==7||n==11)return 1;
  else if(n%2==0)return 0;
  else 
  for(int i=3;i*i<=n;i+=2)
  {
    if(n%i==0)
    return 0;
  }
  return 1;
}    

int main()
{
  int n,low,high;
  while(cin>>n,n)
  {
    if(isprime(n)){cout<<0<<endl;continue;}
    
    
    for(int i=n;;i--)
    {
      if(isprime(i))
      {low=i;break;}
    }
    for(int i=n;;i++)
    {
      if(isprime(i))
      {high=i;break;}
    }
    cout<<high-low<<endl;
   }
}      
      
  