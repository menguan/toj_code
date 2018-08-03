#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int n,t;
  cin>>t;
  while(t--)
  {
            cin>>n;
            if(n==0||n==1) {cout<<0<<endl;continue;};
            
            int bas=1;
            int ans=0;
            while(n>bas)
            {
            bas*=2;
            ans++;
            }
            cout<<ans<<endl;
  }       
}

 