#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
  double a,b;
  double t;
  while(cin>>a>>b)
  {
    a=sqrt(1+1.0/a);
    b=sqrt(1+1.0/b);
    t=2*a-2*b+log(abs((a-1)/(a+1)))-log(abs((b-1)/(b+1)));
    cout<<setprecision(2)<<fixed<<t<<endl;
  }
}