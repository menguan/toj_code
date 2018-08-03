#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
  double s;
  while(cin>>s)
  {
    if(s<0)
      return 0;
    double t=sqrt(s*2.0);
    cout<<setprecision(2)<<fixed<<t<<endl;
  }
}  