#include<iostream>
#include<cstring>
using namespace std;
long long mod=987654321;
int main()
{
  long long n,m;
  while(cin>>n>>m&&(m!=-1&&n!=-1))
  {
    long long ans=1;
    if(m>n||m<=2)
    {
      for(int i=0;i<n;i++)
      {
        ans=ans*m%mod;
      }
    }
    else
    {
      for(long long i=1;i<=m;i++)
      {
        ans=ans*i%mod;
      }
      ans=(ans+m)%mod;
    }
    cout<<ans<<endl;
  }
}