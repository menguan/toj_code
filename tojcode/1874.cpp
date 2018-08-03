#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
  int t,count=1;;
  double d,v,u;
  cin>>t;
  while(t--)
  {
    cin>>d>>v>>u;
    double s=d/u;
    if(u<=v||v==0)
    {
      cout<<"Case "<<count++<<": can't determine"<<endl;
      continue;
    }
    double l=d/(sqrt(u*u-v*v));
    cout<<"Case "<<count++<<": ";
    cout<<setprecision(3)<<fixed<<l-s<<endl;
  }
}     
    
   