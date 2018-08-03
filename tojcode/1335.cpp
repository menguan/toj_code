#include<iostream>
using namespace std;
int main()
{
  int s,d;
  while(cin>>s>>d)
  {
    int money=-1;
    if(s*4<d)
       money=10*s-2*d;
    else if(3*s<2*d)
       money=8*s-4*d;
    else if(2*s<3*d)
       money=6*s-6*d;
    else if(s<4*d)
       money=3*s-9*d;
    
    if(money>=0)
      cout<<money<<endl;
    else
      cout<<"Deficit"<<endl;
  }
}   