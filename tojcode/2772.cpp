#include<iostream>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;
int main()
{
    int t;double xa,ya,xc,yc,xb,yb,xd,yd;
    double xe,ye,xf,yf;
    cin>>t;
    while(t--)
    {
       cin>>xa>>ya>>xc>>yc>>xb>>yb>>xd>>yd;
       xe=(xa+xc)/2;
       xf=(xb+xd)/2;
       ye=(ya+yc)/2;
       yf=(yb+yd)/2;
       if(fabs(xe-xf)<eps&&fabs(ye-yf)<eps)
       {
           cout<<"Yes"<<endl;
       }
       else
         cout<<"No"<<endl;
    }
}                                                
