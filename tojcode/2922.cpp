#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    unsigned long long ans;
    long long a,b;
    while(cin>>a>>b)
    {
      if(b==0)
      {  cout<<2<<endl;
         continue;
      }        
      else if(b==1)
      {
        cout<<3<<endl;
        continue;
        }     
      else 
      {
         ans=3+(3+3+b-2)*(b-1)/2;
         cout<<ans<<endl;
      }
    }
}        
