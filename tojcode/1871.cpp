#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
  int l,f;
  while(cin>>l>>f&&(l+f))
  {
    cout<<setprecision(5)<<fixed<<sqrt(2*1.0*l*f)<<" ";
    cout<<setprecision(5)<<fixed<<1800*sqrt(1.0*2*f/l)<<endl;
  }
}    