#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   int a,b,c;
   while(cin>>a>>b>>c&&(a+b+c))
   {
      if(a>c) a-=c;
      else a=c-a;
      if(a%b!=0)
          cout<<"No accounting tablet"<<endl;
      else
      {
          a/=b;
          int ans=0;
          ans+=a/3;a%=3;
          ans+=a/2;a%=2;
          ans+=a;
          cout<<ans<<endl;
      } 
    }
}
