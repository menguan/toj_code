#include<iostream>
#include<cmath>
#include<string>
using namespace std;
const double pi=acos(-1.0);
int main()
{
  string s;
  int x,y,z;
  while(cin>>s&&s!="ENDOFINPUT")
  {
    cin>>x>>y>>z;
    cin>>s;
    if(z>180)
      z=360-z;
    double len=2.0*x*pi*(z*1.0/180);//来回 
    double ll=5*y;//最多可以走 
    if(ll>=len)
    {
      cout<<"YES "<<(int)(y-len/5)<<endl;
    }
    else
    {
      cout<<"NO "<<ll<<endl;
    }  
  }
}      
    