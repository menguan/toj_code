#include<iostream>
using namespace std;
int main()
{
  long long ans;
  long long t,a;
  cin>>t;
  while(t--)
  {
    cin>>a;
    if(a==0)
      cout<<1<<endl;
    else if(a==1)
      cout<<2<<endl;
    else if(a==2)
      cout<<5<<endl;
    else
    {
      ans=5;
      a-=2;
      long long st=6;
      long long en=st+(a-1)*4;
      ans+=(st+en)/2*a;
      cout<<ans<<endl;
    }
    
  }
}              
      