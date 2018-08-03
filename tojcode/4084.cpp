#include<iostream>
using namespace std;
int mod=10007;
typedef long long ll;
int main() 
{
  ll m,n;
  while(cin>>m>>n)
  {
    if(2*n-1>=mod)
    {
      cout<<0<<endl;
    }
    else
    {
      ll temp=3;
      for(ll i=1;i<=2*n-1;i+=2)
         temp=temp*i%mod;
      cout<<(temp*((m%mod)*(m%mod)+2*m))%mod<<endl;
    }
  }
}      
   