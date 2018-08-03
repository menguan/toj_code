#include<iostream>
#include<cmath>
#include<iomanip>
const double PI=acos(-1);
using namespace std;
int main()
{
  double a,b,c,d,e,f;
  while(cin>>a>>b>>c>>d>>e>>f)
  {
    double m,n,p;
    m=hypot(a-c,b-d);
    n=hypot(a-e,b-f);
    p=hypot(c-e,d-f);
    double cos=(m*m+n*n-p*p)/(2*m*n);
    
    double sin=sqrt(1-cos*cos);
    
    double s=0.5*m*n*sin;
    
    double t=PI*(m*n*p)/(2*s);
    cout<<setprecision(2)<<fixed<<t<<endl;
  }
}    