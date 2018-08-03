#include<iostream>
using namespace std;
int main()
{
  int t;
  int a,b,x,y;
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>x>>y;
    if((x*x*1.0/(a*a)+1.0*y*y/(b*b))<1)
      cout<<"In ellipse"<<endl;
    else
      cout<<a*a*b*b<<endl;
  }
}        