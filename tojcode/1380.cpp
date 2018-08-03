#include<iostream>
using namespace std;
int main()
{
  double t;
  while(cin>>t)
  {
    while(t>18)
    t/=18;
    if(t<=9)
    cout<<"Stan wins.\n";
    else
    cout<<"Ollie wins.\n";
  }
} 