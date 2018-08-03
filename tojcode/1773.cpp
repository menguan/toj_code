#include<iostream>

using namespace std;
long long n;
long long f(long long t)
{
  long long ans=1;
  while(t--)
  {
    ans*=n;
  }
  return ans;
}    
    
  
int main()
{
  
  while(cin>>n,n)
  {
    cout<<(f(6)+3*f(4)+12*f(3)+8*f(2))/24<<endl; 
  }
}    