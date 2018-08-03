#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
  double vs,r,c,w,vr;
  int n;
  cin>>vs>>r>>c>>n;
  while(n--)
  {
    cin>>w;
    vr=r*c*w*vs/(sqrt(r*r*c*c*w*w+1));
    cout<<setprecision(3)<<fixed<<vr<<endl;
  }
} 