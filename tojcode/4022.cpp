#include<iostream>
using namespace std;
int main()
{
  long long t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    if(n==2)
    {
      cout<<1<<endl;
      continue;
    }  
    if(n%2)
    {
      cout<<(n/2)*(n-n/2)<<endl;
      continue;
    }
    if(!(n%2))
    {
      if((n/2)%2)
      cout<<(n/2-2)*(n/2+2)<<endl;
      else
      cout<<(n/2-1)*(n/2+1)<<endl;
      continue;
    }       
  }
}    