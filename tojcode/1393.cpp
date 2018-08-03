#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main()
{
  double d,v;
  while(cin>>d>>v)
  {
    if(d==0&&v==0)
      return 0;
    
    double t;
    t=pow((pow(d,3.0)-6*v/pi),1/3.0);
    cout<<setprecision(3)<<fixed<<t<<endl;
  }
}        
  