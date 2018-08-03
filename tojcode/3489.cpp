#include<iostream>
#include<algorithm>
using namespace std;
int dog[100];
int main()
{
  int t;
  cin>>t;
  int n;
  while(t--)
  {
   cin>>n;
   for(int i=0;i<n;i++)
   {
     cin>>dog[i];
   }
   sort(dog,dog+n);
   long long ans=dog[0];
   for(int i=1;i<n;i++)
   {
     ans*=(dog[i]-i);
     ans%=1000000007;
     if(ans==0)
      break;
   }
   cout<<ans<<endl;
  }
}     
   
     
   